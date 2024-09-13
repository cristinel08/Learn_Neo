cmake_minimum_required(VERSION 3.21)
set(CMAKE_C_COMPILER "gcc")

set(CMAKE_C_FLAGS "-mcpu=Cortex-a57 -flax-vector-conversions ")

project(lab2)

set(TARGET_NAME ${PROJECT_NAME})

file(GLOB SRC_FILES
    src/*.c
    inc/*.h
)

set(INC_DIRECTORIES
    ${CMAKE_CURRENT_LIST_DIR}/inc
)


add_executable(${TARGET_NAME} ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE ${INC_DIRECTORIES})