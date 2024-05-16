#include "TokenizerDriver.h"
#include "Tokenizer.h"
#include "Token.h"
#include "../Logger/Logger.h"
#include <fstream>
#include <iostream>


TokenizerDriver::TokenizerDriver(std::string sourceFilename)
{
    SourceFilename = sourceFilename;

    // Create the Tokenizer object
    Tokenizer_obj = new Tokenizer(SourceFilename);
}

TokenizerDriver::~TokenizerDriver()
{
    // Delete the Tokenizer object
    delete Tokenizer_obj;
}

void TokenizerDriver::Run()
{
    Token* token;

    do
    {
        // Get the next token
        token = Tokenizer_obj->GetNextToken();
 
        std::cout << *token << std::endl;    
    } 
    while (token->Type != TokenType::EndOfInput);
}