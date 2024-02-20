#include <iostream>

void list_sorting(int *arr, int size)
{
    
}

int solution(int *arr, int size)
{   
    int sum=0;
    list_sorting(arr, size);
    for (int count = 0; count < size - size/5; count++)sum+=arr[count];
    return sum;
}

int main()
{
    int size;
    std::cout <<"Enter the size of shoppings:";
    std::cin >> size;
    int arr[size];
    std::cout << "Enter the price of each stuffs:" << std::endl;
    for (int i = 0; i < size; i++)std::cin >> arr[i];

    std::cout << solution(arr, size) << std::endl;   
    return 0;
}