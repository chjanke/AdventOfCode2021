cmake_minimum_required(VERSION 3.16)

project(AoC-Utility LANGUAGES CXX)

add_library(AoC-Utility INTERFACE)
target_include_directories(AoC-Utility INTERFACE include)
target_compile_features(AoC-Utility INTERFACE cxx_std_20)

add_library(AoC::AoC-Utility ALIAS AoC-Utility)