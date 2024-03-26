#include <iostream>
#include <vector>
#include <climits>
#include "methods.hpp"


void multiples_of_five()
{
    int cols, rows; 
    std::cout << " enter the length of cols & rows:";
    std::cin >> rows >> cols;

    int** arr = new int*[cols];
    for (int i = 0; i < rows; i++)arr[i] = new int[rows];

    std::cout << "Enter the elements of matrix: " << std::endl;

    input(arr,rows, cols);

    for (int i = 0; i < cols; i++)
    {
        int max_value = INT_MIN,  count_of_elements = 0; 
        for (int j = 0; j < rows; j++)
        {
            if (arr[i][j] % 5 == 0 && arr[i][j] != 0)
            {
                count_of_elements++;
                if (max_value < arr[i][j]) max_value = arr[i][j];
            }
        }

        std::cout << count_of_elements << " fives in row " << i+1 << std::endl;
        std::cout << "max multiple of five in " << i+1<< " row is: " << max_value << std::endl;
        std::cout << std::endl;                 
    }
    for (int i = 0; i < rows; ++i) delete[] arr[i]; 
    delete[] arr;
}
 
void max_and_min_of_each_row()
{
    int cols, rows;
    std::cout << " enter the length of cols & rows:";
    std::cin >> rows >> cols;
    int** arr = new int*[cols];
    for (int i = 0; i < rows; i++)arr[i] = new int[rows];
    std::cout << "Enter the elements of matrix: " << std::endl;

    input(arr,rows, cols);
    
    for (int i = 0; i < rows; i++)
    {
        int max_index = getMaxValue(arr, cols,  i);
        int min_index = getMinValue(arr, cols,  i);
        
        swap(&arr[i][0], &arr[i][max_index]);
        if (min_index != 0 && min_index != cols - 1)swap(&arr[i][cols - 1], &arr[i][min_index]); 
    }
    
    

    std::cout << " swapped array: " << std::endl;

    output(arr,rows,cols);


    for (int i = 0; i < rows; ++i) delete[] arr[i]; //stack cleaning
    delete[] arr;
}

void sorted_cols()
{
    int cols, rows;
    std::cout << " enter the length of cols & rows:";
    std::cin >> rows >> cols;
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++)arr[i] = new int[rows];


    std::cout << "Enter the elements of matrix: " << std::endl;

    input(arr,rows, cols);

    for (int i = 0; i < cols; i++) dynamic_selection_sort(arr,i,rows);
    

    std::cout << "\nResult: " << std::endl;
    output(arr,rows,cols);

    for (int i = 0; i < rows; ++i) delete[] arr[i]; //stack cleaning
    delete[] arr;
}


void sort_by_product_of_nums()
{
    int cols, rows, product = 1;
    std::cout << " enter the length of cols & rows:";
    std::cin >> rows >> cols;
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++)arr[i] = new int[rows];

    std::cout << "Enter the elements of matrix: " << std::endl;
    input(arr,rows,cols);
    
    
     
    for (int i = 0; i < rows; ++i) delete[] arr[i];
    delete[] arr;
}

    // 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\ 7\

int main()
{

    int choice;
    std::cout << "Choose one of the tasks(1,2,3,4), or press 0, for leave:";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "you chose #1:\nДля цілочислової матриці знайти для кожного рядка кількість елементів, що кратні п’яти, і найбільший з одержаних результатів.\n" << std::endl;
        multiples_of_five();
        break;
    case 2:
        std::cout << " you chose #2:\nЗнайти в кожному рядку перший з максимальних і перший з мінімальних елементів і поставити їх на першому (технічно 0-му) і останньому місцях рядка.\n" << std::endl;
        max_and_min_of_each_row();
        break;
    
    case 3:
        std::cout << " you chose #3:\nУпорядкувати всі стовпчики з парними номерами за незростанням, а всі стовпчики з непарними номерами за неспаданням.\n" << std::endl;
        sorted_cols();
        break;
    case 4: 
        std::cout << "you chose #4:\nУпорядкувати стовпчики матриці за незростанням добутків елементів у цих стовпчиках.\n" << std::endl;
        sort_by_product_of_nums();    
        break;

    case 0:
        return 0;
    default:
        std::cout << "Invalid input, try again." << std::endl;
        break;
    }

    return 0;
}