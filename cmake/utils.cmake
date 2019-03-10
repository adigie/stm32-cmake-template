macro(utils_target_generate_hex TARGET_NAME)
    add_custom_target(hex
        ALL
        DEPENDS
            ${TARGET_NAME}
        COMMAND
            ${CMAKE_OBJCOPY} -O ihex
                $<TARGET_FILE:${TARGET_NAME}>
                ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}.hex
    )
endmacro()

macro(utils_target_generate_bin TARGET_NAME)
    add_custom_target(bin
        ALL
        DEPENDS
            ${TARGET_NAME}
        COMMAND
            ${CMAKE_OBJCOPY} -O binary
                $<TARGET_FILE:${TARGET_NAME}>
                ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}.bin
    )
endmacro()

macro(utils_target_print_size TARGET_NAME)
    add_custom_command(TARGET ${TARGET_NAME}
        POST_BUILD
            COMMAND
                ${CMAKE_SIZE_UTIL} --format=sysv --radix=16 $<TARGET_FILE:${TARGET_NAME}>
    )
endmacro()

