#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

// Kiem tra so nguyen to
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}


bool isSuperPrime(int num) {
    while (num > 0) {
        if (!isPrime(num)) return false; 
        num /= 10; 
    }
    return true; 
}

// Tim va in ra cac so sieu nguyen to
void printSuperPrimes(int n) {
    queue<int> superPrimes; // hang doi luu tru so sieu nguyen to

    // Kiểm tra từ 2 den n
    for (int i = 2; i <= n; ++i) {
        if (isSuperPrime(i)) {
            superPrimes.push(i); // neu i la so siu nguyen to, them vao hang doi
        }
    }

    // In ra cac so siu nguyen to
    while (!superPrimes.empty()) {
        cout << superPrimes.front() << " ";
        superPrimes.pop();
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap so n: ";
    cin >> n;
    printSuperPrimes(n);
    return 0;
}
