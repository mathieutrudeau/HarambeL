#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

class Tokenizer {
public:
    Tokenizer();
    ~Tokenizer();

    void tokenize(const std::string& input);
    std::vector<std::string> getTokens() const;

private:
    std::vector<std::string> tokens;
};

#endif // TOKENIZER_H