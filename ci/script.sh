#!/bin/bash

set -vex

if [[ "$OS_FAMILY" == "windows" ]]; then
	export PATH="/C/Program Files/LLVM/bin:$PATH"
	if [[ "$CHOCO_OPENCV_VERSION" != "" ]]; then # chocolatey build
		# missing aruco module that will not allow us to run tests, that's why contrib feature is not enabled
		export PATH="/C/tools/opencv/build/x64/vc14/bin:$PATH"
		export OPENCV_LINK_PATHS="/C/tools/opencv/build/x64/vc14/lib"
		export OPENCV_LINK_LIBS="opencv_world${CHOCO_OPENCV_VERSION//./}"
		export OPENCV_INCLUDE_PATHS="/C/tools/opencv/build/include"
	else # vcpkg build
		CARGO_FEATURES="$CARGO_FEATURES,contrib"
		export VCPKGRS_DYNAMIC=1
		export VCPKG_ROOT="$HOME/build/vcpkg"
		echo "=== Installed vcpkg packages:"
		"$VCPKG_ROOT/vcpkg" list
	fi
	echo "=== Installed chocolatey packages:"
	choco list --local-only
elif [[ "$OS_FAMILY" == "osx" ]]; then
	CARGO_FEATURES="$CARGO_FEATURES,contrib"
	# fixme, enable building with xcode libclang
#	xcode_path="$(xcode-select --print-path)/"
#	toolchain_path="$xcode_path/Toolchains/XcodeDefault.xctoolchain/"
#	export LIBCLANG_PATH="$toolchain_path/usr/lib/libclang.dylib"
#	export CLANG_PATH="$toolchain_path/usr/bin/clang"
#	export DYLD_LIBRARY_PATH="$toolchain_path/usr/lib/"
	if [[ "$BREW_OPENCV_VERSION" != "" ]]; then # brew build
		if [[ "$BREW_OPENCV_VERSION" == "@3" ]]; then
			export PKG_CONFIG_PATH="/usr/local/opt/opencv@3/lib/pkgconfig"
		fi
	else # framework build
		clang_dir="$(clang --print-search-dirs | awk -F= '/^libraries: =/ { print $2 }')"
		export OPENCV_LINK_PATHS="$HOME/build/opencv/opencv-$OPENCV_VERSION-build,$clang_dir/lib/darwin"
		export OPENCV_LINK_LIBS="opencv2.framework,OpenCL.framework,Cocoa.framework,Accelerate.framework,AVFoundation.framework,CoreGraphics.framework,CoreMedia.framework,CoreVideo.framework,QuartzCore.framework,clang_rt.osx"
#		export OPENCV_INCLUDE_PATHS="$HOME/build/opencv/opencv-$OPENCV_VERSION-build/opencv2.framework"
		export OPENCV_INCLUDE_PATHS="$HOME/build/opencv/opencv-$OPENCV_VERSION-build/build/build-x86_64-macosx/install/include"
	fi
elif [[ "$OS_FAMILY" == "linux" ]]; then
	if [[ "$OPENCV_VERSION" != "3.2.0" ]]; then
		# 3.2.0 version from the repository doesn't have dnn module, that's why contrib feature is not enabled
		CARGO_FEATURES="$CARGO_FEATURES,contrib"
	fi
fi

echo "=== Current directory: $(pwd)"
echo "=== Environment variable dump:"
export
echo "=== Target settings:"
rustc --print=cfg

cargo test -vv -p opencv-binding-generator

# todo: test without contrib too

# linux is the only possible platform to build without `buildtime-bindgen`
if [[ "$OS_FAMILY" == "linux" ]]; then
	cargo test -vv --no-default-features --features "$CARGO_FEATURES"
	cargo test --release -vv --no-default-features --features "$CARGO_FEATURES"
fi

CARGO_FEATURES="$CARGO_FEATURES,buildtime-bindgen"
cargo test -vv --no-default-features --features "$CARGO_FEATURES"
cargo test --release -vv --no-default-features --features "$CARGO_FEATURES"

# on windows clang through `cc` crate fails because of -fPIC flag
if [[ "$OS_FAMILY" != "windows" ]]; then
	export CXX=clang++
	touch build.rs
	cargo test -vv --no-default-features --features "$CARGO_FEATURES"
	cargo test --release -vv --no-default-features --features "$CARGO_FEATURES"
fi

CARGO_FEATURES="$CARGO_FEATURES,clang-runtime"
cargo test -vv --no-default-features --features "$CARGO_FEATURES"
cargo test --release -vv --no-default-features --features "$CARGO_FEATURES"
