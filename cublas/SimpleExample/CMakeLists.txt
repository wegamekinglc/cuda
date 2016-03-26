file(GLOB SIMPLEEXAMPLE_FILES "*.hpp" "*.cpp")
add_executable(SimpleExample ${SIMPLEEXAMPLE_FILES})

target_link_libraries(SimpleExample cublas)
target_link_libraries(SimpleExample cudart)