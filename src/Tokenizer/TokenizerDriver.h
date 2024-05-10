#ifndef TOKENIZERDRIVER_H
#define TOKENIZERDRIVER_H

#include <string>

class TokenizerDriver {
    public:
        TokenizerDriver(std::string sourceFilename);

        void Run();

        ~TokenizerDriver();

    private:

        std::string SourceFilename;
        
        

};


#endif // TOKENIZERDRIVER_H