#include <iostream>

int countGreaterThanT(const int* arr, int size, int t) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > t) {
            count++;
        }
    }
    return count;
}

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int SIZE = 5;
    int A[SIZE], B[SIZE];
    int t;

    std::cout << "Введите значение t: ";
    std::cin >> t;

    std::cout << "Введите " << SIZE << " элементов массива A:" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cin >> A[i];
    }

    std::cout << "Введите " << SIZE << " элементов массива B:" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cin >> B[i];
    }

    int countA = countGreaterThanT(A, SIZE, t);
    int countB = countGreaterThanT(B, SIZE, t);

    if (countA < countB) {
        std::cout << "Массив A имеет меньше элементов больше " << t << " (" << countA << "):" << std::endl;
        printArray(A, SIZE);
        std::cout << "Массив B (" << countB << "):" << std::endl;
        printArray(B, SIZE);
    }
    else {
        std::cout << "Массив B имеет меньше элементов больше " << t << " (" << countB << "):" << std::endl;
        printArray(B, SIZE);
        std::cout << "Массив A (" << countA << "):" << std::endl;
        printArray(A, SIZE);
    }

    return 0;
}