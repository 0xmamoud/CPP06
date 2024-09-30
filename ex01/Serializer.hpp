#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>

typedef struct s_Data {
  int a;
  int b;
} Data;

class Serializer {
private:
  Serializer();
  Serializer(const Serializer &copy);
  Serializer &operator=(const Serializer &copy);
  ~Serializer();

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif // !SERIALIZER_HPP
