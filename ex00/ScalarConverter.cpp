#include "ScalarConverter.hpp"
#include "utils.hpp"
#include <iostream>

ScalarConverter::ScalarConverter() {
  std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
  std::cout << "ScalarConverter copy constructor called" << std::endl;
  *this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
  std::cout << "ScalarConverter operator= called" << std::endl;
  return *this;
}

ScalarConverter::~ScalarConverter() {
  std::cout << "ScalarConverter destructor called" << std::endl;
}

void ScalarConverter::convert(std::string str) {

  if (include(str)) {

    if (str == "-inff" || str == "-inf")
      return minLiteral();

    if (str == "+inff" || str == "+inf")
      return maxLiteral();

    if (str == "nanf" || str == "nan")
      return nanLiteral();
    throw ImpossibleException();
  }

  if (str.length() == 1 && !isdigit(str[0])) {
    return charLiteral(str);
  }

  if (str[str.length() - 1] == 'f') {
    int i = 0;
    if (str[0] == '-' || str[0] == '+') {
      i++;
    }
    while (i < str.length() && (isdigit(str[i]) || str[i] == '.')) {
      i++;
    }
    if (i == str.length() - 1) {
      return floatLiteral(str);
    }
    throw ImpossibleException();
  }

  if (str.find('.') != std::string::npos) {
    int i = 0;
    if (str[0] == '-' || str[0] == '+') {
      i++;
    }
    while (i < str.length() && (isdigit(str[i]) || str[i] == '.')) {
      i++;
    }
    if (i == str.length()) {
      return doubleLiteral(str);
    }
    throw ImpossibleException();
  }

  if (isdigit(str[0]) || str[0] == '-' || str[0] == '+') {
    int i = 0;
    if (str[0] == '-' || str[0] == '+') {
      i++;
    }
    while (i < str.length() && isdigit(str[i])) {
      i++;
    }
    if (i == str.length()) {
      return intLiteral(str);
    }
    throw ImpossibleException();
  }

  throw ImpossibleException();
}

const char *ScalarConverter::ImpossibleException::what() const throw() {
  return "impossible to convert";
}
