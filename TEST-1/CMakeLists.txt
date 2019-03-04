cmake_minimum_required(VERSION 3.2)

project(test)

add_executable(test main.cpp MainWindow.h MainWindow.cpp)

set_target_properties(test
    PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
)

find_package(Qt5Widgets)

target_link_libraries(test Qt5::Widgets)
