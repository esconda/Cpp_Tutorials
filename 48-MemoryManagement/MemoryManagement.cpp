// Author: Burak Doğançay
#include "MemoryManagement.h"

MemoryManagement::MemoryManagement()
{
}

void MemoryManagement::freeStorage(){
    //The term 'heap' is a general computing term meaning an area of memory from which portions can be allocated
    //and deallocated independently of the memory provided by the stack
    //Areas of memory allocated from the Free Store may live longer than the original scope in which it was allocated.
    //Data too large to be stored on the stack may also be allocated from the Free Store.
    float *foo = nullptr;
    *foo = new float; // Allocates memory for a float
    float bar; // Stack allocated

    delete foo; // Deletes the memory for the float at pF, invalidating the pointer
    foo = nullptr; // Setting the pointer to nullptr after delete is often considered good practice

}

void MemoryManagement::freeStorageExOne(){
 /* It's also possible to allocate fixed size arrays with new and delete, with a slightly different syntax. Array allocation is
    not compatible with non-array allocation, and mixing the two will lead to heap corruption. Allocating an array also
    allocates memory to track the size of the array for later deletion in an implementation-defined way. */
    // Allocates memory for an array of 256 ints
    int *foo = new int[256];
    // Deletes an array of 256 ints at foo
    delete[] foo;

    //C++14 added std::make_unique to the STL, changing the recommendation to favor std::make_unique or
    //std::make_shared instead of using naked new and delete.

}

void MemoryManagement::placementNew(){
 /* There are situations when we don't want to rely upon Free Store for allocating memory and we want to use custom
    memory allocations using new.
    For these situations we can use Placement New, where we can tell `new' operator to allocate memory from a preallocated memory location*/
 
    int a4byteInteger;
    char *a4byteChar = new (&a4byteInteger) char[8];
    /* In this example, the memory pointed by a4byteChar is 4 byte allocated to 'stack' via integer variable a4byteInteger.
    The benefit of this kind of memory allocation is the fact that programmers control the allocation. In the example
    above, since a4byteInteger is allocated on stack, we don't need to make an explicit call to 'delete a4byteChar`. */

    int *a8byteDynamicInteger = new int[2];
    char *a8byteChar = new (a8byteDynamicInteger) char[8];
    /* In this case, the memory pointer by a8byteChar will be referring to dynamic memory allocated by
    a8byteDynamicInteger. In this case however, we need to explicitly calldelete a8byteDynamicInteger to release the
    memory */
}

void void MemoryManagement::stack(){

    //Data stored on the stack is only valid so long as the scope that allocated the variable is still active
    /* int* pA = nullptr;
    void foo() {
        int b = *pA;
        pA = &b;
    }

    int main() {
        int a = 5;
        pA = &a;
        foo();
        //Undefined behavior, the value pointed to by pA is no longer in scope
        a = *pA;
    } */
    
}