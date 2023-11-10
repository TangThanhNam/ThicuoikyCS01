#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cout << "T = ";
    cin >> T;

    while (T--) {
        int n, sum = 0;
        cout << "n = ";
        cin >> n;

        for (int i = 1; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                sum += i;
                if (i != n / i) {
                    sum += n / i;
                }
            }
        }

        
        int sqrt_n = sqrt(n);
        if (sqrt_n * sqrt_n == n) {
            sum -= sqrt_n;
        }

        cout << "Sum of divisors: " << sum << endl;
    }

    return 0;
}


