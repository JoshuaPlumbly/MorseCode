#include "MorseCode.h"

using std::cout;

int main()
{
    cout << MorseCode::Encode("The quick brown fox jumps over the lazy dog");
    cout << '\n' << MorseCode::Decode("- .... . / --.- ..- .. -.-. -.- / -... .-. --- .-- -. / ..-. --- -..- / .--- ..- -- .--. ... / --- ...- . .-. / - .... . / .-.. .- --.. -.-- / -.. --- --.");
}