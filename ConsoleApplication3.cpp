#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    float x, y;

    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;

    float R = pow(1.0 / cos(sqrt(y)), 3); 
    float S = sqrt(fabs(x)) / log(y);

    cout << "R = " << R << endl;
    cout << "S = " << S << endl;

    float C = max(R, S);

    cout << "C = " << C << endl;
    system("pause");

    return 0;
}