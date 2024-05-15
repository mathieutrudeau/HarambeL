#include <cctype>
#include <algorithm>
#include "Token.h"
#include "../Logger/Logger.h"

// Constructor
Token::Token(TokenType type, std::string lexeme, int line, int column)
{
    //Logger::log("Creating token with type: " + std::to_string((int)type) + ", lexeme: " + lexeme + ", line: " + std::to_string(line) + ", column: " + std::to_string(column));

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
    Type = TokenType::None;
    Lexeme = "";
    Line = 0;
    Column = 0;
}

// Methods
TokenType Token::StringToTokenType(std::string tokenStr)
{
    //Logger::log("Converting token string to token type: " + tokenStr);

    // Make the string lowercase for easier comparison
    std::transform(tokenStr.begin(), tokenStr.end(), tokenStr.begin(), ::tolower);

    // Start by checking for a type
    if (tokenStr == "int" || tokenStr == "integer")
        return TokenType::Integer;
    else if (tokenStr == "float")
        return TokenType::Float;
    else if (tokenStr == "string")
        return TokenType::String;
    else if (tokenStr == "bool" || tokenStr == "boolean")
        return TokenType::Boolean;
    else if (tokenStr == "char" || tokenStr == "character")
        return TokenType::Char;
    else if (tokenStr == "void")
        return TokenType::Void;
    else if (tokenStr == "double")
        return TokenType::Double;

    // Check for punctuation
    if (tokenStr == ";")
        return TokenType::Semicolon;
    else if (tokenStr == ",")
        return TokenType::Comma;
    else if (tokenStr == "(")
        return TokenType::LeftParenthesis;
    else if (tokenStr == ")")
        return TokenType::RightParenthesis;
    else if (tokenStr == "{")
        return TokenType::LeftBrace;
    else if (tokenStr == "}")
        return TokenType::RightBrace;
    else if (tokenStr == "[")
        return TokenType::LeftBracket;
    else if (tokenStr == "]")
        return TokenType::RightBracket;
    else if (tokenStr == ".")
        return TokenType::Dot;
    else if (tokenStr == ":")
        return TokenType::Colon;

    // Check for operators
    if (tokenStr == "+")
        return TokenType::Plus;
    else if (tokenStr == "-")
        return TokenType::Minus;
    else if (tokenStr == "*")
        return TokenType::Multiply;
    else if (tokenStr == "/")
        return TokenType::Divide;
    else if (tokenStr == "%")
        return TokenType::Modulus;
    else if (tokenStr == "++")
        return TokenType::Increment;
    else if (tokenStr == "--")
        return TokenType::Decrement;
    else if (tokenStr == "=")
        return TokenType::Assignment;
    else if (tokenStr == "+=")
        return TokenType::PlusAssignment;
    else if (tokenStr == "-=")
        return TokenType::MinusAssignment;
    else if (tokenStr == "*=")
        return TokenType::MultiplyAssignment;
    else if (tokenStr == "/=")
        return TokenType::DivideAssignment;
    else if (tokenStr == "%=")
        return TokenType::ModulusAssignment;
    else if (tokenStr == "==")
        return TokenType::Equal;
    else if (tokenStr == "!=")
        return TokenType::NotEqual;
    else if (tokenStr == ">")
        return TokenType::GreaterThan;
    else if (tokenStr == "<")
        return TokenType::LessThan;
    else if (tokenStr == ">=")
        return TokenType::GreaterThanOrEqual;
    else if (tokenStr == "<=")
        return TokenType::LessThanOrEqual;
    else if (tokenStr == "&&")
        return TokenType::And;
    else if (tokenStr == "||")
        return TokenType::Or;
    else if (tokenStr == "!")
        return TokenType::Not;

    // Check for keywords
    if (tokenStr == "if")
        return TokenType::If;
    else if (tokenStr == "else")
        return TokenType::Else;
    else if (tokenStr == "func")
        return TokenType::Func;
    else if (tokenStr == "return")
        return TokenType::Return;

    // Check for the end of input
    if (tokenStr == "\0")
        return TokenType::EndOfInput;

    // Check for an identifier
    if (IsIdentifier(tokenStr))
        return TokenType::Identifier;

    // Check for an integer literal
    if (IsIntegerLiteral(tokenStr))
        return TokenType::IntegerLiteral;

    return TokenType::None;
}


bool Token::IsIdentifier(std::string tokenStr)
{
    // An identifier must start with a letter or an underscore
    if (!isalpha(tokenStr[0]) && tokenStr[0] != '_')
        return false;

    // Check the rest of the characters, they can be letters, numbers, or underscores
    for (int i = 1; i < tokenStr.length(); i++)
    {
        if (!isalnum(tokenStr[i]) && tokenStr[i] != '_')
            return false;
    }

    return true;
}

bool Token::IsIntegerLiteral(std::string tokenStr)
{
    // Check if the string is empty
    if (tokenStr == "")
        return false;

    // Check if the first character is a digit  
    if (!isdigit(tokenStr[0]))
        return false;

    // If the first character is a zero, the string must be a single zero
    if (tokenStr[0] == '0' && tokenStr.length() > 1)
        return false;

    // Check the rest of the characters, they must all be digits
    for (int i = 1; i < tokenStr.length(); i++)
    {
        if (!isdigit(tokenStr[i]))
            return false;
    }

    return true;
}



// Overloaded Operators
std::ostream& operator<<(std::ostream& os, const Token& token)
{
    if (token.Type == TokenType::EndOfInput)
    {
        os << "Token: End of Input (Type: " << (int)token.Type << ", Line: " << token.Line << ", Column: " << token.Column << ")";
        return os;
    }
    
    os << "Token: " << token.Lexeme << " (Type: " << (int)token.Type << ", Line: " << token.Line << ", Column: " << token.Column << ")";
    return os;
}