# CMake Git Version Detect

This module allows you to use Git versioning information in your `CMakeLists.txt`.


## Installation

This repo is meant to be cloned as a submoule inside your project CMake modules folder. Alternatively, you can copy the cmake module directly in your folder.

Remember to add your CMake modules folder to the module search path in your `CMakeLists.txt`. This can be done with the list append command:
```CMake
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/<your_cmake_modules_folder>/cmake-gitversiondetect")
```

Also, include the module in your `CMakeLists.txt`:
```CMake
include(GitVersionDetect)
```


## Usage

After you have included the module, the following variables will be available:
* `GITVERSIONDETECT_VERSION`: Full git tag as `git describe --dirty` would produce.
* `GITVERSIONDETECT_VERSION_MAJOR`: Major version matched from `GITVERSIONDETECT_VERSION`.
* `GITVERSIONDETECT_VERSION_MINOR`: Minor version matched from `GITVERSIONDETECT_VERSION`.
* `GITVERSIONDETECT_VERSION_PATCH`: Patch version matched from `GITVERSIONDETECT_VERSION`.
* `GITVERSIONDETECT_VERSION_COMMIT_NUM`: Number of commits that separate current source from the detected version tag.
* `GITVERSIONDETECT_VERSION_COMMIT_SHA`: Current commit SHA.
