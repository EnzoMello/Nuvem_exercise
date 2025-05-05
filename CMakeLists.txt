# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(nuvem_exercise C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(nuvem_exercise nuvem_exercise.c 
                utils/button/Button.c
                utils/joystick/joystick.c
                utils/TMP36/tmp.c
                utils/WIFI/wifi.c
                utils/Server_connect/serverConnect.c
)

pico_set_program_name(nuvem_exercise "")
pico_set_program_version(nuvem_exercise "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(nuvem_exercise 0)
pico_enable_stdio_usb(nuvem_exercise 1)

# Add the standard library to the build
target_link_libraries(nuvem_exercise
        pico_stdlib
        hardware_adc
        hardware_uart
        pico_cyw43_arch_lwip_threadsafe_background)

# Add the standard include files to the build
target_include_directories(nuvem_exercise PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/utils/button
        ${CMAKE_CURRENT_LIST_DIR}/utils/joystick
        ${CMAKE_CURRENT_LIST_DIR}/utils/TMP36
        ${CMAKE_CURRENT_LIST_DIR}/utils/WIFI
        ${CMAKE_CURRENT_LIST_DIR}/utils/Server_connect
)

# Add any user requested libraries
target_link_libraries(nuvem_exercise 
        
        )

pico_add_extra_outputs(nuvem_exercise)

