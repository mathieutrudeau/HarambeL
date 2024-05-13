#include "TokenizerDriver.h"
#include "Tokenizer.h"
#include "../Logger/Logger.h"
#include <fstream> 
#include <iostream>

using namespace std;

/**
 * @brief Construct a new Tokenizer Driver:: Tokenizer Driver object
 * 
 * @param sourceFilename Filename of the source file to tokenize
*/
TokenizerDriver::TokenizerDriver(std::string sourceFilename){

    // Log the initialization
    Logger::log("Initializing Tokenizer Driver");

    SourceFilename = sourceFilename;
    Tokenizer_ptr = new Tokenizer(SourceFilename);
}

// Destructor
TokenizerDriver::~TokenizerDriver(){
    // Log the destruction
    Logger::log("Destroying Tokenizer Driver");
}

void TokenizerDriver::Run(){
    Logger::log("Running Tokenizer Driver");

    // Show the source filename
    Logger::log("Source Filename: " + SourceFilename);

    // Open the file
    ifstream file(SourceFilename);

    // Check if the file is open
    if(file.is_open()){
        Logger::log("File is open");
        string line;
        while(getline(file, line)){
            Logger::log("Line: " + line);
        }
    } else {
        Logger::log("File is not open");
    }

    // Close the file
    file.close();
    
}