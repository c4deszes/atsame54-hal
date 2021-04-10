add_executable(
    App
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
)
target_include_directories(App PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(App LINK_PUBLIC XplainedBoard)
set_target_properties(App PROPERTIES SUFFIX ".elf")
target_link_options(App PUBLIC -T${CMAKE_CURRENT_SOURCE_DIR}/lib/same54p20a_flash.ld)
target_link_options(App PUBLIC -Wl,-Map=App.map)
target_link_options(App PUBLIC -Wl,--gc-sections)

# Creates binary output from ELF
add_custom_command(
    TARGET App POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary App.elf App.bin
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "\tCreating binary output (.bin)"
)

# Creates hex output from ELF
add_custom_command(
    TARGET App POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex App.elf -R .eeprom -R .fuse -R .lock -R .signature App.hex
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "\tCreating hex output (.hex)"
)

# Creates extended listing file from ELF
add_custom_command(
    TARGET App POST_BUILD
    COMMAND ${CMAKE_OBJDUMP} -h -S App.elf > App.lss
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "\tCreating extended listing (.lss)"
)
