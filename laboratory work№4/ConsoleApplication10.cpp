#include <iostream>
#include <set>

using namespace std;

// Функция для ввода множества
set<int> inputSet() {
    set<int> result;
    int size;

    cout << "Введите размер множества: ";
    cin >> size;

    cout << "Введите элементы множества:" << endl;
    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        result.insert(element);
    }

    return result;
}

// Функция для поиска общих элементов, больших t
set<int> findCommonGreaterThanT(const set<int>& setA, const set<int>& setB, int t) {
    set<int> result;

    auto itA = setA.upper_bound(t);

    while (itA != setA.end()) {
        if (setB.find(*itA) != setB.end()) {
            result.insert(*itA);
        }
        ++itA;
    }

    return result;
}

// Функция для вывода множества
void printSet(const set<int>& s) {
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (it != s.begin()) {
            cout << " ";
        }
        cout << *it;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    set<int> A, B;
    int t;

    cout << "Введите значение t: ";
    cin >> t;

    A = inputSet();
    B = inputSet();

    set<int> common = findCommonGreaterThanT(A, B, t);

    if (common.empty()) {
        cout << "Нет общих элементов больше " << t << endl;
    }
    else {
        cout << "Общие элементы больше " << t << ": ";
        printSet(common);
        cout << endl;
    }

    return 0;
}