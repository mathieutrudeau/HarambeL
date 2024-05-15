#include "TokenizerDriver.h"
#include "Tokenizer.h"
#include "Token.h"
#include "../Logger/Logger.h"
#include <fstream>
#include <iostream>

/**
 * @brief Construct a new Tokenizer Driver:: Tokenizer Driver object
 *
 * @param sourceFilename Filename of the source file to tokenize
 */
TokenizerDriver::TokenizerDriver(std::string sourceFilename)
{
    // Log the initialization
    Logger::log("Initializing Tokenizer Driver");

    SourceFilename = sourceFilename;
    Tokenizer_obj = new Tokenizer(SourceFilename);
}

// Destructor
TokenizerDriver::~TokenizerDriver()
{
    // Delete the Tokenizer object
    delete Tokenizer_obj;

    // Log the destruction
    Logger::log("Destroying Tokenizer Driver");
}

void TokenizerDriver::Run()
{
    Logger::log("Running Tokenizer Driver");

    Token* token;

    do
    {
        token = Tokenizer_obj->GetNextToken();
        std::cout << *token << std::endl;    
    } 
    while (token->Type != TokenType::EndOfInput);


}