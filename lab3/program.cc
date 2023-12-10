#include <iostream>
#include <cmath>
#include <climits>

double CalcTriangleSquare(int Bx, int By, int Cx, int Cy)
{
    return 0.5 * abs(Bx * (Cy - 0) + Cx * (0 - By));
}

void CalcTriangleSquareByPoints(int a, int b)
{
    int MODULE_A= abs(a);
    int MODULE_B = abs(b);
    double tempSquare, solutionSquare = INT_MAX;
    int Ax = 0, Ay = 0, Cx, Cy;

    for (int x = 0; x <= MODULE_A; x++)
    {
        for (int y = 0; y <= MODULE_B; y++)
        {
            tempSquare = CalcTriangleSquare(MODULE_A, MODULE_B, x, y);
            if ( tempSquare != 0 && tempSquare < solutionSquare) { solutionSquare = tempSquare; Cx = x; Cy = y;}
        }
    }

    std::cout << "\nSmallest square of triangle equals: " << solutionSquare << std::endl;
    std::cout << "Coordinates of point C equals: (" << ((a<0 && Cx != 0 ) ? '-' : ' ') << Cx << "; " <<((b<0 && Cy != 0) ? '-' : ' ') <<  Cy<< ")" << std::endl;
}

int main()
{
    std::cout << "Task #3. Lab #3\n" << std::endl;
    std::cout << "The coordinates of point A(0,0) are given, we need to find the coordinates of point C(x;y) so that the area of the triangle is minimal and at the same time canceled from zero.  " << std::endl;
    std::cout << "The program receives two values, a and b - the coordinates of point B on the Cartesian coordinate system, and calculates the minimum area of the triangle.\n" << std::endl;

    int a, b;
    std::cout << "Enter here the value x of point B:";
    std::cin >> a;



    std::cout << "Enter here the value y of point B:";
    std::cin >> b;

    CalcTriangleSquareByPoints(a, b);
    return 0;
}