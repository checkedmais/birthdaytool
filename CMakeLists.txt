cmake_minimum_required(VERSION 3.0)

project(birthdaytool)

add_executable(birthdaytool main.cpp)

install(TARGETS birthdaytool RUNTIME DESTINATION bin)
