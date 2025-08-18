cmake_minimum_required(VERSION 4.0)
project(WCleaner C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(WCleaner
        src/cleaner.h
        src/logger.h
        src/main.c)
