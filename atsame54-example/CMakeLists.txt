project(atsame54-example DESCRIPTION "ATSAME54 Example program")
set(PROJECT_VERSION "1.0.0")
set(PROJECT_VARIANT "none")

# Generates runtime metainformation
set(GENERATED_METAINFORMATION_SOURCE ${CMAKE_CURRENT_BINARY_DIR}/config/metainformation.c)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config/metainformation.in
    ${GENERATED_METAINFORMATION_SOURCE}
    @ONLY)

set(
    SOURCES
    src/main.c
    ${GENERATED_METAINFORMATION_SOURCE}
)

# Example application
add_executable(
    atsame54-example EXCLUDE_FROM_ALL
    ${SOURCES}
)
target_include_directories(atsame54-example PRIVATE include)
target_link_libraries(atsame54-example PRIVATE atsame54-xplained atsame54-hal)

# Linker configuration
set(ATSAME54_EXAMPLE_LINKERSCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/ld/same54p20a_flash.ld)
set_target_properties(atsame54-example PROPERTIES SUFFIX ".elf")
set_target_properties(atsame54-example PROPERTIES LINK_DEPENDS ${ATSAME54_EXAMPLE_LINKERSCRIPT})
target_link_options(atsame54-example PRIVATE -T${ATSAME54_EXAMPLE_LINKERSCRIPT})
target_link_options(atsame54-example PRIVATE -Wl,-Map=${PROJECT_NAME}.map
                                             -Wl,--gc-sections
                                             #-Wl,-flto
                                             )

# Creates binary output from ELF
add_custom_command(
    DEPENDS atsame54-example
    COMMAND ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
    OUTPUT ${PROJECT_NAME}.bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "\tCreating binary output (.bin)"
)

# Creates hex output from ELF
add_custom_command(
    DEPENDS atsame54-example
    COMMAND ${CMAKE_OBJCOPY} -O ihex ${PROJECT_NAME}.elf -R .eeprom -R .fuse -R .lock -R .signature ${PROJECT_NAME}.hex
    OUTPUT ${PROJECT_NAME}.hex
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "\tCreating hex output (.hex)"
)

# Creates extended listing file from ELF
add_custom_command(
    DEPENDS atsame54-example
    COMMAND ${CMAKE_OBJDUMP} -h -S ${PROJECT_NAME}.elf > ${PROJECT_NAME}.lss
    OUTPUT ${PROJECT_NAME}.lss
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "\tCreating extended listing (.lss)"
)

# Prints size information of the ELF
add_custom_command(
    DEPENDS atsame54-example
    COMMAND ${CMAKE_OBJSIZE} ${PROJECT_NAME}.elf
    OUTPUT ${PROJECT_NAME}-memory
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "\tCreating memory usage report"
)

add_custom_target(
    atsame54-example-extras
    DEPENDS
        ${PROJECT_NAME}-memory
        ${PROJECT_NAME}.hex
        ${PROJECT_NAME}.bin
        ${PROJECT_NAME}.lss
)

add_library(
    atsame54-example-test EXCLUDE_FROM_ALL
    ${SOURCES}
)
target_link_libraries(atsame54-example-test PUBLIC atsame54-xplained-test atsame54-hal-fake)
target_include_directories(atsame54-example-test PUBLIC include)

#add_subdirectory(test/inttest)
#add_subdirectory(test/unittest)
