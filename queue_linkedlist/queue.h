
#ifndef QUEUE_H_
#define QUEUE_H_

#include <ostream>

class queue {

	struct node {
		int value;
		node* next;
		// node constructor
		node(int x): value(x), next(nullptr) { }
	};

	
	size_t queue_size;

	node* front;
	node* back;

public:

	queue(): 
	     queue_size(0), 
		 front(nullptr), 
		 back(nullptr) 
	{ }

	queue(const queue& q);

	queue(std::initializer_list<int> ilist);

	queue& operator=(const queue& q);

	void push(int val);

	int peek() const;

	void pop();

	void clear();

	size_t size() const;

	bool empty() const;

	void print(std::ostream& out) const {

		node* curr = front;

		out << "[";
		for (size_t i = 0; i < queue_size; ++i) {
			if (i > 0) {
				out << ", ";
			}
			out << curr->value;
			curr = curr->next;
		}
		out << "]";
	}

	~queue();
};

inline std::ostream& operator<<(std::ostream& out, const queue& q) {
	q.print(out);
	return out;
}



#endif /* QUEUE_H_ */
