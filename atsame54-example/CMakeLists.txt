project(atsame54-example DESCRIPTION "ATSAME54 Example program")
set(PROJECT_VERSION "1.0.0")

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
set(ATSAME54_EXAMPLE_LINKERSCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/lib/same54p20a_flash.ld)
set_target_properties(atsame54-example PROPERTIES SUFFIX ".elf")
set_target_properties(atsame54-example PROPERTIES LINK_DEPENDS ${ATSAME54_EXAMPLE_LINKERSCRIPT})
target_link_options(atsame54-example PUBLIC -T${ATSAME54_EXAMPLE_LINKERSCRIPT})
target_link_options(atsame54-example PUBLIC -Wl,-Map=atsame54-example.map)
target_link_options(atsame54-example PUBLIC -Wl,--gc-sections)

# Creates binary output from ELF
add_custom_command(
    TARGET atsame54-example POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary atsame54-example.elf atsame54-example.bin
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "\tCreating binary output (.bin)"
)

# Creates hex output from ELF
add_custom_command(
    TARGET atsame54-example POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex atsame54-example.elf -R .eeprom -R .fuse -R .lock -R .signature atsame54-example.hex
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "\tCreating hex output (.hex)"
)

# Creates extended listing file from ELF
add_custom_command(
    TARGET atsame54-example POST_BUILD
    COMMAND ${CMAKE_OBJDUMP} -h -S atsame54-example.elf > atsame54-example.lss
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "\tCreating extended listing (.lss)"
)
