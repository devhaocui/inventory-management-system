cmake_minimum_required(VERSION 3.29.5)
project(inv)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)

# add invManage source files
set(MAIN_SOURCES
main.cpp
inventoryManagement.cpp
inventoryManagement.h)

# add bcrypt source fil
set(BCRYPT_DIR ${CMAKE_SOURCE_DIR}/lib/bcrypt)
set(BCRYPT_SOURCES
${BCRYPT_DIR}/bcrypt.cpp
${BCRYPT_DIR}/blowfish.cpp
#${BCRYPT_DIR}/bcrypt.h
#${BCRYPT_DIR}/node_blf.h
#${BCRYPT_DIR}/openbsd.h
)

include_directories(${BCRYPT_DIR})

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
  #${IMGUI_DIR}/imgui_impl_glfw.h
  #${IMGUI_DIR}/imgui_impl_opengl3_loader.h
  #${IMGUI_DIR}/imgui_impl_opengl3.h
  #${IMGUI_DIR}/imgui_internal.h
  #${IMGUI_DIR}/imgui.h
  #${IMGUI_DIR}/imgui.ini
  #${IMGUI_DIR}/imstb_rectpack.h
  #${IMGUI_DIR}/imstb_textedit.h
  #${IMGUI_DIR}/imstb_truetype.h
)

include_directories(${IMGUI_DIR})
add_executable(${PROJECT_NAME}
${MAIN_SOURCES}
${BCRYPT_SOURCES}
${IMGUI_SOURCES}
)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.4 REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL)
