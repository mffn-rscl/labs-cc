#include <iostream>
#include <chrono>
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

void output(int **arr, int cols, int rows)
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a= *b;
    *b = temp;
}

void reversed_selection_sort(int **arr, int cols, int i)
{
    for (int j = cols-1; j > 0; j--)
    {
        int smallestIndex = j;
        for (int k = j-1; k >=0; k--)
        {
            if (arr[smallestIndex][i] >arr[k][i])smallestIndex = k;
        }
        swap(&arr[smallestIndex][i], &arr[j][i]);
    }
}

void modified_bouble_sort(int **arr, int cols, int k)
{
    for (int i = 0; i < cols-1; i++)
    {
        bool swaped = false;
        for (int j = 0; j < cols-i-1; j++)
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


void sorted_cols()
{
    Timer t;

    int cols = 4, rows = 5;
    int** arr = new int*[cols];
    for (int i = 0; i < cols; i++)arr[i] = new int[cols];

    int count = 1;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)arr[i][j] = count++;
    }
    

    for (int i = 0; i < rows; i++) 
    {((i+1) % 2 != 0) ? modified_bouble_sort(arr, cols, i) : reversed_selection_sort(arr,cols,i);}
    

    std::cout << "\nResult: " << std::endl;
    output(arr,cols,rows);   
    std::cout << "Time elapsed: " << t.elapsed() << " sec."<<  std::endl;
}

int main()
{
    sorted_cols();
    return 0;
}