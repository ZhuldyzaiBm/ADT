#include "queue.h"
#include <stdexcept>

queue::queue(const queue& q) {
  front = nullptr;
  back = nullptr;
  queue_size = 0;
  node *ptrnode = q.front;
  while (ptrnode) {
    push(ptrnode->value);
    ptrnode = ptrnode->next;
  }
}

queue::queue(std::initializer_list<int> ilist) {
  front = nullptr;
  back = nullptr;
  queue_size = 0;
  for (auto count : ilist) {
    push(count);
  }
}

queue& queue::operator=(const queue& q) {
  clear();
  node *frontptr;
  frontptr = q.front;
  while (frontptr) {
    push(frontptr->value);
    frontptr = frontptr->next;
  }
  return *this;
}

void queue::push(int val) {
  node *node_new = new node(val);
  if (queue_size == 0)
    front = node_new;
  else
    back->next = node_new;
  back = node_new;
  queue_size++;
}

int queue::peek() const {
  if (empty())
    throw std::runtime_error("empty queue: can't peek");
  return front->value;
}

void queue::pop() {
  if (empty())
    throw std::runtime_error("empty queue");

  node *front_new = front->next;
  delete front;
  front = front_new;
  queue_size--;
}

void queue::clear() {
  while (!empty()) {
    pop();
  }
  queue_size = 0;
  front = nullptr;
  back = nullptr;
}

size_t queue::size() const { return queue_size; }

bool queue::empty() const { return queue_size == 0; }

queue::~queue() { clear(); }