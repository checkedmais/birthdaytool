cmake_minimum_required(VERSION 3.0)

project(birthdaytool)

file(GLOB SOURCES "*.cpp")

add_executable(birthdaytool ${SOURCES})

install(TARGETS birthdaytool RUNTIME DESTINATION bin)
