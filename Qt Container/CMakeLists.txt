cmake_minimum_required(VERSION 3.16)

project(Collections LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Collections
  main.cpp
  list.h list.cpp
  vector.h vector.cpp
  set.h set.cpp
)
target_link_libraries(Collections Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS Collections
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
