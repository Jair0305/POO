#include <iostream>
#include <iomanip>

using namespace std;

void Redondeo(float Cantidad, int Decimales);

int main()
{

    Redondeo(23.43423, 4);

    return 0;
}

void Redondeo(float Cantidad, int Decimales)
{
    cout << fixed << setprecision(Decimales) << Cantidad << endl;
}
