#ifndef VECTOR_HPP
#define VECTOR_HPP

template <typename T>
class Vector
{
private:
  T *data;
  int size;
  int capacity;

public:
  Vector();
  ~Vector();
  void push_back(const T &value);
  int getSize() const;
  T &operator[](int index);
};

#endif // VECTOR_HPP