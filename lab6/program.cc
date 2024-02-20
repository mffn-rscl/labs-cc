#include <iostream>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shell_sort(int data[], int size)
{   
    for (int interval = size / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < size; i += 1) {
            int temp = data[i];
            int j;
            for (j = i; j >= interval && data[j - interval] > temp; j -= interval) {
                data[j] = data[j - interval];
            }
            data[j] = temp;
        }
    }
}

int solution(int arr[], int size)
{   
    int sum=0;
    shell_sort(arr, size);
    for (int count = size/5; count < size; count++)sum+=arr[count];
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