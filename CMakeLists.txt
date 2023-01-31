cmake_minimum_required(VERSION 3.1.0)
project(C_DEEP VERSION 1.0.0)
project(C_DEEP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(NAME "Ansu")
message("This project has been made by ${NAME}.")

add_library(libraries
            src/rn.cpp)

add_executable(main
            src/main.cpp)
            

target_include_directories(libraries PUBLIC include)
target_link_libraries(main PUBLIC libraries)