cmake_minimum_required(VERSION 3.16)

project(align)

set(CMAKE_CXX_STANDARD 20) # 20 is causing all sorts of warnings
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(align src/align.cpp)

target_include_directories(align PUBLIC "${PROJECT_SOURCE_DIR}/include")
#target_link_libraries(align tbb)
target_compile_options(align PRIVATE -Wno-unknown-warning-option -Wno-tautological-compare -Wno-sign-compare -D_REENTRANT -Wno-ignored-attributes -O3 -DBOOST_DISABLE_ASSERTS)

find_package(Catch2 REQUIRED)
add_executable(tests tests/src/tests.cpp)
target_include_directories(tests PUBLIC /usr/local/Cellar/catch2/2.13.4/include "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(tests PRIVATE Catch2::Catch2)
