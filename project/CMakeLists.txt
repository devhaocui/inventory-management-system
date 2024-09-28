cmake_minimum_required(VERSION 3.29.5)
project(inv)
set(CMAKE_OSX_DEPLOYMENT_TARGET "11.0")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS OFF) #disable dynamic library

# Add invManage source files
set(MAIN_SOURCES
  main.cpp
  inventoryManagement.cpp
  inventoryManagement.h
)

# Add bcrypt source files
set(BCRYPT_DIR ${CMAKE_SOURCE_DIR}/lib/bcrypt)
set(BCRYPT_SOURCES
  ${BCRYPT_DIR}/bcrypt.cpp
  ${BCRYPT_DIR}/blowfish.cpp
)

# Add dear imgui source files
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

# Add sqlite3 source files
set(SQLITE3_DIR ${CMAKE_SOURCE_DIR}/lib/sqlite3)
set(SQLITE3_SOURCES
  ${SQLITE3_DIR}/sqlite3.c
)

# Add sqlite3pp source files
set(SQLITE3PP_DIR ${CMAKE_SOURCE_DIR}/lib/sqlite3pp/headeronly_src)
set(SQLITE3PP_SOURCES
)

# copy data files for the bundle app to be read from
file(COPY ${CMAKE_SOURCE_DIR}/data/item.csv
${CMAKE_SOURCE_DIR}/data/user.csv
${CMAKE_SOURCE_DIR}/data/jetbrains.ttf
DESTINATION ${CMAKE_SOURCE_DIR}/build/inv.app/Contents/Resources/data
)

include_directories(${BCRYPT_DIR})
include_directories(${IMGUI_DIR})
include_directories(${SQLITE3_DIR})
include_directories(${SQLITE3PP_DIR})

add_executable(
  ${PROJECT_NAME}
  ${MAIN_SOURCES}
  ${BCRYPT_SOURCES}
  ${IMGUI_SOURCES}
  ${SQLITE3_SOURCES}
  ${SQLITE3PP_SOURCES}
)

# used add_subdirectory for glfw because glfw is not a system library
# while OpenGL is part of the system library in many Operating Systems already
# note: the CMakeLists.txt inside of lib/glfw for some reason also has code
# inside that makes a copy of lib/glfw to the /build directory.
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/glfw)
# removed find_package for glfw because it is already part of the sub_directory
#find_package(glfw3 3.4 REQUIRED STATIC)
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME}
  glfw
  OpenGL::GL)

set_target_properties(${PROJECT_NAME} PROPERTIES
  MACOSX_BUNDLE TRUE)
