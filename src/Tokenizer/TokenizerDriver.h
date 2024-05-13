#ifndef TOKENIZERDRIVER_H
#define TOKENIZERDRIVER_H

#include <string>


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
};


#endif // TOKENIZERDRIVER_H