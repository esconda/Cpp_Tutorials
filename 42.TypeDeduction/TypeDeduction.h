//Author : Burak Dogancay
#ifndef TYPEDEDUCTION_H
#define TYPEDEDUCTION_H
#include <iostream>
#include <vector>
#include <functional>




class TypeDeduction
{
public:
    TypeDeduction();

    void autoTypeDeduction();
    void dclTypeAuto();
    void anotherAutoTypeDedeuction();
    

    //Template parameter deduction for constructors
    /* template <class Iter>
    vector(Iter, Iter) -> vector<typename iterator_traits<Iter>::value_type>
    
    int array[] = {1, 2, 3};
    std::vector v(std::begin(array), std::end(array)); // deduces std::vector<int> */

    //Template Type Deduction
    template<typename T>
    void f(T& param); //param is a reference
    void templateTypeDeduction();

    
    
};
#endif