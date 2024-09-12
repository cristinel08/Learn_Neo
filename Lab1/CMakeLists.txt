set(CMAKE_C_COMPILER "gcc")

set(CMAKE_C_FLAGS "-mcpu=Cortex-a57 -flax-vector-conversions ")

project(LAB1)

set(TARGET_NAME ${PROJECT_NAME})

add_executable(${TARGET_NAME} main.c)
