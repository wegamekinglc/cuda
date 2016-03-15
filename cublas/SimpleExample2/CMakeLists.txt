file(GLOB SIMPLEEXAMPLE_FILES2 "*.hpp" "*.cpp")
add_executable(SimpleExample2 ${SIMPLEEXAMPLE_FILES2})
target_link_libraries(SimpleExample2 ${CUDA_LIBRARY_DIR}/libcublas.so)
target_link_libraries(SimpleExample2 ${CUDA_LIBRARY_DIR}/libcudart.so)