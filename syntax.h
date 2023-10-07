#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "lexeme.hpp" // Include your lexeme definition or header file here

// Function to parse a declaration
std::string parseDeclaration(std::vector<Lexeme>& lexemes);

// Function to parse an assignment
std::string parseAssign(std::vector<Lexeme>& lexemes);

// Function to parse an expression
std::string parseExpr(std::vector<Lexeme>& lexemes);

// Function to parse the entire program
std::string parseProgram(std::vector<Lexeme>& lexemes);

void reportError(const std::vector<Lexeme>& erroneousLexemes);

#endif // PARSER_H
