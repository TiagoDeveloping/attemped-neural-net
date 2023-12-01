cmake_minimum_required(VERSION 3.10)

project(Neural)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(image.png ${CMAKE_CURRENT_BINARY_DIR}/image.png COPYONLY)
# configure_file(resources/matrices ${CMAKE_CURRENT_BINARY_DIR}/matrices COPYONLY)

# Add your source files
set(SOURCES
    main.cpp
    Matrix.cpp
    # neural/Kernel.cpp
    neural/Neural.cpp
    Util.cpp
    StringMatrixMap.cpp
    neural/NeuralUtil.cpp
    neural/Weights.cpp
)

# Add header files
set(HEADERS
    Matrix.hpp
    # neural/Kernel.hpp
    neural/Neural.hpp
    Util.hpp
    StringMatrixMap.hpp
    stb_image.h
    neural/NeuralUtil.hpp
    neural/Weights.hpp
)

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Add the executable
add_executable(Neural ${SOURCES})

# target_link_libraries(Neural PRIVATE STB::STB)

# Optional: Specify output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY .)
