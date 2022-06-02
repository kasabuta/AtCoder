#pragma once
#include "Utility.h"
#include <cmath>
#include <assert.h>
#include <bitset>
#include <queue>

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

template <>
std::vector<std::string> Split(std::string str, const char* del) {
    return SplitString(str, del);
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

long long Sum(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), (long long)0);
}
long long Sum(const std::vector<long long>& vec) {
    return std::accumulate(vec.begin(), vec.end(), (long long)0);
}
double Sum(const std::vector<double>& vec) {
    return std::accumulate(vec.begin(), vec.end(), (double)0);
}

// max以下の素数をすべて求める
void GetPrimesInRange(int max, std::vector<int>& outPrimes) {
    std::vector<bool> check(max + 1, false);
    for (auto i = 2; i <= max; i++) {
        if (!check[i]) {
            outPrimes.push_back(i);
            auto tmp = i;
            while (tmp <= max) {
                check[tmp] = true;
                tmp += i;
            }
        }
    }
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

int GetDigitNum(int num, int nary) {
    if (num == 0) {
        return 1;
    }
    auto digVal = 1;
    auto dig = 0;
    while (digVal <= num) {
        digVal *= nary;
        dig++;
    }
    return dig;
}
int GetDigitNum(long long num, int nary) {
    if (num == 0) {
        return 1;
    }
    long long digVal = 1;
    auto dig = 0;
    while (digVal <= num) {
        digVal *= nary;
        dig++;
    }
    return dig;
}

// 10進数からn進数への変換
std::string ConvertNary(long long num, int n) {
    std::string str;
    auto dig = GetDigitNum(num, n);
    long long div = Pow((long long)n, dig - 1);
    repeat(i, dig) {
        auto curDig = num / div;
        char c;
        if (curDig < 10) {
            c = '0' + curDig;
        } else {
            c = 'a' + curDig - 10;
        }
        str.push_back(c);
        num -= div * curDig;
        div /= n;
    }
    return str;
}
// n進数から10進数への変換
long long ConvertDecimal(std::string num, int n) {
    int dig = num.length();
    long long v = 1;
    long long dec = 0;
    repeat(i, dig) {
        auto curDig = 0;
        auto c = num[dig - 1 - i];
        if (c >= '0' && c <= '9') {
            curDig = c - '0';
        } else {
            curDig = c - 'a';
        }
        dec += curDig * v;
        v *= n;
    }
    return dec;
}
// nのexp乗をdivで割ったあまりを繰り返し二乗法で求める
long long PowBinary(long long n, long long exp, long long div) {
    auto bits = ConvertNary(exp, 2);
    int size = bits.length();

    // powMod[i] = Pow((k - 2), Pow(2, i)) % div
    std::vector<long long> powMod(size);
    powMod[0] = n;
    for (auto i = 1; i < size; i++) {
        powMod[i] = powMod[i - 1] * powMod[i - 1] % div;
    }
    long long result = 1;
    repeat(i, size) {
        if (bits[size - 1 - i] == '1') {
            result = result * powMod[i] % div;
        }
    }
    return result;
}

int BitCount(int n) {
    auto count = 1;
    while (n > (1 << count)) {
        count++;
    }
    return count + 1;
}

int BitCount(long long n) {
    auto count = 1;
    while (n > ((long long)1 << count)) {
        count++;
    }
    return count + 1;
}

int OnBitCount(int n) {
    auto size = BitCount(n);
    auto count = 0;
    repeat(i, size) {
        if (bittest(n, i)) count++;
    }
    return count;
}
int OnBitCount(long long n) {
    auto size = BitCount(n);
    auto count = 0;
    repeat(i, size) {
        if (bittest(n, i)) count++;
    }
    return count;
}

std::string ReplaceBitToText(int n, const char* zero, const char* one, int digit) {
    auto maxDigit = digit != 0 ? digit : BitCount(n);
    std::string str;
    for (auto dig = 0; dig < maxDigit; dig++) {
        str.append((n & 1 << dig) ? one : zero);
    }
    return str;
}
std::string ReplaceBitToText(long long n, const char* zero, const char* one, int digit) {
    auto maxDigit = digit != 0 ? digit : BitCount(n);
    std::string str;
    for (auto dig = 0; dig < maxDigit; dig++) {
        str.append((n & ((long long)1 << dig)) ? one : zero);
    }
    return str;
}

double DegToRad(double degree) {
    return degree * M_PI / 180.0;
}

double RadToDeg(double radian) {
    return radian * 180.0 / M_PI;
}

// 条件を満たす最大の整数を求める
// fn : 条件式
int BinarySearchMax(int lower, int upper, std::function<bool(int)> fn) {
    while (upper - lower > 1) {
        auto next = (upper + lower) / 2;
        if (fn(next)) {
            lower = next;
        } else {
            upper = next;
        }
    }
    return lower;
}

// 条件を満たす最小の整数を求める
// fn : 条件式
int BinarySearchMin(int lower, int upper, std::function<bool(int)> fn) {
    while (upper - lower > 1) {
        auto next = (upper + lower) / 2;
        if (fn(next)) {
            upper = next;
        } else {
            lower = next;
        }
    }
    return upper;
}

std::vector<std::vector<int>> MakeTree(const std::vector<Edge>& edges) {
    return MakeGraph(edges, edges.size() + 1);
}
std::vector<std::vector<int>> MakeTree(const std::vector<TwoNums<int>>& edges) {
    return MakeGraph(edges, edges.size() + 1);
}

std::vector<std::vector<int>> MakeGraph(const std::vector<Edge>& edges, int size) {
    int length = edges.size();
    std::vector<std::vector<int>> graph;
    graph.resize(size);
    repeat(i, length) {
        graph[edges[i].from].push_back(edges[i].to);
        graph[edges[i].to].push_back(edges[i].from);
    }
    return graph;
}
std::vector<std::vector<int>> MakeGraph(const std::vector<TwoNums<int>>& edges, int size) {
    int length = edges.size();
    std::vector<std::vector<int>> graph;
    graph.resize(size);
    repeat(i, length) {
        graph[edges[i].first].push_back(edges[i].second);
        graph[edges[i].second].push_back(edges[i].first);
    }
    return graph;
}
std::vector<std::vector<int>> MakeGraph(const std::vector<ThreeNums<int>>& edges, int size) {
    int length = edges.size();
    std::vector<std::vector<int>> graph;
    graph.resize(size);
    repeat(i, length) {
        graph[edges[i].first].push_back(edges[i].second);
        graph[edges[i].second].push_back(edges[i].first);
    }
    return graph;
}

std::vector<std::vector<int>> MakeGraphDirected(const std::vector<Edge>& edges, int size) {
    int length = edges.size();
    std::vector<std::vector<int>> graph;
    graph.resize(size);
    repeat(i, length) {
        graph[edges[i].from].push_back(edges[i].to);
    }
    return graph;
}
std::vector<std::vector<TwoNums<int>>> MakeWeightedGraph(const std::vector<Edge>& edges, int size) {
    int length = edges.size();
    std::vector<std::vector<TwoNums<int>>> graph;
    graph.resize(size);
    repeat(i, length) {
        graph[edges[i].from].push_back(TwoNums<int>(edges[i].to, edges[i].weight));
        graph[edges[i].to].push_back(TwoNums<int>(edges[i].from, edges[i].weight));
    }
    return graph;
}
std::vector<std::vector<TwoNums<int>>> MakeWeightedGraph(const std::vector<ThreeNums<int>>& edges, int size) {
    int length = edges.size();
    std::vector<std::vector<TwoNums<int>>> graph;
    graph.resize(size);
    repeat(i, length) {
        graph[edges[i].first].push_back(TwoNums<int>(edges[i].second, edges[i].third));
        graph[edges[i].second].push_back(TwoNums<int>(edges[i].first, edges[i].third));
    }
    return graph;
}

std::vector<int> GetGraphDistance(const std::vector<std::vector<TwoNums<int>>>& graph, int start) {
    std::vector<int> distance(graph.size(), INT_MAX);
    std::queue<int> que;
    que.push(start);
    distance[start] = 0;
    while (!que.empty()) {
        auto current = que.front();
        que.pop();
        foreach(road, graph[current]) {
            if (distance[road.first] > distance[current] + road.second) {
                distance[road.first] = distance[current] + road.second;
                que.push(road.first);
            }
        }
    }
    return distance;
}


void GetTreeDistanceDFS(const std::vector<std::vector<int>>& tree, int current, int before, int length, std::vector<int>* outLength) {
    assert(tree.size() == (*outLength).size());

    (*outLength)[current] = length;
    length++;

    for (auto next : tree[current]) {
        if (next == before) continue;
        GetTreeDistanceDFS(tree, next, current, length, outLength);
    }
}

std::vector<int> GetTreeDistance(const std::vector<std::vector<int>>& tree, int root) {
    std::vector<int> distance(tree.size(), -1);
    GetTreeDistanceDFS(tree, root, -1, 0, &distance);
    return distance;
}
