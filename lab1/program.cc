#include <iostream>
#include <cmath>
void cubeVolume()
{

    std::cout << "Введіть довжину сторони куба, для обчислення об'єму: ";
    double sideOfcube;
    std::cin >> sideOfcube;

    double volume = pow(sideOfcube, 3);

    std::cout << "сторона куба дорівнює " << sideOfcube << ", та його об'єм дорівнює " << volume << std::endl;
}

void example()
{
    double x; 
    std::cin >> x; 
    
    std::cout << "результат: " << pow(abs(x + 1), 0.25) + pow(x, -2) << std::endl;
}
void isInRange()
{
    double x, y;
    
    std::cin >> x >> y;
    
    bool isInRange = (abs(x) <= 1 && y <= 2 && y >= abs(x) - 1);
    
    if (isInRange) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
int main()
{
    int choice;
    std::cout << "Choose the task programm(enter 1,2,3) or if you wanna leave, press 0:";
    std::cin;
    
    do
    {
         switch(choice)
    {
    case 1:
    cubeVolume();
        break;
    case 2:
        example();
        break;
    case 3:
        isInRange();
        break;    
    default:
        std::cerr << "Incorrect input. Please, try again." << std::endl;
        break;
    }
    } while (choice !=0);
    
    return 0;
}