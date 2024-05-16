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

Token *Tokenizer::GetNextToken()
{
    // Define the current lexeme
    std::string lexeme = "";

    // Check if the buffer index is at the end of the buffer
    if (BufferIndex >= Buffer.size())
    {
        // Create an end of input token
        return CreateToken("\0");
    }

    // Loop through the buffer until a special character is found
    do
    {
        // Get the next character
        GetNextChar();

        // Add the character to the lexeme if it is not a special character
        if (!CheckForSpecialCharacter(CurrentCharacter))
            lexeme += CurrentCharacter;
    } while (!CheckForSpecialCharacter(CurrentCharacter) || lexeme == "");

    bool isCut = false;
    size_t tokenSize = lexeme.size();

    while (Token::StringToTokenType(lexeme) == TokenType::None && lexeme != "")
    {
        // Since the lexeme is not a valid token, remove the last character
        lexeme.pop_back();
        Backtrack();

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
            return true;
    return false;
}

Token *Tokenizer::CreateToken(std::string lexeme)
{
    // Convert the lexeme to a token type
    TokenType type = Token::StringToTokenType(lexeme);

    int line, column;

    GetTokenPosition(line, column, (int) lexeme.size());

    // Create a new token
    return new Token(type, lexeme, line, column);
}


void Tokenizer::GetTokenPosition(int& line, int& column, int lexemeSize)
{
    line = 1;
    column = 1;

    int topIndex = BufferIndex - lexemeSize;

    for (int i = 0; i < topIndex; i++)
    {
        // Make sure the last character is not a special character
        if (CheckForSpecialCharacter(Buffer[i+lexemeSize]) && i == topIndex - 1)
            break;

        if (Buffer[i] == '\n')
        {
            line++;
            column = 1;
        }
        else if (Buffer[i] == '\t')
            column += 4;
        else
            column++;

        
    }
}


void Tokenizer::GetNextChar()
{
    // Check if the buffer index is at the end of the buffer
    if (BufferIndex >= Buffer.size())
    {
        CurrentCharacter = '\0';
        return;
    }

    // Get the next character
    CurrentCharacter = Buffer[BufferIndex];
    BufferIndex++;
}

void Tokenizer::Backtrack()
{
    // Move the buffer index back one
    BufferIndex--;

    // Set the current character to the previous character
    CurrentCharacter = Buffer[BufferIndex];
}