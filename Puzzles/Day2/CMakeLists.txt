add_executable(Day2 main.cpp "day2.hpp")
target_link_libraries(Day2 PRIVATE AoC::AoC-Utility)

add_executable(Day2Test test.cpp "day2.hpp")
target_link_libraries(Day2Test PRIVATE AoC::AoC-Utility)
target_include_directories(Day2Test PRIVATE ${CMAKE_SOURCE_DIR}/Dependencies/)
target_compile_features(Day2Test PRIVATE cxx_std_20)
target_compile_definitions(Day2Test PRIVATE BOOST_UT_DISABLE_MODULE)
