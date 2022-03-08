#include "StdForwardList.h"

template <typename T>
std::ostream &operator<<(std::ostream &s, const std::forward_list<T> &v)
{
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto &e : v)
    {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}

StdForwardList::StdForwardList()
{
}

void StdForwardList::forwardListInit()
{
    // c++11 initializer list syntax:
    std::forward_list<std::string> words1{"the", "frogurt", "is", "also", "cursed"};
    std::cout << "words1: " << words1 << '\n';
    // words2 == words1
    std::forward_list<std::string> words2(words1.begin(), words1.end());
    std::cout << "words2: " << words2 << '\n';
    // words3 == words1
    std::forward_list<std::string> words3(words1);
    std::cout << "words3: " << words3 << '\n';
    // words4 is {"Mo", "Mo", "Mo", "Mo", "Mo"}
    std::forward_list<std::string> words4(5, "Mo");
    std::cout << "words4: " << words4 << '\n';
}

void StdForwardList::pairExample()
{
    //First Example
    std::vector<std::pair<int, std::string>> v = {{2, "baz"},
                                                  {2, "bar"},
                                                  {1, "foo"}};
    std::sort(v.begin(), v.end());
    for (const auto &p : v)
    {
        std::cout << "(" << p.first << "," << p.second << ") ";
        //output: (1,foo) (2,bar) (2,baz)
    }

    //Second Example
    std::pair<int, int> p = std::make_pair(1, 2);         //Creating the pair
    std::cout << p.first << " " << p.second << std::endl; //Accessing the elements

    //We can also create a pair and assign the elements later
    std::pair<int, int> p1;
    p1.first = 3;
    p1.second = 4;
    std::cout << p1.first << " " << p1.second << std::endl;

    //We can also create a pair using a constructor
    std::pair<int, int> p2 = std::pair<int, int>(5, 6);
    std::cout << p2.first << " " << p2.second << std::endl;
}
