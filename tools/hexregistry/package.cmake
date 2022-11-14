# Inputs
#   target_name : for example package
#   (project_name): implicit
#   (project_version): implicit
#   (project_description): implicit
#   variant: how the fuck do i pass this?
#   authors: needs list, how do i expand it into json?
#   attachments: needs list, need to expand in json
#   artifacts: needs list of hex files

function(hexregistry_package)
    cmake_parse_arguments(
        ""
        ""
        "TARGET_NAME;"
        "VARIANT_ATTRIBUTES;AUTHORS;ATTACHMENTS;ARTIFACTS"
        ${ARGN}
    )

    # Load defaults
    if(NOT _TARGET_NAME)
        message(SEND_ERROR "Target must be set")
    endif()
    if(NOT _VARIANT_ATTRIBUTES)
        set(_VARIANT_ATTRIBUTES)
    endif()

    set(PACKAGE_STRING ${PROJECT_NAME}-${PROJECT_VERSION}-${PROJECT_VARIANT})
    set(HEX_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/package/${PACKAGE_STRING}.hex)
    set(PACKAGE_METAINFORMATION_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/package/${PACKAGE_STRING}.json)

    # Generates hexregistry package metainformation
    configure_file(
        ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/package.json.in
        ${PACKAGE_METAINFORMATION_OUTPUT}
        @ONLY
    )

    # Copies hex output into package
    add_custom_command(
        OUTPUT ${HEX_OUTPUT}
        DEPENDS ${hex_file}
        COMMAND ${CMAKE_COMMAND} -E copy ${hex_file} ${HEX_OUTPUT}
    )

    # Registers meta target for creating package
    add_custom_target(
        ${target_name}
        DEPENDS
            ${HEX_OUTPUT}
            ${PACKAGE_METAINFORMATION_OUTPUT}
    )
endfunction()