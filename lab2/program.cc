#include <iostream>
#include <climits>
#include <cmath>

int cycles;

void doBlockOne(int n)
{
    int number;
    int maxNum = INT_MIN; 
    int minNum = INT_MAX; 
    int i = 0;
    std::cout << "Виберіть один із циклів, який ви хочете використати в програмі(for - 1, while - 2, do while - 3): ";
    std::cin >> cycles;
    switch (cycles)
    {
    case 1:
        for (int i = 1; i <= n; i++)
        {
            std::cout << "Введіть " << i << " число: " <<  std::endl;
            std::cin >> number;

            if(number > maxNum)
            {
                maxNum = number;
            }
            if (number < minNum)
            {
                minNum = number;
            }
        }
        
        break;
    case 2:
        while( i < n)
        {
            i++;
            
            std::cout << "Введіть " << i << " число: " <<  std::endl;
            std::cin >> number;

            if(number > maxNum)
            {
                maxNum = number;
            }
            if (number < minNum)
            {
                minNum = number;
            }
        }
        break;
    case 3:
          
        do{
            i++;
            std::cout << "Введіть " << i << " число: " <<  std::endl;
            std::cin >> number;

            if(number > maxNum)
            {
                maxNum = number;
            }
            if (number < minNum)
            {
                minNum = number;
            }
        }while( i < n);
        break;
    

    default:
            std::cout << "команда не розпізнана, Зробіть, будь ласка, вибір із 1,2,3." << std::endl;

        break;
    }
   
      int difference = maxNum - minNum; 
    std::cout << "Різниця максимального і мінімального чисел дорівнює: " << difference << std::endl;

}

void doBlockTwo()
{
    int number = 1;
    int i = 1;
    int posCounter = 0;
    int negCounter = 0;
    std::cout << "\nпрограма буде працювати, допоки ви не введете 0." << std::endl; 
    std::cout << "Виберіть один із циклів, який ви хочете використати в програмі(for - 1, while - 2, do while - 3): ";
    std::cin >> cycles;
    switch (cycles)
    {
    case 1:
        for ( i = 1; i < 100; i++)
        {
            std::cout << "Введіть " << i << " число: " << std::endl;
            std::cin >> number; 
            if (number == 0)
            {
                i = 100;
            }
             if (number > 0)
            {
                posCounter++;
            }
            else if (number < 0) 
            {
                negCounter++;
            }      
            
        }
        
        break;
    case 2:
        while (number != 0){
            std::cout << "Введіть " << i << " число: " << std::endl;
            std::cin >> number; 

            if (number > 0)
            {
                posCounter++;
            }
            else if (number < 0) 
            {
                negCounter++;
            }      
            i++;
    }
        break;
    case 3:
        do{
            std::cout << "Введіть " << i << " число: " << std::endl;
            std::cin >> number; 

            if (number > 0)
            {
                posCounter++;
            }
            else if (number < 0) 
            {
                negCounter++;
            }        
            i++;
        }while (number != 0);
        break;        
    
    default:
            std::cout << "команда не розпізнана, Зробіть, будь ласка, вибір із 1,2,3." << std::endl;
        break;
    }
    
    if (negCounter > posCounter)
    {
        std::cout << "від'ємних чисел більше, ніж додатніх.\n" << std::endl;
    }
    else if (negCounter < posCounter)
    {
        std::cout << "додатніх чисел більше, ніж від'ємних.\n" << std::endl;
    }
    else 
    {
        std::cout << "кількість додатних та від'ємних чисел рівна.\n" << std::endl;
    }
}

void doBlockThree(int x,int n)
{
    double S;
    
    std::cout << "\nВиберіть один із циклів, який ви хочете використати в програмі(for - 1, while - 2, do while - 3): ";
    std::cin >> cycles;
    
    switch (cycles)
    {
    case 1:
         if(n % 2== 0)
        {
            S = (n-1)*x + pow(-1, 1+((n+2)%3/2)) * cos(n*x);
        
        }
        else 
        {
            S = (n-1) * x + pow(-1, 1+((n+2)%3/2)) *sin(x*n);
        }
        n--;
        if(n >= 1)
        {
            for (int i = n-1; i --> 1; )
            {
                S = i * x + sin(S);
        
                if(i % 2== 0)
                {
                
                    S = i*x + pow(-1, 1+((i+1)%3/2)) * cos(n*x);

                }

                else 
                {
                    S = i * x +  pow(-1, 1+((i+1)%3/2)) *sin(x*i);
                }

            }
            std::cout << sin(S)<< "\n\n";

        } 
        else 
        {
        
        std::cout << sin(S)<< "\n\n";
        }
        break;
    case 2:
        if (n >= 1)
        {
            while (n > 1)
            {
                if (n % 2 == 0)
                {
                    S = (n - 1) * x + pow(-1, 1 + ((n + 2) % 3 / 2)) * cos(n * x);
                }
                else
                {
                    S = (n - 1) * x + pow(-1, 1 + ((n + 2) % 3 / 2)) * sin(x * n);
                }

                S = (n - 1) * x + sin(S);

                n--;
            }
            std::cout << sin(S) << "\n\n";
        }
        else
        {
            std::cout << sin(S) << "\n\n";
        }
        break;
    case 3:
        if (n >= 1)
        {
            do
            {
                if (n % 2 == 0)
                {
                    S = (n - 1) * x + pow(-1, 1 + ((n + 2) % 3 / 2)) * cos(n * x);
                }
                else
                {
                    S = (n - 1) * x + pow(-1, 1 + ((n + 2) % 3 / 2)) * sin(x * n);
                }

                S = (n - 1) * x + sin(S);

                n--;
            } while (n > 1);
            std::cout << sin(S) << "\n\n";
        }
        else
        {
            std::cout << sin(S) << "\n\n";
        }
        break;   
    default:
            std::cout << "команда не розпізнана, Зробіть, будь ласка, вибір із 1,2,3." << std::endl;
        break;
    }
    
}

int main()
{
    int choice,n;
    do
    {
        std::cout <<"Для виконання блоку 1 (варіант 11) введіть 1" << std::endl;
        std::cout <<"Для виконання блоку 2 (варіант 34) введіть 2" << std::endl;
        std::cout <<"Для виконання блоку 3 (варіант 63) введіть 3" << std::endl;
        std::cout << "Для виходу з програми введіть 0\n" << std::endl;

        std::cin >> choice;

        switch (choice)
        {

        case 1:

            std::cout << "Виконую блок 1"<< std::endl;
            std::cout << "В першому блоці дана пословність n чисел. Програма знаходить різницю максимального та мінімального чисел." <<std::endl;
            std::cout << "Введіть значення n: ";
            std::cin >> n;
            doBlockOne(n);
            break;
    
    
        case 2:    
            std::cout << "Виконую блок 2" << std::endl;
            doBlockTwo();
            break;
    
    
    
        case 3: 

        std::cout << "Ви обрали блок 3." << std::endl;  
        std::cout << " умова до задачі:\n S = sin(x + cos(2x −sin(3x + cos(4x + sin(5x − cos(6x +...)...) (до sin(nx) чи cos(nx)включно, sin(nx) чи cos(nx) залежить від парності n; на кожні три рази двічі відбувається додавання, один раз віднімання)." << std::endl;
        std::cout << "\nВведіть значення n та х відповідно: ";

        int x;
        std::cin >> n >> x;
        doBlockThree(x,n);

        break;
        default:
            std::cout << "команда не розпізнана, Зробіть, будь ласка, вибір із 0,1,2,3." << std::endl;
            break;
    }    

    } while (choice != 0);
    return 0;
}