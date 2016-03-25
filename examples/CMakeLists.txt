find_package(CUDA)

add_subdirectory(seqSerial)
add_subdirectory(seqCuda)
add_subdirectory(seqRuntime)
add_subdirectory(seqAsync)