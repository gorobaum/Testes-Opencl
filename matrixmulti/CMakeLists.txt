CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
project(matrixmulti)


find_library(OPENCL OpenCL)
include_directories(${OPENCL}) 
message("OpenCL Library == ${OPENCL}")

INCLUDE_DIRECTORIES( 
  "/usr/include/CL/"
)

message("include directories: \n")
get_directory_property(includes INCLUDE_DIRECTORIES)
message("${includes}\n")

ADD_DEFINITIONS(-DCL_SOURCE_DIR="${matrixmulti_SOURCE_DIR}")

set(multilib opcl.c)
set(opcllib matrixmulti)
add_library(${opcllib} ${multilib})

set(exec matrix)
add_executable(${exec} main.c)

target_link_libraries(${exec} ${opcllib} ${OPENCL})
