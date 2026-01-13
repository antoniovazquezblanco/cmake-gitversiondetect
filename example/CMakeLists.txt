# Specify minimum CMake version
cmake_minimum_required(VERSION 3.5)

# Include the FetchContent module to get other modules...
include(FetchContent)

# Fetch the GitVersionDetect module...
FetchContent_Declare(
  gitversiondetect
  GIT_REPOSITORY https://github.com/antoniovazquezblanco/cmake-gitversiondetect.git
  GIT_TAG main  # Or specify a version
)
FetchContent_MakeAvailable(gitversiondetect)
list(APPEND CMAKE_MODULE_PATH "${gitversiondetect_SOURCE_DIR}")

# Include the GitVersionDetect module
include(GitVersionDetect)

# Set project version using GitVersionDetect variables
set(PROJECT_VERSION_MAJOR ${GITVERSIONDETECT_VERSION_MAJOR})
set(PROJECT_VERSION_MINOR ${GITVERSIONDETECT_VERSION_MINOR})
set(PROJECT_VERSION_PATCH ${GITVERSIONDETECT_VERSION_PATCH})
set(PROJECT_VERSION ${GITVERSIONDETECT_VERSION})

# Define the project
project(
  example_project
  VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
  LANGUAGES C
)

# Add executable
add_executable(example main.c)

# Pass version info to the source code
target_compile_definitions(example PRIVATE
  VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
  VERSION_MINOR=${PROJECT_VERSION_MINOR}
  VERSION_PATCH=${PROJECT_VERSION_PATCH}
  VERSION_STRING="${PROJECT_VERSION}"
)
