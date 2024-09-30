cmake_minimum_required(VERSION 3.16)

project(S_Pointer LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(S_Pointer
  main.cpp
  ptrclsss.h ptrclsss.cpp
)
target_link_libraries(S_Pointer Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS S_Pointer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
