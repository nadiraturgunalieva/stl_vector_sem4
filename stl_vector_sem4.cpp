#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    setlocale(LC_ALL, "Rus");

    // 1. Чтение из файла целочисленного одномерного вектора
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    int num;
    while (file >> num) {
        vec.push_back(num);
    }
    file.close();

    // 2. Реверсирсия последовательности элементов вектора
    std::reverse(vec.begin(), vec.end());
    std::cout << "Реверсированный вектор:";
    for (int num : vec) {
        std::cout << " " << num;
    }

    // 3. Нахождение минимального элемента
    int min_element = *std::min_element(vec.begin(), vec.end());

    std::cout << "\nМинимальный элемент: " << min_element << "\n";

    // 4. Удаление из вектора всех четных элементов
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }), vec.end());

    std::cout << "Новый вектор:";
    for (int num : vec) {
        std::cout << " " << num;
    }

    // 5. Сортировка вектора в убывающей последовательности
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    // 6. Вставка произвольного элемента, не нарушая сортировку
    int new_element = 17;
    vec.insert(std::upper_bound(vec.begin(), vec.end(), new_element, std::greater<int>()), new_element);

    // 7. Определение индекса заданного элемента
    int target_element = 17;
    auto it = std::find(vec.begin(), vec.end(), target_element);
    int index = (it != vec.end()) ? std::distance(vec.begin(), it) : -1;
    std::cout << "\nИндекс элемента " << target_element << ": " << index << "\n";

    // 8. Удаление дублированных элементов
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    std::cout << "Новый вектор:";
    for (int num : vec) {
        std::cout << " " << num;
    }


    // Выводим результаты

    std::cout << "\nРеверсированный вектор:";
    for (int num : vec) {
        std::cout << " " << num;
    }
    std::cout << "\nМинимальный элемент: " << min_element << "\n";
    std::cout << "Вектор без четных элементов, отсортированный в порядке убывания:";
    for (int num : vec) {
        std::cout << " " << num;
    }
    std::cout << "\nИндекс элемента  " << target_element << ": " << index << "\n";

    return 0;
}