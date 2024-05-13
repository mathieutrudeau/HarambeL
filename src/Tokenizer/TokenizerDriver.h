#ifndef TOKENIZERDRIVER_H
#define TOKENIZERDRIVER_H

#include <string>

class Tokenizer;


class TokenizerDriver {
    public:
        // Constructor
        TokenizerDriver(std::string sourceFilename);

        // Destructor
        ~TokenizerDriver();

        // Methods
        void Run();
    private:
        // Properties
        std::string SourceFilename;
        Tokenizer* Tokenizer_ptr;
        
};


#endif // TOKENIZERDRIVER_H