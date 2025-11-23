#include <iostream>
using namespace std;
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

bool isSymmetricBinary(int num) {
    int binary[32];
    int length = 0;

    while (num > 0) {
        binary[length] = num % 2;
        num /= 2;
        ++length;
    }

    for (int i = 0; i < length / 2; ++i) {
        if (binary[i] != binary[length - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    cout << "Prime numbers with symmetric binary before: " << N << ":\n";

    for (int i = 2; i <= N; ++i) {
        if (isPrime(i) && isSymmetricBinary(i)) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}