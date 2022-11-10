#ifndef STACK_H_
#define STACK_H_

#include <ostream>

class stack {

	int *values;
	size_t stack_size;
	size_t array_capacity;

public:

	stack() :
		values(new int[5]),
		stack_size(0),
		array_capacity(5)
	{
	}

	stack(const stack& stk);

	stack(std::initializer_list<int> ilist);

	stack& operator=(const stack& stk);

	void push(int val);

	int peek() const;

	void pop();

	void clear();

	size_t size() const;

	bool empty() const;

	void print(std::ostream& out) const {

		out << "[";
		for (size_t i = 0; i < stack_size; ++i) {
			if (i > 0) {
				out << ", ";
			}
			out << values[i];
		}
		out << "]";
	}

	~stack();
};

inline std::ostream& operator<<(std::ostream& out, const stack& stk) {
	stk.print(out);
	return out;
}

#endif /* STACK_H_ */
