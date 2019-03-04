cmake_minimum_required(VERSION 3.2)

project(Calculator)

add_executable(Calculator main.cpp MainWindow.h MainWindow.cpp)

set_target_properties(Calculator
    PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
)

find_package(Qt5Widgets)

target_link_libraries(Calculator Qt5::Widgets)
