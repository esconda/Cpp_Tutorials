#include "StdVariantAny.h"

VariantExample::StdVariant::StdVariant()
{
}

void VariantExample::StdVariant::variantBasicExample()
{

    std::variant<int, double, std::string> tVariable;
    tVariable = "Variant Variable is string";
    std::cout << "Variant Variable type is : " << std::get<std::string>(tVariable) <<" : "<<std::get_if<std::string>(&tVariable)<< std::endl; //std::get<decltype(std::string)> is not working

    tVariable = 42;
    std::cout << "Variant Variable is : " << std::get<int>(tVariable) << std::endl;

    tVariable = 50.5;
    std::cout << "Variant Variable is : " << std::get<double>(tVariable) << std::endl;
}

AnyExample::StdAny::StdAny()
{
}

void AnyExample::StdAny::anyBasicExample()
{
    std::any tVariable;
    tVariable = std::string("Variable is string");

    std::cout << "Any Variable type is : " << std::any_cast<std::string>(tVariable) << std::endl;

    tVariable = int(42);
    std::cout << "Any Variable is : " << std::any_cast<int>(tVariable) << std::endl;

    tVariable = double(50.5);
    std::cout << "Any Variable is : " << std::any_cast<double>(tVariable) << std::endl;

    try
    {
        std::cout << std::any_cast<float>(tVariable) << "\n";
    }
    catch (const std::bad_any_cast &)
    {
        std::cout << "Wrong Type!\n";
    }
}

SetMultiSetExample::StdSetMultiset::StdSetMultiset()
{
}

void SetMultiSetExample::StdSetMultiset::setMultisetBasicExample()
{
    //DEFAULT SORT
    std::set<std::string> sut({"1", "2", "5", "13", "7", "290"});
    std::cout << "### Default sort on std::set<std::string> :" << std::endl;
    for (auto &&data : sut)
        std::cout << data << std::endl;

    //CUSTOM SORT
    std::set<std::string, custom_compare> sut_custom({"1", "2", "5", "23", "6", "290"}, custom_compare{}); //< Compare object optional as its default constructible.
    std::cout << std::endl
              << "### Custom sort on set :" << std::endl;
    for (auto &&data : sut_custom)
        std::cout << data << std::endl;

    //LAMBDA SORT
    auto compare_via_lambda = [](auto &&lhs, auto &&rhs)
    { return lhs > rhs; };
    using set_via_lambda = std::set<std::string, decltype(compare_via_lambda)>;
    set_via_lambda sut_reverse_via_lambda({"1", "2", "5", "23", "6", "290"},
                                          compare_via_lambda);
    std::cout << std::endl
              << "### Lambda sort on set :" << std::endl;
    for (auto &&data : sut_reverse_via_lambda)
        std::cout << data << std::endl;
}

void SetMultiSetExample::StdSetMultiset::setMultisetOp(){
    std::set<std::string> sut({"10", "20", "30", "40", "50", "60"});

    std::set<std::string>::iterator it = sut.find("30"); // find variable from sut set
    sut.erase(it);// erase found variable from sut

    std::cout << std::endl
              << "### Erasing :" << std::endl;
    for (auto &&data : sut)
        std::cout << data << std::endl;
}