#pragma once

#include <string>
#include <vector>

void OutputFormat(std::string* outString, const char* format, ... );

void OutputInt(std::string* outString, const int num);
void OutputFloat(std::string* outString, const float num);
void OutputLongLong(std::string* outString, const long long num);

void OutputNumsInt(std::string* outString, const std::vector<int> out);
void OutputNumsFloat(std::string* outString, const std::vector<float> out);
void OutputNumsLongLong(std::string* outString, const std::vector<long long> out);