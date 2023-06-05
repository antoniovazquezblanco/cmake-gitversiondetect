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


## Example

```CMake
# Add all module folders to the search path...
file(GLOB MODULE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/*/" LIST_DIRECTORIES true)
list(APPEND CMAKE_MODULE_PATH "${MODULE_DIRS}")

# Use git version detect to obtain a project version based on tags
include(GitVersionDetect)
set(MYPROJECT_VERSION_MAJOR ${GITVERSIONDETECT_VERSION_MAJOR})
set(MYPROJECT_VERSION_MINOR ${GITVERSIONDETECT_VERSION_MINOR})
set(MYPROJECT_VERSION_PATCH ${GITVERSIONDETECT_VERSION_PATCH})
set(MYPROJECT_VERSION ${MYPROJECT_VERSION_MAJOR}.${MYPROJECT_VERSION_MINOR}.${MYPROJECT_VERSION_PATCH})

# Define the project
project(
  my_project
  VERSION ${MYPROJECT_VERSION}
  LANGUAGES C)
```
