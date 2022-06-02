#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <numeric>
#include <map>
#include <climits>
#define _USE_MATH_DEFINES
#include <math.h>

// �}�N��
#define SIZEOF(a) (sizeof(a)/sizeof(a[0]))
#define repeat(itr, count) for(auto itr = 0; itr < count; itr++ )
#define foreach(itr, vec) for(auto&& itr : vec)
#define bitrepeat(itr, maxbit) for(auto itr = 0; itr < (1LL << maxbit); itr++ )
#define bittest(num, bit) (num & (1LL << bit))

// �����񑀍�
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
template <>
std::vector<std::string> Split(std::string str, const char* del);

template <typename ... Args>
std::string format(const char* fmt, Args ... args) {
    size_t len = std::snprintf(nullptr, 0, fmt, args ...);
    std::vector<char> buf(len + 1);
    std::snprintf(&buf[0], len + 1, fmt, args ...);
    return std::string(&buf[0], &buf[0] + len);
}

// int������ƃo�O��\�������邽�ߔ񐄏�
// int / int �͐؂�̂ĂȂ̂ŁA��{�I�ɂ���𗘗p����ق������S
int RoundUp(float input);
int RoundDown(float input);
int Round(float input);

// �����̐؂�グ
template <typename T>
T RoundUp(T in, T div) {
    T result = (in + div - 1) / div;
    return result;
}

template <typename T>
inline T Max(T i, T j) {
    return(i > j ? i : j);
}
// vector���̍ő�l���擾
template <typename T>
inline T Max(const std::vector<T>& vec) {
    return *std::max_element(vec.begin(), vec.end());
}
// vector���̍ő�l�̃C���f�b�N�X���擾
template <typename T>
inline size_t ArgMax(const std::vector<T>& vec) {
    auto maxIt = std::max_element(vec.begin(), vec.end());
    return std::distance(vec.begin(), maxIt);
}

template <typename T>
inline T Min(T i, T j) {
    return(i < j ? i : j);
}
// vector���̍ŏ��l���擾
template <typename T>
inline T Min(std::vector<T> vec) {
    return *std::min_element(vec.begin(), vec.end());
}
// vector���̍ŏ��l�̃C���f�b�N�X���擾
template <typename T>
inline size_t ArgMin(const std::vector<T>& vec) {
    auto minIt = std::min_element(vec.begin(), vec.end());
    return std::distance(vec.begin(), minIt);
}

long long Sum(const std::vector<int>& vec);
long long Sum(const std::vector<long long>& vec);
double Sum(const std::vector<double>& vec);

template <typename T>
std::vector<T> GetDivisors(T num) {
    std::vector<T> divs;
    auto cal = 1;
    auto root = sqrt(num);
    auto i = 1;
    while (i <= root) {
        if (num % i == 0) {
            auto rest = num / i;
            divs.push_back(i);
            if (rest != i) {
                divs.push_back(rest);
            }
        }
        i++;
    }
    return divs;
}

template <typename T>
bool IsPrime(T num) {
    T i = 2;
    auto root = sqrt(num);
    while (i <= root) {
        if (num % i == 0) {
            return false;
        }
        i++;
    }
    return true;
}

template <typename T>
void GetPrimes(T num, std::map<T, int>* outMap) {
    auto i = 2;
    auto root = sqrt(num);
    while (i <= root) {
        if (num % i == 0) {
            (*outMap)[i]++;
            num /= i;
            root = sqrt(num);
            continue;
        }
        i++;
    }
    (*outMap)[num]++;
}

// max�ȉ��̑f�������ׂċ��߂�
void GetPrimesInRange(int max, std::vector<int>& outPrimes);

template <typename T>
T LCM(T a, T b) {
    if (a < b) {
        auto tmp = a;
        a = b;
        b = tmp;
    }
    while (a % b != 0) {
        auto rest = a % b;
        a = b;
        b = rest;
    }
    return b;
}

template <typename T>
T GCD(T a, T b) {
    auto lcm = LCM(a, b);
    auto result = a / lcm * b;
    return result;
}

////   ���v�Z   ////
std::vector<int> GetDigits(int num);
std::vector<int> GetDigits(long long num);

// 10�i���p
template <typename T>
int GetDigitNum(T num) {
    auto str = std::to_string(num);
    return str.size();
}
int GetDigitNum(int num, int nary);
int GetDigitNum(long long num, int nary);

// 10�i������n�i���ւ̕ϊ�
std::string ConvertNary(long long num, int n);
// n�i������10�i���ւ̕ϊ�
long long ConvertDecimal(std::string num, int n);

constexpr long long Pow(long long num, int count) {
    long long result = 1;
    repeat(i, count) {
        result *= num;
    }
    return result;
}
constexpr long long Pow(int num, int count) {
    return Pow((long long)num, count);
}

// n��exp���pow�Ŋ��������܂���J��Ԃ����@�ŋ��߂�
long long PowBinary(long long n, long long exp, long long div);

////   vector����   ////
// �����\�[�g
template <typename T>
std::vector<T> Sort(const std::vector<T>& array) {
    auto sortedArray = array;
    std::sort(sortedArray.begin(), sortedArray.end());
    return sortedArray;
}
template <typename T>
void Sort(const std::vector<T>& array, std::vector<T>* outArr) {
    *outArr = array;
    std::sort(outArr->begin(), outArr->end());
}

// �~���\�[�g
template <typename T>
std::vector<T> SortInv(const std::vector<T>& array) {
    auto sortedArray = array;
    std::sort(sortedArray.begin(), sortedArray.end(), std::greater<T>{});
    return sortedArray;
}
template <typename T>
void SortInv(const std::vector<T>& array, std::vector<T>* outArr) {
    *outArr = array;
    std::sort(outArr->begin(), outArr->end(), std::greater<T>{});
}

// compare 0->first, 1->second
//template <typename T>
//void SortTwoNums(const std::vector<TwoNums<T>> array, std::vector<TwoNums<T>>* outArr, int compare) {
//    auto sortedArray = array;
//    if (compare == 0) {
//        std::sort(
//            sortedArray.begin(),
//            sortedArray.end(),
//            [array](const int& x, const int& y) {return array[x].first < array[y].first; }
//        );
//    } else {
//
//    }
//}

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

// do {} while (Enumerate(vec)); �̌`�Ŏg�p���܂�
template <typename T>
bool Enumerate(std::vector<T>& vec) {
    return std::next_permutation(vec.begin(), vec.end());
}

void AllCombinationImpl(std::vector<int> all, int num, std::vector<std::vector<int>>* outVec);

template <typename T>
struct TwoNums {
    T first;
    T second;

    TwoNums()
        : first(0)
        , second(0)
    {}

    TwoNums(T x, T y)
        : first(x)
        , second(y)
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

    ThreeNums(T x, T y, T z)
        : first(x)
        , second(y)
        , third(z)
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

    Point2D(T inX, T inY)
        : x(inX)
        , y(inY)
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

    Point3D(T inX, T inY, T inZ)
        : x(inX)
        , y(inY)
        , z(inZ)
    {}
};
double DegToRad(double degree);

double RadToDeg(double radian);

template <typename T>
class Matrix {
public:
    Matrix()
        : mat()
    {}
    Matrix(int row)
        : mat(row)
    {}
    Matrix(int row, int col)
        : mat(row, std::vector<T>(col, 0))
    {}
    Matrix(int row, int col, T init)
        : mat(row, std::vector<T>(col, init))
    {}

    std::vector<T>& operator [](int n) { return mat[n]; }
    const std::vector<T>& operator [](int n) const { return mat[n]; }
    size_t size() const { return mat.size(); }

    typedef typename std::vector<std::vector<T>>::iterator iterator;
    typedef typename std::vector<std::vector<T>>::const_iterator const_iterator;
    iterator begin() { return mat.begin(); }
    const_iterator begin() const { return mat.begin(); }
    iterator end() { return mat.end(); }
    const_iterator end() const { return mat.end(); }
private:
    std::vector<std::vector<T>> mat;
};

template <typename T>
double Distance(Point2D<T> p1, Point2D<T> p2) {
    double length = 0;
    length += (p1.x - p2.x) * (p1.x - p2.x);
    length += (p1.y - p2.y) * (p1.y - p2.y);
    return sqrt(length);
}

template <typename T>
double Distance(Point3D<T> p1, Point3D<T> p2) {
    double length = 0;
    length += (p1.x - p2.x) * (p1.x - p2.x);
    length += (p1.y - p2.y) * (p1.y - p2.y);
    length += (p1.z - p2.z) * (p1.z - p2.z);
    return sqrt(length);
}

template <typename T>
T ManhattanDistance(Point2D<T> p1, Point2D<T> p2) {
    T result = 0;
    result += abs(p1.x - p2.x);
    result += abs(p1.y - p2.y);
    return result;
}

template <typename T>
inline std::string NumToBitStr(T n) {
    std::string str;
    while (n > 0) {
        str.push_back('0' + (n & 1));
        n >>= 1;
    }
    std::reverse(str.begin(), str.end());
    return str;
}

// n��bit�ɂ����Ƃ��ɉ��r�b�g�K�v��
int BitCount(int n);
int BitCount(long long n);
// n��bit�ɂ����Ƃ��ɉ��r�b�g�����Ă��邩
int OnBitCount(int n);
int OnBitCount(long long n);

std::string ReplaceBitToText(int n, const char* zero, const char* one, int digit = 0);
std::string ReplaceBitToText(long long n, const char* zero, const char* one, int digit = 0);

// �����𖞂����ő�̐��������߂�
// fn : ������
int BinarySearchMax(int lower, int upper, std::function<bool(int)> fn);

// �����𖞂����ŏ��̐��������߂�
// fn : ������
int BinarySearchMin(int lower, int upper, std::function<bool(int)> fn);

template <typename T>
void Swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

// modint: mod �v�Z�� int �������悤�Ɉ�����\����
template<int MOD> struct ModNum {
    long long val;
    constexpr ModNum(long long v = 0) noexcept : val(v% MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr ModNum operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr ModNum operator + (const ModNum& r) const noexcept { return ModNum(*this) += r; }
    constexpr ModNum operator - (const ModNum& r) const noexcept { return ModNum(*this) -= r; }
    constexpr ModNum operator * (const ModNum& r) const noexcept { return ModNum(*this) *= r; }
    constexpr ModNum operator / (const ModNum& r) const noexcept { return ModNum(*this) /= r; }
    constexpr ModNum& operator += (const ModNum& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr ModNum& operator -= (const ModNum& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr ModNum& operator *= (const ModNum& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr ModNum& operator /= (const ModNum& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; Swap(a, b);
            u -= t * v; Swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const ModNum& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const ModNum& r) const noexcept {
        return this->val != r.val;
    }
    //friend constexpr ostream& operator << (ostream& os, const ModNum<MOD>& x) noexcept {
    //    return os << x.val;
    //}
    friend constexpr ModNum<MOD> modpow(const ModNum<MOD>& a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

struct Edge {
    int from;
    int to;
    int weight;

    Edge()
        : from(0)
        , to(0)
        , weight(0)
    {}

    Edge(int fr, int t)
        : from(fr)
        , to(t)
        , weight(0)
    {}

    Edge(TwoNums<int> two)
        : from(two.first)
        , to(two.second)
        , weight(0)
    {}

    Edge(int fr, int t, int w)
        : from(fr)
        , to(t)
        , weight(w)
    {}

    Edge(ThreeNums<int> three)
        : from(three.first)
        , to(three.second)
        , weight(three.third)
    {}
};

std::vector<std::vector<int>> MakeTree(const std::vector<Edge>& edges);
std::vector<std::vector<int>> MakeTree(const std::vector<TwoNums<int>>& edges);

std::vector<std::vector<int>> MakeGraph(const std::vector<Edge>& edges, int size);
std::vector<std::vector<int>> MakeGraph(const std::vector<TwoNums<int>>& edges, int size);
std::vector<std::vector<int>> MakeGraph(const std::vector<ThreeNums<int>>& edges, int size);
std::vector<std::vector<int>> MakeGraphDirected(const std::vector<Edge>& edges, int size);
std::vector<std::vector<TwoNums<int>>> MakeWeightedGraph(const std::vector<Edge>& edges, int size);
std::vector<std::vector<TwoNums<int>>> MakeWeightedGraph(const std::vector<ThreeNums<int>>& edges, int size);

// �d�ݕt���O���t�ł�start����e�_�ւ̋���
std::vector<int> GetGraphDistance(const std::vector<std::vector<TwoNums<int>>>& graph, int start = 0);

// ���������AGetTreeDistance���g�p���Ă�������
void GetTreeDistanceDFS(const std::vector<std::vector<int>>& tree, int current, int before, int length, std::vector<int>* outLength);
// �؂ɂ�����root����̋���
std::vector<int> GetTreeDistance(const std::vector<std::vector<int>>& tree, int root);

class UnionTree {
public:
    // N : �S�̂̃T�C�Y
    UnionTree(int N) : par(N) { //�ŏ��͑S�Ă����ł���Ƃ��ď�����
        for (int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // �f�[�^x��������؂̍����ċA�œ���Froot(x) = {x�̖؂̍�}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // x��y�̖؂𕹍�
        int rx = root(x); //x�̍���rx
        int ry = root(y); //y�̍���ry
        if (rx == ry) return; //x��y�̍�������(=�����؂ɂ���)���͂��̂܂�
        par[rx] = ry; //x��y�̍��������łȂ�(=�����؂ɂȂ�)���Fx�̍�rx��y�̍�ry�ɂ���
    }

    bool same(int x, int y) { // 2�̃f�[�^x, y��������؂������Ȃ�true��Ԃ�
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
private:
    std::vector<int> par; // par[i]:i�̐e�̔ԍ��@(��) par[3] = 2 : 3�̐e��2

};
