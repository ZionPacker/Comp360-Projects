#pragma once
#include <vector>

#include "analyzer.hpp"
#include "lexeme.hpp"

static const std::vector<std::string> keywords {"float", "void"};
static const std::vector<std::string> ops {"=", "+", "-"};
static const std::vector<std::string> punctuation {"(", ")", "{", "}", ";"};

class LexicalAnalyzer : public Analyzer {
public:
    LexicalAnalyzer();
    /// @brief Parses a string into a vector of lexemes
    /// @param input The string to parse.
    /// @return A list of lexeme objects.
    std::vector<Lexeme> Analyze(std::string input) override;
private:
    /// @brief Attempts to identify the lexeme and return a Lexeme object.
    /// @param lexeme The working string representation of the lexeme.
    /// @return A Lexeme object.
    Lexeme ParseLexeme(std::string lexeme);
    inline void FinalizeLexeme(std::vector<Lexeme>& lexemes, std::string& s);
};