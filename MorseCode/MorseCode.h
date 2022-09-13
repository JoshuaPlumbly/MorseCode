#pragma once
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <fstream>

using std::string;
using std::stringstream;
using std::map;
using std::vector;
using std::ifstream;

namespace MorseCode
{
	static const char* DASH = "-";
	static const char* DOT = ".";
	static const char* SPACE = "/";
	static const char* INVALID = "#";
	static const char* SEPARATOR = " ";

	static const char* NewLine = ".-.-";
	static const char* EndOfMessage = ".-.-.";
	static const char* Wait = ".-...";
	static const char* Break = "-...-.-";
	static const char* Newparagraph = "-...-";
	static const char* Clear = "-.-..-..";
	static const char* StartCopying = "-.-.-";
	static const char* StartingSignal = "-.-.-";
	static const char* InviteToTransmit = "-.--.";
	static const char* EndTransmission = "...-.-";
	static const char* Understood = "...-.";
	static const char* SOS = "...---...";

	const char* EncodeChar(char ch);
	string Decode(const string& str);
	string Encode(const string& str);
}