idf_component_register(
    SRC_DIRS
        src
        tasks
    PRIV_REQUIRES
        driver
        spi_flash
        usb
    INCLUDE_DIRS
        inc/tinyusb
        inc
        .
)

target_compile_options(${COMPONENT_LIB} PRIVATE -std=gnu23)

# Determine whether tinyusb is fetched from component registry or from local path
idf_build_get_property(build_components BUILD_COMPONENTS)
if(tinyusb IN_LIST build_components)
    set(tinyusb_name tinyusb) # Local component
else()
    set(tinyusb_name espressif__tinyusb) # Managed component
endif()

# Pass tusb_config.h from this component to TinyUSB
idf_component_get_property(tusb_lib ${tinyusb_name} COMPONENT_LIB)
target_include_directories(${tusb_lib} PRIVATE inc/tinyusb)

# Libraries
add_subdirectory(lib/utf8-utf16-converter)
target_link_libraries(${COMPONENT_LIB} PRIVATE utf8-utf16-converter)
