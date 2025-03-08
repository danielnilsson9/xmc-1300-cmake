cmake_minimum_required(VERSION 3.0)

project(xmc-1300 C ASM)

set(LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/ld/XMC1300x0064.ld")

add_compile_definitions(XMC1302_T038x0064)

add_subdirectory(lib/xmc-1)

add_executable(xmc-1300
    src/startup/startup_XMC1300.S
    src/startup/system_XMC1300.c
    src/main.c
)

target_link_options(xmc-1300 PRIVATE "-T${LINKER_SCRIPT}")

target_link_libraries(xmc-1300 PUBLIC XMCNewlib XMCLib)
