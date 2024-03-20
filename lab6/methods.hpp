void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void input(double *arr, int size)
{
    for (int i = 0; i < size; i++)std::cin >> arr[i];
}
void shell_sort(auto data[], int size) 
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

void selection_sort(int *arr, int size)
{
    for (int i = 0; i < size -1; i++)
    {
        int smallestIndex = i;

        for (int j = i+1; j < size; j++)
        {
            if (arr[smallestIndex] < arr[j])
                smallestIndex = j;

            swap(&arr[smallestIndex], &arr[i]);            
        }

                
    }
}