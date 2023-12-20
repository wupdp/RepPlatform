cmake_minimum_required(VERSION 3.26)
project(RepPlatform)

set(CMAKE_CXX_STANDARD 17)

add_executable(RepPlatform src/main.cpp
        src/classes/user_module/guest.cpp
        include/guest.h
        src/classes/user_module/user.cpp
        include/user.h
        src/classes/catalog_module/courses.cpp
        include/courses.h
        src/classes/user_module/student.cpp
        src/classes/algorythm.cpp
        include/algorythm.h
        include/teacher.h
        src/classes/user_module/teacher.cpp
        src/classes/user_module/cards.cpp
        include/cards.h
        src/classes/catalog_module/subcatalog.cpp
        include/subcatalog.h
        src/classes/catalog_module/catalog.cpp
        include/catalog.h
        src/classes/exception_module/Exception.cpp
        "include/Exception.h"
        include/FileException.h
        src/classes/exception_module/FileException.cpp
        include/InputException.h
        src/classes/exception_module/InputException.cpp
        include/interface.h
        src/classes/interface.cpp
        include/stack.h
        src/classes/stack.inl
        #src/classes/teacher.cpp
        #src/classes/teacher.h
        #src/classes/student.cpp
        #src/classes/student.h
)
