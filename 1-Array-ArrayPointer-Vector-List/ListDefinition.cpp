#include "ListDefinition.h"

ListDefinition::ListDefinition() : count(0)

{
}

ListDefinition::ListDefinition(const ListDefinition &ruleOfThree)
{
}

ListDefinition &ListDefinition::operator=(const ListDefinition &ruleOfThree)
{
}
ListDefinition::~ListDefinition()
{
}

void ListDefinition::listManagement()
{
}



void ListDefinition::listInitializations()
{
    //FIRST WAY****
    mStringVal = std::list<string>{"TB2", "Aksungur", "Akinci", "Hurkus", "Atak", "M2"};
    mStringVal2 = std::list<string>{"Hel", "Scorp", "Maxim"};
    mStringVectRef = &mStringVal;

    //SECOND WAY****
    for (std::list<string>::iterator ite = std::begin(mStringVal); ite != std::end(mStringVal); ++ite)
    {
        mStringVal2.push_back(*ite);
    }

    //THIRD WAY****
    std::list<string>::iterator itrptr = mStringVal.begin(); //FİLL
    std::advance(itrptr, 3);

    //FORTH WAY****
    // copying 1 vector elements in other using inserter()
    // inserts mStringVal2 after 3rd position in ar
    std::list<string>::iterator itrptr2 = mStringVal.begin();
    std::advance(itrptr2, 3);
    std::copy(mStringVal2.begin(), mStringVal2.end(), std::inserter(mStringVal, itrptr2));

    //FIFTH WAY****
    std::list<string>::iterator firstitr = mStringVal.begin();
    std::list<string>::iterator lastitr = mStringVal.end();
    std::list<string>::iterator itr = std::next(firstitr, 2); // Using next() to return new iterator   // points to Akinci
    for (std::list<string>::iterator ite = firstitr; ite != lastitr; ++ite)
    {
        mStringVal3.push_back(*itr);
    }

    //SIXTH WAY
    mStringVal4.assign(10, "Atak");

    //PRINT ALLL VECTORS******************
    std::cout << "Aerial Vehicles Val :" << std::endl;
    for (string &x : mStringVal)
    {
        print(x);
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Aerial Vehicles RefVal :" << std::endl;
    for (string &x : *mStringVectRef)
    {
        print(x);
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Aerial Vehicles Val2 :" << std::endl;
    for (int i = 0; i < mStringVal2.size(); i++)
    {
        print(*std::next(mStringVal.begin(),1));
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Aerial Vehicles Val3 :" << std::endl;
    for (int i = 0; i < mStringVal3.size(); i++)
    {
        print(*std::next(mStringVal.begin(),2));
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Aerial Vehicles Val4 :" << std::endl;
    for (int i = 0; i < mStringVal4.size(); i++)
    {
        print(*std::next(mStringVal.begin(),i));
        std::cout << std::endl;
    }
}

void ListDefinition::listAllOperations()
{

    /*
begin() – Returns an iterator pointing to the first element in the vector
end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
cbegin() – Returns a constant iterator pointing to the first element in the vector.
cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
*/
    if (mIntegerVal.empty())
    {
        for (int i = 1; i <= 5; i++)
            mIntegerVal.push_back(i);

        std::cout << "Output of begin and end: ";
        for (auto i = mIntegerVal.begin(); i != mIntegerVal.end(); ++i)
            std::cout << *i << " ";

        std::cout << "\nOutput of cbegin and cend: ";
        for (auto i = mIntegerVal.cbegin(); i != mIntegerVal.cend(); ++i)
            std::cout << *i << " ";

        std::cout << "\nOutput of rbegin and rend: ";
        for (auto ir = mIntegerVal.rbegin(); ir != mIntegerVal.rend(); ++ir)
            std::cout << *ir << " ";

        std::cout << "\nOutput of crbegin and crend : ";
        for (auto ir = mIntegerVal.crbegin(); ir != mIntegerVal.crend(); ++ir)
            std::cout << *ir << " ";
    }

    /*
size() – Returns the number of elements in the vector.
max_size() – Returns the maximum number of elements that the vector can hold.
capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
             Öğe sayısı olarak ifade edilen vektöre halihazırda ayrılmış depolama alanının boyutunu döndürür.
resize(n) – Resizes the container so that it contains ‘n’ elements.
empty() – Returns whether the container is empty.
shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
reserve() – Requests that the vector capacity be at least enough to contain n elements.
*/

    std::cout << std::endl;
    std::cout << std::endl;
    if (mIntegerVal2.empty())
    {
        for (int i = 1; i <= 5; i++)
            mIntegerVal2.push_back(i);

        std::cout << "Size : " << mIntegerVal2.size();
        std::cout << "\nMax_Size : " << mIntegerVal2.max_size();

        // resizes the vector size to 4
        mIntegerVal2.resize(4);

        // prints the vector size after resize()
        std::cout << "\nSize : " << mIntegerVal2.size();

        // checks if the vector is empty or not
        if (mIntegerVal2.empty() == false)
            std::cout << "\nVector is not empty";
        else
            std::cout << "\nVector is empty";

        
    }

    /*
reference operator [g] – Returns a reference to the element at position ‘g’ in the vector
at(g) – Returns a reference to the element at position ‘g’ in the vector
front() – Returns a reference to the first element in the vector
back() – Returns a reference to the last element in the vector
data() – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.    
*/
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Values Are : ";
    for (int i = 0; i <= 10; i++)
    {
        mIntegerVal3.push_back(i * 10);
        std::cout << *std::next(mIntegerVal3.begin(),i) << " , ";
    }
    std::cout << "\nReference operator [g] : mIntegerVal3[2] = " << *std::next(mIntegerVal3.begin(),2);

    std::cout << "\nat : mIntegerVal3.at(4) = " << *std::next(mIntegerVal3.begin(),3);

    std::cout << "\nfront() : mIntegerVal3.front() = " << mIntegerVal3.front();

    std::cout << "\nback() : mIntegerVal3.back() = " << mIntegerVal3.back();

    // pointer to the first element
    int *pos = &*mIntegerVal3.begin();

    std::cout << "\nThe first element is " << *pos;

    /*
assign() – It assigns new value to the vector elements by replacing old ones
push_back() – It push the elements into a vector from the back
pop_back() – It is used to pop or remove elements from a vector from the back.
insert() – It inserts new elements before the element at the specified position
erase() – It is used to remove elements from a container from the specified position or range.
swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
clear() – It is used to remove all the elements of the vector container
emplace() – It extends the container by inserting new element at position
emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector
*/

    std::cout << std::endl;
    std::cout << std::endl;
    // fill the array with 10 five times
    mIntegerVal4.assign(5, 10);

    std::cout << "The vector elements are: ";
    for (int i = 0; i < mIntegerVal4.size(); i++)
        std::cout << *std::next(mIntegerVal4.begin(),i) << " ";

    // inserts 15 to the last position
    mIntegerVal4.push_back(15);
    int n = mIntegerVal4.size();
    std::cout << "\nThe last element is: " <<*std::next(mIntegerVal4.begin(),n - 1);

    // removes last element
    mIntegerVal4.pop_back();

    // prints the vector
    std::cout << "\nThe vector elements are: ";
    for (int i = 0; i < mIntegerVal4.size(); i++)
        std::cout << *std::next(mIntegerVal4.begin(),i)<< " ";

    // inserts 5 at the beginning
    mIntegerVal4.insert(mIntegerVal4.begin(), 5);

    std::cout << "\nThe first element is: " << *std::next(mIntegerVal4.begin(),0);

    // removes the first element
    mIntegerVal4.erase(mIntegerVal4.begin());

    std::cout << "\nThe first element is: " << *std::next(mIntegerVal4.begin(),0);

    // inserts at the beginning
    mIntegerVal4.emplace(mIntegerVal4.begin(), 5);
    std::cout << "\nThe first element is: " << *std::next(mIntegerVal4.begin(),0);

    // Inserts 20 at the end
    mIntegerVal4.emplace_back(20);
    n = mIntegerVal4.size();
    std::cout << "\nThe last element is: " << *std::next(mIntegerVal4.begin(),n-1);

    // erases the vector
    mIntegerVal4.clear();
    std::cout << "\nVector size after erase(): " << mIntegerVal4.size();

    // two vector to perform swap
    std::vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    v2.push_back(4);

    std::cout << "\n\nVector 1: ";
    for (int i = 0; i < v1.size(); i++)
        std::cout << v1[i] << " ";

    std::cout << "\nVector 2: ";
    for (int i = 0; i < v2.size(); i++)
        std::cout << v2[i] << " ";

    // Swaps v1 and v2
    v1.swap(v2);

    std::cout << "\nAfter Swap \nVector 1: ";
    for (int i = 0; i < v1.size(); i++)
        std::cout << v1[i] << " ";

    std::cout << "\nVector 2: ";
    for (int i = 0; i < v2.size(); i++)
        std::cout << v2[i] << " ";
}

void ListDefinition::listTransferOpStruct()
{

    UavProperties2 uavProperties2;
    int structSize = sizeof(uavProperties2);
    std::vector<char> uavpropertiesvector(structSize);
    std::cout << "Size of struct : " << structSize << std::endl;
    //std::copy(&uavProperties2,&uavProperties2+structSize,uavpropertiesvector.begin());
    memcpy(uavpropertiesvector.data(), &uavProperties2, structSize);

    std::cout << "Electronic systems : " << *uavpropertiesvector.begin();
}

void ListDefinition::listTransferOpArray()
{
}

void ListDefinition::listStructArray()
{
    for (int i = 0; i < 10; i++)
    {
        UavProperties uavproperties;
        uavproperties.electronicSys = static_cast<string>(("Electronic system") + std::to_string(i));
        uavproperties.IMUSys = static_cast<string>(("IMU System") + std::to_string(i));
        uavproperties.motorSys = static_cast<string>(("Motor System") + std::to_string(i));
        uavproperties.servoSys = static_cast<string>(("Servo System") + std::to_string(i));
        //pass struct to the vector
        mStructVector.push_back(uavproperties);
    }

    for (std::list<UavProperties>::iterator ite = mStructVector.begin(); ite != mStructVector.end(); ++ite)
    {
        std::cout << ite->electronicSys << std::endl;
        std::cout << ite->IMUSys << std::endl;
        std::cout << ite->motorSys << std::endl;
        std::cout << ite->servoSys << std::endl;
        std::cout << std::endl;
    }
}

void ListDefinition::listDynamicAllocation()
{
    std::list<string> *tStringVector = new std::list<string>();
    if (!mStringVal5.empty())
    {
        //tStringVector = &mStringVal;//This one same as below
        //copy(mStringVal5.begin(), mStringVal5.end(), back_inserter(*tStringVector));//This one same as below
        tStringVector->assign(mStringVal5.begin(), mStringVal5.end());
        for (std::list<string>::iterator ite = std::begin(*tStringVector); ite != std::end(*tStringVector); ++ite)
        {
            std::cout << *ite << std::endl;
        }
    }
    else
    {
        std::cout << "mStringVal vector is empty";
    }
}

void ListDefinition::listIteratorOp()
{
    UavProperties2 uavProperties2;
    int structSize = sizeof(uavProperties2);
    //char *uavpropptr = (char *)&uavProperties2 ;// Also can be used for casting
    std::list<char> uavpropertiesvector(structSize);

    std::cout << "Size of struct : " << structSize << std::endl;
    std::copy((char *)&uavProperties2, (char *)&uavProperties2 + structSize, uavpropertiesvector.begin()); //Copy can be used to copy things to vector or otherwise

    for (std::list<char>::iterator ite = std::begin(uavpropertiesvector); ite != std::end(uavpropertiesvector); ++ite)
    {
        std::cout << *ite << std::endl;
    }
}
