#include <iostream>
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

void extra_task_three() 
{
    Timer t;
    static const int n = 6;
    int arr[n] {10000, 40, 200, 100, 250, 70};
    shell_sort(arr,n);

    int counter = 0;
    
    for (int i = n - 1; i >= 2 ; i--)
    {
      for (int j = i-1; j >= 1 ; j--)
      {
        for (int k = j-1; k >= 0 ; k--)
        {
          if (arr[i]-arr[j]-arr[k] < 0)counter++;
        }
      }   
    }    

    
    std::cout << "\nnum of non-degenerate triangles is " << counter << std::endl;

    std::cout << "Time elapsed: " << static_cast<double>(t.elapsed())<< " sec."<<  std::endl;
    

}

int main()
{
    extra_task_three();
    return 0;
}