#pragma once
#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using std::string;
using std::stringstream;
using std::map;
using std::vector;

const string DASH = "-";
const string DOT = ".";
const string SPACE = "/";
const string INVALID = "#";
const string SEPARATOR = " ";

const string SOS = "...---...";
const string EndOfMessage = ".-.-.";

string DecodeMorseCode(const string& str);
string EncodeMorseCode(const string& str);