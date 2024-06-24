add_library(libBcrypt bcrypt.cpp blowfish.cpp)
target_include_directories(libBcrypt INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
