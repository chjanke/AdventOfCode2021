add_executable(Day3 main.cpp "day3.hpp")
target_link_libraries(Day3 PRIVATE AoC::AoC-Utility)

add_executable(Day3Test test.cpp "day3.hpp")
target_link_libraries(Day3Test PRIVATE AoC::AoC-Utility)
target_include_directories(Day3Test PRIVATE ${CMAKE_SOURCE_DIR}/Dependencies/)
target_compile_features(Day3Test PRIVATE cxx_std_20)
target_compile_definitions(Day3Test PRIVATE BOOST_UT_DISABLE_MODULE)
