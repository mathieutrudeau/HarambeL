#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Tokenizer.h"
#include "Token.h"
#include "../Logger/Logger.h"


Tokenizer::Tokenizer(std::string sourceFilename)
{
    Logger::log("Initializing Tokenizer with source file: " + sourceFilename);

    SourceFilename = sourceFilename;
    CurrentCharacter = ' ';
    CurrentLine = 1;
    CurrentColumn = 1;
    Buffer = "";
    BufferIndex = 0;

    // Open the source file for reading
    std::ifstream sourceFile(SourceFilename);

    char c;

    // Check if the file is open
    if (sourceFile.is_open())
    {
        while (sourceFile.get(c))
        {
            Buffer += c;
        }

        Logger::log("Source file contents: " + Buffer);      
    }
    else
    {
        Logger::log("Error opening source file: " + SourceFilename);
        return;
    }
}

Tokenizer::~Tokenizer()
{
    Logger::log("Destroying Tokenizer");
}

Token* Tokenizer::GetNextToken()
{    
    // Check if the buffer index is at the end of the buffer
    if (BufferIndex >= Buffer.size() || CurrentCharacter == '\0')
    {
        Logger::log("EOF");
        
        Token* token = new Token();
        token->Type = TokenType::EndOfInput;
        
        return token;
    }

    // Get the next character
    CurrentCharacter = Buffer[BufferIndex];
    BufferIndex++;

    // Check if the character is a space
    if (CurrentCharacter == ' ')
    {
        return GetNextToken();
    }

    // Check if the character is a newline
    if (CurrentCharacter == '\n')
    {
        Logger::log("Newline");
        CurrentLine++;
        CurrentColumn = 1;
        return GetNextToken();
    }

    Logger::log("Got character: " + std::string(1, CurrentCharacter));


    return new Token();

}
