cmake_minimum_required(VERSION 3.5)

project(QFileTagger VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS "${PROJECT_SOURCE_DIR}/assets/ui/")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql)

file(GLOB SRC src/*)
file(GLOB QRC assets/*.qrc)
file(GLOB  UI assets/ui/*)

qt_add_executable(qfiletagger ${SRC} ${QRC} ${UI})

target_link_libraries(qfiletagger PUBLIC
    Qt6::Gui
    Qt6::Widgets
    Qt6::Core
    Qt6::Sql
)
