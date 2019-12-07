//Copyright 2019 <mmeshcher>
#ifndef INCLUDE_RUNNER_HPP_
#define INCLUDE_RUNNER_HPP_
#include <vector>
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <stdint.h>


#define MB 1024 * 1024

using std::vector;
enum Type
{
    Direct,
    Back,
    Random,
    Unknown
};
class Massive{
public:
    unsigned __int64 DirectPass(int* begin, int* end, int size, int count);
    unsigned __int64  BackPass(int* begin, int* end, int size, int count);
    unsigned __int64 RandomPass(int* begin, int* end, int size, int count);
    void StartLoop(double size, int count, int type);
};
#endif // INCLUDE_RUNNER_HPP_