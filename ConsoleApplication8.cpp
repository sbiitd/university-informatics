#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

void inputSet(std::vector<int>* set) {
    int size;
    std::cout << "Введите размер множества: ";
    std::cin >> size;

    std::cout << "Введите элементы множества:" << std::endl;
    for (int i = 0; i < size; i++) {
        int element;
        std::cin >> element;
        set->push_back(element);
    }

    std::sort(set->begin(), set->end());
    set->erase(std::unique(set->begin(), set->end()), set->end());
}

std::vector<int> findCommonGreaterThanT(const std::vector<int>& setA, const std::vector<int>& setB, int t) {
    std::vector<int> result;

    for (const int& elem : setA) {
        if (elem > t && std::find(setB.begin(), setB.end(), elem) != setB.end()) {
            result.push_back(elem);
        }
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> A, B;
    int t;

    std::cout << "Введите значение t: ";
    std::cin >> t;

    inputSet(&A);
    inputSet(&B);

    std::vector<int> common = findCommonGreaterThanT(A, B, t);

    if (common.empty()) {
        std::cout << "Нет общих элементов больше " << t << std::endl;
    }
    else {
        std::cout << "Общие элементы больше " << t << ": ";
        for (const int& elem : common) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
    system("pause")
}