set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

file(GLOB OPENMP_FILES "*.hpp" "*.cpp")
add_executable(testOpenmp ${OPENMP_FILES})

if(UNIX)
    target_link_libraries(seqAsync gomp)
endif()
