#include "MorseCode.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::cin;

const char* encodeArg = "encode";
const char* decodeArg = "decode";

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        string str;

        do
        {
            cout << "Using your number keys, select one of the following option:\n\n";
            
            cout << "1. Encode - Converts standard text to morse code.\n";
            cout << "2. Decode - Converts morse code to standard text.\n";
            cout << "3. Exit - close session.\n";

            cout << "\n\nSelect option number: ";
            cin >> str;

            if (str == "1")
            {
                cout << "\nEnter standered text to convert to morse code:\n\n";
                cin.ignore();
                getline(cin, str);

                cout << "\nOutput:\n";
                cout << MorseCode::Encode(str) << "\n\n";
            }
            else if (str == "2")
            {
                cout << "\nEnter morse code to convert to standered text:\n\n";
                cin.ignore();
                getline(cin, str);

                cout << "\nOutput:\n";
                cout << MorseCode::Decode(str) << "\n\n";
            }
            else if (str == "3")
            {
                return 0;
            }
            else
            {
                cout << "\nInvalide responce.\n\n";
            }
        } while (true);
    }
    else if(*argv[1] == *encodeArg)
    {
        if (argc > 2)
        {
            cout << MorseCode::Encode(argv[2]);
            return 0;
        }

        string str;
        cout << "Enter standered text to convert to morse code:\n\n";
        getline(cin, str);
        cout << "\nOutput:\n";
        cout << MorseCode::Encode(str);
    }
    else if (*argv[1] == *decodeArg)
    {
        if (argc > 2)
        {
            cout << MorseCode::Decode(argv[2]);
            return 0;
        }

        string str;
        cout << "Enter morse code to convert to standered text:\n\n";
        getline(cin, str);
        cout << "\nOutput:\n";
        cout << MorseCode::Decode(str);
    }

    return 0;
}