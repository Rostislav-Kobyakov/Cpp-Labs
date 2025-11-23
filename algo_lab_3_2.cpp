#include <iostream>
#include <vector>
#include <cmath>

void foldAndNumber(int k) {
    int size = pow(2, k);
    std::vector<int> numbers(size);

    for (int i = 0; i < size; i++) {
        int index = i;
        for (int j = k - 1; j >= 0; j--) {
            int mid = pow(2, j);
            int left = index / mid;
            int right = index % mid;

            if (left % 2 == 0) {
                index = right * mid + left;
            }
            else {
                index = (mid - 1 - right) * mid + left;
            }
        }
        numbers[index] = i + 1;
    }

    for (int i = 0; i < size; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int k;
    std::cin >> k;
    foldAndNumber(k);
    return 0;
}
