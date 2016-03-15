file(GLOB MYEXAMPLE_FILES "*.hpp" "*.cpp")
add_executable(MyExample ${MYEXAMPLE_FILES})
target_link_libraries(MyExample ${CUDA_LIBRARY_DIR}/libcublas.so)
target_link_libraries(MyExample ${CUDA_LIBRARY_DIR}/libcudart.so)