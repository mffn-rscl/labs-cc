/*default libs*/
#ifndef METHODS_HPP
#define METHODS_HPP
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void choiceSort(int size, std::vector<int> *array) 
{
    for (int i = 0; i < size - 1; i++) 
    {

        int smallestIndex = i;

        for (int j = i + 1; j < size; j++) {  
            if (array->at(j) < array->at(smallestIndex)) {  
                smallestIndex = j;
            }
        }
        
        std::swap((*array)[i], (*array)[smallestIndex]); 
    }
}



int randNums() 
{
   int randNum = (rand() % 100) - ((rand() % 10) * 5); // generating an elements of array with range [-99; 99]
    return randNum;
}
void initRandomSeed() {
    srand(static_cast<int>(time(nullptr)));
}
#endif