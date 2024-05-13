#include "Token.h"

// Constructor
Token::Token(TokenType type, std::string lexeme, int line, int column)
{
    Type = type;
    Lexeme = lexeme;
    Line = line;
    Column = column;
}

// Destructor
Token::~Token()
{
}

Token::Token()
{
    Type = TokenType::None;
    Lexeme = "";
    Line = 0;
    Column = 0;
}

// Methods
TokenType Token::StringToTokenType(std::string tokenStr)
{
    if (tokenStr == "+")
    {
        return TokenType::Plus;
    }
    else if (tokenStr == "-")
    {
        return TokenType::Minus;
    }
    else if (tokenStr == "*")
    {
        return TokenType::Multiply;
    }
    else if (tokenStr == "/")
    {
        return TokenType::Divide;
    }
    else if (tokenStr == "(")
    {
        return TokenType::LeftParenthesis;
    }
    else if (tokenStr == ")")
    {
        return TokenType::RightParenthesis;
    }
    else
    {
        return TokenType::None;
    }
}