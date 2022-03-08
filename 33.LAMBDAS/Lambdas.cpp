#include "Lambdas.h"

Lambdas::Lambdas()
{
}

void Lambdas::lambdaDef(int i){
    [&]{};          // OK: by-reference capture default
    [&, i]{};       // OK: by-reference capture, except i is captured by copy
    //[&, &i] {};     // Error: by-reference capture when by-reference is the default
    [&, this] {};   // OK, equivalent to [&]
    [&, this, i]{}; // OK, equivalent to [&, i]
}

void Lambdas::lambdaDef2(int i){

    [=]{};          // OK: by-copy capture default
    [=, &i]{};      // OK: by-copy capture, except i is captured by reference
   // [=, *this]{};   // until C++17: Error: invalid syntax
                    // since c++17: OK: captures the enclosing S2 by copy
    [=, this] {};   // until C++20: Error: this when = is the default
                    // since C++20: OK, same as [=]
}

void Lambdas::captureList()
{
    // [] is the capture list .By default, variables of the enclosing scope cannot be accessed by a lambda. Capturing a
    //variable makes it accessible inside the lambda, either as a copy or as a reference
    int a = 0; // Define an integer variable
    auto f = [=](){ return a * 9; }; // Error: 'a' cannot be accessed
    auto l = [a](){ return a * 9; }; // OK, 'a' is "captured" by value
    auto d = [&a](){ return a++; }; // OK, 'a' is "captured" by reference
    // Note: It is the responsibility of the programmer
    // to ensure that a is not destroyed before the
    auto e = f();
}

void Lambdas::parameterList(){
//() is the parameter list, which is almost the same as in regular functions. If the lambda takes no arguments, these
//parentheses can be omitted (except if you need to declare the lambda mutable). These two lambdas are equivalent:
//{} is the body, which is the same as in regular functions.
    //auto call_foo = [x](x.foo();)
    //auto call_foo2 = [x]{ x.foo(); };
    /* The parameter list can use the placeholder type auto instead of actual types. By doing so, this argument behaves
like a template parameter of a function template. Following lambdas are equivalent when you want to sort a vector */
    //auto sort_cpp11 = [](std::vector<T>::const_reference lhs, std::vector<T>::const_reference rhs) {return lhs < rhs; };
    //auto sort_cpp14 = [](const auto &lhs, const auto &rhs) { return lhs < rhs; }; 
}
void Lambdas::callingLambda(){
    int multiplier = 5;
    int multiplierThree = 3;

    auto timesFive = [multiplier](int a) { return a * multiplier; };
    std::function<int(int a)> timesThree = [multiplierThree](int a) { return a * multiplierThree; };//Alternative of above


    std::cout << timesFive(2)<<"  :  "<< timesThree(3)<<std::endl; // Prints 10 and 9

    multiplier = 15;
    std::cout << timesFive(2) << std::endl; // Still prints 2*5 == 10

    //You can also manually specify the return type using the following syntax:
    []() -> bool { return true; };
}

void Lambdas::specifiyingReturnType(){
    //double is explicitly specified
    auto returnDouble = [](int value) -> double {
        if (value < 10) {
            return 1;
        } 
        else {
            return 1.5;
        }
    };
    std::cout<<returnDouble(12)<<std::endl;

}

void Lambdas::captureByValue(){
    int a = 0;
    [a]() {
        std::cout<< "Capture By Value : "<< a << std::endl;
        return a; // Ok, 'a' is captured by value

    };
}

void Lambdas::captureByValueSecond(){
    int a = 5 ;
    auto plus5Val = [a] (void) { return a + 5 ; } ;
    auto plus5Ref = [&a] (void) {return a + 5 ; } ;
    a = 7 ;
    std::cout << a << ", value " << plus5Val() << ", reference " << plus5Ref() ;
    // The result will be "7, value 10, reference 12"
}

void Lambdas::recursiveLambdas(){
    //We can have a lambda capture a reference to a not-yet constructed std::function:
    std::function<int(int, int)> gcd = [&](int a, int b){
                return b == 0 ? a : gcd(b, a%b);
            };
    std::cout<<gcd(4,5)<<std::endl;
}

void Lambdas::defaultCapture(){
    int a = 1;
    int b = 2;
    // Default capture by value
    [=]() { return a + b; }; // OK; a and b are captured by value
    // Default capture by reference
    [&]() { return a + b; }; // OK; a and b are captured by reference
}
void Lambdas::classLambdaEx(){
    auto lambdaDef = [](Lambdas &lambdaClass, int variable){
            // modification of a private member variable
            lambdaClass.lambdaStruct.lambdaVariable = 30;
    };
    lambdaDef(*this,50);
    std::cout<<"Lambda Class Variable : "<<this->lambdaStruct.lambdaVariable<<std::endl;
}

void Lambdas::captureByReference(){
  /*   If you precede a local variable's name with an &, then the variable will be captured by reference. Conceptually, this
means that the lambda's closure type will have a reference variable, initialized as a reference to the corresponding
variable from outside of the lambda's scope. Any use of the variable in the lambda body will refer to the original
variable: */
    int a = 0;

    auto set=[&a]() mutable {
        a = 20;
    };
    set();
    std::cout<<"Reference var : "<<a<<std::endl;

}

void Lambdas::genericLambdas(){
    auto twice = [](auto x){ return x; };
    int i = twice(2); // i == 4
    std::string s = twice("hello"); // s == "hellohello"
    std::cout<<"Generic Variables : "<<i <<" : "<<s<<std::endl;

    //Lambda functions can be variadic and perfectly forward their arguments:
    //auto lam = [](auto&&... args){return f(decltype(args)(args)...);};
}

void Lambdas::generilizedCapture(){
    std::unique_ptr<Lambdas> p = std::make_unique<Lambdas>();
    auto lamb = [p = std::move(p)]() //Overrides capture-by-value of `p`.
    {
        p->genericLambdas();
    };
    auto lamb_move = std::move(lamb); //legal.
    lamb_move();
    
}