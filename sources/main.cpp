//Copyright 2019 <mmeshcher>

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <stdint.h>

#define MB 1024 * 1024

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

unsigned __int64 DirectPass(int* begin, int* end, int size, int count)
{
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    unsigned __int64 avg = 0;
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

unsigned __int64 BackPass(int* begin, int* end, int size, int count)
{
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    unsigned __int64 avg = 0;
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

unsigned __int64 RandomPass(int* begin, int* end, int size, int count)
{
    int* array = new int[size];
    for(int i = 0; i < size; i++) array[i] = i;
    for(int i = 0; i < size; i++) std::swap(array[i], array[rand() % size]);
    
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    unsigned __int64 avg = 0;
    
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
    srand (time(0));
    int buf_len = (int ) (MB * size / 4);
    int* buf = new int[buf_len];
    for (int i = 0; i < buf_len; i++) buf[i] = rand();
    for (int i = 0; i < buf_len; i++) {
        buf[i] = buf[i];
    }
    unsigned __int64 avg = 0;
    switch (type) {
        case Direct:
            avg = DirectPass(buf, buf + buf_len, buf_len ,count);
            break;
        case Back:
            avg = BackPass(buf, buf + buf_len, buf_len ,count);
            break;
        case Random:
            avg = RandomPass(buf, buf + buf_len, buf_len ,count);
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



int main(int argc, const char * argv[]) {
    int cycles_count = 5;
    double cache_size[] = { 0.5, 2, 4, 8, 12 };
    for (int type = Direct; type != Unknown; type++)
    {
        std::cout << ConvertType(type) << '\n';
        std::cout << "======================" << '\n';
        StartLoop(cache_size[0], cycles_count, type);
        std::cout << "======================" << '\n';
        StartLoop(cache_size[1], cycles_count, type);
        std::cout << "======================" << '\n';
        StartLoop(cache_size[2], cycles_count, type);
        std::cout << "======================" << '\n';
        StartLoop(cache_size[3], cycles_count, type);
        std::cout << "======================" << '\n';
        StartLoop(cache_size[4], cycles_count, type);
        std::cout << "======================" << '\n';
    }
    return 0;
}
