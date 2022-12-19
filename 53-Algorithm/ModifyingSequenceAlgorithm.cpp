//Author: Burak Doğançay
#include "ModifyingSequenceAlgorithm.h"

ModifyingSequenceAlgorithm::ModifyingSequenceAlgorithm()
{
}

void ModifyingSequenceAlgorithm::copyFunctions(){
    //WE WILL CONSIDER
    //std::copy , std::copy_backward, std::copy_if , std::copy_n

    printOneLine("----------COPY ALGORITHMS-------------");

    //std::copy
    //Copy elements from one sequence to another
    std::vector<int> firstCopyVec{20,30,40,50};
    std::vector<int> secondCopyVec;

    //std::copy(firstCopyVec.begin(), firstCopyVec.end(),secondCopyVec.begin());
    //alternative way
    std::copy(firstCopyVec.begin(), firstCopyVec.end(),std::back_inserter(secondCopyVec));

    printOneLine("-------Std::copy-----------");
     for (auto &n: secondCopyVec){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------

    //std::copy_backward
    //Copy elements from one sequence to another
    std::vector<int> firstCopyBackWardVec{20,30,40,50};
    std::vector<int> secondCopyBackWardVec(10);

    std::copy_backward(firstCopyBackWardVec.begin(), firstCopyBackWardVec.end(),secondCopyBackWardVec.end());
   
    printOneLine("-------Std::copy_backward-----------");
     for (auto &n: secondCopyBackWardVec){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------

    //std::copy_if
    //Copies elements for which a predicate returns true from one sequence to another
    std::vector<int> firstCopyIfVec{20,30,40,50};
    std::vector<int> secondCopyIfVec;

    std::copy_if(firstCopyIfVec.begin(), firstCopyIfVec.end(),std::back_inserter(secondCopyIfVec),[](const auto &i){ return i % 3 ==0;});
   
    printOneLine("-------Std::copy_if-----------");
     for (auto &n: secondCopyIfVec){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------

    //std::copy_n
    //Copies n elements from one sequence to a new value
    std::vector<int> firstCopyNVec{20,30,40,50};
    std::vector<int> secondCopyNVec;

    std::copy_n(firstCopyNVec.begin(), 3,std::back_inserter(secondCopyNVec));
   
    printOneLine("-------Std::copy_n-----------");
     for (auto &n: secondCopyNVec){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------
     printOneLine("-------------------------------------");
}

void ModifyingSequenceAlgorithm::fillFunctions(){
    //WE WILL CONSIDER
    //std::fill , std::fill_n
    printOneLine("----------FILL ALGORITHMS-------------");

    //std::fill
    //Sets all elements in the sequence to a new value
    std::vector<int> fillVec{20,30,40,50};

    std::fill(fillVec.begin(),fillVec.end(),5);
   
    printOneLine("-------Std::fill-----------");
     for (auto &n: fillVec){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------

    //std::fill_n
    //Sets the first n elements in the sequence to a new value
    std::vector<int> fillNVec{20,30,40,50};

    std::fill_n(fillNVec.begin(),3,5);
   
    printOneLine("-------Std::fill_n-----------");
     for (auto &n: fillNVec){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------

    printOneLine("-------------------------------------");
    
}

void ModifyingSequenceAlgorithm::generateFunctions(){
   //WE WILL CONSIDER
   //std::generate , std::generate_n
    printOneLine("----------GENERATE ALGORITHMS-------------");

    //std::generate
    //Call a specific function to generate a new val of each elements in the sequence
    std::function<int()> generatefunc =[=](){
        static int i;
        return ++i;
    } ;

    std::vector<int> generateVec(10);
      std::generate(generateVec.begin(),generateVec.end(),generatefunc);
   
    printOneLine("-------Std::generate-----------");
     for (auto &n: generateVec){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------

    //std::fill_n
    //Sets the first n elements in the sequence to a new value
    std::vector<int> fillNVec{20,30,40,50};

    std::fill_n(fillNVec.begin(),3,5);
   
    printOneLine("-------Std::fill_n-----------");
     for (auto &n: fillNVec){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------

    printOneLine("-------------------------------------");
}

void ModifyingSequenceAlgorithm::moveFunctions(){
    //WE WILL CONSIDER
    //std::move , std::move_backward
    printOneLine("----------MOVE ALGORITHMS-------------");

    //std::move 
    //Moves elements from one seq to another This uses efficient move semantics
    std::vector<int> moveFirstVec{1,2,3,4,5};
    std::vector<int> moveSecondVec(5);

    moveSecondVec = std::move(moveFirstVec);
   
    printOneLine("-------Std::move-----------");
     for (auto &n: moveFirstVec){
        printTwoLine("First Vector" , n);
    }

    for (auto &n: moveSecondVec){
        printTwoLine("Second Vector" , n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------

    //std::move 
    //Moves elements from one seq to another This uses efficient move semantics
    std::vector<int> moveBackwardFirstVec{1,2,3,4,5};
    std::vector<int> moveBackwardSecondVec(5);
    
    std::move_backward(moveBackwardFirstVec.begin(), moveBackwardFirstVec.end(),moveBackwardSecondVec.end());
   
    printOneLine("-------Std::move_backward-----------");
     for (auto &n: moveBackwardFirstVec){
        printTwoLine("First Vector" , n);
    }

    for (auto &n: moveBackwardSecondVec){
        printTwoLine("Second Vector" , n);
    }

    printOneLine("");
    //----------------------------------------------------------------------------------

    printOneLine("-------------------------------------");
    
    
}
void ModifyingSequenceAlgorithm::removeFunctions(){
    //WE WILL CONSIDER
    //std::remove , std::remove_if , std::remove_copy , std::remove_copy_if
    printOneLine("----------REMOVE ALGORITHMS-------------");

    //std::remove ,std::remove_if
    //Moves elements from one seq to another This uses efficient move semantics
    std::string str1 = "Text with some   spaces";
 
    auto noSpaceEnd = std::remove(str1.begin(), str1.end(), ' ');
 
    // The spaces are removed from the string only logically.
    // Note, we use view, the original string is still not shrunk:
    std::cout << std::string_view(str1.begin(), noSpaceEnd) 
              << " size: " << str1.size() << '\n';
 
    str1.erase(noSpaceEnd, str1.end());
 
    // The spaces are removed from the string physically.
    std::cout << str1 << " size: " << str1.size() << '\n';
 
    std::string str2 = "Text\n with\tsome \t  whitespaces\n\n";
    str2.erase(std::remove_if(str2.begin(), 
                              str2.end(),
                              [](unsigned char x){return std::isspace(x);}),
               str2.end());
    std::cout << str2 << '\n';
    printOneLine("");
     //----------------------------------------------------------------------------------

    printOneLine("-------------------------------------");
    
}
void ModifyingSequenceAlgorithm::replaceFunctions(){
    //WE WILL CONSIDER
    //std::replace , std::replace_if, std::replace_copy, std::replace_copy_if
     printOneLine("----------REPLACE ALGORITHMS-------------");

    //std::move 
    //Moves elements from one seq to another This uses efficient move semantics
    std::vector<int> replaceVec{1,2,3,4,5};

    std::replace(replaceVec.begin(),replaceVec.end(),4,15);
   
    printOneLine("-------Std::replace-----------");
     for (auto &n: replaceVec){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------
    printOneLine("-------------------------------------");

    
}
void ModifyingSequenceAlgorithm::reverseFunctions(){
    //WE WILL CONSIDER
    //std:reverse , std::reverse_copy
    
}
void ModifyingSequenceAlgorithm::rotateFunctions(){
    //WE WILL CONSIDER
    //std::rotate, std::rotate_copy
    
}
void ModifyingSequenceAlgorithm::sampleShuffleFunctions(){
    //WE WILL CONSIDER
    // std::sample, std::shuffle, std::random_shuffle
    
}
void ModifyingSequenceAlgorithm::transformFunctions(){
    //WE WILL CONSIDER
    //std::transform
}

void ModifyingSequenceAlgorithm::uniqueFunctions(){
    //WE WILL CONSIDER
    //std::unique , std::unique_copy   
}