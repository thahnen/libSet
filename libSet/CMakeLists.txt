cmake_minimum_required(VERSION 3.15)
project(Set
        VERSION         1.6.1
        DESCRIPTION     "Simple shared library for (ordered) sets and their functions"
        HOMEPAGE_URL    "https://github.com/thahnen/libSet"
        LANGUAGES       C)

set(CMAKE_C_STANDARD 11)
set(DEFAULT_BUILD_TYPE "Release")

include_directories(./include)


####################################################################################################
#
#           SHARED LIBRARY
#
####################################################################################################
add_library(${PROJECT_NAME}
        SHARED
            include/ll.h
            include/type.h
            include/set.h
            src/set.c)

set_target_properties(${PROJECT_NAME}
        PROPERTIES
            VERSION ${PROJECT_VERSION}
            C_VISIBILITY_PRESET hidden
            PUBLIC_HEADER include/set.h)
            
target_include_directories(${PROJECT_NAME}
        PUBLIC
            ${PROJECT_SOURCE_DIR/include})


####################################################################################################
#           FIND LIBRARY AFTER BUILD PROCESS!
####################################################################################################
find_library(Set REUQIRED)


####################################################################################################
#
#           TEST LIBRARY
#
####################################################################################################
add_executable(libSet_Unittest
        tests/Unittests.h
        tests/Unittests.c
        tests/test_set_empty.c
        tests/test_set_create.c)

target_include_directories(libSet_Unittest PUBLIC "/usr/local/Cellar/check/0.15.2/include")
target_link_libraries(libSet_Unittest Set "/usr/local/Cellar/check/0.15.2/lib/libcheck.dylib")


####################################################################################################
#
#           INSTALL LIBRARY TO FILESYSTEM
#
####################################################################################################
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES include/set.h DESTINATION include)
