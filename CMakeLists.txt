cmake_minimum_required(VERSION 3.25)
project(AutoExamReloaded)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

add_subdirectory(OpenXLSX)

add_executable(AutoExamReloaded main.cpp XLSXUtilities.cpp XLSXUtilities.h Career.cpp Career.h Constants.h Subject.cpp Subject.h DNAOptimization.cpp DNAOptimization.h)
target_link_libraries(AutoExamReloaded OpenXLSX::OpenXLSX)