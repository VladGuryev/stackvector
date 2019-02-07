#ifndef STACKVECTOR_H
#define STACKVECTOR_H

#include <stdexcept>
#include <array>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
  explicit StackVector(size_t a_size = 0) : vec_capacity(N), vec_size(a_size){
    if(a_size > vec_capacity)
      throw invalid_argument("size more than capacity");
  }

  T& operator[](size_t index){
    return arr[index];
  }
  const T& operator[](size_t index) const{
    arr[index];
  }

  typename array<T,N>::iterator begin(){
    return arr.begin();
  }
  typename array<T,N>::iterator end(){
    return arr.begin() + vec_size;
  }
  typename array<T,N>::const_iterator begin() const{
    return arr.begin();
  }
  typename array<T,N>::const_iterator end() const{
    return arr.begin() + vec_size;
  }

  size_t Size() const{
    return vec_size;
  }
  size_t Capacity() const{
    return vec_capacity;
  }

  void PushBack(const T& value){
    if(vec_size == vec_capacity)
      throw overflow_error("overflow");
    else
      arr[vec_size++] = value;
  }
  T PopBack(){
    if(vec_size == 0)
      throw underflow_error("underflow");
    else
      return arr[--vec_size];
  }

private:
  size_t vec_capacity;
  size_t vec_size;
  array<T, N> arr;
};


#endif // STACKVECTOR_H
