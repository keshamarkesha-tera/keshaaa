#include <iostream>
using namespace std;

int fibonacci3(int n) {
    if (n <= 1)
        return n;
    int fib3[n + 1];
    fib3[0] = 0;
    fib3[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib3[i] = fib3[i - 1] + fib3[i - 2];
    }
    return fib3[n];
}
int main() {
    int n;
    cout << "Enter the number n: ";
    cin >> n;
    cout << "Fibonacci Numbers: " << fibonacci3(n) << endl;
    return 0;
}
