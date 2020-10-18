 cmake_minimum_required(VERSION 3.10)
project(researchProject)

set(CMAKE_CXX_STANDARD 17)
 set(CMAKE_CXX_FLAGS "-lgmpxx")

add_executable(researchProject gcd.cpp fermat.cpp pollardRho.cpp)

 include_directories(researchProject "/usr/include")
 target_link_libraries(researchProject gmp gmpxx )
