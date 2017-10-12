#ifndef _log_n_vector_h_
#define _log_n_vector_h_

#include <cmath>
#include <memory>
#include <vector>

template <typename T>
class LogNVector {
  // Members
private:
  std::vector<std::unique_ptr<T[]> > arrays;
  int size
  int capacity;

  // Constructor
public:
  LogNVector() {
    // TODO
  }
  LogNVector(const LogNVector& other) : LogNVector() {
    // TODO
  }
  LogNVector(std::initializer_list<T> ilist) : LogNVector() {
    // TODO
  }
  ~LogNVector() {
    // TODO
  }

  // Getters
public:
  int size() const noexcept {
    return this->size;
  }
  int capacity() const noexcept {
    return this->capacity;
  }

  // Modifiers
public:
  void push_back(const T& value) {
    // TODO
  }

  // Operators
public:
  const T& operator[](int index) const {
    // TODO
  }
  T& operator[](int index) {
    // TODO
  }

  // Helpers
private:
  int getLastArrNum()
  {
    // Returns -1 if capacity = 0
    return log2(capacity + 1) - 1;
  }

  int getNextArrSize()
  {
    // Returns size of what the next created array will be
    
  }


};

#endif // _log_n_vector_h_