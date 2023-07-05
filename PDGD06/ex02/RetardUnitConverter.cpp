#include <iomanip>
#include <iostream>
#include <sstream>

int main()
{
    std::string input;
    while (std::getline(std::cin, input)) {
        std::stringstream ss(input);
        double temperature;
        std::string scale;
        ss >> temperature >> scale;
        if (scale == "Celsius" || scale == "C") {
            double fahrenheit = (temperature * 9.0 / 5.0) + 32;
            std::cout << std::fixed << std::setprecision(3) << std::setw(16)
                      << fahrenheit << "\tFahrenheit" << std::endl;
        } else if (scale == "Fahrenheit" || scale == "F") {
            double celsius = (temperature - 32) * 5.0 / 9.0;
            std::cout << std::fixed << std::setprecision(3) << std::setw(16)
                      << celsius << "\tCelsius" << std::endl;
        } else {
            std::cout << "Invalid scale." << std::endl;
        }
    }
    return 0;
}
