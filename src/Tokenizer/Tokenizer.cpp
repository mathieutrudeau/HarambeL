#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Tokenizer.h"
#include "Token.h"
#include "../Logger/Logger.h"


char Tokenizer::Special_Characters[] = {'\0', ' ', '\n', '\t', '\r', '\v', '\f'};


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
    // Define the current lexeme
    std::string lexeme = "";
    Token* token = new Token();

    // Loop through the buffer until a special character is found
    do
    {
        // Get the next character
        CurrentCharacter = Buffer[BufferIndex];
        BufferIndex++;  

        // Add the character to the lexeme if it is not a special character
        if (!CheckForSpecialCharacter(CurrentCharacter))
            lexeme += CurrentCharacter;
    } 
    while (!CheckForSpecialCharacter(CurrentCharacter) || lexeme == "");

    Logger::log("Current lexeme: "+lexeme);

    bool isCut = false;
    size_t tokenSize = lexeme.size();

    while (Token::StringToTokenType(lexeme) == TokenType::None && lexeme != "")
    {
        // Since the lexeme is not a valid token, remove the last character
        lexeme.pop_back();
        BufferIndex--;

        isCut = true;
        tokenSize--;
    }

    // Move the buffer index back one if the lexeme was cut
    if (isCut && tokenSize > 0)
        BufferIndex--;

    // Create a new token
    return CreateToken(lexeme);
}


bool Tokenizer::CheckForSpecialCharacter(char c)
{
    for (int i = 0; i < sizeof(Special_Characters); i++)
        if (Special_Characters[i] == c)
        {
            // Update the current line and column if the character is a newline
            if (c == '\n')
            {
                CurrentLine++;
                CurrentColumn = 1;
            }
            // Update the current column if the character is not a newline
            else
            {
                CurrentColumn++;
            }
            return true;
        }
    return false;
}



Token* Tokenizer::CreateToken(std::string lexeme)
{
    // Convert the lexeme to a token type
    TokenType type = Token::StringToTokenType(lexeme);

    // Create a new token
    return new Token(type, lexeme, CurrentLine, CurrentColumn);
}