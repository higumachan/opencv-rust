# Rust OpenCV bindings

[![Github Actions](https://github.com/twistedfall/opencv-rust/workflows/opencv-rust/badge.svg)](https://github.com/twistedfall/opencv-rust/actions?query=workflow%3Aopencv-rust)
[![Documentation](https://docs.rs/opencv/badge.svg)](https://docs.rs/opencv)
[![Package](https://img.shields.io/crates/v/opencv.svg)](https://crates.io/crates/opencv)

Experimental Rust bindings for OpenCV 3 and 4.

The API is usable, but unstable and not very battle-tested; use at your own risk.

## Quickstart

Make sure the supported OpenCV version (3.2, 3.4 or 4.x) is installed in your system.

Update your Cargo.toml
```toml
opencv = "0.36"
```

Select OpenCV version if different from default (opencv-4) in Cargo.toml:
```toml
opencv = {version = "0.36", default-features = false, features = ["opencv-34"]}
```

Or enable usage of `contrib` modules:
```toml
opencv = {version = "0.36", features = ["contrib"]}
```

Import prelude
```rust
use opencv::prelude::*;
```

When building on Windows and macOS you must enable `buildtime-bindgen` feature to avoid link errors:
```toml
opencv = {version = "0.36", features = ["buildtime-bindgen"]}
```

## Getting OpenCV

### Linux

You have several options of getting the OpenCV library:

* install it from the repository, make sure to install `-dev` packages because they contain headers necessary
  for the crate build (also check that your package contains `pkg_config` or `cmake` files).

* build OpenCV manually and set up the following environment variables prior to building the project with
  `opencv` crate:
  * `PKG_CONFIG_PATH` for the location of `*.pc` files or `OpenCV_DIR` for the location of `*.cmake` files
  * `LD_LIBRARY_PATH` for where to look for the installed `*.so` files during runtime

### Windows package

Installing OpenCV is easy through the following sources:

* from [chocolatey](https://chocolatey.org), also install `llvm` package, it's required for building:
  ```shell script
  choco install llvm opencv
  ```
  also set `OPENCV_LINK_LIBS`, `OPENCV_LINK_PATHS` and `OPENCV_INCLUDE_PATHS` environment variables (see below
  for details).
  
  Also, check the user guides [here](https://github.com/twistedfall/opencv-rust/issues/118#issuecomment-619608278)
  and [here](https://github.com/twistedfall/opencv-rust/issues/113#issue-596076777).

* from [vcpkg](https://docs.microsoft.com/en-us/cpp/build/vcpkg), also install `llvm` package,
  necessary for building:
  ```shell script
  vcpkg install llvm opencv4[contrib,nonfree]
  ```

### macOS package

Get OpenCV from homebrew:

* [homebrew](https://brew.sh), be sure to also install `llvm` and `pkg-config` that are required for building:
  ```shell script
  brew install llvm pkg-config opencv
  ```

### Manual build

You can of course always compile OpenCV of the version you prefer manually. This is also supported, but it
requires some additional configuration.

You need to set up the following environment variables to point to the installed files of your OpenCV build: 
`OPENCV_LINK_LIBS`, `OPENCV_LINK_PATHS` and `OPENCV_INCLUDE_PATHS` (see below for details).

## Troubleshooting

1. One of the common problems is link errors in the end of the build.

   Try building with `buildtime-bindgen` feature enabled (requires installed clang/llvm), it will recreate
   rust and cpp files to match the version you have installed. Please be sure to also set up the relevant
   environment variables that will allow the linker to find the libraries it needs (see below).

2. You're getting runtime errors like:
   ```
   thread 'main' panicked at 'called `Result::unwrap()` on an `Err` value: Error { code: -215, message: "OpenCV(4.2.0) /build/opencv/src/opencv-4.2.0/modules/highgui/src/window.cpp:384: error: (-215:Assertion failed) size.width>0 && size.height>0 in function \'imshow\'\n" }', src/libcore/result.rs:1188:5
   ```
   ```
   thread 'extraction::tests::test_contour_matching' panicked at 'called `Result::unwrap()` on an `Err` value: Error { code: -215, message: "OpenCV(4.1.1) /tmp/opencv-20190908-41416-17rm3ol/opencv-4.1.1/modules/core/src/matrix_wrap.cpp:79: error: (-215:Assertion failed) 0 <= i && i < (int)vv.size() in function \'getMat_\'\n" }', src/libcore/result.rs:1165:5
   ```

   These errors (note the .cpp source file and `Error` return value) are coming from OpenCV itself, not from
   the crate. It means that you're using the OpenCV API incorrectly, e.g. passing incompatible or unexpected
   arguments. Please refer to the OpenCV documentation for details.

3. You're getting errors that methods don't exist or not implemented for specific `struct`s, but you can see
   them in the documentation and in the crate source.

   Be sure to import ```use opencv::prelude::*;```. The crate contains a lot of traits that need to be imported
   first.

   Also check that if you're using a contrib module that the `contrib` feature is enabled for the crate. 

4. On Windows, you're getting the `(exit code: 0xc0000135, STATUS_DLL_NOT_FOUND)` error when running the
   compiled binary.

   That often means that Windows can't find the OpenCV library dll. Be sure to set up `PATH` environment
   variable correctly or copy the dll next to the binary you're trying to run. Check
   [that](https://github.com/twistedfall/opencv-rust/issues/118#issuecomment-619608278) guide too.

## Reporting issues

If you still have trouble using the crate after going through the Troubleshooting steps please fill free to
report it to the [bugtracker](https://github.com/twistedfall/opencv-rust/issues).

When reporting an issue please state:
1. Operating system
2. The way you installed OpenCV: package, official binary distribution, manual compilation, etc.
3. OpenCV version
4. Attach the full output of the following command from your project directory:
   ```shell script
   RUST_BACKTRACE=full cargo build -vv 
   ```

## Environment variables

The following variables must be set when building without `pkg_config`, `cmake` or `vcpkg`. You can set them
on any platform, the specified values will override those automatically discovered.

* `OPENCV_LINK_LIBS`
  Comma separated list of library names to link to. `.lib`, `.so` or `.dylib` extension is optional. If you
  specify the ".framework" extension then build script will link a macOS framework instead of plain shared
  library.
  E.g. "opencv_world411".

* `OPENCV_LINK_PATHS`
  Comma separated list of paths to search for libraries to link. E.g. "C:\tools\opencv\build\x64\vc14\lib".

* `OPENCV_INCLUDE_PATHS`
  Comma separated list of paths to search for system include files during compilation. E.g.
  "C:\tools\opencv\build\include". One of the directories specified therein must contain
  "opencv2/core/version.hpp" or "core/version.hpp" file, it's used to detect the version of the headers.

The following variables are rarely used, but you might need them under some circumstances:

* `OPENCV_HEADER_DIR`
  During crate build it uses OpenCV headers bundled with the crate. If you want to use your own (system)
  headers supply `OPENCV_HEADER_DIR` environment variable.
  The directory in that environment variable should contain `opencv2` dir, e.g. set it `/usr/include` for
  OpenCV-3.4.x or `/usr/include/opencv4` for OpenCV-4.x.

* `OPENCV_PACKAGE_NAME`
  In some cases you might want to override the pkg-config, cmake or vcpkg package name, you can use this
  environment variable for that. If you set it pkg-config will expect to find the file with that name and `.pc`
  extension in the package directory. Cmake will look for that file with `.cmake` extension. And vcpkg will use
  that name to try to find package in `packages` directory under `VCPKG_ROOT`. You can also use separate
  environment variables to set different package names for different package systems:
    * `OPENCV_PKGCONFIG_NAME`
    * `OPENCV_CMAKE_NAME`
    * `OPENCV_VCPKG_NAME`

* `OPENCV_CMAKE_BIN`
  Path to cmake binary (used in OpenCV discovery process using cmake). If not set then just "cmake" will be
  used. For example, you can set something like "/usr/local/bin/cmake" here.

* `OPENCV_DISABLE_PROBES`
  Comma separated list of OpenCV package auto-discovery systems to exclude from running. Might be useful if
  one of the higher priority systems is producing incorrect results. Can contain the following values:
    * pkg_config
    * cmake
    * vcpkg

The following variables affect the building the of the `opencv` crate, but belong to external components:

* `PKG_CONFIG_PATH`
  Where to look for `*.pc` files see the [man pkg-config](https://linux.die.net/man/1/pkg-config)
  Path specified here must contain `opencv.pc` (pre OpenCV 4) or `opencv4.pc` (OpenCV 4 and later).

* `VCPKG_ROOT` and `VCPKGRS_DYNAMIC`
  The root of `vcpkg` installation and flag allowing use of `*.dll` libraries, see the
  [documentation for `vcpkg` crate](https://docs.rs/vcpkg)

* `OpenCV_DIR`
  The directory that contains OpenCV package cmake files. Usually there are `OpenCVConfig.cmake`,
  `OpenCVConfig-version.cmake` and `OpenCVModules.cmake` in it.

* `LD_LIBRARY_PATH`
  On Linux it sets the list of directories to look for the installed `*.so` files during runtime.
  [Linux documentation](https://tldp.org/HOWTO/Program-Library-HOWTO/shared-libraries.html) has more info.
  Path specified here must contain `libopencv_*.so` files.

* `DYLD_LIBRARY_PATH`
  Similar to `LD_LIBRARY_PATH`, but for loading `*.dylib` files on macOS, see
  [man dyld](https://man.cx/dyld(1)) for more info.
  Path specified here must contain `*.dylib` files.

* `PATH`
  Windows searches for `*.dll`s in `PATH` among other places, be sure to set it up, or copy required OpenCV
  `*.dll`s next to your binary. Be sure to specify paths in UNIX style (/C/Program Files/Dir) because colon
   in `PATH` might be interpreted as the entry separator. Summary
  [here](https://stackoverflow.com/questions/2463243/dll-search-on-windows#answer-6546427).

* clang crate environment variables
  See crate's [README](https://github.com/KyleMayes/clang-sys/blob/master/README.md#environment-variables)

## Cargo features
* `opencv-32` - build against OpenCV 3.2.0, this feature is aimed primarily on stable Debian and
  Ubuntu users who can install OpenCV from the repository without having to compile it from the
  source
* `opencv-34` - build against OpenCV 3.4.x
* `opencv-4` (default) - build against OpenCV 4.x
* `contrib` - enable the usage of OpenCV contrib modules for corresponding OpenCV version
* `buildtime-bindgen` - regenerate all bindings, requires installed clang/llvm (minimum supported version is
  6.0), should only be used during the crate development or when building on Windows or macOS, with this
  feature enabled the bundled headers are no longer used for the code generation, the ones from the installed
  OpenCV are used instead
* `docs-only` - internal usage, for building docs on [docs.rs](https://docs.rs/opencv)

## API details

[API Documentation](https://docs.rs/opencv) is automatically translated from OpenCV's doxygen docs. Most
likely you'll still want to refer to the official [OpenCV C++ documentation](https://docs.opencv.org/master)
as well.

### OpenCV version support

The following OpenCV versions are supported at the moment:
* 3.2 - enabled by `opencv-32` feature
* 3.4 - enabled by `opencv-34` feature
* 4.3 - enabled by the default `opencv-4` feature

If you need support for `contrib` modules, also enable `contrib` feature.

### Minimum rustc version

Generally you should use the latest stable rustc to compile this crate.

### Platform support

Currently, the main development and testing of the crate is performed on Linux, but other major platforms are
also supported: macOS and Windows.

For some more details please refer to the CI build scripts:
[Linux OpenCV install](https://github.com/twistedfall/opencv-rust/blob/master/ci/install-bionic.sh),
[macOS OpenCV install as framework](https://github.com/twistedfall/opencv-rust/blob/master/ci/install-macos-framework.sh),
[macOS OpenCV install via brew](https://github.com/twistedfall/opencv-rust/blob/master/ci/install-macos-brew.sh),
[Windows OpenCV install via Chocolatey](https://github.com/twistedfall/opencv-rust/blob/master/ci/install-windows-chocolatey.sh),
[Windows OpenCV install via vcpkg](https://github.com/twistedfall/opencv-rust/blob/master/ci/install-windows-vcpkg.sh),
[Test runner script](https://github.com/twistedfall/opencv-rust/blob/master/ci/script.sh).

### Functionality

Generally the crate tries to only wrap OpenCV API and provide some convenience functions
to be able to use it in Rust easier. We try to avoid adding any functionality besides
that.

### Errors

Most functions return a `Result` to expose a potential C++ exception. Although some methods like property reads
or functions that are marked CV_NOEXCEPT in the OpenCV headers are infallible and return a naked value.

### Properties

Properties of OpenCV classes are accessible through setters and getters. Those functions are infallible, they
return the value directly instead of `Result`.

### Infallible functions

For infallible functions (like setters) that accept `&str` values the following logic applies: if a Rust
string passed as argument contains null byte then this string will be truncated up to that null byte. So if
for example you pass "123\0456" to the setter, the property will be set to "123". 

### Callbacks

Some API functions accept callbacks, e.g. set_mouse_callback. While currently
it's possible to successfully use those functions there are some limitations to
keep in mind. Current implementation of callback handling keeps hold of the
passed callback argument forever. That means that the closure used as a callback
will never be freed during the lifetime of a program and moreover Drop will
not be called for it (they are stored in global static [`Slab`](https://crates.io/crates/slab)).
There is a plan to implement possibility to be able to free at least some of the
closures.

### Unsafety

Although crate tries to provide ergonomic Rust interface for OpenCV, don't expect
Rust safety guarantees at this stage. It's especially true for borrow checking and
shared mutable ownership. Notable example would be `Mat` which is a reference counted
object in its essence. You can own a seemingly separate `Mat` in Rust terms, but
it's going to be a mutable reference to the other `Mat` under the hood. Treat safety
of the crate's API as you would treat one of C++, use `clone()` when needed.

## Contrib modules

The following modules require [`opencv_contrib`](https://github.com/opencv/opencv_contrib) installed:
 * aruco
 * bgsegm
 * bioinspired
 * ccalib
 * cvv
 * dnn (only for OpenCV 3.2)
 * dpm
 * face
 * freetype
 * fuzzy
 * hdf
 * img_hash
 * line_descriptor
 * phase_unwrapping
 * plot
 * sfm
 * shape
 * structured_light
 * superres
 * surface_matching
 * text
 * videostab
 * viz
 * xfeatures2d
 * xobjdetect
 * xphoto

## Missing modules and functions

While most of the API is covered, for various reasons (that might no longer hold) there are modules and
functions that are not yet implemented. If a missing module/function is near and dear to you, please file an
issue (or better, open a pull request!).

CUDA is not supported at the moment, but is definitely in the roadmap. You can use OpenCL for now.

## The binding strategy

This crate works similar to the model of python and java's OpenCV wrappers - it uses libclang to parse the
OpenCV C++ headers, generates a C interface to the C++ API, and wraps the C interface in Rust.

All the major modules in the C++ API are merged together in a huge `cv::` namespace. We instead made one rust
module for each major OpenCV module. So, for example, C++ `cv::Mat` is `opencv::core::Mat` in this crate.

The methods and field names have been snake_cased. Methods arguments with default value lose these default
values, but they are reported in the API documentation.

Overloaded methods have been mostly manually given different names or automatically renamed to *_1, *_2, etc.

## OpenCV 2 support

If you can't use OpenCV 3.x or higher, the (no longer maintained) `0.2.4` version of this crate is known to
work with OpenCV `2.4.7.13` (and probably other 2.4 versions). Please refer to the README.md file for that
version because the crate has gone through the considerable rewrite since.

## Contributor's Guide

The binding generator code lives in a separate crate under [binding-generator](binding-generator). During the
build phase (with `buildtime-bindgen` feature enabled) it creates bindings from the header files and puts them
into [bindings](bindings) directory. Those are then transferred to [src](src) for the consumption by the
crate users. 

The crate itself, as imported by users, consists of generated rust code in [src](src) committed to the repo.
This way, users don't have to handle the code generation overhead in their builds. When developing this crate,
you can test changes to the binding generation using `cargo build -vv --features buildtime-bindgen`. When
changing the `binding-generator`, be sure to push changes to the generated code!

If you're looking for things to improve be sure to search for `todo` and `fixme` labels in the project
source, those usually carry the comment of what exactly needs to be fixed.

The license for the original work is [MIT](https://opensource.org/licenses/MIT).

Special thanks to [ttacon](https://github.com/ttacon) for yielding the crate name.
