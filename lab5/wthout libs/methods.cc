/*default libs*/
#include <vector>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void choiceSort(int size, std::vector<int> array) //choice sort
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

void quickSort()
{

}

