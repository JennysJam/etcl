cmake_minimum_required(VERSION 3.11)
project(etcl)

## global variables

# current directory
set (ETCLROOT "${CMAKE_CURRENT_SOURCE_DIR}")

# public include directories
set (
    ETCL_PUBLIC_INCLUDES
    "${ETCLROOT}/include/"
)
set (
    ETCL_PRIVATE_INCLUDES
    "${ETCLROOT}/src/"
)

# sources
set (
    ETCL_SOURCES 
    "${ETCLROOT}/src/Interp.cpp"
    "${ETCLROOT}/src/Object.cpp"
    "${ETCLROOT}/include/etcl/common.h"
    "${ETCLROOT}/include/etcl/etcl.h"
    "${ETCLROOT}/include/etcl/Interp.h"
    "${ETCLROOT}/include/etcl/Value.h"
    "${ETCLROOT}/include/etcl/Parser.h"
)

message (INFO " ETCL_SOURCES = ${ETCL_SOURCES}")

message (INFO " ETCL_PRIVATE_INCLUDES = ${ETCL_PRIVATE_INCLUDES}")

message (INFO " ETCL_PUBLIC_INCLUDES = ${ETCL_PUBLIC_INCLUDES}")

## Dynamic library

add_library(etcl SHARED)
add_library(etcl::etcl ALIAS etcl)

target_sources(
    etcl PRIVATE
    "${ETCL_SOURCES}"
)
target_include_directories(
    etcl PUBLIC
    "${ETCL_PUBLIC_INCLUDES}"
    PRIVATE
    "${ETCL_PRIVATE_INCLUDES}"
)



## Static library
add_library(staticetcl STATIC)
add_library(etcl::staticetcl ALIAS staticetcl)

target_sources(
    staticetcl PRIVATE
    "${ETCL_SOURCES}"
)
target_include_directories(
    staticetcl PUBLIC
    "${ETCL_PUBLIC_INCLUDES}"
    PRIVATE
    "${ETCL_PRIVATE_INCLUDES}"
)


## Sample executable shell 

add_executable(etclshell)

target_link_libraries(
    etclshell PRIVATE
    etcl
)

target_sources(
    etclshell PRIVATE
    "${ETCLROOT}/src/shell.cpp"
)
