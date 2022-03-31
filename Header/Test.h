#ifndef BINARYTREE_TEST_H
#define BINARYTREE_TEST_H
#include <iostream>

void print_test(const bool& successful, const std::string& testType, const std::string& description, const std::string& expected = "", const std::string& actual = "")
{
    if (!successful)
        std::cout << "FAILED test ";
    else
        std::cout << "SUCCESSFUL test ";
    std::cout << testType << '(' << description << ')' << ", expected: " << expected << ", actual: " << actual << std::endl;
}

template<typename T>
void check(const T& exp, const T& act, const std::string& description, const bool& silent = false)
{
    const bool result{ exp == act };
    if (!silent)
        print_test(result, "compare", description, std::to_string(exp), std::to_string(act));
}

#endif //BINARYTREE_TEST_H
