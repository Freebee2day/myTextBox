cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME renamehere)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp cmake_modules/Typing.cpp cmake_modules/Typing.h cmake_modules/SpecicalChar.cpp cmake_modules/SpecicalChar.h cmake_modules/Letter.cpp cmake_modules/Letter.h cmake_modules/LetterLower.cpp cmake_modules/LetterLower.h cmake_modules/Number.cpp cmake_modules/Number.h cmake_modules/Keyword.cpp cmake_modules/Keyword.h cmake_modules/myBase.cpp cmake_modules/myBase.h cmake_modules/Slider.cpp cmake_modules/Slider.h cmake_modules/Menu.cpp cmake_modules/Menu.h cmake_modules/MenuItem.cpp cmake_modules/MenuItem.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()