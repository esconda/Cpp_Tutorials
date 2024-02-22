#include "VectorDefinition.h"
#include "VectorClassEx.h"

VectorDefinition::VectorDefinition() : count(0)

{
}

VectorDefinition::VectorDefinition(const VectorDefinition &ruleOfThree)
{
}

VectorDefinition &VectorDefinition::operator=(const VectorDefinition &ruleOfThree)
{
}

void VectorDefinition::vectorManagement()
{
}

VectorDefinition::~VectorDefinition()
{
}

void VectorDefinition::vectorInitializations()
{
    //FIRST WAY****
    mStringVal = std::vector<string>{"TB2", "Aksungur", "Akinci", "Hurkus", "Atak", "M2"};
    mStringVal2 = std::vector<string>{"Hel", "Scorp", "Maxim"};
    mStringVectRef = &mStringVal;

    //SECOND WAY****
    for (std::vector<string>::iterator ite = std::begin(mStringVal); ite != std::end(mStringVal); ++ite)
    {
        mStringVal2.push_back(*ite);
    }

    //THIRD WAY****
    std::vector<string>::iterator itrptr = mStringVal.begin(); //FİLL
    std::advance(itrptr, 3);

    //FORTH WAY****
    // copying 1 vector elements in other using inserter()
    // inserts mStringVal2 after 3rd position in ar
    std::vector<string>::iterator itrptr2 = mStringVal.begin();
    std::advance(itrptr2, 3);
    std::copy(mStringVal2.begin(), mStringVal2.end(), std::inserter(mStringVal, itrptr2));

    //FIFTH WAY****
    std::vector<string>::iterator firstitr = mStringVal.begin();
    std::vector<string>::iterator lastitr = mStringVal.end();
    std::vector<string>::iterator itr = std::next(firstitr, 2); // Using next() to return new iterator   // points to Akinci
    for (std::vector<string>::iterator ite = firstitr; ite != lastitr; ++ite)
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
        print(mStringVal2.at(i));
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Aerial Vehicles Val3 :" << std::endl;
    for (int i = 0; i < mStringVal3.size(); i++)
    {
        print(mStringVal3.at(i));
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Aerial Vehicles Val4 :" << std::endl;
    for (int i = 0; i < mStringVal4.size(); i++)
    {
        print(mStringVal4.at(i));
        std::cout << std::endl;
    }
}

void VectorDefinition::vectorInitializationAlternative(){
    //INITIALIZING METHODES
    std::vector<int> vector1(5,10);// Initialize vector and add items 10 for 5 times

    //Initialize vectors with pushback, push values one by one
    std::vector<int> vector2;
    vector2.push_back(20);
    vector2.push_back(30);
    vector2.push_back(40);

    //Initializing like arrays
    std::vector<int> vector3{1,2,3,4,5,6};
    std::vector<int> vector4 = {10,11,12,13,14};
    std::vector<int> vector5 = std::vector<int>{20,30,40,50};
    

    //Initializing with dynamic allocation
    std::vector<int> *vector6 = new std::vector<int>(5,10);

    vector1.reserve(10);
    vector2.reserve(5);
    vector3.reserve(10);
    vector4.reserve(20);
    vector5.reserve(10);
    vector6->reserve(10);

    
    std::cout<<"-----------VECTOR INITIALIZATION-------------"<<std::endl;
    std::cout<<"-----------VECTOR1-------------"<<std::endl;
    for(int &item: vector1){
        std::cout<<"Vector1 Item"<< item <<std::endl;
    }
    std::cout<<"-----------VECTOR2-------------"<<std::endl;
    for(int &item: vector2){
        std::cout<<"Vector2 Item"<< item <<std::endl;
    }
    std::cout<<"-----------VECTOR3-------------"<<std::endl;
    for(int &item: vector3){
        std::cout<<"Vector3 Item"<< item <<std::endl;
    }
    std::cout<<"-----------VECTOR4-------------"<<std::endl;
    for(int &item: vector4){
        std::cout<<"Vector4 Item"<< item <<std::endl;
    }
    std::cout<<"-----------VECTOR5-------------"<<std::endl;
     for(int &item: vector5){
        std::cout<<"Vector5 Item"<< item <<std::endl;
    }
     std::cout<<"-----------VECTOR6-------------"<<std::endl;
     for(int &item: *vector6){
        std::cout<<"Vector6 Item"<< item <<std::endl;
    }
    std::cout<<"--------------------------------------------"<<std::endl;
}

void VectorDefinition::vectorAllOperations()
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
resize(n) – Resizes the container so that it contains ‘n’ elements.
empty() – Returns whether the container is empty.
shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
reserve() – Requests that the vector capacity be at least enough to contain n elements.
*/

    std::cout << std::endl;
    std::cout << std::endl;
    if (mIntegerVal2.empty())
    {
        /*  RESERVE We need to understand how vectors work under the hood. When you push an element into an empty or full vector, we need to:
allocate a new block of memory that is larger.
move all the elements we have already stored in the previous block into the new one.
Both these operations are expensive and we want to avoid them as much as possible, if you can, sometimes you just accept things the way they are.

The size of the new block is 2X the capacity. Therefore, 
if you have a vector where both size() and capacity() are 100 elements and you push_back() element 101th, the block of memory (and the capacity) will jump to 200. */
        mIntegerVal.reserve(20);

        for (int i = 1; i <= 5; i++)
            mIntegerVal2.push_back(i);

        std::cout << "Size : " << mIntegerVal2.size();
        std::cout << "\nCapacity : " << mIntegerVal2.capacity();
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

        // Shrinks the vector
        mIntegerVal2.shrink_to_fit();
        std::cout << "\nVector elements are: ";
        for (auto it = mIntegerVal2.begin(); it != mIntegerVal2.end(); it++)
            std::cout << *it << " ";
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
        std::cout << mIntegerVal3.at(i) << " , ";
    }
    std::cout << "\nReference operator [g] : mIntegerVal3[2] = " << mIntegerVal3[2];

    std::cout << "\nat : mIntegerVal3.at(4) = " << mIntegerVal3.at(4);

    std::cout << "\nfront() : mIntegerVal3.front() = " << mIntegerVal3.front();

    std::cout << "\nback() : mIntegerVal3.back() = " << mIntegerVal3.back();

    // pointer to the first element
    int *pos = mIntegerVal3.data();

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
        std::cout << mIntegerVal4[i] << " ";

    // inserts 15 to the last position
    mIntegerVal4.push_back(15);
    int n = mIntegerVal4.size();
    std::cout << "\nThe last element is: " << mIntegerVal4[n - 1];

    // removes last element
    mIntegerVal4.pop_back();

    // prints the vector
    std::cout << "\nThe vector elements are: ";
    for (int i = 0; i < mIntegerVal4.size(); i++)
        std::cout << mIntegerVal4[i] << " ";

    // inserts 5 at the beginning
    mIntegerVal4.insert(mIntegerVal4.begin(), 5);

    std::cout << "\nThe first element is: " << mIntegerVal4[0];

    // removes the first element
    mIntegerVal4.erase(mIntegerVal4.begin());

    std::cout << "\nThe first element is: " << mIntegerVal4[0];

    // inserts at the beginning
    mIntegerVal4.emplace(mIntegerVal4.begin(), 5);
    std::cout << "\nThe first element is: " << mIntegerVal4[0];

    // Inserts 20 at the end
    mIntegerVal4.emplace_back(20);
    n = mIntegerVal4.size();
    std::cout << "\nThe last element is: " << mIntegerVal4[n - 1];

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

void VectorDefinition::vectorTransferOpStruct()
{

    UavProperties2 uavProperties2;
    int structSize = sizeof(uavProperties2);
    std::vector<char> uavpropertiesvector(structSize);
    std::cout << "Size of struct : " << structSize << std::endl;
    //std::copy(&uavProperties2,&uavProperties2+structSize,uavpropertiesvector.begin());
    memcpy(uavpropertiesvector.data(), &uavProperties2, structSize);

    std::cout << "Electronic systems : " << *uavpropertiesvector.begin();
}

void VectorDefinition::vectorTransferOpArray()
{
}

void VectorDefinition::vectorStructArray()
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

    for (std::vector<UavProperties>::iterator ite = std::begin(mStructVector); ite != std::end(mStructVector); ++ite)
    {
        std::cout << ite->electronicSys << std::endl;
        std::cout << ite->IMUSys << std::endl;
        std::cout << ite->motorSys << std::endl;
        std::cout << ite->servoSys << std::endl;
        std::cout << std::endl;
    }
}

void VectorDefinition::vectorDynamicAllocation()
{
    std::vector<string> *tStringVector = new std::vector<string>();
    if (!mStringVal5.empty())
    {
        //tStringVector = &mStringVal;//This one same as below
        //copy(mStringVal5.begin(), mStringVal5.end(), back_inserter(*tStringVector));//This one same as below
        tStringVector->assign(mStringVal5.begin(), mStringVal5.end());
        for (std::vector<string>::iterator ite = std::begin(*tStringVector); ite != std::end(*tStringVector); ++ite)
        {
            std::cout << *ite << std::endl;
        }
    }
    else
    {
        std::cout << "mStringVal vector is empty";
    }
}

void VectorDefinition::vectorIteratorOp()
{
    UavProperties2 uavProperties2;
    int structSize = sizeof(uavProperties2);
    //char *uavpropptr = (char *)&uavProperties2 ;// Also can be used for casting
    std::vector<char> uavpropertiesvector(structSize);

    std::cout << "Size of struct : " << structSize << std::endl;
    std::copy((char *)&uavProperties2, (char *)&uavProperties2 + structSize, uavpropertiesvector.begin()); //Copy can be used to copy things to vector or otherwise

    for (std::vector<char>::iterator ite = std::begin(uavpropertiesvector); ite != std::end(uavpropertiesvector); ++ite)
    {
        std::cout << *ite << std::endl;
    }
}

void VectorDefinition::vectorClassAproach()
{
    VectorClassEx vectorClassEx;
    int i = 10;

    std::vector<VectorClassEx> vectorOfClass;
    vectorOfClass.push_back(vectorClassEx);
    vectorOfClass.push_back(vectorClassEx);
    vectorOfClass.push_back(vectorClassEx);

    for (VectorClassEx &vectorCl : vectorOfClass)
    {
        i += 10;
        vectorCl.setIntDef(i);
        vectorCl.setStringDef(std::to_string(i) + " " + "Sayisi");
    }

    for (VectorClassEx &vectorCl : vectorOfClass)
    {
        std::cout << "Vector Integer Elements : " << vectorCl.getIntDef() << std::endl;
        std::cout << "Vector String Elements : " << vectorCl.getStringDef() << std::endl;
        std::cout << " " << std::endl;
    }
}

void VectorDefinition::correctWayOfVector()
{
    std::vector<int> vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::cout<<"Capacity before reserve : " << vector.capacity()<<std::endl;
    vector.reserve(15); //It allocates 15 element in memory according to 15 value, therefore it wont reallocate memory again and again afterpushback
    if (!vector.empty())
    {
        std::cout<<"Capacity after reserve:" << vector.capacity()<<std::endl;
        for (int i = 0; i < 5; i++)
        {
            vector.emplace_back(20);//Emplace back can be used to get rid of creating copyconstructor and copy it to vector
            vector.push_back(20);
        }

        for (int &vectorElement : vector)
        {
            std::cout<<"Vector Elements : "<<vectorElement<<std::endl;
        }
    }
}

void VectorDefinition::correctwayOfVectorWithShrink()
{
    std::vector<int> vector;
    
    vector.reserve(20);
    std::cout<<"Capacity of The Vector after reserve : "<<vector.capacity()<<std::endl;

    for(int i=0;i<20;i++)
    {
        vector.emplace_back(i);
    }

    vector.clear();
    std::cout<<"Capacity of The Vector after clear : "<<vector.capacity()<<std::endl;

    vector.shrink_to_fit();
    std::cout<<"Capacity of The Vector after shrink to fit : "<<vector.capacity()<<std::endl;
    std::cout<<""<<std::endl;
}

void VectorDefinition::copyOpOfTheVector(){
    std::cout<<"*****COPY PART OF THE VECTOR****"<<std::endl;

    // A loop to copy elements of old vector into new vector by Iterative method 
    std::cout<<"----IterativeMethode----"<<std::endl;
    std::vector<int> vectorIter{1,2,3,4,5,6,7};
    std::vector<int> iteDstVec;

    for (int i=0; i<vectorIter.size(); i++) 
        iteDstVec.push_back(vectorIter[i]); //Pusdhback Aproach copy elements

    for (int i=0; i<iteDstVec.size(); i++) 
        std::cout << iteDstVec[i] << " "; 
    std::cout << std::endl; 
    std::cout<<"-------------------------------"<<std::endl;
    //-----------------------------------------------------------------------------------------

    ////////// Using memcpy function to copy one vector to another
    std::cout<<"---- = MemcopyMethode ----"<<std::endl;
    std::vector<int> vectorMemcpy{1,2,3,4,5,6,7};
    std::vector<int> memcpyDstVec;
    memcpyDstVec.resize(vectorMemcpy.size());

   //std::memcpy(&memcpyDstVec[0], &(*vectorMemcpy.begin()),vectorMemcpy.size() * sizeof(int));
   //std::memcpy(std::data(memcpyDstVec), vectorMemcpy.data(),vectorMemcpy.size() * sizeof(int)); //Same as above
   std::memcpy(memcpyDstVec.data(), vectorMemcpy.data(),vectorMemcpy.size() * sizeof(int)); //Same as above

    for (int i=0; i<memcpyDstVec.size(); i++) 
        std::cout << memcpyDstVec[i] << " "; 
    std::cout << std::endl; 
    std::cout<<"-------------------------------"<<std::endl;
    //-----------------------------------------------------------------------------------------

    ////////// Using assignment operator to copy one vector to anpther
    std::cout<<"---- = AsignmentMethode----"<<std::endl;
    std::vector<int> vectorAsignment{1,2,3,4,5,6,7};
    std::vector<int> asignmentDstVec;

    asignmentDstVec = vectorAsignment; //" = " opeartor asignment aproach

    for (int i=0; i<asignmentDstVec.size(); i++) 
        std::cout << asignmentDstVec[i] << " "; 
    std::cout << std::endl; 
    std::cout<<"-------------------------------"<<std::endl;
    //-----------------------------------------------------------------------------------------

    ////////Passing Vector as Constructor
    std::cout<<"----Passing Vector as Constructor----"<<std::endl;
    std::vector<int> vectorConstr{1,2,3,4,5,6,7};
    std::vector<int> ConstrDstVec(vectorConstr); //Constructor methode deep copy

    for (int i=0; i<ConstrDstVec.size(); i++)
        std::cout << ConstrDstVec[i] << " "; 
    std::cout << std::endl; 
    std::cout<<"-------------------------------"<<std::endl;
    //-----------------------------------------------------------------------------------------

    ////////std::copy Methode to Copy Elements
    std::cout<<"----std::copy Methode to Copy Elements----"<<std::endl;
    std::vector<int> vectorCopy{1,2,3,4,5,6,7};
    std::vector<int> copyDstVec; 
    copyDstVec.resize(vectorCopy.size());

    //std::copy(vectorCopy.begin(),vectorCopy.end()-2,std::back_inserter(copyDstVec));
    std::copy(std::data(vectorCopy), std::data(vectorCopy) + vectorCopy.size(), copyDstVec.begin());

    for (int i=0; i<copyDstVec.size(); i++) 
        std::cout << copyDstVec[i] << " "; 
    std::cout << std::endl; 
    std::cout<<"-------------------------------"<<std::endl;
    //-----------------------------------------------------------------------------------------

    ////////assign Function Methode to Copy Elements
    std::cout<<"----assign Function Methode to Copy Elements----"<<std::endl;
    std::vector<int> vectorAssign{1,2,3,4,5,6,7};
    std::vector<int> assignDstVec; 

    assignDstVec.assign(vectorAssign.begin(),vectorAssign.end());

    for (int i=0; i<assignDstVec.size(); i++) 
        std::cout << assignDstVec[i] << " "; 
    std::cout << std::endl; 
    std::cout<<"-------------------------------"<<std::endl;
    //-----------------------------------------------------------------------------------------

    ////////insert Function Methode to Copy Elements
    std::cout<<"----insert Function Methode to Copy Elements----"<<std::endl;
    std::vector<int> vectorInsert{1,2,3,4,5,6,7};
    std::vector<int> insertDstVec; 

    insertDstVec.insert(insertDstVec.begin(),vectorInsert.begin(),vectorInsert.end());

    for (int i=0; i<insertDstVec.size(); i++) 
        std::cout << insertDstVec[i] << " "; 
    std::cout << std::endl; 
    std::cout<<"-------------------------------"<<std::endl;
    //-----------------------------------------------------------------------------------------
    std::cout<<"*******************************"<<std::endl;
}
