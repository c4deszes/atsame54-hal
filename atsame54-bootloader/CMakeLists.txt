project(atsame54-bootloader DESCRIPTION "ATSAME54 Example Bootloader")
set(PROJECT_VERSION "0.1.0")
set(PROJECT_VARIANT "none")

add_executable(
    ${PROJECT_NAME} EXCLUDE_FROM_ALL
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
)
target_link_libraries(${PROJECT_NAME} PRIVATE atsame54-hal)

set(ATSAME54_BOOTLOADER_LINKERSCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/ld/bootloader.ld)
set(GENERATED_BOOTLOADER_LINKERSCRIPT ${CMAKE_CURRENT_BINARY_DIR}/bootloader.ld)
# get_target_property(INCLUDES ${PROJECT_NAME} INCLUDE_DIRECTORIES)
add_custom_target(
    atsame54-bootloader-preprocess-linker
    DEPENDS ${ATSAME54_BOOTLOADER_LINKERSCRIPT}
    COMMAND ${CMAKE_C_COMPILER}
        -E -dM -x c ${ATSAME54_BOOTLOADER_LINKERSCRIPT}
        -o ${GENERATED_BOOTLOADER_LINKERSCRIPT}
)

# Linker configuration
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".elf")
#set_target_properties(${PROJECT_NAME} PROPERTIES LINK_DEPENDS ${GENERATED_BOOTLOADER_LINKERSCRIPT})
#target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_dependencies(
    ${PROJECT_NAME} atsame54-bootloader-preprocess-linker
)
target_link_options(${PROJECT_NAME} PRIVATE -T${GENERATED_BOOTLOADER_LINKERSCRIPT})
target_link_options(${PROJECT_NAME} PRIVATE -Wl,-Map=${PROJECT_NAME}.map)
target_link_options(${PROJECT_NAME} PRIVATE -Wl,--gc-sections)

# Creates hex output from ELF
add_custom_command(
    DEPENDS ${PROJECT_NAME}
    COMMAND ${CMAKE_OBJCOPY} -O ihex ${PROJECT_NAME}.elf -R .eeprom -R .fuse -R .lock -R .signature ${PROJECT_NAME}.hex
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.hex
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "\tCreating hex output (.hex)"
)

# Creates extended listing file from ELF
add_custom_command(
    DEPENDS ${PROJECT_NAME}
    COMMAND ${CMAKE_OBJDUMP} -h -S ${PROJECT_NAME}.elf > ${PROJECT_NAME}.lss
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.lss
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "\tCreating extended listing (.lss)"
)
