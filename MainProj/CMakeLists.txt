#Addanki Adithya
# ---------------------------------------------------------------------------- #
# CMake configuration

cmake_minimum_required(VERSION 2.8)


# ---------------------------------------------------------------------------- #
# Project configuration

# Define the top-level project
project(MainProj CXX)
enable_testing()

# Compiler config
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
include_directories(.)

# ---------------------------------------------------------------------------- #
# Build

# Add the library
add_library(MainProj neighbor.cpp main.cpp)


# ---------------------------------------------------------------------------- #
# Testing

# This macro will create unit tests for a module.
macro(add_unit_test mod file)
  set(tgt ${mod}.${file})
  add_executable(${tgt} ${mod}.test/${file}.cpp)
  target_link_libraries(${tgt} MainProj)
  add_test(test.${tgt} ${tgt})
endmacro()

# Add a test suite.
add_unit_test(neighbor neighbor_ptest)
add_unit_test(neighbor neighbor_p3test)
add_unit_test(neighbor neighbor_strtest)
add_unit_test(neighbor neighbor_binstr)

# ---------------------------------------------------------------------------- #
# Submission

# The make_manifest macro creates targets that generate a PDF of
# your code for grading.
macro(make_manifest)
  # Complete the paths to all files
  set(src "")
  set(doc "")
  foreach(i ${ARGV})
    # Make sure the file has its absolute path.
    set(f ${CMAKE_CURRENT_SOURCE_DIR}/${i})

    # What kind of file are we talking about?
    # We're going to process them a little differently.
    get_filename_component(ext ${i} EXT)
    if (${ext} STREQUAL ".md")
      list(APPEND doc ${f})
    else()
      list(APPEND src ${f})
    endif()
  endforeach()

  # Generate the manifest target
  set(outdoc "${CMAKE_CURRENT_BINARY_DIR}/doc.html")
  add_custom_target(manifest
    COMMAND pandoc ${doc} -o ${outdoc}
    COMMAND a2ps -Afill -o manifest.ps ${outdoc} ${src}
    COMMAND ps2pdf manifest.ps)
endmacro()

