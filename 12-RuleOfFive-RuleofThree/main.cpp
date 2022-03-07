#include "RuleofFive-Ruleofthree.h"
#include <iostream>
// void ruleOfFive(){
//   RuleOfFive o1{"abc"}; // normal constructor
//     std::cout << o1 << ' ';

//     RuleOfFive o2{ o1 }; // I. uses copy constructor
//     std::cout << o2 << ' ';

//     RuleOfFive o3("def");
//     std::cout << o3 << ' ';

//     o3 = o2; // III. uses copy assignment
//     std::cout << o3 << ' ';
// }

void ruleOfThree(){
    RuleOfThree o1{"abc"}; // normal constructor
    std::cout << o1 << ' ';

    auto o2{ o1 }; // I. uses copy constructor
    std::cout << o2 << ' ';

    RuleOfThree o3("def");
    std::cout << o3 << ' ';

    o3 = o2; // III. uses copy assignment
    std::cout << o3 << ' ';
}

int main(){

    ruleOfThree();
    
}