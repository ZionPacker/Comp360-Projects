#include <ios>
#include <string>
#include <sstream>
#include <vector>

#include "lexical_analyzer.hpp"
#include "util.hpp"

LexicalAnalyzer::LexicalAnalyzer() {}

std::vector<Lexeme> LexicalAnalyzer::Analyze(std::string input) {
    std::vector<Lexeme> lexemes;
    std::string lexeme;

    for (char c : input) {
        // If it is a whitespace and the working lexeme is not empty, then that denotes the end of a lexeme.
        if (std::isspace(c) && !lexeme.empty()) {
            FinalizeLexeme(lexemes, lexeme);
            continue;
        }
        else if (std::isspace(c)) // otherwise, we just skip it since there is nothing else to do.
            continue; 
         
        // If the current character is an operator or a punctation, then that will denote the end of the working lexeme
        // (if any), and then add the lexeme for the punctation/operator.
        if (FindStringInVector(ops, c) != -1) {
            if (!lexeme.empty()) FinalizeLexeme(lexemes, lexeme);
            lexemes.push_back(Lexeme(TokenCategory::OPERATOR, std::string{c}));
            continue;
        }
        else if (FindStringInVector(punctuation, c) != -1) {
            if (!lexeme.empty()) FinalizeLexeme(lexemes, lexeme);
            lexemes.push_back(Lexeme(TokenCategory::PUNCTUATION, std::string{c}));
            continue;
        }
        // Otherwise, it is either a keyword, or identifer...or invalid. So we need to keep getting
        // the characters until we reach a whitespace or end of the input.
        
        // If the char is not between 0-9 or a-Z, then an error will be thrown.
        if (!std::isalpha(c))
            throw std::invalid_argument("Lexical analyzer encountered an invalid character: ");

        // Otherwise, add it to the working lexeme.
        lexeme += c;
    }

    // If the lexeme is not empty - which indicates that the lexeme is the last one - 
    // then we add it, otherwise we are done.
    if (!lexeme.empty()) FinalizeLexeme(lexemes, lexeme);
    return lexemes;
}

/// @brief Pushes the parsed lexeme into the vector and clears the string.
/// @param lexemes The vector to add the lexeme to.
/// @param s The working string representation of the lexeme.
inline void LexicalAnalyzer::FinalizeLexeme(std::vector<Lexeme>& lexemes, std::string& s) {
    lexemes.push_back(ParseLexeme(s));
    s.clear();
}

Lexeme LexicalAnalyzer::ParseLexeme(std::string lexeme) {
    
    // Check to see if it is a keyword.
    auto it = FindStringInVector(keywords, lexeme);
    if (it != -1)
        return Lexeme(TokenCategory::KEYWORD, lexeme);
    // Check to see if it is an operator.
    it = FindStringInVector(ops, lexeme);
    if (it != -1)
        return Lexeme(TokenCategory::OPERATOR, lexeme);
    // Check to see if it is punctuation.
    it = FindStringInVector(punctuation, lexeme);
    if (it != -1)
        return Lexeme(TokenCategory::PUNCTUATION, lexeme);
    // Now, the only thing that"s left is that it has to be an identifier.
    return Lexeme(TokenCategory::IDENTIFIER, lexeme);
}
