file(GLOB MYEXAMPLE_FILES "*.hpp" "*.cpp")
add_executable(MyExample ${MYEXAMPLE_FILES})

target_link_libraries(MyExample cublas)
target_link_libraries(MyExample cudart)