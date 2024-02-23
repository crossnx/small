#include <includejs/engine.h>

#include <cstdlib>    // EXIT_SUCCESS, EXIT_FAILURE
#include <filesystem> // std::path
#include <fstream>    // std::ifstream
#include <iostream>   // std::cout
#include <optional>   // std::optional
#include <string>     // std::string

struct InputFile {
  std::string source;
  std::string file_name;
};

bool run(const std::string &source, const std::string &file_name) {
  includejs::Engine engine;

  includejs::Value result{engine.evaluate(source, file_name)};
  if (!result.is_number()) {
    std::cerr << "Error: result is not a number\n";
    return false;
  }

  std::cout << result.to_number() << "\n";
  return true;
}

void print_usage() { std::cerr << "Usage: smallruntime <path-to-js-file>\n"; }

std::optional<InputFile> read_file(const char *input) {
  const std::filesystem::path path{input};
  if (!std::filesystem::exists(path)) {
    std::cerr << "Error: file does not exist\n";
    return std::nullopt;
  }

  std::ifstream file(path, std::ios::in);

  if (!file.is_open()) {
    std::cerr << "Error: could not open file\n";
    return std::nullopt;
  }

  std::string source{std::istreambuf_iterator<char>(file),
                     std::istreambuf_iterator<char>()};
  std::string file_name{path.filename()};

  return std::make_optional<InputFile>(InputFile{source, file_name});
}

int main(int argc, char *argv[]) {
  // Check if the user provided enough arguments
  if (argc < 2) {
    print_usage();
    return EXIT_FAILURE;
  }

  // Check if the file exists and can be opened
  const auto input_file{read_file(argv[1])};
  if (!input_file.has_value()) {
    return EXIT_FAILURE;
  }

  // Run the code
  if (!run(input_file->source, input_file->file_name)) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
