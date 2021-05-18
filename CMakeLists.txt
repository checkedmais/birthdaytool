cmake_minimum_required(VERSION 3.0)

project(birthdaytool)

file(GLOB SOURCES "*.cpp")

add_executable(bdaytool ${SOURCES})

install(TARGETS bdaytool DESTINATION bin)
