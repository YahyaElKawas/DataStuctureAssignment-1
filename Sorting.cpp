#include<iostream>
// #include "Sorting.hpp"
#include "Student.cpp"
#include<vector>
using namespace std;



// template <class Iterator>
// inline void insertionSort(Iterator begin, Iterator end, FuncPtr func = nullptr)
// {
//     int n = end - begin;
//     for (Iterator it = begin+1; (it-begin) < n; it++) {
//         Iterator j = it-1;
//         bool value = (func == nullptr ? false : func(*(j+1), *j) );
//         while(j >= begin &&( value || *(j + 1) < *j)){
//             swap(*(j+1), *j);
//             j--;
//         } 
//     }
// }

template <class Iterator, class FuncPtr = nullptr_t>
inline void BubbleSort(Iterator begin, Iterator end, FuncPtr func = nullptr)
{
    int n = end - begin;
    for (Iterator it = begin; (it - begin) < n; ++it)
    {
        for (Iterator it2 = it + 1; (it2 - begin) < n; ++it2)
        {
            if constexpr (!is_same_v<FuncPtr,nullptr_t>)
            {
                if (func(*it, *it2))
                {
                    swap(*it, *it2);
                }
            }
            else
            {
                if (*it2 < *it)
                {
                    swap(*it, *it2);
                }
            }
        }
    }
}

template <class Iterator, class FuncPtr = nullptr_t>
inline void merge(Iterator begin,Iterator mid, Iterator end, FuncPtr func = nullptr)
{
    int size = end - begin;
    Iterator s1 = begin, s2 = mid + 1;
    Student tmp[size];
    for(int i = 0; i < size; ++i)    
    {
        if(s1 > mid)     // start1 is done
            tmp[i] = *s2++;
        else if(s2 >= end)   // start2 is done
            tmp[i] = *s1++;
        else if constexpr (!is_same_v<FuncPtr, nullptr_t>){
            if(func(*s1, *s2))
                tmp[i] = *s1++;
            else
                tmp[i] = *s2++;
        }
        else{
            if(*s1 < *s2)
                tmp[i] = *s1++;
            else
                tmp[i] = *s2++;
        }
    }

    Iterator cur = begin;
    for(int i = 0; i < size; ++i){
        *cur = tmp[i];
        cur++;
    }
}


template <class Iterator, class FuncPtr = nullptr_t>
inline void mergeSort(Iterator begin, Iterator end, FuncPtr func = nullptr)
{
    if(begin+1 == end || begin == end)
        return;

    int size = end - begin - 1;
    int middle = size/2;
    Iterator mid = begin+middle;
    mergeSort(begin, mid+1, func);
    mergeSort(mid+1, end, func);

    merge(begin, mid, end, func);
}

template <class Iterator, class FuncPtr = nullptr_t>
inline Iterator make_Pivot(Iterator begin, Iterator end, FuncPtr func = nullptr)
{
    Iterator x = begin, i = begin;
    for(Iterator j = begin+1; j != end; ++j){
        if constexpr (!is_same_v<FuncPtr, nullptr_t>){
            if(func((*j), (*x))){
                i++;
                swap(*i, *j);
            }
        }
        else{
            if(*j < *x){
                i++;
                swap(*i, *j);
            }
        }
    }
    swap(*i, *begin);
    return i;
}


template <class Iterator, class FuncPtr = nullptr_t >
inline void quickSort(Iterator begin, Iterator end, FuncPtr func = nullptr)
{
    if(begin+1 >= end)
        return;

    Iterator pavoit = make_Pivot(begin, end, func);
    quickSort(begin, pavoit, func);
    quickSort(pavoit+1, end, func);
}