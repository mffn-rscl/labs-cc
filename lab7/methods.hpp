#include <iostream>
void swap(int *a, int *b)
{
    int temp = *a;
    *a= *b;
    *b = temp;
}

void dynamic_selection_sort(int **arr, int checker, int rows) {
    int start = 0;
    int end = rows - 1;
    int step = 1;
    if ((checker + 1) % 2 != 0) {
        start = rows - 1;
        end = 0;
        step = -1;
    }

    for (int i = start; i != end; i += step) {
        int smallestIndex = i;
        for (int j = i + step; j >= 0 && j < rows; j += step) {
            if (arr[j][checker] > arr[smallestIndex][checker]) {
                smallestIndex = j;
            }
        }
        if (smallestIndex != i) {
            swap(&arr[smallestIndex][checker], &arr[i][checker]);
        }
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

int getMinValue(int **arr, int rows, int counter)
{
    int min_element = INT_MAX, index;
        for (int j = 0; j < rows; j++) 
            if (arr[counter][j] < min_element) 
            {
                min_element = arr[counter][j];
                index = j;
            }
    
    return index;
}

int getMaxValue(int **arr, int rows, int counter)
{
    int max_element = INT_MIN, index;
        for (int j = 0; j < rows; j++) 
            if (arr[counter][j] > max_element) 
            {
                max_element = arr[counter][j];
                index = j;
            }
    
    return index;
}