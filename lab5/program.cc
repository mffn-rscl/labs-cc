// this cpp file contains minimal quant of libs 
#include <iostream> 
#include <ctime> // for time()
#include <cstdlib> // for rand() & srand()
#include <thread> //find an explain
#include <chrono>// find an explain
#include <vector>
#include <algorithm> // std::sort
#include <unordered_map> // hash-table

int binarySearch(int *array, int size, int target)  // binarySearch
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (array[mid] == target) 
        {   return (mid + 1); }
        else if (array[mid] < target) { left = mid + 1; }
        else{ right = mid - 1; }
    }
    return 0;
}

void choiceSort(int size, int *array) //choice sort
{
    for (int i = 0; i < size - 1; i++)
    {
        int smallestIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (array[j] > array[smallestIndex]) { smallestIndex = j; }
        }
        std::swap(array[i],array[smallestIndex]);
    }
}

void inputInOneLine(int size, int *array) {  for (int i = 0; i < size; i++) { std::cin >> array[i]; }}

void randNumbersForArray(int size, int *array)
{
    srand(static_cast<int>(time(nullptr))); //find an explain
    std::cout << "finished array: ";
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100; // generating an elements of array with range [-99; 99]
        
        if (array[i] % 2 == 0) {  array[i] = -array[i]; } // adding negative numbers
       
        std::cout << array[i]<< " ";
    }

}

void inputSeparately(int size, int *array)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the " << i + 1 << " value of array:";
        std::cin >> array[i];
        std::cout << std::endl;
    }
}

void findTheMaxValFromArray(int size,int *array) // initializing func for two max numbers from array without using lib <climits>
{
    int max1 = array[0], max2 = array[1], temp;
    if (max1 < max2)
    {
        temp = max1;
        max1 = max2;
        max2 = temp;
    }
    
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

void taskOne()
{
    

}
void taskSeven()
{
    
}
void taskSix()
{

}

void taskFive()
{
    std::string str;
    getline(std::cin,str);
    std::cin.ignore();
    int N,M;
    std::cin >> N;
    std::vector<int> arr1, arr2;
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr1[i];
    }
    
    std::cin >> M;

    for (int i = 0; i < M; i++)
    {
        std::cin >> arr2[i];
    }

    if (str == "UNION")
    {
       std::vector<int> solution;





        
    }
    else if (str == "INTERSECTION")
    {
       std::vector<int> solution;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; i < M; i++)
            {
                if (arr2[j] == arr1[i])
                {
                    solution.push_back(arr1[j]);
                    break; 
                }
                
            }
            std::cout << solution[i] << " ";
        }

        
    }
    else if (str == "DIFFERENCE")
    {
       std::vector<int> solution(arr1);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; i < M; i++)
            {
                if (arr2[j] == arr1[i])
                {
                    solution.erase(solution.begin() + i);
                }
                
            }
        }
    }
}

void taskFour()
{
    
        
}

void taskThree()
{
     int N, M;
    std::cin >> N;
    std::vector<int> arr1(N);
    for (int i = 0; i < N; ++i) { std::cin >> arr1[i]; }

    std::cin >> M;
    std::vector<int> arr2(M);
    for (int i = 0; i < M; ++i) { std::cin >> arr2[i];}

    std::vector<int> sortedArr1(arr1);
    
    std::sort(sortedArr1.begin(), sortedArr1.end());

    std::unordered_map<int, int> indexMap;
    for (int i = 0; i < N; ++i) { indexMap[sortedArr1[i]] = i + 1; }

    for (int i = 0; i < M; ++i) {std::cout << indexMap[arr2[i]] << " "; }

}

int taskTwo()
{
     long int a, b;
    std::cin >> a >> b;

   long int low = a, high = b, mid, answer;
    std::string result;
    
    for (int i = 0; i < 50; ++i) {
        mid = (low + high) / 2;
        std::cout << "try " << mid << std::endl;
        std::cout.flush();

        std::cin >> result;

        if (result == "answer") {
            std::cout << "answer " << mid << std::endl;
            return 0;
        } 
        else if (result == "+") {low = mid + 1;} 
        
        else {
            high = mid - 1;
            answer = mid;
        }
    }

    std::cout << "answer " << answer << std::endl;
    return 0;
}


void ToSquaresWithTwoMax()
{
    int size;
    std::cout << "enter here length of array:";
    std::cin >> size;
    int array[size];

    std::cin.ignore();
    char choice;
    
   
    std::cout << "Do you want to fill array by random or fill it by yourself? ('r' - random, 'y' - by youreslf): ";
    std::cin >> choice;
    
    switch (choice)
    {
         
        case 'r':
            std::cout << "you chose to fill array by random. "<<std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
            randNumbersForArray(size, array); 
            break;
        case 'y':
            std::cout << "you chose to fill array by yourself. "<<std::endl;
            std::cout << "fill the array in one line?(y/n): ";
            
            char choiceLine;
            std::cin >> choiceLine;
            
            (choiceLine == 'y') ? inputInOneLine(size, array) : inputSeparately(size, array);
           
            std::cout << "finished array: ";      
            
            for (int i = 0; i < size; i++) { std::cout << array[i] << " "; }
            
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
            break;
        default:
            std::cerr << "incorrect input. Try again." << std::endl;
            break;
    }
   

    std::cout << "\nreplacing all positive numbers into their squares... " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(700));

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
    int choice;
    do
    {
        std::cout << "Here we have 8 task, where 15-21 are bonuses. Pick a task number for continue(14-21).If you want to leave, press 0:";
        std::cin >> choice;
        switch (choice)
        {
        case 0: 
            std::cout << "leaving.." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
            break;
            
        case 14:
            std::cout << "You chose #14." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
            std::cout << "Need to change positive numbers to their squares in array, after find two maximums." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
            ToSquaresWithTwoMax();
            break;
        
        case 15:
            std::cout << "You chose #15." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
            taskOne();
            break;
        
        case 16:
            std::cout << "You chose #16." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(700));   
            taskTwo();
            break;
        case 17:
            std::cout << "You chose #17." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
            taskThree();
            break;
        
        case 18:
            std::cout << "You chose #18." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
            taskFour();
            break;
        
        case 19:
            std::cout << "You chose #19." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
            taskFive();
            break;

        case 20:
            std::cout << "You chose #20." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(700)); 
            taskSix(); 
            break;

        case 21:
            std::cout << "You chose #21." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(700));  
            taskSeven();
            break;
                
        default:
            std::cerr << "incorrect input. Try again." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            
        }
    } while (choice != 0);
    return 0;
} 