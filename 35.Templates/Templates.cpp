#include "Templates.h"
template <typename T>
Templates<T>::Templates() : mNumber(0)
{
}

template <typename T>
void Templates<T>::setNum(T pNumber)
{
    mNumber = pNumber;
}

template <typename T>
T Templates<T>::plus1() const
{
    return mNumber + 1;
}
template <typename T>
template<typename Type>
void Templates<T>::printSum(Type add1, Type add2)
{
    std::cout << (add1 + add2) << std::endl;
}