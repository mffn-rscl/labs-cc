/*default libs*/
#include <iostream> // input/output
#include <ctime> // for time()
#include <cstdlib> // for rand() & srand()
#include "task.cc"
#include "methods.hpp"


void findTheMaxValFromArray(int size,int *array) // initializing func for two max numbers from array without using lib <climits>
{
    if(size < 2)
    {
        exit(0);
    }
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

void inputInOneLine(int size, int *array) {  for (int i = 0; i < size; i++) { std::cin >> array[i]; }}

void inputSeparately(int size, int *array)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the " << i + 1 << " value of array: ";
        std::cin >> array[i];
    }
}

void ToSquaresWithTwoMax()
{
    int size;
    std::cout << "Enter here length of array:";
    std::cin >> size;
    int array[size];

    std::cin.ignore();
    char choice;
    
   
    std::cout << "Do you want to fill array by random or fill it by yourself? ('r' - random, 'y' - by youreslf): ";
    std::cin >> choice;
    
    switch (choice)
    {
         
        case 'r':
            std::cout << "You chose to fill array by random. "<<std::endl;
            std::cout << "Finished array: ";
            for (int i = 0; i < size; i++) 
            { 
                array[i] = randNums(); 
                std::cout << array[i] << " ";
            }
            break;
       
        case 'y':
            std::cout << "You chose to fill array by yourself. "<<std::endl;
            std::cout << "Fill the array in one line?(y/n): ";
            
            std::cin >> choice;
            
            (choice == 'y') ? inputInOneLine(size, array) : inputSeparately(size, array);
           
            std::cout << "Finished array: ";      
            
            for (int i = 0; i < size; i++) { std::cout << array[i] << " "; }
            
            break;
        default:
            std::cerr << "\nIncorrect input. Try again." << std::endl;
            exit(0);
            break;
    }
   

    std::cout << "\nReplacing all positive numbers into their squares.. " << std::endl;

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
    initRandomSeed();
    int choice;
    std::cout << "Pick a task form the list below: \n" << std::endl;
    std::cout << "To squares with two max values from list (1)." << std::endl; 
    std::cout << "Table (2)." << std::endl;
    std::cout << "Game: 'Guess a Number!' (3)." << std::endl;
    std::cout << "Searching elements in list 1 (4)." << std::endl;
    std::cout << "Plurals operations (5)." << std::endl;

    do
    {
        std::cout << "\nPick a task number from list: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 0:
            std::cout << "Ending process.." << std::endl;
            break;

        case 1:
            std::cout << "You chose 'To squares with two max values from list'.\n" << std::endl;
            ToSquaresWithTwoMax();
            break;
        case 2:
            std::cout << "You chose task 'Table'.\n" << std::endl;
            Table();
            break;

        case 3:
            std::cout << "You chose game 'guess a number!'\n" << std::endl;
            std::cout << "input here range from a to b: ";
            long int a, b;
            std::cin >> a >> b;
            GuessedNumber(a, b);
            break;
        case 4: 
            std::cout << "You chose 'Searching elements in list 1.'\n" << std::endl;

            SearchingElementsInArray1();
            break;
        case 5: 
            std::cout << "You chose 'Plurals operations'.\n" << std::endl;
            plurals();
            break;
        default:
            std::cerr << "Incorrect input.Try again." << std::endl;
            break;
        }
    } while (choice != 0);
    
    return 0;
}


