#include "node.hpp"

#include <memory>

#include "linked_lists/helper_functions.hpp"

int main()
{
  std::unique_ptr<Node<int>> head = std::make_unique<Node<int>>(1);
  helpers::appendAtEnd(head, 2);
  helpers::appendAtEnd(head, 3);
  helpers::appendAtEnd(head, 4);
  helpers::appendAtEnd(head, 5);
  helpers::appendAtEnd(head, 7);
  helpers::print(head);
  helpers::appendAfter(head, 6, 5);
  helpers::print(head);
  return 0;
}
