#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <exception>
#include <string>
class ScalarConverter {

private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &copy);
  ScalarConverter &operator=(const ScalarConverter &copy);
  ~ScalarConverter();

public:
  static void convert(std::string str);

  class ImpossibleException : public std::exception {
    virtual const char *what() const throw();
  };
};

#endif // !SCALARCONVERTER_HPP
