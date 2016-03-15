cmake_minimum_required(VERSION 2.8)

PROJECT(alglib)

set(CUDA_INCLUDE_DIR "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v7.5/include")
set(CUDA_LIBRARY_DIR "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v7.5/lib/x64")

include_directories(${CUDA_INCLUDE_DIR})

add_subdirectory(cublas)