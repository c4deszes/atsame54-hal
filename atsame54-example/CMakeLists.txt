project(atsame54-example DESCRIPTION "ATSAME54 Example program")
set(PROJECT_VERSION "1.0.0")
set(PROJECT_VARIANT "none")

# Generates runtime metainformation
set(GENERATED_METAINFORMATION_SOURCE ${CMAKE_CURRENT_BINARY_DIR}/config/metainformation.c)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config/metainformation.in
    ${GENERATED_METAINFORMATION_SOURCE}
    @ONLY)

# Example application
add_executable(
    atsame54-example EXCLUDE_FROM_ALL
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
    ${GENERATED_METAINFORMATION_SOURCE}
)
target_include_directories(atsame54-example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(atsame54-example PUBLIC atsame54-xplained atsame54-hal)

# Linker configuration
set(ATSAME54_EXAMPLE_LINKERSCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/ld/same54p20a_flash.ld)
set_target_properties(atsame54-example PROPERTIES SUFFIX ".elf")
set_target_properties(atsame54-example PROPERTIES LINK_DEPENDS ${ATSAME54_EXAMPLE_LINKERSCRIPT})
target_link_options(atsame54-example PUBLIC -T${ATSAME54_EXAMPLE_LINKERSCRIPT})
target_link_options(atsame54-example PUBLIC -Wl,-Map=${PROJECT_NAME}.map)
target_link_options(atsame54-example PUBLIC -Wl,--gc-sections)

# Creates binary output from ELF
add_custom_command(
    DEPENDS atsame54-example
    COMMAND ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "\tCreating binary output (.bin)"
)

# Creates hex output from ELF
add_custom_command(
    DEPENDS atsame54-example
    COMMAND ${CMAKE_OBJCOPY} -O ihex ${PROJECT_NAME}.elf -R .eeprom -R .fuse -R .lock -R .signature ${PROJECT_NAME}.hex
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.hex
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "\tCreating hex output (.hex)"
)

# Creates extended listing file from ELF
add_custom_command(
    DEPENDS atsame54-example
    COMMAND ${CMAKE_OBJDUMP} -h -S ${PROJECT_NAME}.elf > ${PROJECT_NAME}.lss
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.lss
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "\tCreating extended listing (.lss)"
)
