//
// Created by Zion Packer on 10/2/23.
//

#ifndef COMP360_PROJECTS_MAIN_SYNTAX_H
#define COMP360_PROJECTS_MAIN_SYNTAX_H

#endif //COMP360_PROJECTS_MAIN_SYNTAX_H
#pragma once
#include <vector>
#include "lexeme.hpp" // You may need to include the token structure definition here.

std::string parseDeclaration(std::vector<Lexeme>& lexemes, std::vector<Lexeme>& incorrectCode);
std::string parseAssign(std::vector<Lexeme>& lexemes, std::vector<Lexeme>& incorrectCode);
std::string parseExpr(std::vector<Lexeme>& lexemes, std::vector<Lexeme>& incorrectCode);
std::string parseProgram(std::vector<Lexeme>& lexemes, std::vector<Lexeme>& incorrectCode);
