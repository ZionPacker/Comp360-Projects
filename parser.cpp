#include <iostream>

#include "parser.hpp"
#include "lexical_analyzer.hpp"
#include "util.hpp"

Parser::Parser() {}

void Parser::Parse(std::vector<Lexeme> lexemes) {
    for (Lexeme lexeme : lexemes) {
        if (lexeme.category == TokenCategory::KEYWORD) {
            if (FindStringInVector(keywords, lexeme.value) == -1) {
                std::cout << "Invalid keyword: " << lexeme.value << std::endl;
            }
        }
    }
}