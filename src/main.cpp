#include <iostream>

using std::cout;
using std::cin;
using std::endl;

double power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    else if (exponent == 1) {
        return base;
    }

    double result = base;
    for (int i = 0; i < exponent - 1; i++) {
        result *= base;
    }
    return result;
}

void calculate_power() {
    int base, exponent;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;
    cout << power(base, exponent) << endl;
}

int main() {
    calculate_power;
    return 0;
}