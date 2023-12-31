//
// Created by Zion Packer on 10/1/23.
//
#include <iostream>
#include "analyzer.hpp"
#include "lexical_analyzer.hpp"
#include "lexeme.hpp"
#include "parser.hpp"
#include "vector"
#include "syntax.h"


std::string parseDeclaration(std::vector<Lexeme>& lexemes, std::vector<Lexeme>& incorrectCode) {
    if (lexemes.size() >= 2 &&
        (lexemes[0].category == KEYWORD) &&
        (lexemes[1].category == IDENTIFIER)) {
        lexemes.erase(lexemes.begin(), lexemes.begin() + 2); // Consume "keyword identifier"
        if (lexemes.size() >= 1 && (lexemes[0].category == PUNCTUATION)) {
            lexemes.erase(lexemes.begin()); // Consume ";"
            return ""; // No error
        }
        // Store the incorrect code
        for (auto it = lexemes.begin(); it != lexemes.end(); ++it) {
            incorrectCode.push_back(*it);
        }
        return "Expected ';'";
    }
    // Store the incorrect code
    for (auto it = lexemes.begin(); it != lexemes.end(); ++it) {
        incorrectCode.push_back(*it);
    }
    return "Invalid declaration";
}

std::string parseAssign(std::vector<Lexeme>& lexemes, std::vector<Lexeme>& incorrectCode) {
    if (lexemes.size() >= 3 &&
        (lexemes[0].category == IDENTIFIER) &&
        (lexemes[1].category == OPERATOR)) {
        lexemes.erase(lexemes.begin(), lexemes.begin() + 2); // Consume "identifier ="
        if (parseExpr(lexemes, incorrectCode) == "") {
            if (lexemes.size() >= 1 && (lexemes[0].category == PUNCTUATION)) {
                lexemes.erase(lexemes.begin()); // Consume ";"
                return ""; // No error
            }
            // Store the incorrect code
            for (auto it = lexemes.begin(); it != lexemes.end(); ++it) {
                incorrectCode.push_back(*it);
            }
            return "Expected ';'";
        }
        return parseExpr(lexemes, incorrectCode);
    }
    // Store the incorrect code
    for (auto it = lexemes.begin(); it != lexemes.end(); ++it) {
        incorrectCode.push_back(*it);
    }
    return "Invalid assignment";
}

std::string parseExpr(std::vector<Lexeme>& lexemes, std::vector<Lexeme>& incorrectCode) {
    if (lexemes.size() >= 3 &&
        (lexemes[0].category == IDENTIFIER) &&
        (lexemes[1].category == OPERATOR)) {
        lexemes.erase(lexemes.begin(), lexemes.begin() + 2); // Consume "identifier operator"
        return parseExpr(lexemes, incorrectCode);
    } else if (lexemes.size() >= 1 && (lexemes[0].category == IDENTIFIER)) {
        lexemes.erase(lexemes.begin()); // Consume "identifier"
        return ""; // No error
    }
    // Store the incorrect code
    for (auto it = lexemes.begin(); it != lexemes.end(); ++it) {
        incorrectCode.push_back(*it);
    }
    return "Invalid expression";
}

void reportError(const std::string& erroneousText) {
    std::cerr << "Syntax error: " << erroneousText << std::endl;
}

std::string parseProgram(std::vector<Lexeme>& lexemes, std::vector<Lexeme>& incorrectCode) {
    if (lexemes.size() >= 7 &&
        (lexemes[0].category == KEYWORD) &&
        (lexemes[1].category == IDENTIFIER) &&
        (lexemes[2].category == PUNCTUATION) &&
        (lexemes[3].category == KEYWORD) &&
        (lexemes[4].category == IDENTIFIER) &&
        (lexemes[5].category == PUNCTUATION) &&
        (lexemes[6].category == PUNCTUATION)) {
        lexemes.erase(lexemes.begin(), lexemes.begin() + 7); // Consume the entire program declaration
        bool lastBraceConsumed = false;
        while (!lexemes.empty()) {
            std::string parseResult;
            if ((parseResult = parseDeclaration(lexemes, incorrectCode)) == "" || (parseResult = parseAssign(lexemes, incorrectCode)) == "") {
                // Successfully parsed a declaration or assignment
                continue;
            } else if (lexemes.size() >= 1 && lexemes[0].category == PUNCTUATION && lexemes[0].value == "}") {
                // Consume the closing curly brace on a separate line
                lexemes.erase(lexemes.begin());
                lastBraceConsumed = true;
            } else {
                // Report the error with erroneous portion of code
                reportError(lexemes[0].value);
                return parseResult;
            }
        }
        if (!lastBraceConsumed) {
            // Report the missing closing curly brace error with erroneous portion of code
            reportError("}");
            return "Expected '}' on a separate line";
        }
        return ""; // No error
    }
    // Store the incorrect code
    for (auto it = lexemes.begin(); it != lexemes.end(); ++it) {
        incorrectCode.push_back(*it);
    }
    // Report an invalid program error
    reportError("Invalid program");
    return "Invalid program";
}




