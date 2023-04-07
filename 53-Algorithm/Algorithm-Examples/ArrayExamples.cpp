// Author: Burak Doğançay
#include "ArrayExamples.h"

ArrayExamples::ArrayExamples()
{
}

void ArrayExamples::removeDuplicatesFromSortedArray()
{
    // Remove Duplicates from Sorted Array
    // We are going to solve it with only Big-O Notations:  O(n) in for loop
    std::cout << " " << std::endl;
    std::cout << "----REMOVE DUPLICATES FROM SORTED ARRAY---" << std::endl;
    std::vector<int> tExampleVector{0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 5, 6, 7};
    int position = 1;
    for (int i = 1; i < tExampleVector.size(); i++)
    {
        if (tExampleVector[i] != tExampleVector[i - 1])
        {
            tExampleVector[position] = tExampleVector[i];
            position++;
        }

        else
        {
            continue;
        }
    }

    for (int &intVar : tExampleVector)
    {
        std::cout << "New vector variable : " << intVar << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;
}

void ArrayExamples::rotateArray()
{

    /*
     QUESTION
     Input: nums = [1,2,3,4,5,6,7], k = 3
     Output: [5,6,7,1,2,3,4]
     Explanation:
     rotate 1 steps to the right: [7,1,2,3,4,5,6]
     rotate 2 steps to the right: [6,7,1,2,3,4,5]
     rotate 3 steps to the right: [5,6,7,1,2,3,4]
     */
    std::cout << " " << std::endl;
    std::cout << "----ROTATE ARRAY BY K STEPS---" << std::endl;
    std::cout << "----{1, 2, 3, 4, 5, 6, 7}---" << std::endl;
    std::vector<int> tNums{1, 2, 3, 4, 5, 6, 7};

    // FIRST APROACH
    int k = 3;
    bool callOnce = true;
    for (int i = 0; i < k; i++)
    {
        int n = tNums.size();
        int temp = tNums[n - 1];

        for (int i = n - 1; i > 0; i--)
        {
            tNums[i] = tNums[i - 1];
        }
        tNums[0] = temp;
    }
    std::cout << "First aproach variable : ";
    for (int &intVar : tNums)
    {
        std::cout << intVar <<" ";
    }
    std::cout<<std::endl;
    std::cout << "-------------------------------------" << std::endl;
}

void ArrayExamples::firstNonRepeatedCharacterIndex()
{
    // input : vvaarrilabs
    // output : Index of "i"
    /*
    Explanation:
    You have astring like : vvaarrilabs
    You should find the first nonrepeated character
    return the index of the character
    show it with std::cout on the screen
    */
    std::cout << " " << std::endl;
    std::cout << "----FIND FIRST NON REPETAED CHARACTER INDEX ---" << std::endl;
    std::cout << "----vvaarrilabs ---" << std::endl;
    std::string myString = "vvaarrilabs";
    int position = 0;
    for (int i = 1; i < myString.size(); i++)
    {
        if ((myString[i] != myString[i - 1]) && (myString[i] != myString[i + 1]))
        {
            position = i;
            break;
        }
        else
        {
            continue;
        }
    }

    std::cout << "Position index is : " << position << std::endl;
    std::cout << "Position index Variable is : " << myString[position] << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}

void ArrayExamples::containsDuplicate()
{
    // Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
    // Input: nums = [1,2,3,1]
    // Output: true

    // Input: nums = [1,2,3,4]
    // Output: false

    // 1 <= nums.length <= 105
    //-109 <= nums[i] <= 109
    std::cout << " " << std::endl;
    std::cout << "----IF CONTAINS DUPLICATE IN ARRAY---" << std::endl;
    std::cout << "----{1, 2, 3, 2, 1}---" << std::endl;
    std::vector<int> myVariables{1, 2, 3, 2, 1};
    bool boolVariable = false;
    std::unordered_set<int> hSet;
    for (int i = 0; i < myVariables.size(); i++)
    {
        if (hSet.count(myVariables[i]))
        {
            boolVariable = true;
            break;
        }
        else
        {
            hSet.insert(myVariables[i]);
            boolVariable = false;
            continue;
        }
    }
    std::cout << "Contains duplicate situation in Array : " << boolVariable << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    // Second Aproach
    /* sort(nums.begin(), nums.end());
    for (int idx = 0; idx < nums.size() - 1; idx++)
    {
        // Check the duplicate element...
        if (nums[idx] == nums[idx + 1])
            return true;
    }
    // Otherwise return false...
    return false; */
}

void ArrayExamples::singleNumber()
{
    // Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
    // You must implement a solution with a linear runtime complexity and use only constant extra space.
    // Each element in the array appears twice except for one element which appears only once.
    /* Example 1:
    Input: nums = [2,2,1]
    Output: 1

    Example 2:
    Input: nums = [4,1,2,1,2]
    Output: 4

    Example 3:
    Input: nums = [1]
    Output: 1 */
    std::cout << " " << std::endl;
    std::cout << "----FIND SINGLE NOT DUPLICATED ELEMENT---" << std::endl;
    std::cout << "----{6, 1, 2, 1, 2}---" << std::endl;
    std::vector<int> myVariables{6, 1, 2, 1, 2};
    int XOR = 0;
    for (int i = 0; i < myVariables.size(); i++)
    {
        XOR ^= myVariables[i];
    }
    std::cout << "Single Non Duplicated Variable is: " << XOR << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}

void ArrayExamples::intersectionOfTwoArrays()
{
    // Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
}

void ArrayExamples::findSecondLargestElementInArray()
{
    /* Input: arr[] = {12, 35, 1, 10, 34, 1}
    Output: The second largest element is 34.
    Explanation: The largest element of the
    array is 35 and the second
    largest element is 34 */

    /* Input: arr[] = {10, 5, 10}
    Output: The second largest element is 5.
    Explanation: The largest element of
    the array is 10 and the second
    largest element is 5 */
    std::cout << " " << std::endl;
    std::cout << "----FIND SECOND LARGEST ELEMENT IN ARRAY---" << std::endl;
    std::cout << "----{12,36, 38, 1, 10, 34, 1}---" << std::endl;

    int secondLargestElement = 0;
    std::vector<int> myArray = {12,36, 38, 1, 10, 34, 1};
    std::sort(myArray.begin(), myArray.end());
    for (int i = myArray.size() - 2; i >= 0; i--)
    {
        if (myArray[i] != myArray[myArray.size() - 1])
        {
            secondLargestElement = myArray[i];
            break;
        }
    }

    std::cout << "Second Largest Element In Array is: " <<secondLargestElement<< std::endl;
    std::cout << "-------------------------------------" << std::endl;
}