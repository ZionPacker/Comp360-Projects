#pragma once
#include <ios>
#include <string>
#include <vector>

#include "lexeme.hpp"

/// @brief The base class for all analyzers.
class Analyzer {

public:
    /// @brief Parses a string into a vector of lexemes
    /// @param input The string to parse.
    /// @return A list of lexeme objects.
    virtual std::vector<Lexeme> Analyze(std::string input) = 0;

};