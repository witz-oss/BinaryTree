#ifndef BINARYTREE_QUICKSORT_H
#define BINARYTREE_QUICKSORT_H
#include <iostream>
#include <vector>
template<class T>
void swap(T* a, T* b)
{
    T tmp{ std::move(*a) };
    *a = std::move(*b);
    *b = std::move(tmp);
}

//typename std::enable_if<has_const_iterator<Container>::value void>::type
//template<typename C, typename T = typename C::value_type>
//template<typename C, typename T = std::decay_t <decltype(*begin(std::declval<C>()))>, typename = std::enable_if_t< std::is_convertible_v<T, int>>>
//template<typename C, typename T = std::decay_t<decltype(*begin(std::declval<C>()))>>
void quickSort(std::vector<int>& vector, int LOW, int HIGH)
{
    int low{ LOW };
    int high{ HIGH };
    int average{ (vector[low] + vector[high - 1u]) / 2 };

    while (low <= high){
        while (vector[low] < average)
            low++;
        while (vector[high] > average)
            high--;
        if (low <= high){
            swap(&vector[low], &vector[high]);
            low++;
            high--;
        }
    }

    if (LOW < high)
        quickSort(vector, LOW, high);
    if (low < HIGH)
        quickSort(vector, low, HIGH);
}

#endif //BINARYTREE_QUICKSORT_H
