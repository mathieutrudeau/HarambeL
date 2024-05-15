#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>
#include <fstream>

class Token;

class Tokenizer {
    public:
        // Constructor
        Tokenizer(std::string sourceFilename);

        // Destructor
        ~Tokenizer();

        // Methods
        Token* GetNextToken();

    private:

        // Properties
        std::string SourceFilename;
        char CurrentCharacter;
        int CurrentLine;
        int CurrentColumn;
        int BufferIndex;
        std::string Buffer;

        static char Special_Characters[];

        // Methods
        bool CheckForSpecialCharacter(char c);
        Token* CreateToken(std::string lexeme);

        
};

#endif // TOKENIZER_H