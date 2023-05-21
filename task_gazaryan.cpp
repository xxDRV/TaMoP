#include <iostream>
#include <vector>

// Функция, проверяющая монотонность заданной функции на множестве M1
bool isMonotonic(const std::vector<int>& M1) {
    int size = M1.size();

    // Проверяем монотонность по возрастанию
    bool isIncreasing = true;
    for (int i = 1; i < size; i++) {
        if (M1[i] < M1[i - 1]) {
            isIncreasing = false;
            break;
        }
    }

    // Проверяем монотонность по убыванию, только если функция не является монотонной по возрастанию
    bool isDecreasing = true;
    if (!isIncreasing) {
        for (int i = 1; i < size; i++) {
            if (M1[i] > M1[i - 1]) {
                isDecreasing = false;
                break;
            }
        }
    }

    return isIncreasing || isDecreasing;
}

int main() {
    setlocale(LC_ALL, "Rus");
    // Пример использования
    std::vector<int> M1 = { 1, 6, 2, 8 }; // Измените этот вектор на свое множество M1

    if (isMonotonic(M1)) {
        std::cout << "Функция монотонна на множестве M1." << std::endl;
    }
    else {
        std::cout << "Функция не является монотонной на множестве M1." << std::endl;
    }

    return 0;
}