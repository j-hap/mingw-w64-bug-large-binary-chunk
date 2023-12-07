cmake_minimum_required(VERSION 3.5)

project(mingw-w64-bug-large-binary-chunk LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mingw-w64-bug-large-binary-chunk main.cpp)

include(GNUInstallDirs)
install(TARGETS mingw-w64-bug-large-binary-chunk
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
