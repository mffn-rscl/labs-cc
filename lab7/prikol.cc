#include <iostream>
#include <vector>
class C_Dictionary
{
    private:
        int m_index;
        int m_product;

    public:
        C_Dictionary(int index, int product) : m_product(product), m_index(index) {}

    int getProduct() const {return m_product;}
    int getIndex() const {return m_index;}

};
void input(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) std::cin >> arr[i][j];
    }
}

void dictionary_swap(C_Dictionary *a, C_Dictionary *b)
{
    C_Dictionary temp = *a;
    *a = *b;
    *b = temp;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void dictionary_selection_sort(std::vector<C_Dictionary> &dictionary, int cols)
{
    for (int i = cols-1; i > 0; i--)
    {
        int smallestIndex = i;
        for (int j = i-1; j >= 0; j--)
        {
            if (dictionary[smallestIndex].getProduct() > dictionary[j].getProduct()) smallestIndex = j;
        }
        dictionary_swap(&dictionary[smallestIndex], &dictionary[i]);        
    }
    
}
void sort_by_product_of_nums()
{
    int cols, rows, product = 1;
    std::cout << " enter the length of cols & rows:";
    std::cin >> rows >> cols;
    int** arr = new int*[cols];
    for (int i = 0; i < rows; i++)arr[i] = new int[rows];

    std::vector<C_Dictionary> dictionary;

    std::cout << "Enter the elements of matrix: " << std::endl;
    input(arr,rows, cols);

    for (int i = 0; i < cols; i++)
    {
        for (int  j = 0; j < rows; j++)
        {
            product*=arr[j][i];
        }
        
        C_Dictionary t(i,product);
        dictionary.push_back(t);
        product = 1;

    }
    dictionary_selection_sort(dictionary, cols);

    int solution[rows][cols];
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++) solution[j][i] = arr[j][dictionary[i].getIndex()];
        
    }
    

    std::cout << "solution: " << std::endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << solution[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
     
    for (int i = 0; i < rows; ++i) delete[] arr[i];
    delete[] arr;
}

int main()
{
    sort_by_product_of_nums();
    return 0;
} 