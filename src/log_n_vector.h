#ifndef _log_n_vector_h_
#define _log_n_vector_h_

#include <cmath>
#include <memory>
#include <vector>

template <typename T>
class LogNVector {
  // Members -----------------
private:
  std::vector<std::unique_ptr<T[]> > arrays;
  int size_;
  int capacity_;

  // Constructor ----------------
public:
  LogNVector() {
    this->size_ = 0;
    this->capacity = 0;
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

  // Getters --------------
public:
  int size() const noexcept {
    return this->size_;
  }
  int capacity() const noexcept {
    return this->capacity_;
  }


// Modifiers -----------
public:
  void push_back(const T& value) {
    // Creates next array if capacity is full
    if(this->size_ == this->capacity_)
      this->createNextArray();

    // Value goes into last array in first open location
    int lastArr = this->getLastArrNum();
    int arrNextLoc = this->size_ - getConsecMaxArrSize(lastArr - 1);

    *(this->arrays[lastArr])[arrNextLoc] = value;
    size_ += 1;
  }

// Operators -----------
public:
  const T& operator[](int index) const {
    int arrNum = log2(index);
    int position = index - getConsecMaxArrSize(arrNum - 1) - 1;
    return *(this->arrays[arrNum])[position];
  }
  T& operator[](int index) {
    // TODO
  }

  // Helpers -----------
private:
  void createNextArray()
  {
    // Gets the the num
    int nextSize = getArrMaxSize( getLastArrNum() + 1 );
    this->arrays.push_back(new T[nextSize]);
    this->capcaity_ += nextSize;
  }

  int getLastArrNum() const
  {
    // first array is 0.  If no arrays return -1
    return this->arrays.size() - 1;

    //return log2(capacity + 1) - 1;
  }

  int getArrMaxSize(int num) const
  {
    // Returns capacity of what this->arrays[num] would be
    return exp2(num);
  }

  int getConsecMaxArrSize(int num) const
  {
  //Returns how many objects can fit within a num amount of arrays
    int total = 0;
    for (int k = 0; k <= num; k++)
      total += getArrMaxSize(k);
    return total;
  }


};

#endif // _log_n_vector_h_