#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


void S(const double x, const double eps, int& n, double& s);


void A(const double x, const int n, double& a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;


    cout << "-----------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << " |"
        << setw(10) << "ln(x)" << " |"
        << setw(10) << "S" << " |"
        << setw(5) << "n" << " |"
        << endl;
    cout << "-----------------------------------------" << endl;


    x = xp;
    while (x <= xk)
    {
        if (x > 0) {
            S(x, eps, n, s);
            cout << "|" << setw(7) << setprecision(2) << x << " |"
                << setw(10) << setprecision(5) << log(x) << " |"
                << setw(10) << setprecision(5) << s << " |"
                << setw(5) << n << " |"
                << endl;
        }
        else {
            cout << "|" << setw(7) << setprecision(2) << x << " |"
                << setw(10) << "undefined" << " |"
                << setw(10) << "undefined" << " |"
                << setw(5) << "n/a" << " |"
                << endl;
        }

        x += dx;
    }

    cout << "-----------------------------------------" << endl;
    return 0;
}


void S(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double z = (x - 1) / (x + 1);
    double z_pow = z;
    s = 0;
    double R;

    do {
        R = 2 * z_pow / (2 * n + 1);
        s += R;
        n++;
        z_pow *= z * z;
    } while (abs(R) >= eps);
}


void A(const double x, const int n, double& a)
{

}
