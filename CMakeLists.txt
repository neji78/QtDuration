cmake_minimum_required(VERSION 3.14)
project(QtDuration LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Qml)

enable_testing()

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Install path" FORCE)
endif()

add_library(QtDuration SHARED
    src/qduration.cpp
    include/QDuration/qduration.h
    include/QDuration/qduration_global.h
)

target_compile_definitions(QtDuration PRIVATE QDURATION_LIBRARY)
target_link_libraries(QtDuration PRIVATE Qt6::Core Qt6::Qml)

target_include_directories(QtDuration PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS QtDuration
    EXPORT QtDurationTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/qduration.h
    ${CMAKE_CURRENT_SOURCE_DIR}/QDuration
    DESTINATION include/QtDuration
)

add_subdirectory(examples)
add_subdirectory(tests)
