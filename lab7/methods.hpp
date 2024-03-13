#include <iostream>
void swap(int *a, int *b)
{
    int temp = *a;
    *a= *b;
    *b = temp;
}
void selection_sort(int *arr, int rows)
{
     for (int j = rows-1; j > 0; j--)
    {
        int smallestIndex = j;
        for (int k = j-1; k >=0; k--)
        {
            if (arr[smallestIndex] > arr[k]) smallestIndex=k;

        }
        swap(&arr[smallestIndex], &arr[j]);
    }
    
}

void reversed_selection_sort(int **arr, int rows, int i)
{
    for (int j = rows-1; j > 0; j--)
    {
        int smallestIndex = j;
        for (int k = j-1; k >=0; k--)
        {
            if (arr[smallestIndex][i] >arr[k][i])smallestIndex = k;
        }
        swap(&arr[smallestIndex][i], &arr[j][i]);
    }
}

void modified_bouble_sort(int **arr, int rows, int k)
{
    for (int i = 0; i < rows-1; i++)
    {
        bool swaped = false;
        for (int j = 0; j < rows-i-1; j++)
        {
            if (arr[j][k] > arr[j + 1][k])
            {
                swap(&arr[j+1][k], &arr[j][k]);
                swaped = true;
            }
        }
         if (!swaped)
            break; 
    }
}           


void output(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}

void input(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) std::cin >> arr[i][j];
    }
}