#include <iostream>
#include <cmath>
#include <chrono>
#include "methods.hpp"
class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;


    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now()) {}

    void reset()
    {
        m_beg = clock_t::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

void input(double *arr, int size)
{
    for (int i = 0; i < size; i++)std::cin >> arr[i];
}



void extra_task_one()
{
    int size, counter =0 ;

    
    std::cout << "enter the length of two arrays:";
    std::cin >> size;
    double holes[size], bridges[size];
    std::cout << "input the holes: ";
    input(holes, size);
    std::cout << " input the bridges: ";
    input(bridges, size);
    
    for (int i = size -1 ; i >= 0; i--)
    {
        for (int j = size -1; j >=0; j--)
        {
            if (bridges[j]  > holes[i])
            {
                counter++;
            }
        }
        
    }
    std::cout << "Max value of covered gaps:"<< counter << std::endl;
}

void extra_task_two() 
{
    int n;
    std::cout << "Enter the number of segments: ";
    std::cin >> n;
    std::cout << "Enter the segments: ";
    double arr[n];
    input(arr,n);
    shell_sort(arr,n);
    
    for (int i = n-1; i >=2; i--)
    {
        if (arr[i] < arr[i-1] + arr[i-2])
        {
            int p = (arr[i] + arr[i-1] + arr[i-2]) / 2;
            std::cout << "the sides of triangle is: "<< arr[i] << " " << arr[i-1] << " " <<arr[i-2] << std::endl;   
            std::cout << "end the square is: "<< sqrt(p*(p-arr[i])*(p-arr[i-1])*(p-arr[i-2])) << std::endl;
            return;
        }
    }
    
    std::cout << "\nundefined." << std::endl;
}


void task_20_modified()
{
    Timer t;
    static const int n = 6;
    int arr[n] {10000, 40, 200, 100, 250, 70};
    shell_sort(arr,n);



}

void extra_task_three() 
{
    Timer t;
    static const int n = 6;
    int arr[n] {10000, 40, 200, 100, 250, 70};
    shell_sort(arr,n);

    int counter = 0;
    
    

    
    std::cout << "\nnum of non-degenerate triangles is " << counter << std::endl;

    std::cout << "Time elapsed: " << t.elapsed() << " sec."<<  std::endl;
    

}

void solution() 
{   
    int size;
    std::cout <<"Enter the count of shops:";
    std::cin >> size;
    double arr[size];
    std::cout << "Enter the price of each stuffs:" << std::endl;
    input(arr,size);

    int sum=0;
    shell_sort(arr, size);
    for (int count = size/5; count < size; count++)sum+=arr[count];
    std::cout << sum << std::endl;
}

int main()
{
        std::cout << "Among the tasks below:" <<std::endl;
        std::cout << "1. lab work(12 option)." << std::endl;
        std::cout << "2. Extra task #18." << std::endl;
        std::cout << "3. Extra task #19." << std::endl;
        std::cout << "4. Extra task #20." << std::endl;
        std::cout << "select the task number you want to compile, press 0 for leave:";
        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "\nМагазин, що торгує лише цілісними окремими товарами влаштував розпродаж, за правилами якого покупці мають право на власний";
            std::cout << "розсуд групувати будь-які вибрані ними товари на групи по 5 товарів, і платити лише за 4 дорожчих із них, а 5-й (найдешевший у групі) отримувати безплатно.\n" << std::endl;
             solution();  
            break;
        case 2:
            std::cout << "\nЄ дві сукупності цілих додатних чисел. Одна виражає ширини тих прогалин, які дуже бажано перекрити мостами.";
            std::cout << "Якумаксимальну кількість прогалин вдасться перекрити мостами?\n" << std::endl;
            extra_task_one();
            break;

        case 3:
            std::cout << "\nДано сукупність з n (n≥4) дійсних додатних чисел, що являють собою довжини відрізків. Серед цих відрізків слід вибрати три різні, і";
            std::cout <<"сформувати з них трикутник. Які з відрізків слід вибрати, щоб отриманий трикутник мав максимально можливу за вказаних умов площу?";
            std::cout << "(Програма повинна вивести довжини вибраних трьох відрізки, і площу, обчислену на їх основі.)\n" << std::endl;
            extra_task_two();
            break;      

        case 4:
            std::cout << "\nДано сукупність з n (n≥4) дійсних додатних чисел, що являють собою довжини відрізків.";
            std::cout << "Скільки є різних способів вибрати такі три різні з них, щоб з них можна було сформувати не вироджений трикутник?\n" << std::endl  ;
            extra_task_three();
            break;

        case 0:
            return 0;
        default:
            std::cout << "Incorrect input, please, try again." << std::endl;
            break;
        }
   
    
    return 0;
}