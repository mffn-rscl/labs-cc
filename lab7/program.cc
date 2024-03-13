#include <iostream>
#include <vector>
#include <climits>
#include "methods.hpp"


void multiples_of_five()
{
    int cols, rows, count_of_elements = 0,max_value = -32768;    
    std::cout << " enter the length of cols & rows:";
    std::cin >> rows >> cols;
    std::vector<int> arr;
    int temp;
    for (int i = 0; i < cols*rows; i++)
    {
        std::cin >>temp;
        arr.push_back(temp);
        
        if (arr[i] % 5 == 0 && arr[i] != 0)
        {
            if (max_value < arr[i])max_value = arr[i];
            count_of_elements++;
        }
        
        if ((i+1) % cols == 0)
        {
            std::cout << "elements multiples of five in row "<<  (i+1) / cols << " is: " << count_of_elements << std::endl;
            count_of_elements = 0;            
        }
    }
    std::cout << "The max element multiple of five is " << max_value <<"."<< std::endl;    
}
 
void max_and_min_of_each_row() 
{
    int cols, rows, min_int = INT_MAX, max_int = INT_MIN, max_index, min_index;
    std::cout << " enter the length of cols & rows:";
    std::cin >> rows >> cols;
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++)arr[i] = new int[rows];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) 
        {
            std::cin >> arr[i][j];
            if (max_int < arr[i][j])
            {
                max_int = arr[i][j];
                max_index = j;
            }

            if (min_int > arr[i][j])
            {
                min_int = arr[i][j];
                min_index = j;
            }
        }
        
        if(arr[i][cols-1] == max_int && arr[i][0] == min_int)
        {
            swap(&arr[i][cols-1], &arr[i][0]);
        }
        else
        {
            swap(&arr[i][0], &arr[i][max_index]);
            swap(&arr[i][cols-1], &arr[i][min_index]);

        }
        min_int = INT_MAX, max_int = INT_MIN;
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

    for (int i = 0; i < cols; i++) 
    {((i+1) % 2 != 0) ? modified_bouble_sort(arr, rows, i) : reversed_selection_sort(arr,rows,i);}
    

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
    int solution[cols];
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++)arr[i] = new int[rows];


    std::cout << "Enter the elements of matrix: " << std::endl;

    input(arr,rows, cols);
    
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++) product = product*arr[j][i];
        std::cout << "Product of " << i + 1 << " column is " << product << std::endl;
        solution[i] = product;
        product = 1;
    }
    selection_sort(solution, cols);             

    std::cout << "Sorted array of product of numbers: ";
    for (int i = 0; i < cols; i++) std::cout << solution[i] << " ";
     
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