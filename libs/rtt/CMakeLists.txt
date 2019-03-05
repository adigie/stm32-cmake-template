add_library(rtt STATIC)

target_include_directories(rtt
    SYSTEM PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/segger-rtt/RTT
)

target_sources(rtt
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/segger-rtt/RTT/SEGGER_RTT.h
        ${CMAKE_CURRENT_SOURCE_DIR}/segger-rtt/RTT/SEGGER_RTT_Conf.h
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/segger-rtt/RTT/SEGGER_RTT.c
        ${CMAKE_CURRENT_SOURCE_DIR}/segger-rtt/RTT/SEGGER_RTT_printf.c
        ${CMAKE_CURRENT_SOURCE_DIR}/segger-rtt/Syscalls/SEGGER_RTT_Syscalls_GCC.c
)
