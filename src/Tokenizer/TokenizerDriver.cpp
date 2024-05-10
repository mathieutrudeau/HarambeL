#include "TokenizerDriver.h"

#include <iostream>

using namespace std;

// Constructor
TokenizerDriver::TokenizerDriver(std::string sourceFilename){

    cout << "Initializing Tokenizer Driver" << endl;

    SourceFilename = sourceFilename;
}

// Destructor
TokenizerDriver::~TokenizerDriver(){
}

void TokenizerDriver::Run(){
    cout << "Running Tokenizer Driver" << endl;
}