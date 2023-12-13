cmake_minimum_required(VERSION 3.26)
project(RepPlatform)

set(CMAKE_CXX_STANDARD 17)

add_executable(RepPlatform src/main.cpp
        src/classes/Guest.cpp
        src/classes/Guest.h
        src/classes/User.cpp
        src/classes/User.h
        src/classes/courses.cpp
        src/classes/courses.h
        src/classes/student.cpp
        src/classes/algorythm.cpp
        src/classes/algorythm.h
        src/classes/teacher.h
        src/classes/teacher.cpp
        src/classes/cards.cpp
        src/classes/cards.h
        src/classes/subcatalog.cpp
        src/classes/subcatalog.h
        src/classes/catalog.cpp
        src/classes/catalog.h
        src/classes/Exception.cpp
        "src/classes/Exception.h"
        src/classes/FileException.h
        src/classes/FileException.cpp
        src/classes/InputException.h
        src/classes/InputException.cpp
        #src/classes/teacher.cpp
        #src/classes/teacher.h
        #src/classes/student.cpp
        #src/classes/student.h
)
