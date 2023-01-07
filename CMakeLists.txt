cmake_minimum_required(VERSION 3.21)
project(
        herd_common
        VERSION 0.1
        DESCRIPTION "Herd's common module"
        LANGUAGES CXX
)

## Common
add_library(herd_common INTERFACE)

# Warnings config
if(MSVC)
    target_compile_options(
            herd_common
            INTERFACE
            /W4
            /WX "/permissive-"
    )
else()
    target_compile_options(
            herd_common
            INTERFACE
            -Wall
            -Wextra
            -Wshadow
            -Wnon-virtual-dtor
            -Wold-style-cast
            -Wcast-align
            -Wdouble-promotion
            -Wunused
            -Woverloaded-virtual
            -Wpedantic
            -Wconversion
            -Wsign-conversion
            -Wnull-dereference
            -Werror
    )
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        target_compile_options(
                herd_common
                INTERFACE
                -Waddress-of-packed-member
                -Wmisleading-indentation
                -Wduplicated-cond
                -Wduplicated-branches
                -Wlogical-op
                -Wuseless-cast
        )
    endif()
endif()

# Project options config
target_compile_features(herd_common INTERFACE cxx_std_20)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    if(!MSVC)
        option(ENABLE_COVERAGE "Enable coverage reporting (gss/clang)" FALSE)

        if(ENABLE_COVERAGE)
            target_compile_options(herd_common INTERFACE --coverage -O0 -g)
            target_link_libraries(herd_common INTERFACE --coverage)
        endif()
    endif()
endif()

target_include_directories(herd_common INTERFACE include)

#target_sources(
#        herd_common
#        PRIVATE
#
#        include/herd_common/column_type.hpp
#        include/herd_common/schema_type.hpp
#)

