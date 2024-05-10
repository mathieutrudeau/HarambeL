#include <iostream>
#include "./Tokenizer/TokenizerDriver.h"


using std::cout;
using std::endl;

int main() {
    
    cout << "Hello, World!" << endl;

    TokenizerDriver tokenizerDriver("test.txt");
    tokenizerDriver.Run();

    return 0;
}