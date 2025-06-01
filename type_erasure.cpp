#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>
// Example types i want interface for with runtime polymorphism but with flexibility of Templates.
struct A
{
  void print()
  {
  }
};
struct B
{
  void print()
  {
  }
};
// Type Erasure Idiom
struct MyAbstractType
{
  virtual void print() = 0;
  ~MyAbstractType() = default;
};
template <typename T>
struct MyWrapper : public MyAbstractType
{
  T obj_;
  MyWrapper(T obj) : obj_(std::move(obj))
  {
  }
  void print() override
  {
    std::cout << "Do something specific to type T \n";
    obj_.print();
  }
};
int main()
{
  // A concrete type A is wrapped in a template (at compile time) and exposing it through a runtime interface
  // MyAbstractType
  std::unique_ptr<MyAbstractType> a = std::make_unique<MyWrapper<A>>(A{});
  std::unique_ptr<MyAbstractType> b = std::make_unique<MyWrapper<B>>(B{});
  // Why use a pointer at all ? To avoid life time issues and mainly avoid slicing
  // MyAbstractType a_sliced /*runtime interface */ = MyWrapper<A>(A{}); /* template (Compile time) */
  MyWrapper<A> a_wrapper(A{});
  MyAbstractType& a_non_sliced_runtime = a_wrapper;
  return 0;
}
// Why not just have a base abstract and have A and B inherit?
// - you need to maintain the hierarchy
// - cannot use third party concrete type whose print() you wanna use
// - Thus give more flexibility with run time polymorphism with the cost of the signature building at each
// MyWrapper<T>... potential bloating
// - the only thing is print() is virtually dispatch at runtime. so the client does not need to know the type T. thus no
// need of std::visit
// - just can hold a heterogeneous vector of unique_ptr<MyAbstractType> and call print() on every element of the vector
// to use different print() (s).
