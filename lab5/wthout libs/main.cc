/*default libs*/
#include <iostream> // input/output
#include <ctime> // for time()
#include <cstdlib> // for rand() & srand()

#include "methods.cc"
#include "task.cc"

void inputInOneLine(int size, int *array) {  for (int i = 0; i < size; i++) { std::cin >> array[i]; }}

void randNumbersForArray(int size, int *array) // rewrite
{
    srand(static_cast<int>(time(nullptr))); //find an explain
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100; // generating an elements of array with range [-99; 99]
        
        if (array[i] % 2 == 0) {  array[i] = -array[i]; } // adding negative numbers
       
        std::cout << array[i]<< " ";
    }

}

void inputSeparately(int size, int *array)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the " << i + 1 << " value of array: ";
        std::cin >> array[i];
    }
}

void findTheMaxValFromArray(int size,int *array) // initializing func for two max numbers from array without using lib <climits>
{
    int max1 = array[0], max2 = array[1], temp;
    if (max1 < max2) {swap(&max1, &max2); }
    
    for (int i = 2; i < size; i++)
    {
       if (array[i] > max1)
       {
        max2 = max1;
        max1 = array[i];
       }
       else if (array[i] > max2) { max2 = array[i]; }
       
    }

    std::cout << "\nfound two max values: " << max1<< " and " << max2 << ".\n\n";
    
}

void ToSquaresWithTwoMax()
{
    int size;
    std::cout << "enter here length of array:";
    std::cin >> size;
    int array[size];

    std::cin.ignore();
    char choice;
    
   
    std::cout << "Do you want to fill array by random or fill it by yourself? ('r' - random, 'y' - by youreslf): ";
    std::cin >> choice;
    
    switch (choice)
    {
         
        case 'r':
            std::cout << "you chose to fill array by random. "<<std::endl;
            std::cout << "finished array: ";

            randNumbersForArray(size, array); 
            break;
        case 'y':
            std::cout << "you chose to fill array by yourself. "<<std::endl;
            std::cout << "fill the array in one line?(y/n): ";
            
            char choiceLine;
            std::cin >> choiceLine;
            
            (choiceLine == 'y') ? inputInOneLine(size, array) : inputSeparately(size, array);
           
            std::cout << "finished array: ";      
            
            for (int i = 0; i < size; i++) { std::cout << array[i] << " "; }
            
            break;
        default:
            std::cerr << "incorrect input. Try again." << std::endl;
            break;
    }
   

    std::cout << "\nreplacing all positive numbers into their squares... " << std::endl;

    std::cout << "Result: ";
    for (int i = 0; i < size; i++)
    {
        if (array[i] > 0) { array[i] = array[i] * array[i]; }
        
        std::cout << array[i] << " ";
    }
    

    findTheMaxValFromArray(size, array);
}

int main()
{
    
    return 0;
}


