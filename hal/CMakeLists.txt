file(GLOB_RECURSE HAL_HEADERS CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

file(GLOB_RECURSE HAL_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/*.s
)

add_library(${PROJECT_NAME}-hal OBJECT)

target_include_directories(${PROJECT_NAME}-hal
    SYSTEM PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Inc
        ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32L0xx_HAL_Driver/Inc
        ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32L0xx_HAL_Driver/Inc/Legacy
        ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Device/ST/STM32L0xx/Include
        ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Include
)

target_compile_definitions(${PROJECT_NAME}-hal
    PUBLIC
        USE_HAL_DRIVER
        STM32L053xx
)

target_sources(${PROJECT_NAME}-hal
    PUBLIC
        ${HAL_HEADERS}
    PRIVATE
        ${HAL_SOURCES}
)

