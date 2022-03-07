#include "StdMap.h"

StdMap::StdMap()
{
}

void StdMap::mapAccessingElements()
{

    std::map<std::string, int> ranking{std::make_pair("stackoverflow", 2),
                                       std::make_pair("docs-beta", 1)};

    //Inserting Elements
    ranking["stackoverflow"] = 3;
    ranking["docs-beta"] = 4;

    //Access Elements
    std::cout << "Ranking stackowverflow : " << ranking["stackoverflow"] << std::endl;
    std::cout << "Ranking docs-beta : " << ranking["docs-beta"] << std::endl;

    //Access Elements Alternative Methodes
    std::cout << "Ranking Stackoverflow Alternative :" << ranking.at("stackoverflow") << std::endl;
    std::cout << "Ranbking Stackoverflow Alyternative : " << ranking.at("docs-beta") << std::endl;
}

void StdMap::iteratorBaseAproach()
{

    std::multimap<int, std::string> mmp{std::make_pair(2, "stackoverflow"),
                                        std::make_pair(1, "docs-beta"),
                                        std::make_pair(2, "stackexchange")};

    auto it = mmp.begin();
    std::cout << it->first << " : " << it->second << std::endl; // Output: "1 : docs-beta"
    it++;
    std::cout << it->first << " : " << it->second << std::endl; // Output: "2 : stackoverflow"
    it++;
    std::cout << it->first << " : " << it->second << std::endl; // Output: "2 : stackexchange"

    // Example using rbegin()
    std::map<int, std::string> mp{std::make_pair(2, "stackoverflow"),
                                  std::make_pair(1, "docs-beta"),
                                  std::make_pair(2, "stackexchange")};
    auto it2 = mp.rbegin();
    std::cout << "R begin" << it2->first << " : " << it2->second << std::endl; // Output: "2 : stackoverflow"
    it2++;
    std::cout << "R begin" << it2->first << " : " << it2->second << std::endl; // Output: "1 : docs-beta"
}

void StdMap::insertingElements()
{
    std::map<std::string, size_t> mapVariables;
    /*     he insert() function returns a pair consisting of an iterator and a bool value:
    If the insertion was successful, the iterator points to the newly inserted element, and the bool value is
    true.
    If there was already an element with the same key, the insertion fails. When that happens, the iterator
    points to the element causing the conflict, and the bool is value is false. */
    mapVariables.insert({"UAV", 20});
    mapVariables.insert(std::make_pair("stackoverflow", 20));
    mapVariables.insert(std::pair<std::string, size_t>("UGV", 30));
    mapVariables.insert(std::map<std::string, size_t>::value_type("UHV", 50));

    auto success = mapVariables.insert({"UAV", 20});
    if (!success.second)
    {                                // we already have 'grapes' in the map
        success.first->second += 20; // access the iterator to update the value
    }

    /* For convenience, the std::map container provides the subscript operator to access elements in the map and
to insert new ones if they don't exist: */
    mapVariables["UDV"] = 10;
    /* While simpler, it prevents the user from checking if the element already exists. If an element is missing,
std::map::operator[] implicitly creates it, initializing it with the default constructor before overwriting it
with the supplied value. */

    /*insert() can be used to add several elements at once using a braced list of pairs. This version of insert()
    returns void: */
    mapVariables.insert({{"apricot", 1}, {"jackfruit", 1}, {"lime", 1}, {"mango", 7}});

    for (auto &mapVariable : mapVariables)
    {
        std::cout << "All Map Variables : " << mapVariable.first << " : " << mapVariable.second << std::endl;
    }
}

void StdMap::initializingElments()
{
    std::multimap<int, std::string> mmp{std::make_pair(2, "stackoverflow"),
                                        std::make_pair(1, "docs-beta"),
                                        std::make_pair(2, "stackexchange")};
    // 1 docs-beta
    // 2 stackoverflow
    // 2 stackexchange
    std::map<int, std::string> mp{std::make_pair(2, "stackoverflow"),
                                  std::make_pair(1, "docs-beta"),
                                  std::make_pair(2, "stackexchange")};

    // 1 docs-beta
    // 2 stackoverflow
    // From std::map or std::multimap iterator
    std::multimap<int, int> mmap{{1, 2}, {3, 4}, {6, 5}, {8, 9}, {6, 8}, {3, 4}, {6, 7}};
    // {1, 2}, {3, 4}, {3, 4}, {6, 5}, {6, 8}, {6, 7}, {8, 9}
    auto it = mmap.begin();
    std::advance(it, 3);                  //moved cursor on first {6, 5}
    std::map<int, int> map(it, mmap.end()); // {6, 5}, {8, 9}

    //From std::pair array
    std::pair<int, int> arr[10];
    arr[0] = {1, 3};
    arr[1] = {1, 5};
    arr[2] = {2, 5};
    arr[3] = {0, 1};
    std::map<int, int> map2(arr, arr + 4); //{0 , 1}, {1, 3}, {2, 5}
    
    //From std::vector of std::pair
    std::vector<std::pair<int, int>> v{{1, 5}, {5, 1}, {3, 6}, {3, 2}};
    std::multimap<int, int> map3(v.begin(), v.end());
    // {1, 5}, {3, 6}, {3, 2}, {5, 1}
}

void StdMap::deletingElemenets(){
    //------------------------------------------------------------------------------------------
    std::multimap<int,int> mmp{{1,2},{3,4}};
       for (auto &mapVar : mmp)
    {
        std::cout<<"Initialized Elements : "<< mapVar.first << " : " << mapVar.second<<std::endl;
    }
    mmp.clear(); //delete elements in mmp
    std::cout<<"Map Size :"<<mmp.size()<<std::endl;
    //------------------------------------------------------------------------------------------
    
    //Removing element from somewhere with the help of iterator:
    
    //------------------------------------------------------------------------------------------
}