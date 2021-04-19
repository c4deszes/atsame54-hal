add_executable(
    atsame54-example
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
)
target_include_directories(atsame54-example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(atsame54-example PUBLIC atsame54-xplained)
set_target_properties(atsame54-example PROPERTIES SUFFIX ".elf")
target_link_options(atsame54-example PUBLIC -T${CMAKE_CURRENT_SOURCE_DIR}/lib/same54p20a_flash.ld)
target_link_options(atsame54-example PUBLIC -Wl,-Map=App.map)
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
