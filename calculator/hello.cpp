#include <iostream>
#include <cmath>
#include <cstdlib>

int main() {
    std::string input;
    double angle;

    std::cout << "Введите угол в градусах или радианах: ";
    std::cin >> input;


    try {
        angle = std::stod(input);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: Введенное значение не является числом." << std::endl;
        return 1;
    }

    double radians;
    if (input.find("rad") != std::string::npos) {
        radians = angle;
    } else if (input.find("deg") != std::string::npos) {
        radians = angle * M_PI / 180.0;
    } else {
        std::cerr << "Ошибка: Не удалось определить единицы измерения угла (используйте 'rad' или 'deg')." << std::endl;
        return 1;
    }

    double tangent = tan(radians);
    double cotangent = 1.0 / tangent;

    std::cout << "Тангенс(" << angle << ") = " << tangent << std::endl;
    std::cout << "Котангенс(" << angle << ") = " << cotangent << std::endl;

    return 0;
}

