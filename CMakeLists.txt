# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
cmake_minimum_required(VERSION 3.13)

#option(ADD_HPGL "Add HPGL plugin" OFF)
# Note: WiFi and Ethernet cannot be enabled at the same time!
#option(ADD_BLUETOOTH "Add Bluetooth" OFF)
#option(AddMyPlugin "Add my_plugin.c to build" OFF)

# Select the correct board in VSCode, the following line will be updated accordingly
#set(PICO_BOARD pico CACHE STRING "Board type")

include(pico_sdk_import.cmake)

include(grbl/CMakeLists.txt)
#include(fatfs/CMakeLists.txt)
#include(spindle/CMakeLists.txt)
#include(sdcard/CMakeLists.txt)
#include(keypad/CMakeLists.txt)
#include(eeprom/CMakeLists.txt)
#include(bluetooth/CMakeLists.txt)
#include(laser/CMakeLists.txt)
#include(plugins/CMakeLists.txt)

project(grblHAL)
pico_sdk_init()

add_executable(grblHAL
        main.c
        driver.c
        serial.c
        usb_serial.c
        stdio_usb_descriptors.c
        flash.c
        #    i2c.c
        #    spi.c
        #    PCA9654E.c
        ioports.c
        ioports_analog.c
        #    tmc_uart.c
        #    MCP3221.c
        boards/pico_cnc.c
        boards/btt_skr_pico_10.c
        #    littlefs/lfs.c
        #    littlefs/lfs_util.c
        #    littlefs_hal.c
)

pico_generate_pio_header(grblHAL ${CMAKE_CURRENT_LIST_DIR}/driverPIO.pio)

target_compile_definitions(grblHAL PUBLIC RP_MCU=2040)
target_compile_definitions(grblHAL PUBLIC RP2040)
#target_compile_definitions(grblHAL PUBLIC NEW_FATFS)
#target_compile_definitions(grblHAL PUBLIC LITTLEFS_ENABLE=1)

#
#if(ADD_BLUETOOTH)
#    target_compile_definitions(grblHAL PUBLIC BLUETOOTH_ENABLE=1)
#    target_compile_definitions(grblHAL PUBLIC NDEBUG)
#    target_sources(grblHAL PRIVATE
#     bt_native.c
#    )
#    target_include_directories(grblHAL PRIVATE ${PICO_SDK_PATH}/lib/btstack/src)
#    target_link_libraries(grblHAL PRIVATE
#     pico_btstack_classic
#     pico_btstack_ble
#     pico_btstack_cyw43
#    )
#    if(NOT ADD_WIFI)
#        target_compile_definitions(grblHAL PUBLIC CYW43_LWIP=0)
#        target_link_libraries(grblHAL PRIVATE
#         pico_cyw43_arch_poll
#        )
#    endif()
#endif()

target_include_directories(grblHAL PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_compile_definitions(grblHAL PUBLIC RP_MCU=2040)
target_link_libraries(grblHAL PRIVATE
        hardware_rtc
)

target_link_libraries(grblHAL PRIVATE
        grbl
        # fatfs
        # sdcard
        # motors
        # trinamic
        # spindle
        # keypad
        # fans
        # laser
        # bluetooth
        # eeprom
        # misc_plugins
        # embroidery
        tinyusb_device_unmarked
        pico_stdlib
        pico_unique_id
        hardware_dma
        hardware_uart
        hardware_pio
        # hardware_i2c
        # hardware_spi
        hardware_gpio
        hardware_pwm
        hardware_clocks
        hardware_flash
)

pico_add_extra_outputs(grblHAL)

#unset(PICO_BOARD CACHE)
#unset(ADD_BLUETOOTH CACHE)
# After the build target (grblHAL) is created, run the script
add_custom_command(TARGET grblHAL POST_BUILD
        COMMAND /home/anadi/Programs/pico/RP2040/uf2Copier.sh
        COMMENT "Running post-build script"
)