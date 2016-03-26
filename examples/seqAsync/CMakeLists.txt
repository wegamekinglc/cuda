set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -Xcompiler -fopenmp")

file(GLOB SEQASYNC_FILES "*.cu")
CUDA_ADD_EXECUTABLE(seqAsync ${SEQASYNC_FILES})

if(UNIX)
    target_link_libraries(seqAsync gomp)
endif()
