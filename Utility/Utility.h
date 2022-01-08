#pragma once
#include <string>
#include <vector>

#define SIZEOF(a) (sizeof(a)/sizeof(a[0]))
#define repeat(itr, count) for(auto itr = 0; itr < count; itr++ )

std::vector<std::string> Split(std::string str, const char* del = " ");
std::vector<int> SplitToInt(std::string str, const char* del = " ");
std::vector<float> SplitToFloat(std::string str, const char* del = " ");
std::vector<long long> SplitToLongLong(std::string str, const char* del = " ");

template <typename ... Args>
std::string format(const char* fmt, Args ... args) {
    size_t len = std::snprintf(nullptr, 0, fmt, args ...);
    std::vector<char> buf(len + 1);
    std::snprintf(&buf[0], len + 1, fmt, args ...);
    return std::string(&buf[0], &buf[0] + len);
}

int RoundUp(float input);
int RoundDown(float input);
int Round(float input);

template <typename T>
std::vector<T> Sort(std::vector<T> array);
template <typename T>
std::vector<int> SortIndex(const std::vector<T> array);

struct Edge {
    int from;
    int to;

    Edge()
    : from()
    , to()
        {}
};

std::vector<std::vector<int>> MakeGraph(std::vector<Edge> edges, int size);
std::vector<std::vector<int>> MakeGraphDirected(std::vector<Edge> edges, int size);
