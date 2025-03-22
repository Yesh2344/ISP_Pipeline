cmake_minimum_required(VERSION 3.10)
project(isp_pipeline)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(isp_pipeline 
    src/main.cpp
    src/ISP_Pipeline.cpp
)