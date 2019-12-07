//Copyright 2019 <mmeshcher>

#include <Runner.hpp>
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