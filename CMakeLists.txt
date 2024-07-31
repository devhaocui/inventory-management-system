cmake_minimum_required(VERSION 3.29.5)
project(inv)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

# add invManage source files
set(MAIN_SOURCES
main.cpp
inventoryManagement.cpp
inventoryManagement.h)

# add bcrypt source files
set(BCRYPT_DIR ${CMAKE_SOURCE_DIR}/lib/bcrypt)
set(BCRYPT_SOURCES
${BCRYPT_DIR}/bcrypt.cpp
${BCRYPT_DIR}/blowfish.cpp
)

# add dear imgui source files
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/lib/imgui)
set(IMGUI_SOURCES
  ${IMGUI_DIR}/imgui.cpp
  ${IMGUI_DIR}/imgui_demo.cpp
  ${IMGUI_DIR}/imgui_draw.cpp
  ${IMGUI_DIR}/imgui_tables.cpp
  ${IMGUI_DIR}/imgui_widgets.cpp
  ${IMGUI_DIR}/imgui_impl_glfw.cpp
  ${IMGUI_DIR}/imgui_impl_opengl3.cpp
)

# add sqlite3 source files
set(SQLITE3_DIR ${CMAKE_SOURCE_DIR}/lib/sqlite3)
set(SQLITE3_SOURCES
  ${SQLITE3_DIR}/sqlite3.c
)

include_directories(${BCRYPT_DIR})
include_directories(${IMGUI_DIR})
include_directories(${SQLITE3_DIR})

add_executable(
  ${PROJECT_NAME}
  ${MAIN_SOURCES}
  ${BCRYPT_SOURCES}
  ${IMGUI_SOURCES}
  ${SQLITE3_SOURCES}
)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.4 REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL)
