#include <string>

#include "lexeme.hpp"

Lexeme::Lexeme(TokenCategory cat, std::string val) : category(cat), value(val) {}

std::string Lexeme::GetCategoryString() {
    switch (category) {
        case KEYWORD:
            return "KEYWORD";
        case OPERATOR:
            return "OPERATOR";
        case PUNCTUATION:
            return "PUNCTUATION";
        case IDENTIFIER:
            return "IDENTIFIER";
        case UNKNOWN:
            return "UNKNOWN";
        default:
            return "Invalid Token Category";
    }
}