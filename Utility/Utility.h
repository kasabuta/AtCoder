#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

#define SIZEOF(a) (sizeof(a)/sizeof(a[0]))
#define repeat(itr, count) for(auto itr = 0; itr < count; itr++ )

std::vector<std::string> SplitString(std::string str, const char* del = " ");
std::vector<int> SplitToInt(std::string str, const char* del = " ");
std::vector<float> SplitToFloat(std::string str, const char* del = " ");
std::vector<long long> SplitToLongLong(std::string str, const char* del = " ");


template <typename T>
std::vector<T> Split(std::string str, const char* del = " ");
template <>
std::vector<int> Split(std::string str, const char* del);
template <>
std::vector<long long> Split(std::string str, const char* del);
template <>
std::vector<float> Split(std::string str, const char* del);

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

std::vector<int> GetDigits(int num);
std::vector<int> GetDigits(long long num);

// 昇順ソート
template <typename T>
std::vector<T> Sort(const std::vector<T> array) {
    auto sortedArray = array;
    std::sort(sortedArray.begin(), sortedArray.end());
    return sortedArray;
}

// 降順ソート
template <typename T>
std::vector<T> SortInv(const std::vector<T> array) {
    auto sortedArray = array;
    std::sort(sortedArray.begin(), sortedArray.end(), std::greater<T>{});
    return sortedArray;
}

template <typename T>
std::vector<int> SortIndex(const std::vector<T> array) {
    auto length = array.size();
    int indexArray[length];
    repeat(i, length) {
        indexArray[i].index = i;
    }
    std::sort(
        indexArray.begin(),
        indexArray.end(),
        [array](const int& x, const int& y) {return array[x] < array[y]; }
    );
    return indexArray;
}

template <typename T>
struct TwoNums {
    T first;
    T second;

    TwoNums()
        : first(0)
        , second(0)
    {}
};

template <typename T>
struct ThreeNums {
    T first;
    T second;
    T third;

    ThreeNums()
        : first(0)
        , second(0)
        , third(0)
    {}
};

template <typename T>
struct Point2D {
    T x;
    T y;

    Point2D()
        : x(0)
        , y(0)
    {}
};

template <typename T>
struct Point3D {
    T x;
    T y;
    T z;

    Point3D()
        : x(0)
        , y(0)
        , z(0)
    {}
};

template <typename T>
double GetLength(Point2D<T> p1, Point2D<T> p2) {
    double length = 0;
    length += (p1.x - p2.x) * (p1.x - p2.x);
    length += (p1.y - p2.y) * (p1.y - p2.y);
    return sqrt(length);
}

template <typename T>
double GetLength(Point3D<T> p1, Point3D<T> p2) {
    double length = 0;
    length += (p1.x - p2.x) * (p1.x - p2.x);
    length += (p1.y - p2.y) * (p1.y - p2.y);
    length += (p1.z - p2.z) * (p1.z - p2.z);
    return sqrt(length);
}

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
