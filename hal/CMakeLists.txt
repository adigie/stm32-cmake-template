file(GLOB_RECURSE HAL_HEADERS CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

file(GLOB_RECURSE HAL_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/*.s
)

add_library(hal OBJECT)

target_include_directories(hal
    SYSTEM PUBLIC
        #${CMAKE_CURRENT_SOURCE_DIR}/...
)

target_compile_definitions(hal
    PUBLIC
        USE_HAL_DRIVER
        #STM32...
)

target_sources(hal
    PUBLIC
        ${HAL_HEADERS}
    PRIVATE
        ${HAL_SOURCES}
)

target_link_options(hal
    PUBLIC
        #-T ${CMAKE_CURRENT_SOURCE_DIR}/linker_script.ld
)
