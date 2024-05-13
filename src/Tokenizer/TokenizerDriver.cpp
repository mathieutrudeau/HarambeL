#include "TokenizerDriver.h"
#include <fstream> 
#include <iostream>

using namespace std;

/**
 * @brief Construct a new Tokenizer Driver:: Tokenizer Driver object
 * 
 * @param sourceFilename Filename of the source file to tokenize
*/
TokenizerDriver::TokenizerDriver(std::string sourceFilename){

    cout << "Initializing Tokenizer Driver" << endl;

    SourceFilename = sourceFilename;
}

// Destructor
TokenizerDriver::~TokenizerDriver(){
}

void TokenizerDriver::Run(){
    cout << "Running Tokenizer Driver" << endl;

    // Show the source filename
    cout << "Source Filename: " << SourceFilename << endl;

    // Open the file
    ifstream file(SourceFilename);

    // Check if the file is open
    if(file.is_open()){
        cout << "File is open" << endl;
        string line;
        while(getline(file, line)){
            cout << line << endl;
        }
    } else {
        cout << "File is not open" << endl;
    }

    // Close the file
    file.close();
    
}