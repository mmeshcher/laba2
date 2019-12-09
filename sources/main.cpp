//Copyright 2019 <mmeshcher>

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <stdint.h>
#include <stdlib.h>
#include <vector>

#define MB 1024 * 1024

static unsigned int seed;

enum Type
{
    Direct,
    Back,
    Random,
    Unknown
};

const char* ConvertType(int type)
{
    switch (type) {
        case Direct:
            return "Direct";
            break;
        case Back:
            return "Back";
            break;
        case Random:
            return "Random";
            break;
        default:
            return "Unknown";
            break;
    }
}

__uint64_t DirectPass(int* begin, int* end, int count)
{
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    __uint64_t avg = 0;
    for (int k = 0; k < count; k++){
        start = std::chrono::system_clock::now();
        for (auto i = begin; i != end; i++)
        {
            if (*i < 0) std::cout << i;
        }
        stop = std::chrono::system_clock::now();
        avg += std::chrono::duration_cast<std::chrono::microseconds>
        (stop-start).count();
    }
    avg /= count;
    return avg;
}

__uint64_t BackPass(int* begin, int* end, int count)
{
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    __uint64_t avg = 0;
    for (int k = 0; k < count; k++){
        start = std::chrono::system_clock::now();
        for (auto i = end - 1; i != begin; i--)
        {
            if (*i < 0) std::cout << i;
        }
        stop = std::chrono::system_clock::now();
        avg += std::chrono::duration_cast<std::chrono::microseconds>
        (stop-start).count();
    }
    avg /= count;
    return avg;
}

__uint64_t RandomPass(int* begin, int size, int count)
{
    int* array = new int[size];
    for (int i = 0; i < size; i++) array[i] = i;
    for (int i = 0; i < size; i++) std::swap(array[i], array[rand() % size]);
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    __uint64_t avg = 0;
    for (int k = 0; k < count; k++){
        start = std::chrono::system_clock::now();
        for (auto i = 0; i < size; i++)
        {
            if (*(begin + array[i]) < 0) std::cout << i;
        }
        stop = std::chrono::system_clock::now();
        avg += std::chrono::duration_cast<std::chrono::microseconds>
        (stop-start).count();
    }
    avg /= count;
    return avg;
}
void StartLoop(double size, int count, int type)
{
    srand(time(0));
    int buf_len = static_cast<int>(MB * size / 4);
    int* buf = new int[buf_len];
    for (int i = 0; i < buf_len; i++) buf[i] = rand_r(&seed);
    for (int i = 0; i < buf_len; i++) {
        buf[i] = buf[i];
    }
    __uint64_t avg = 0;
    switch (type) {
        case Direct:
            avg = DirectPass(buf, buf + buf_len, count);
            break;
        case Back:
            avg = BackPass(buf, buf + buf_len, count);
            break;
        case Random:
            avg = RandomPass(buf, buf_len, count);
            break;
        default:
            avg = 0;
            break;
    }
    std::cout << "cache size : " << size << '\n';
    std::cout << "cycles : " << count << '\n';
    std::cout << "AVG time in microsecconds: " << avg << '\n';
    delete [] buf;
}



int main() {
    int i;
    std :: cout << "Введите количество уровней кэша ";
    std :: cin >> i;
    std :: vector<double>cache_size(i + 2);
    for (int k=1; k <= i; k++){
        std :: cout <<"№ " << k << "размер уровня равен = ";
        std :: cin >> cache_size[k];
    }
    cache_size[0] = 0.5*cache_size[1];
    cache_size[i+1] = 1.5*cache_size[i];
    int cycles_count = i+2;
    for (int type = Direct; type != Unknown; type++)
    {
        std :: cout << ConvertType(type) << '\n';
        std :: cout << "======================" << '\n';
        for (int k = 0; k < i+2; k++)
        {
            StartLoop(cache_size[k], cycles_count, type);
            std :: cout << "======================" << '\n';
        }
    }
    return 0;
}
