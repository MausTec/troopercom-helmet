cmake_minimum_required(VERSION 3.16.0)

if (NOT DEFINED ENV{ADF_PATH})
    set(ENV{ADF_PATH} ${CMAKE_SOURCE_DIR}/vendor/esp-adf)
endif()

execute_process(COMMAND git describe --always --tags --dirty
                OUTPUT_VARIABLE ADF_VER
                OUTPUT_STRIP_TRAILING_WHITESPACE)
add_definitions(-DADF_VER=\"${ADF_VER}\")

list(APPEND EXTRA_COMPONENT_DIRS $ENV{ADF_PATH}/components)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(troopercom-helmet)
