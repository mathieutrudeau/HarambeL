#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <vector>


/**
 * @brief A Token Type represents the type of a token.
*/
enum class TokenType {
    // Date Types
    Integer,
    Float,
    String,
    Boolean,
    Double,
    Char,
    Void,

    // Punctuation
    Comma,
    Semicolon,
    Colon,
    Dot,
    LeftParenthesis,
    RightParenthesis,
    LeftBrace,
    RightBrace,
    LeftBracket,
    RightBracket,

    // Operators
    Plus,
    Minus,
    Multiply,
    Divide,
    Modulus,
    Increment,
    Decrement,
    Assignment,
    PlusAssignment,
    MinusAssignment,
    MultiplyAssignment,
    DivideAssignment,
    ModulusAssignment,
    Equal,
    NotEqual,
    GreaterThan,
    LessThan,
    GreaterThanOrEqual,
    LessThanOrEqual,
    And,
    Or,
    Not,

    // Keywords
    If,
    Else,
    Func,
    Return,


    EndOfInput,
    None,
};

/**
 * @brief A Token represents a token in the source code.
*/
class Token{
    public:

        // Constructor
        Token(TokenType type, std::string lexeme, int line, int column);
        Token();

        // Destructor
        ~Token();

        // Properties
        TokenType Type;
        std::string Lexeme;
        int Line;
        int Column;

        // Methods
        static TokenType StringToTokenType(std::string tokenStr);

    private:

};

#endif // TOKEN_H