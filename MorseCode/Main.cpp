#include "MorseCode.h"

int main()
{
    std::cout << EncodeMorseCode("The quick brown fox jumps over the lazy dog");
    std::cout << '\n' << DecodeMorseCode("- .... . / --.- ..- .. -.-. -.- / -... .-. --- .-- -. / ..-. --- -..- / .--- ..- -- .--. ... / --- ...- . .-. / - .... . / .-.. .- --.. -.-- / -.. --- --.");
}