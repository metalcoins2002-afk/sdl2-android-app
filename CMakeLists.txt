cmake_minimum_required(VERSION 3.10)
project(SDL2GLESApp)

# تفعيل ميزات C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# البحث عن مكتبة SDL2 و OpenGL ES
find_package(SDL2 REQUIRED)
find_library(GLES_V2 GLESv2 REQUIRED)

# إنشاء المكتبة البرمجية التي سيقرأها أندرويد
add_library(main SHARED main.cpp)
target_link_libraries(main ${SDL2_LIBRARIES} ${GLES_V2})

