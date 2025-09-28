cmake_minimum_required(VERSION 3.14)
project(ChatServerGUI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SOURCES
    main.cpp
    MainWindow.cpp
    MainWindow.h
    MainWindow.ui
)

add_executable(ChatServerGUI ${SOURCES})

target_link_libraries(ChatServerGUI Qt5::Widgets)