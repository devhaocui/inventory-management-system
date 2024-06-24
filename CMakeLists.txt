cmake_minimum_required(VERSION 3.29.5)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

project(inventory)
add_executable(${PROJECT_NAME} main.cpp inventoryManagement.cpp)

target_link_libraries(${PROJECT_NAME} libBcrypt)
add_subdirectory(lib/bcrypt)
