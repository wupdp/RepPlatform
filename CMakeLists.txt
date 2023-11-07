cmake_minimum_required(VERSION 3.26)
project(RepPlatform)

set(CMAKE_CXX_STANDARD 17)

add_executable(RepPlatform src/main.cpp
        src/classes/Guest.cpp
        src/classes/Guest.h
        src/classes/User.cpp
        src/classes/User.h
        #src/classes/teacher.cpp
        #src/classes/teacher.h
        #src/classes/student.cpp
        #src/classes/student.h
)
