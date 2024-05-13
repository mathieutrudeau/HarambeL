#include "Token.h"


// Constructor
Token::Token(TokenType type, std::string lexeme, int line, int column){
    Type = type;
    Lexeme = lexeme;
    Line = line;
    Column = column;
}

// Destructor
Token::~Token(){
}

Token::Token(){
    Type = TokenType::None;
    Lexeme = "";
    Line = 0;
    Column = 0;
}