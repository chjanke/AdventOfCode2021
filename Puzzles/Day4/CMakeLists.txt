add_executable(Day4 main.cpp "day4.hpp")
target_link_libraries(Day4 PRIVATE AoC::AoC-Utility)

add_executable(Day4Test test.cpp "day4.hpp")
target_link_libraries(Day4Test PRIVATE AoC::AoC-Utility)
target_include_directories(Day4Test PRIVATE ${CMAKE_SOURCE_DIR}/Dependencies/)
target_compile_features(Day4Test PRIVATE cxx_std_20)
target_compile_definitions(Day4Test PRIVATE BOOST_UT_DISABLE_MODULE)
