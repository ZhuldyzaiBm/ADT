#include "stack.h"
#include <stdexcept>

stack::stack(const stack &stk)
    : array_capacity(stk.array_capacity), stack_size(stk.stack_size),
      values(new int[stk.array_capacity]) {
  for (size_t count = 0; count < stk.stack_size; ++count) {
    values[count] = stk.values[count];
  }
}

stack::stack(std::initializer_list<int> ilist) {
  array_capacity = 5;
  values = new int[array_capacity];
  stack_size = 0;
  for (auto element : ilist) {
    push(element);
  }
}

stack &stack::operator=(const stack &stk) {
  if (stack_size != stk.stack_size) {
    array_capacity = stk.array_capacity;
    delete[] values;
    values = new int[stk.array_capacity];
  }
  stack_size = stk.stack_size;
  for (size_t count = 0; count < stack_size; ++count) {
    values[count] = stk.values[count];
  }
  return *this;
}

void stack::push(int val) {
  if (array_capacity <= (stack_size + 1)) {
    array_capacity = array_capacity * 2;

    int *newStack = new int[array_capacity];
    for (size_t count = 0; count < stack_size; ++count) {
      newStack[count] = values[count];
    }
    delete[] values;
    values = newStack;
  }
  values[stack_size] = val;
  ++stack_size;
}

int stack::peek() const {
  if (empty())
    throw std::runtime_error("empty stack");
  return values[stack_size - 1];
}

void stack::pop() {
  if (empty())
    throw std::runtime_error("empty stack");
  stack_size--;
}

void stack::clear() { stack_size = 0; }

size_t stack::size() const { return stack_size; }

bool stack::empty() const { return (stack_size == 0); }

stack::~stack() { delete[] values; }