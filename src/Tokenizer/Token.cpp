#include "Token.h"
#include "../Logger/Logger.h"

// Constructor
Token::Token(TokenType type, std::string lexeme, int line, int column)
{
    Logger::log("Creating token with type: " + std::to_string((int)type) + ", lexeme: " + lexeme + ", line: " + std::to_string(line) + ", column: " + std::to_string(column));

    Type = type;
    Lexeme = lexeme;
    Line = line;
    Column = column;
}

// Destructor
Token::~Token()
{
    Logger::log("Destroying token with type: " + std::to_string((int)Type) + ", lexeme: " + Lexeme + ", line: " + std::to_string(Line) + ", column: " + std::to_string(Column));
}

Token::Token()
{
    Logger::log("Creating token with default values");

    Type = TokenType::None;
    Lexeme = "";
    Line = 0;
    Column = 0;
}

// Methods
TokenType Token::StringToTokenType(std::string tokenStr)
{
    Logger::log("Converting token string to token type: " + tokenStr);
    return TokenType::EndOfInput;
}