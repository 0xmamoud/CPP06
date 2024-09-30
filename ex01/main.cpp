#include "Serializer.hpp"
#include <iostream>

int main() {
  Data data;

  data.a = 42;
  data.b = 21;

  uintptr_t raw = Serializer::serialize(&data);
  Data *ptr = Serializer::deserialize(raw);

  std::cout << "Original address (data pointer): " << &data << std::endl;
  std::cout << "Serialized value: " << raw << std::endl;
  std::cout << "Deserialized address (ptr): " << ptr << std::endl;

  std::cout << "ptr->a: " << ptr->a << std::endl;
  std::cout << "ptr->b: " << ptr->b << std::endl;

  return 0;
}
