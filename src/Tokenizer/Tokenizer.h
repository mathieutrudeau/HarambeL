#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>
#include <fstream>

class Token;

/**
 * @brief The Tokenizer class is responsible for tokenizing a source file
 */
class Tokenizer {
    public:
        
        /*
        * @brief Construct a new Tokenizer object
        *
        * @param sourceFilename Filename of the source file to tokenize
        */
        Tokenizer(std::string sourceFilename);

        /*
        * @brief Destroy the Tokenizer object
        */
        ~Tokenizer();

        /*
        * @brief Get the next token from the source file
        */
        Token* GetNextToken();

    private:

        // Source Filename
        std::string SourceFilename;

        // Current Character
        char CurrentCharacter;

        // Buffer Index
        int BufferIndex;

        // Buffer
        std::string Buffer;

        // Special Characters Array
        static char Special_Characters[];

        /*
        * @brief Check if a character is a special character
        * @param c The character to check
        * @return True if the character is a special character, false otherwise
        */
        bool CheckForSpecialCharacter(char c);

        /*
        * @brief Create a token with the given lexeme
        * @param lexeme The lexeme of the token
        * @return The created token object
        */
        Token* CreateToken(std::string lexeme);

        /*
        * @brief Get the next character from the buffer
        */
        void GetNextChar();        

        /*
        * @brief Backtrack the buffer index
        */
        void Backtrack();

        void GetTokenPosition(int& line, int& column, int lexemeSize);

        int GetLineNumber();
        int GetColumnNumber();
};

#endif // TOKENIZER_H