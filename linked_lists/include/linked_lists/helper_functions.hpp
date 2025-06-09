#pragma once
#include "node.hpp"

#include <cassert>
#include <iostream>
#include <memory>

namespace helpers
{
/*
 * Append at the start
 */
template <Printable T>
auto appendAtStartAndReturn(std::unique_ptr<Node<T>> head, T val) -> std::unique_ptr<Node<T>>
{
  std::unique_ptr<Node<T>> new_node = std::make_unique<Node<T>>(val);
  new_node->next = std::move(head);
  return new_node;
}
/*
 * Remove at the start
 */
template <Printable T>
auto removeAtStartAndReturn(std::unique_ptr<Node<T>> head) -> std::unique_ptr<Node<T>>
{
  assert(head != nullptr);
  auto new_tree = std::move(head->next);
  head.reset();
  return new_tree;
}
/*
 * Append at the end
 */
template <Printable T>
auto appendAtEnd(std::unique_ptr<Node<T>>& head, T val) -> void
{
  std::unique_ptr<Node<T>> new_node = std::make_unique<Node<T>>(val);
  if (head == nullptr)
  {
    head = std::move(new_node);
    return;
  }
  auto last = head.get();

  while (last->next != nullptr)
  {
    last = last->next.get();
  }
  last->next = std::move(new_node);
}
/*
 * Append at the after a specific node
 */
template <Printable T>
auto appendAfter(std::unique_ptr<Node<T>>& head, T val, T key) -> void
{
  auto current = head.get();
  while (current != nullptr)
  {
    if (current->value_ == key)
    {
      break;
    }
    current = current->next.get();
  }
  if (current == nullptr)
  {
    std::cout << "No node with given key found\n";
    return;
  }
  std::unique_ptr<Node<T>> new_node = std::make_unique<Node<T>>(val);
  new_node->next = std::move(current->next);
  current->next = std::move(new_node);
}
/*
 * Print the tree/list
 */
template <Printable T>
auto print(std::unique_ptr<Node<T>>& head) -> void
{
  auto current = head.get();
  while (current != nullptr)
  {
    std::cout << current->value_ << "  ";
    current = current->next.get();
  }
  std::cout << "\n";
}
}  // namespace helpers
