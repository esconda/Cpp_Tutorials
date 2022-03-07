#include "IntegerSequence.h"
IntegerSequence::IntegerSequence()
{
}

void IntegerSequence::func(int i, std::string const &s)
{
    std::cout << "f(" << i << ", " << s << ")\n";
}

void IntegerSequence::func(int i, double d, std::string const &s)
{
    std::cout << "f(" << i << ", " << d << ", " << s << ")\n";
}

void IntegerSequence::func(char c, int i, double d, std::string const &s)
{
    std::cout << "f(" << c << ", " << i << ", " << d << ", " << s << ")\n";
}

void IntegerSequence::func(int i, int j, int k)
{
    std::cout << "f(" << i << ", " << j << ", " << k << ")\n";
}

template <typename Tuple, std::size_t... I>
void IntegerSequence::processSub(Tuple const &tuple, std::index_sequence<I...>)
{
    func(std::get<I>(tuple)...);
}

template <typename Tuple>
void IntegerSequence::process(Tuple const &tuple)
{
    processSub(tuple, std::make_index_sequence<std::tuple_size<Tuple>::value>());
}