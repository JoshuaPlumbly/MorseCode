#include "MorseCode.h"

const string _morse[59] = {
    SPACE, // space
    "-.-.--", // !
    ".-..-.", // "
    INVALID, // #
    "...-..-", // $
    INVALID, // %
    ".-...", // &
    ".----.", // '
    "-.--.", // (
    "-.--.-", // )
    INVALID, // *
    ".-.-.", // +
    "--..--", // ,
    "-....-", // -
    ".-.-.-", // .
    "-..-.", // /
    
    "-----", // 0...
    ".----",
    "..---",
    "...--",
    "....-",
    ".....",
    "-....",
    "--...",
    "---..",
    "----.", // ...9
    
    "---...", // :
    "-.-.-.", // ;
    INVALID, // <
    "-...-", // =
    INVALID, // >
    "..--..", // ?
    ".--.-.", // @

    ".-", // A...
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--.." // ...Z
};

string DecodeMorseCode(const string& str)
{
    stringstream ss = stringstream();
    map<string, char> mp;
    
    for (size_t i = 0; i < 59; i++)
    {
        mp[_morse[i]] = i + 32;
    }
        
    char* token;
    char* rest = _strdup(str.c_str());

    while ((token = strtok_s(rest, " ", &rest)))
    {
        auto iter = mp.find(token);

        if (iter != mp.end())
            ss << iter->second;
        else if (token == SPACE)
            ss << ' ';
        else
            ss << INVALID;
    }
        
    return ss.str();
}

string EncodeMorseCode(const string& str)
{
    stringstream ss = stringstream();

    for (size_t i = 0; i < str.length(); i++)
    {
        char ch = toupper(str[i]);

        if (ch >= 32 && ch <= 90)
            ss << _morse[ch - 32];
        else
            ss << INVALID;

        ss << SEPARATOR;
    }

    return ss.str();
}