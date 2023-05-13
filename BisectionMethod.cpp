#include <iostream>
#include <math.h>
using namespace std;

double fx(double x)
{
    double y;
   y = pow(x, 3.0) - 3 * pow(x, 2.0) + 9 * x - 8;
    //y = pow(x, 2) - 4;
    return y;
}

double sgn(double a, double b, double TOL, int max_iter) {
    double xcent = 0;
    int iter = 0;
    while (iter < max_iter) {
        //double xcent, y_xcent;
        xcent = (a + b) / 2;
        //y_xcent = fx(xcent);
        //cout << "\n f(x)=" << y_xcent << ", inf=" << a << ",sup=" << b << "\n";
        if (abs(a - b) < TOL || abs(fx(xcent)) < TOL) {
            break;
        }

        if (fx(a) * fx(xcent) < 0) {
            b = xcent;
        }
        else {
            a = xcent;
        }
        iter++;
    }
    return xcent;
}

int main()
{

    double a,b;

    //cout << "interval a, b = ";
    cin >> a >> b;

    if (fx(a) * fx(b) >= 0) {
        //ÉGÉâÅ[
        std::cout << "same sign at a and b \n";
        return 1;
    }
    

    double xcent = sgn(a, b, 1e-10, 1000);
    //cout << xcent;
    printf("%2.10f\n", xcent);

    return 0;
}

