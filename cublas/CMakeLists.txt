if(WIN32)
    include_directories("C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v7.5/include")
    LINK_DIRECTORIES("C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v7.5/lib/x64")
else()
    include_directories(/usr/local/cuda-7.5/include)
    LINK_DIRECTORIES(/usr/local/cuda-7.5/lib64)
endif()

add_subdirectory(SimpleExample)
add_subdirectory(SimpleExample2)
add_subdirectory(MyExample)