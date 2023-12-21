/*default libs*/
#include <iostream>
#include <vector>
#include <unordered_map> // for hash-table
#include <algorithm> // only for set_union, set_intersection, set_difference
#include "methods.hpp"
void Table() 
{
    int n, k;
    std::cin >> n;
    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {  std::cin >> arr[i]; }

    std::cin >> k;
    std::vector<int> sortedArr(arr);
    std::sort(sortedArr.rbegin(), sortedArr.rend());// make this task without sort

    for (int i = 0; i < n; i++)  { if (sortedArr[k-1] == arr[i]){ std::cout << i+1 << std::endl;}    }
}

int GuessedNumber(long int a, long int b)
{
    long int low = a, high = b, mid, answer;
    std::string result;
    
    for (int i = 0; i < 50; i++) {
        mid = (low + high) / 2;
        std::cout << "try " << mid << std::endl;
        std::cout.flush();

        std::cin >> result;

        if (result == "=") {
            std::cout << "answer " << mid << std::endl;
            return 0;
        } 
        else if (result == "+") 
        {
            low = mid + 1;
        } 
        
        else if(result == "-")
        {
            high = mid - 1;
            answer = mid;
        }
       
        
    }

    std::cout << "answer " << answer << std::endl;
    return 0;
}

void SearchingElementsInArray1()
{
    int N, M;
    std::cin >> N;
    std::vector<int> arr1(N);
    for (int i = 0; i < N; ++i) {   std::cin >> arr1[i]; }

    std::cin >> M;
    std::vector<int> arr2(M);
    for (int i = 0; i < M; ++i) {  std::cin >> arr2[i]; }

    std::vector<int> sortedArr1(arr1);
    
    choiceSort(N, &sortedArr1);

    std::unordered_map<int, int> indexMap;
    for (int i = 0; i < N; ++i) {  indexMap[sortedArr1[i]] = i + 1;  }

    for (int i = 0; i < M; ++i) { std::cout << indexMap[arr2[i]] << " ";}

}


void plurals()
{
    std::string str;
    getline(std::cin, str);
    std::cin.ignore();
    int size1, size2;
    std::cin >> size1;

    std::vector<int> A(size1);
    for (int i = 0; i < size1; i++) {
        std::cin >> A[i];
    }

    std::cin >> size2;
    std::vector<int> B(size2);
    for (int i = 0; i < size2; i++) 
    {
        std::cin >> B[i];
    }


    if (str == "UNION") 
    {
        std::vector<int> solution(A.size() + B.size());
        std::set_union(begin(A), end(A), begin(B), end(B), begin(solution));

        for (int i : solution) {   std::cout << i << " ";  }
    } 
    else if (str == "INTERSECTION") 
    {
        std::vector<int> solution;
        std::set_intersection(begin(A), end(A), begin(B), end(B), back_inserter(solution));

        for (int i : solution) 
        {
            std::cout << i << " ";
        }
    } 
    else if (str == "DIFFERENCE") 
    {
        std::vector<int> solution;
        std::set_difference(begin(A), end(A), begin(B), end(B), back_inserter(solution));

        for (int i : solution) 
        {
            std::cout << i << " ";
        }
    }
}

