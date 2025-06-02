#include <iostream>
#include <memory>
#include <utility>
template <typename T>
struct Node
{
  T value;
  std::unique_ptr<Node<T>> next;
  explicit Node(T v) : value(v)
  {
  }
};

template <typename T>
struct MyStack
{
  std::unique_ptr<Node<T>> head;
  void push_back(T new_value)
  {
    auto temp = std::make_unique<Node<T>>(new_value);
    temp->next = std::move(head);
    head = std::move(temp);
  }
  void pop()
  {
    if (head == nullptr)
    {
      return;
    }
    auto next_head = std::move(head->next);
    head.reset();
    head = std::move(next_head);
  }
  void peek()
  {
    if (head == nullptr)
    {
      std::cout << "Stack empty\n";
      return;
    }
    std::cout << "The number is : " << head->value << "\n";
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
