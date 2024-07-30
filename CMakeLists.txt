# Main CMakeList.txt
cmake_minimum_required(VERSION 3.12)

# set language and the project name
project(template_prj CXX)

# generate version
execute_process(COMMAND git describe --tags WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" OUTPUT_VARIABLE VERSION ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE)
message(STATUS "Version build: " ${VERSION})
configure_file("version.h.in" "${PROJECT_BINARY_DIR}/version.h")
include_directories(${PROJECT_BINARY_DIR})

# CXX standart
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)

# Set compilers options
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        message(STATUS "Compiler - Microsoft Visual Studio (microsoft.com)")
        set(CXX_FLAGS_COMPILER "/W4 /Wall /WX")
        set(CXX_FLAGS_LINKER "")
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        message(STATUS "Compiler - GNU Compiler Collection (gcc.gnu.org)")
        set(CXX_FLAGS_COMPILER "-Wall -Werror -pedantic")
        set(CXX_FLAGS_LINKER ${CXX_FLAGS_COMPILER})
    endif()

    set(CXXFLAGS ${CXX_FLAGS_COMPILER})
    set(CMAKE_EXE_LINKER_FLAGS_INIT ${CXX_FLAGS_LINKER})
endif()

# generate documetation
if(GENERATE_DOC)
    find_package(Doxygen)

    if(DOXYGEN_FOUND)
        message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
        message(STATUS "Doxygen ${DOXYGEN_VERSION} found - Reference manual will be created")

        set(DOXYGEN_PROJECT_NAME ${CMAKE_PROJECT_NAME})
        set(DOXYGEN_INPUT "${PROJECT_SOURCE_DIR}")
        set(DOXYGEN_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/doc")
        configure_file("Doxyfile.in" "${PROJECT_BINARY_DIR}/Doxyfile")

        # doxygen_add_docs(doxygen ${PROJECT_SOURCE_DIR} COMMENT "Generate doc")
        add_custom_target(doc_dox ALL Doxygen::doxygen ${PROJECT_SOURCE_DIR}/build/Doxyfile)
    else(DOXYGEN_FOUND)
        message(STATUS "WARNING: Doxygen not found - Reference manual will not be created")
    endif(DOXYGEN_FOUND)
endif()

include_directories(${Boost_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR})

# include subprojects
add_subdirectory(app)
add_subdirectory(src)

# tests
enable_testing()
add_subdirectory(tests)

# cpack
include(CPack)
set(CPACK_PACKAGE_NAME ${CMAKE_PROJECT_NAME})
set(CPACK_SET_DESTDIR ON)
set(CPACK_PACKAGE_VERSION "${VERSION}")
set(CPACK_PACKAGE_DESCRIPTION "The Truth Table Generator")
