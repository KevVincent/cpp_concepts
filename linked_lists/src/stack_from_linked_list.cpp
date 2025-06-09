#include "node.hpp"

#include <iostream>
#include <memory>
#include <utility>

#include "linked_lists/helper_functions.hpp"

template <Printable T>
struct MyStack
{
  std::unique_ptr<Node<T>> head;
  void push_back(T new_value)
  {
    auto temp_head = std::move(head);
    head = std::move(helpers::appendAtStartAndReturn(std::move(temp_head), new_value));
  }
  void pop()
  {
    if (head == nullptr)
    {
      return;
    }
    auto temp_head = std::move(head);
    head = std::move(helpers::removeAtStartAndReturn(std::move(temp_head)));
  }
  void peek()
  {
    if (head == nullptr)
    {
      std::cout << "Stack empty\n";
      return;
    }
    std::cout << "The number is : " << head->value_ << "\n";
  }
};
int main()
{
  MyStack<int> stack_from_link_list;
  stack_from_link_list.push_back(1);
  stack_from_link_list.push_back(2);
  stack_from_link_list.push_back(3);
  stack_from_link_list.peek();
  stack_from_link_list.pop();
  stack_from_link_list.peek();
  return 0;
}
