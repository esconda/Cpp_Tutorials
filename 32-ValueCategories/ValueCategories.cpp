#include "ValueCategories.h"

ValueCategories::ValueCategories()
{
}

void ValueCategories::rValueExamples(){
/*std::string has a constructor which takes a single parameter of type std::string&&, commonly called a "move
constructor". However, the value category of the expression str is not an rvalue (specifically it is an lvalue), so it
cannot call that constructor overload. Instead, it calls the const std::string& overload, the copy constructor.

Line 3 changes things. The return value of std::move is a T&&, where T is the base type of the parameter passed in.
So std::move(str) returns std::string&&. A function call who's return value is an rvalue reference is an rvalue
expression (specifically an xvalue), so it may call the move constructor of std::string. After line 3, str has been
moved from (who's contents are now undefined).
 */
    std::string str("init"); //1
    std::string test1(str); //2
    std::string test2(std::move(str));//3
    
    std::cout<<"Base string val str: "<<str<<std::endl;
    std::cout<<"Test1 String Val : "<<test1<<std::endl;
    std::cout<<"Test2 String : "<<test2<<std::endl; 

    /* Line 4 passes a temporary to the assignment operator of std::string. This has an overload which takes a
std::string&&. The expression std::string("new value") is an rvalue expression (specifically a prvalue), so it
may call that overload. Thus, the temporary is moved into str, replacing the undefined contents with specific
contents.

Line 5 creates a named rvalue reference called str_ref that refers to str. This is where value categories get
confusing.
See, while str_ref is an rvalue reference to std::string, the value category of the expression str_ref is not an
rvalue. It is an lvalue expression. Yes, really. Because of this, one cannot call the move constructor of std::string
with the expression str_ref. Line 6 therefore copies the value of str into test3.
 */
    str = std::string("new value"); //4
    std::string &&str_ref = std::move(str); //5
    std::string test3(str_ref); //6

    std::cout<<"Base String overload :"<<str<<std::endl;
    std::cout<<"String Reference : "<<str_ref<<std::endl;
    std::cout<<"Test3 definition : "<<test3<<std::endl; 
}

void ValueCategories::xValueExample{
/*   An xvalue (eXpiring value) expression is an expression which has identity and represents an object which can be
implicitly moved from. The general idea with xvalue expressions is that the object they represent is going to be
destroyed soon (hence the "eXpiring" part), and therefore implicitly moving from them is fine. */
struct BaseStruct{ int n;};
struct BaseStruct baseStruct;

4; // prvalue: does not have an identity
baseStruct; // lvalue
baseStruct.n; // lvalue
std::move(baseStruct); // xvalue
std::forward<BaseStruct&>(baseStruct); // lvalue
BaseStruct{4}; // prvalue: does not have an identity
BaseStruct{4}.n; // xvalue: does have an identity and denotes resources
        // that can be reused
}

void ValueCategories::prValueExample(){
    /* A prvalue (pure-rvalue) expression is an expression which lacks identity, whose evaluation is typically used to
    initialize an object, and which can be implicitly moved from. These include, but are not limited to: */
    std::string str;
    str = std::string("123");// Expressions that represent temporary objects
                            //A function call expression that does not return a reference
                            //A literal (except a string literal - those are lvalues), such has 1, true, 0.5f, or 'a'
                            //A lambda expression
}

void ValueCategories::lValueExample(){
   /*  An lvalue expression is an expression which has identity, but cannot be implicitly moved from. Among these are
expressions that consist of a variable name, function name, expressions that are built-in dereference operator uses
and expressions that refer to lvalue references. */

//The typical lvalue is simply a name, but lvalues can come in other flavors as well:
struct X { ... };
X x; // x is an lvalue
X* px = &x; // px is an lvalue
*px = X{}; // *px is also an lvalue, X{} is a prvalue
X* foo_ptr(); // foo_ptr() is a prvalue
X& foo_ref(); // foo_ref() is an lvalue
//Additionally, while most literals (e.g. 4, 'x', etc.) are prValues string literals are lValues

}

void ValueCategories::glValueExample(){
/*     A glvalue (a "generalized lvalue") expression is any expression which has identity, regardless of whether it can be
moved from or not. This category includes lvalues (expressions that have identity but can't be moved from) and
xvalues (expressions that have identity, and can be moved from), but excludes prvalues (expressions without
identity).
If an expression has a name, it's a glvalue: */
    struct X { int n; };
    X foo();
    X x;
    x; // has a name, so it's a glvalue
    std::move(x); // has a name (we're moving from "x"), so it's a glvalue
                    // can be moved from, so it's an xvalue not an lvalue
    foo(); // has no name, so is a prvalue, not a glvalue
    X{}; // temporary has no name, so is a prvalue, not a glvalue
    X{}.n; // HAS a name, so is a glvalue. can be moved from, so it's an xvalue
}
