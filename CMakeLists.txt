cmake_minimum_required(VERSION 3.26)
project(COMP360_Projects_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(tests)

add_executable(COMP360_Projects_main
        tests/lexical_analzyer_tests.hpp
        tests/tests_main.cpp
        analyzer.hpp
        lexeme.cpp
        lexeme.hpp
        lexical_analyzer.cpp
        lexical_analyzer.hpp
        main.cpp
        parser.cpp
        parser.hpp
        util.cpp
        util.hpp
        analyzer.cpp
        syntax.h
)
