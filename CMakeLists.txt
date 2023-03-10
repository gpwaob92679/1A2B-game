cmake_minimum_required(VERSION 3.5)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(1A2B-game VERSION 0.2.0 LANGUAGES CXX)

# Read the git tags to determine the project version
include(GetGitVersion)
get_git_version(GIT_VERSION)
# If no git version can be determined, use the version
# from the project() command
if ("${GIT_VERSION}" STREQUAL "0.0.0")
  set(VERSION "${benchmark_VERSION}")
else()
  set(VERSION "${GIT_VERSION}")
endif()
# Tell the user what versions we are using
message(STATUS "Version: ${VERSION}")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
  src/main.cpp
  src/game.cpp
  src/game.h
  src/util.cpp
  src/util.h
  src/ui/digit_spin_box.h
  src/ui/digit_spin_box.cpp
  src/ui/mainwindow.cpp
  src/ui/mainwindow.h
  src/ui/mainwindow.ui
  src/ui/timer_label.h
  src/ui/timer_label.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(1A2B-game
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
  )

target_include_directories(1A2B-game PRIVATE src/)

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET 1A2B-game APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
  if(ANDROID)
    add_library(1A2B-game SHARED
      ${PROJECT_SOURCES}
    )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
  else()
    add_executable(1A2B-game
      ${PROJECT_SOURCES}
    )
  endif()
endif()

target_link_libraries(1A2B-game PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(1A2B-game PROPERTIES
  MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
  MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
  MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
  MACOSX_BUNDLE TRUE
  WIN32_EXECUTABLE TRUE
)

install(TARGETS 1A2B-game
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(1A2B-game)
endif()
