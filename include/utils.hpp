#ifndef UTILS_H
#define UTILS_H

#include <vector>
template <typename T>
void printVector(const std::vector<T> &vec)
{
    std::cout << "[ ";
    for (const auto &el : vec)
        std::cout << el << ' ';
    std::cout << "] : len " << vec.size();
    std::cout << std::endl;
}

template <typename T>
void print(T val)
{
    std::cout << val << std::endl;
}

#endif