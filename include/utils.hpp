#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <map>
#include <vector>

template <typename T> void printVector(const std::vector<T> &vec) {
    std::cout << "[ ";
    for (const auto &el : vec)
        std::cout << el << ' ';
    std::cout << "] : len " << vec.size();
    std::cout << std::endl;
}

template <typename T> void print(T val) { std::cout << val << std::endl; }

template <typename K, typename V> void printMap(const std::map<K, V> &m) {
    std::cout << "{ ";
    for (const auto &[key, value] : m)
        std::cout << key << ": " << value << " ";
    std::cout << "} : size " << m.size() << std::endl;
}

#endif
