
cmake_minimum_required(VERSION 3.18)

project(small_runtime VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
  includejs
  GIT_REPOSITORY https://github.com/crossnx/includejs
  GIT_TAG        main
  DOWNLOAD_EXTRACT_TIMESTAMP NO)
FetchContent_MakeAvailable(includejs)

add_executable(small_runtime main.cc)
target_link_libraries(small_runtime PRIVATE includejs::engine)
