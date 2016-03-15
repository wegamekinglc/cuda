file(GLOB SIMPLEEXAMPLE_FILES "*.hpp" "*.cpp")
add_executable(SimpleExample ${SIMPLEEXAMPLE_FILES})
target_link_libraries(SimpleExample ${CUDA_LIBRARY_DIR}/libcublas.so)
target_link_libraries(SimpleExample ${CUDA_LIBRARY_DIR}/libcudart.so)