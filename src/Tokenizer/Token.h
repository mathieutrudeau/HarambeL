#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <vector>


/**
 * @brief A Token Type represents the type of a token.
*/
enum class TokenType {
    Plus,
    Minus,
    Multiply,
    Divide,
    LeftParenthesis,
    RightParenthesis,
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