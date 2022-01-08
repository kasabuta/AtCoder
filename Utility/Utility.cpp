#pragma once
#include "Utility.h"
#include <cmath>

template <typename T>
std::vector<T> Split(std::string str, const char* del) {
    std::vector<T> result;
    return result;
}

template <>
std::vector<int> Split(std::string str, const char* del) {
    return SplitToInt(str, del);
}

template <>
std::vector<float> Split(std::string str, const char* del) {
    return SplitToFloat(str, del);
}

template <>
std::vector<long long> Split(std::string str, const char* del) {
    return SplitToLongLong(str, del);
}

std::vector<std::string> SplitString(std::string str, const char* separator) {
    size_t pos = 0;
    size_t next = str.find(separator);

    std::vector<std::string> result;

    if (next == std::string::npos) {
        result.push_back(str);
        return result;
    }

    while (next != std::string::npos) {
        std::string subStr(str, pos, next - pos);
        result.push_back(subStr);

        pos = next + 1;
        next = str.find(separator, pos);
    }
    if (pos != str.size()) {
        std::string subStr(str, pos);
        result.push_back(subStr);
    }

    return result;
}

std::vector<int> SplitToInt(std::string str, const char* separator) {
    size_t pos = 0;
    size_t next = str.find(separator);

    std::vector<int> result;

    if (next == std::string::npos) {
        result.push_back(std::atoi(str.c_str()));
        return result;
    }

    while (next != std::string::npos) {
        std::string subStr(str, pos, next - pos);
        result.push_back(std::atoi(subStr.c_str()));

        pos = next + 1;
        next = str.find(separator, pos);
    }
    if (pos != str.size()) {
        std::string subStr(str, pos);
        result.push_back(std::atoi(subStr.c_str()));
    }

    return result;
}

std::vector<float> SplitToFloat(std::string str, const char* separator) {
    size_t pos = 0;
    size_t next = str.find(separator);

    std::vector<float> result;

    if (next == std::string::npos) {
        result.push_back(std::atof(str.c_str()));
        return result;
    }

    while (next != std::string::npos) {
        std::string subStr(str, pos, next - pos);
        result.push_back(std::atof(subStr.c_str()));

        pos = next + 1;
        next = str.find(separator, pos);
    }
    if (pos != str.size()) {
        std::string subStr(str, pos);
        result.push_back(std::atof(subStr.c_str()));
    }

    return result;
}

std::vector<long long> SplitToLongLong(std::string str, const char* separator) {
    size_t pos = 0;
    size_t next = str.find(separator);

    std::vector<long long> result;

    if (next == std::string::npos) {
        result.push_back(std::atoll(str.c_str()));
        return result;
    }

    while (next != std::string::npos) {
        std::string subStr(str, pos, next - pos);
        result.push_back(std::atoll(subStr.c_str()));

        pos = next + 1;
        next = str.find(separator, pos);
    }
    if (pos != str.size()) {
        std::string subStr(str, pos);
        result.push_back(std::atoll(subStr.c_str()));
    }

    return result;
}

int RoundUp(float input) {
    auto result = std::ceil(input);
    return static_cast<int>(result);
}

int RoundDown(float input) {
    auto result = std::floor(input);
    return static_cast<int>(result);
}

int Round(float input) {
    auto result = std::roundf(input);
    return static_cast<int>(result);
}

std::vector<int> GetDigits(int num) {
    auto str = std::to_string(num);
    std::vector<int> digits;
    for (auto digit : str) {
        digits.push_back(std::atoi(&digit));
    }
    return digits;
}

std::vector<int> GetDigits(long long num) {
    auto str = std::to_string(num);
    std::vector<int> digits;
    for (auto digit : str) {
        digits.push_back(std::atoi(&digit));
    }
    return digits;
}

std::vector<std::vector<int>> MakeGraph(std::vector<Edge> edges, int size) {
    auto length = edges.size();
    std::vector<std::vector<int>> graph;
    graph.resize(size);
    repeat(i, length) {
        graph[edges[i].from].push_back(edges[i].to);
        graph[edges[i].to].push_back(edges[i].from);
    }
    return graph;
}

std::vector<std::vector<int>> MakeGraphDirected(std::vector<Edge> edges, int size) {
    auto length = edges.size();
    std::vector<std::vector<int>> graph;
    graph.resize(size);
    repeat(i, length) {
        graph[edges[i].from].push_back(edges[i].to);
    }
    return graph;

}
