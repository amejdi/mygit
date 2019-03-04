cmake_minimum_required(VERSION 3.2)

project(Calculator)
#set(BLA_VENDOR Intel10_64lp)
#find_package( BLAS REQUIRED )
#find_package( LAPACK REQUIRED )
add_executable(Calculator main.cpp MainWindow.h MainWindow.cpp)

set_target_properties(Calculator
    PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
)

find_package(Qt5Widgets)

target_link_libraries(Calculator Qt5::Widgets ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES})
