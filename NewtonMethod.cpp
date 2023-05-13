#include <iostream>//用いるヘッダファイルが変わります。
#include <math.h>
//using namespace std;//std::を省略

//#include <iostream>
#include <iomanip> // Add this header for std::setprecision
//#include <cmath>

double f(double x) {
    return 2 - x*x - exp(x);
}

double g(double x) {//df/dx
    return -2*x- exp(x); //df/dx = d/dx ( x**3 -3 ) = 3x**2 
}

double Newton(double x) {
    const double eps = 1e-8;
    
    while (fabs(f(x)) > eps) {
        x = x - f(x) / g(x);        
    }

    return x;
}

int main()
{
    double x;
    std::cin >> x;
    std::cout << std::setprecision(7) << std::fixed << (double)Newton(x) << std::endl;//C++ language
}

