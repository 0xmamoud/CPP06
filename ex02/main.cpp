#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <math.h>

Base *generate() {
  int random = rand() % 3;
  switch (random) {
  case 0:
    return new A();
  case 1:
    return new B();
  case 2:
    return new C();
  default:
    return NULL;
  }
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "A" << std::endl;
    return;
  } catch (std::bad_cast &e) {
  }

  try {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "B" << std::endl;
    return;
  } catch (std::bad_cast &e) {
  }

  try {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "C" << std::endl;
    return;
  } catch (std::bad_cast &e) {
  }
}

void identify(Base *p) {

  if (dynamic_cast<A *>(p)) {
    std::cout << "A" << std::endl;
    return;
  }

  if (dynamic_cast<B *>(p)) {
    std::cout << "B" << std::endl;
    return;
  }

  if (dynamic_cast<C *>(p)) {
    std::cout << "C" << std::endl;
    return;
  }
}

int main() {

  {
    std::cout << "Test 1" << std::endl;
    Base *base = generate();
    identify(base);
    identify(base);
    delete base;
  }

  {
    std::cout << std::endl << "Test 2" << std::endl;
    Base *base = generate();
    identify(*base);
    identify(base);
    delete base;
  }

  {
    std::cout << std::endl << "Test 3" << std::endl;
    Base *base = generate();
    identify(*base);
    identify(base);
    delete base;
  }
  return 0;
}
