#include "utils.hpp"
#include <cctype>
#include <cfloat>
#include <climits>
#include <iomanip>
#include <iostream>

bool include(std::string str) {
  const std::string array[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
  for (int i = 0; i < 6; i++) {
    if (str == array[i]) {
      return true;
    }
  }
  return false;
}

void charLiteral(std::string str) {
  if (str.length() == 1) {
    if (std::isprint(str[0])) {
      std::cout << "char: '" << str[0] << "'" << std::endl;
    } else {
      std::cout << "char: Non displayable" << std::endl;
    }
  } else {
    std::cout << "char: impossible" << std::endl;
  }
  std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
  std::cout << "float: : " << std::fixed << std::setprecision(1)
            << static_cast<float>(str[0]) << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(str[0]) << std::endl;
}

void intLiteral(std::string str) {
  int number = std::stoi(str);

  if (std::isprint(number)) {
    std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
  } else {
    std::cout << "char: Non displayable" << std::endl;
  }
  std::cout << "int: " << number << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1)
            << static_cast<float>(number) << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(number) << std::endl;
}

void floatLiteral(std::string str) {
  float number = std::stof(str);

  if (std::isprint(static_cast<int>(number))) {
    std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
  } else {
    std::cout << "char: Non displayable" << std::endl;
  }
  std::cout << "int: " << static_cast<int>(number) << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1) << number << "f"
            << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(number) << std::endl;
}

void doubleLiteral(std::string str) {
  double number = std::stod(str);

  if (std::isprint(static_cast<int>(number))) {
    std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
  } else {
    std::cout << "char: Non displayable" << std::endl;
  }
  std::cout << "int: " << static_cast<int>(number) << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1)
            << static_cast<float>(number) << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1) << number;
}

void minLiteral(void) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: " << INT_MIN << std::endl;
  std::cout << "float: " << FLT_MIN << std::endl;
  std::cout << "double: " << DBL_MIN;
}

void maxLiteral(void) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: " << INT_MAX << std::endl;
  std::cout << "float: " << FLT_MAX << std::endl;
  std::cout << "double: " << DBL_MAX;
}

void nanLiteral(void) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: nanf" << std::endl;
  std::cout << "double: nan" << std::endl;
}
