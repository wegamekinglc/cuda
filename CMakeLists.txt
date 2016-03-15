cmake_minimum_required(VERSION 2.8)

PROJECT(alglib)

set(CUDA_INCLUDE_DIR /usr/local/cuda-7.5/include)
set(CUDA_LIBRARY_DIR /usr/local/cuda-7.5/lib64)

include_directories(${CUDA_INCLUDE_DIR})

add_subdirectory(cublas)