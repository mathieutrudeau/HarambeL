#ifndef TOKENIZERDRIVER_H
#define TOKENIZERDRIVER_H

#include <string>

class Tokenizer;
enum class TokenType;


/**
 * @brief The Tokenizer Driver class is responsible for running the Tokenizer
 */
class TokenizerDriver {
    public:
        /*
        * @brief Construct a new Tokenizer Driver:: Tokenizer Driver object
        * 
        * @param sourceFilename Filename of the source file to tokenize
        */
        TokenizerDriver(std::string sourceFilename);

        /*
        * @brief Destroy the Tokenizer Driver:: Tokenizer Driver object
        */
        ~TokenizerDriver();

        /*
        * @brief Run the Tokenizer Driver
        */
        void Run();

    private:
        
        // Source Filename
        std::string SourceFilename;
        
        // Tokenizer object
        Tokenizer* Tokenizer_obj;
};


#endif // TOKENIZERDRIVER_H