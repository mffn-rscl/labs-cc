#include <iostream>

int main()
{
    int cols = 5, rows = 7;
    int** arr = new int*[cols];
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
            std::cin >> arr[i][j];        
    }

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
            std::cout << arr[i][j] << " ";

        std::cout << std::endl;
        
    }
    
    
    return 0;
}