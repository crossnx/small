<p align="center"><img src="./banner.png" alt="small logo"/></p>
<h1 align="center">small</h1>
<h3 align="center">Toy runtime build on top of <a src="https://github.com/crossnx/includejs">includejs</a></h3>
<p align="center">
  <a href="https://github.com/crossnx/small/actions/workflows/ci.yml"><img src="https://github.com/crossnx/small/actions/workflows/ci.yml/badge.svg" alt="github action build"></a>
</p>

## Usage

```
./build/small_runtime <path of your .fs file>
```

Example:

```
./build/small_runtime index.js
```

## Dependencies

- C++
- CMake
- JavascriptCore
- Brew (macOS)

## Build localy

### Install dependencies

- For `macOS`
  ```
  brew bundle 
  ```

- For Ubuntu
  ```
  sudo apt-get install --yes libjavascriptcoregtk-4.0-dev
  ```

### Run

```
make
```

When the build is finished, you'll find the executable available at this location:

```
./build/small_runtime
```
