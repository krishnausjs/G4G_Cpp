//Program to demonstrate insertion of element(s) into vector in various ways
//Inserting elements in vector will cause existing elements to shift places or
//sometimes complete reallocation, which will invalidates all the existing iterators

#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template <typename T>
void print(T & vecOfElements, std::string delimeter = " , ")
{
    for(auto elem : vecOfElements)
        std::cout << elem << delimeter;
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vecOfNums {1, 4, 5, 22, 33, 2, 11, 89, 49};
    
    //Inserting an element at specific position in vector
    //Create iterator pointig to 4th position
    auto itPos = vecOfNums.begin() + 4;

    //Insert element with value 9 at 4th position in vector
    auto newIt = vecOfNums.insert(itPos, 9);

    std::cout << "Element added in vector is : " << *newIt << std::endl;
    std::cout << "Modified vecOfNums = ";
    print(vecOfNums);
   
    //Inserting multiple elements / range at specific position in vector
    std::vector<std::string> vec1 {"at", "hello", "hi", "there", "where", "now", "is"};
    std::vector<std::string> vec2 {"one", "two", "two"};

    //Insert all elements in vec2 at 3rd position in vec1
    auto iter = vec1.insert(vec1.begin() + 3, vec2.begin(), vec2.end());

    std::cout << "First of the newly added elements : " << *iter << std::endl;
    std::cout << "Modified vec1 = ";
    print(vec1);
   
    //Inserting all elements in initialization list in another vector at speific position
    std::vector<int> vecOfInts {1, 4, 5, 22, 33, 2, 11, 89, 49};
    
    //Insert all elements from initialization list to vector at 3rd position
    auto iter2 = vecOfInts.insert(vecOfInts.begin()+3, {34, 55, 66, 77});
    std::cout << "First of newly added elements : " << *iter2 << std::endl;
    print(vecOfInts);
    
    return 0; 
}
