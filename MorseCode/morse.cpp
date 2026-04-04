#include "morse.h"

namespace morse
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

    const char* encodeChar(char ch)
    {
        char upperCh = toupper(ch);

        if (upperCh >= 32 && upperCh <= 90)
            return _morse[upperCh - 32];
        else
            return INVALID;
    }

    string encode(const string& str)
    {
        stringstream ss = stringstream();

        for (size_t i = 0; i < str.length(); i++)
        {
            ss << encodeChar(str[i]) << SEPARATOR;
        }

        return ss.str();
    }

    string decode(const string& str)
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

    string encode(const string& str, char dot, char dash, char space) {
        string morseCode = encode(str);

        for (char& c : morseCode) {
            if (c == '.')
                c = dot;

            if (c == '-')
                c = dash;

            if (c == '/')
                c = space;
        }

        return morseCode;
    }

    string decode(string& str, char dot, char dash, char space) {

        for (char& c : str) {
            if (c == dot)
                c = '.';

            if (c == dash)
                c = '-';

            if (c == space)
                c = '/';
        }

        return decode(str);
    }
}