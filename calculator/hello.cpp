#include <iostream>
#include <cmath>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Использование: " << argv[0] << " <угол_в_градусах_или_радианах>" << std::endl;
        return 1;
    }

    double angle = std::atof(argv[1]);
    double tangent, cotangent;

    if (std::string(argv[1]).find("pi") != std::string::npos) {
        tangent = tan(angle);
        cotangent = 1.0 / tan(angle);
    } else {
        double angle_radians = angle * M_PI / 180.0;
        tangent = tan(angle_radians);
        cotangent = 1.0 / tan(angle_radians);
    }

    std::cout << "Тангенс угла: " << tangent << std::endl;
    std::cout << "Котангенс угла: " << cotangent << std::endl;

    return 0;
}
