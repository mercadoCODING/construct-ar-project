
cmake_minimum_required (VERSION 3.8)
project(construct-ar-project)

#libraries
include_directories(thirdparty)



#openCv config
set(OpenCV_DIR C:/opencv/opencv/build/x64/vc16/lib)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


# Executable
add_executable(test_exec test.cpp)

# Link OpenCV libraries to the executable
target_link_libraries(test_exec ${OpenCV_LIBS})

