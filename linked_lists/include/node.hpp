#pragma once

#include <concepts>
#include <memory>
#include <ostream>

template <typename T>
concept Printable = requires(std::ostream& streamer, T a) {
  { streamer << a } -> std::same_as<std::ostream&>;
};

template <Printable T>
struct Node
{
  explicit Node(T x) : value_(x)
  {
  }
  T value_;
  std::unique_ptr<Node<T>> next;
};

template <Printable T>
struct DoubleLinkNode : public Node<T>
{
  explicit DoubleLinkNode(T x) : Node<T>(x)
  {
  }
  std::unique_ptr<DoubleLinkNode<T>(T x)> prev;
};
