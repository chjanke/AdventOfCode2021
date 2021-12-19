add_executable(Day1 main.cpp)
target_link_libraries(Day1 PRIVATE AoC::AoC-Utility)

add_executable(Day1Test test.cpp)
target_link_libraries(Day1Test PRIVATE AoC::AoC-Utility)
target_include_directories(Day1Test PRIVATE ${CMAKE_BINARY_DIR}/Dependencies/)
