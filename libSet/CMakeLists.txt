cmake_minimum_required(VERSION 3.15)
project(Set
        VERSION         1.3.0
        DESCRIPTION     "Simple shared library for (ordered) sets and their functions"
        HOMEPAGE_URL    "https://github.com/thahnen/libSet"
        LANGUAGES       C)

set(CMAKE_C_STANDARD 11)

set(DEFAULT_BUILD_TYPE "Release")

include_directories(./include)

########################################################################################################################
#
#           SHARED LIBRARY
#
########################################################################################################################
add_library(${PROJECT_NAME}
        SHARED
            src/set.c include/ll.h include/type.h)

set_target_properties(${PROJECT_NAME}
        PROPERTIES
            VERSION ${PROJECT_VERSION}
            C_VISIBILITY_PRESET hidden
            PUBLIC_HEADER include/set.h)

target_include_directories(${PROJECT_NAME}
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
        PRIVATE
            ${PROJECT_SOURCE_DIR}/src)



########################################################################################################################
#           FIND LIBRARY AFTER BUILD PROCESS!
########################################################################################################################
find_library(Set REUQIRED)


########################################################################################################################
#
#           TEST LIBRARY
#
########################################################################################################################
add_executable(libSet_Test
        samples/Test.c)

target_link_libraries(libSet_Test
        Set)


########################################################################################################################
#
#           INSTALL LIBRARY TO FILESYSTEM
#
########################################################################################################################
install(TARGETS ${PROJECT_NAME}
        EXPORT
            libSetConfig
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY include/
        DESTINATION
            ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

install(EXPORT libSetConfig
        DESTINATION
            share/libSet/cmake)

export(TARGETS ${PROJECT_NAME}
        FILE
            libSetConfig.cmake)