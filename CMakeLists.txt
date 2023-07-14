cmake_minimum_required(VERSION 3.21)
project(
        herd_common
        VERSION 0.1
        DESCRIPTION "Herd's common module"
        LANGUAGES CXX
)

## UUID
pkg_search_module(UUID REQUIRED uuid)

## Common
add_library(herd_common)
target_compile_features(herd_common INTERFACE cxx_std_20)

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
target_compile_features(herd_common PRIVATE cxx_std_20)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    if(!MSVC)
        option(ENABLE_COVERAGE "Enable coverage reporting (gss/clang)" FALSE)

        if(ENABLE_COVERAGE)
            target_compile_options(herd_common INTERFACE --coverage -O0 -g)
            target_link_libraries(herd_common INTERFACE --coverage)
        endif()
    endif()
endif()

target_link_libraries(herd_common
        PRIVATE
        ${UUID_LIBRARIES}
)

target_include_directories(herd_common PUBLIC include)
target_include_directories(herd_common PRIVATE include)

target_sources(
        herd_common
        PRIVATE
        src/uuid.cpp
        src/native_type_mapping.cpp

        include/herd/common/uuid.hpp
        include/herd/common/dag.hpp
        include/herd/common/native_type_mapping.hpp

        include/herd/common/model/exception.hpp

        include/herd/common/model/column_meta.hpp
        include/herd/common/model/column_descriptor.hpp
        include/herd/common/model/data_type.hpp
        include/herd/common/model/job.hpp
        include/herd/common/model/schema_type.hpp

        include/herd/common/model/worker/task.hpp
        include/herd/common/model/worker/data_frame_ptr.hpp
        include/herd/common/model/worker/crypto_key_ptr.hpp

        include/herd/common/model/executor/execution_plan.hpp
        include/herd/common/model/executor/stage.hpp

        include/herd/common/model/circuit/circuit.hpp
        include/herd/common/model/circuit/nodes.hpp
        include/herd/common/model/circuit/operation.hpp

)

