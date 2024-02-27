#include <iostream>
#include <vector>

void input(int **arr, int cols, int rows)
{
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) 
            std::cin >> arr[i][j];
    }
}

void multiples_of_five()
{
    int cols, rows, count_of_elements = 0,max_value = -32768;    
    std::cout << " enter the length of cols & rows:";
    std::cin >> cols >> rows;
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
        
        if ((i+1) % rows == 0)
        {
            std::cout << "elements multiples of five in row "<<  (i+1) / rows << " is: " << count_of_elements << std::endl;
            count_of_elements = 0;            
        }
    }
    std::cout << "The max element multiple of five is " << max_value <<"."<< std::endl;    
}
 
void max_and_min_of_each_row() 
{
    int cols, rows;
    std::cout << " enter the length of cols & rows:";
    std::cin >> cols >> rows;
    int arr[cols][rows];

    for (int i = 0; i < ; i++)
    {
        /* code */
    }
    

}

void sorted_rows()
{

}

void sort_by_product_of_nums()
{

}

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
        sorted_rows();
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