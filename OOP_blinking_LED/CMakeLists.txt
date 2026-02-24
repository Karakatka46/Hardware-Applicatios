cmake_minimum_required(VERSION 3.15)

project(stm32_baremetal C CXX ASM)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m3)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

set(CPU_FLAGS "-mcpu=cortex-m3 -mthumb")

set(CMAKE_C_FLAGS "${CPU_FLAGS} -ffreestanding -Wall -O0")
set(CMAKE_CXX_FLAGS "${CPU_FLAGS} -ffreestanding -Wall -O0 -fno-exceptions -fno-rtti")

set(CMAKE_EXE_LINKER_FLAGS
    "${CPU_FLAGS} -T${CMAKE_SOURCE_DIR}/linker.ld -nostartfiles -Wl,--gc-sections"
)

add_executable(${PROJECT_NAME}
    startup.s
    src/main.cpp
    src/system.cpp
)

target_link_libraries(${PROJECT_NAME}
    -lc
    -lm
    -lnosys
)
