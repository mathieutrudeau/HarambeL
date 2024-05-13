#include <iostream>
#include <string>
#include <vector>
#include "Tokenizer.h"
#include "Token.h"

Tokenizer::Tokenizer(std::string sourceFilename)
{
    SourceFilename = sourceFilename;
    CurrentCharacter = ' ';
    CurrentLine = 1;
    CurrentColumn = 1;
}

Tokenizer::~Tokenizer()
{
    
}

Token* Tokenizer::GetNextToken()
{
    return new Token();
}
