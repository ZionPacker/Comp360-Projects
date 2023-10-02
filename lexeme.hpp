#pragma once
#include <string>

enum TokenCategory {
    KEYWORD,
    OPERATOR,
    PUNCTUATION,
    IDENTIFIER,
    UNKNOWN
};

class Lexeme {
public:
    TokenCategory category;
    std::string value;
    Lexeme(TokenCategory cat, std::string val);
    std::string GetCategoryString();
};

