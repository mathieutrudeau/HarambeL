#include <iostream>
#include "src/Tokenizer/TokenizerDriver.h"


using std::cout;
using std::endl;

int main(int, char**) {
    TokenizerDriver tokenizerDriver("C:\\Users\\mathi\\OneDrive\\Bureau\\HarambeL\\src\\Tokenizer\\TestFiles\\ValidTokens.hara");
    tokenizerDriver.Run();

    return 0;
}