#include "MorseCode.h"

namespace MorseCode
{
    const char* _morse[59] = {
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

    const char* EncodeChar(char ch)
    {
        char upperCh = toupper(ch);

        if (upperCh >= 32 && upperCh <= 90)
            return _morse[upperCh - 32];
        else
            return INVALID;
    }

    string Decode(const string& str)
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

    string Encode(const string& str)
    {
        stringstream ss = stringstream();

        for (size_t i = 0; i < str.length(); i++)
        {
            ss << EncodeChar(str[i]) << SEPARATOR;
        }

        return ss.str();
    }
}