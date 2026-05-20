# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0-a4)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)
project(Pico_ePaper_73)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target/runtime)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target/library)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target/archive)

pico_sdk_init()

# add a compilation subdirectory
add_subdirectory(lib/Config)
add_subdirectory(lib/e-Paper)
add_subdirectory(lib/RTC)
add_subdirectory(lib/Fonts)
add_subdirectory(lib/GUI)
add_subdirectory(lib/led)
add_subdirectory(examples)
add_subdirectory(lib/FatFs_SPI build)

# add a header directory
include_directories(examples)
include_directories(./lib/Config)
include_directories(./lib/GUI)
include_directories(./lib/RTC)
include_directories(./lib/led)

# generate an executable file
add_executable(acep_enhanced
main.c
)

# enable usb output, disable uart output
pico_enable_stdio_usb(acep_enhanced 1)
pico_enable_stdio_uart(acep_enhanced 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(acep_enhanced)

target_link_libraries(acep_enhanced examples ePaper GUI led Fonts Config RTC FatFs_SPI)