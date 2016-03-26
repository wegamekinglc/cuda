#set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -D USE_HOST -Xcompiler -fopenmp")
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -arch=sm_50 -use_fast_math -Xcompiler -fopenmp")

file(GLOB XORNM_FILES "*.hpp" "*.cpp" "*.cu")
CUDA_ADD_EXECUTABLE(xorNM ${XORNM_FILES})
if(UNIX)
    target_link_libraries(xorNM gomp)
endif()
