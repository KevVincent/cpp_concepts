#include <functional>
#include <iostream>
struct MyCallable {
  void operator()(int a) {}
};
void print(int a) { std::cout << a; }
int main() {
  // pre c++ 14. Function as function pointers. Partially Type Safe. Not
  // flexible. No type erasure.
  void (*my_function_var)(int);
  int dummy_state;
  MyCallable c;
  my_function_var = &print;       // Allowed
  my_function_var = [](int a) {}; // Allowed
  // my_function_var = [&dummy_state](int a) {}; // Not allowed with stateful
  // lambdas my_function_var = c; // No allowed. Callable

  // from c++ 14. Using function wrappers. Type safe. Type Erasure
  std::function<void(int)> function_wrap;
  function_wrap = &print;                   // Allowed
  function_wrap = [](int a) {};             // Allowed
  function_wrap = [&dummy_state](int a) {}; // Allowed with stateful lambdas
  function_wrap = c;                        // Allowed. Callable
  return 0;
}
