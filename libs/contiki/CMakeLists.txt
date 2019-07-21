add_library(contiki-conf INTERFACE)

target_include_directories(contiki-conf
    SYSTEM INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/conf
)

add_library(contiki STATIC)

target_include_directories(contiki
    SYSTEM PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/contiki/core
        ${CMAKE_CURRENT_SOURCE_DIR}/contiki/lib
)

file(GLOB_RECURSE CONTIKI_HEADERS CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/core/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.h
)

set(CONTIKI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/contiki/core/sys/arg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/contiki/core/sys/ctimer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/contiki/core/sys/etimer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/contiki/core/sys/process.c
    ${CMAKE_CURRENT_SOURCE_DIR}/contiki/core/sys/stimer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/contiki/core/sys/timer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/contiki/core/lib/list.c
)

target_sources(contiki
    PUBLIC
        ${CONTIKI_HEADERS}
    PRIVATE
        ${CONTIKI_SOURCES}
)

target_link_libraries(contiki
    PUBLIC
        contiki-conf
)
