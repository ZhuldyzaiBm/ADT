#include "queue.h"
#include <iostream>

void output(const queue& q) {
	std::cout << q.size() << " " << q.empty() << " " << q << std::endl;
}

int main() {

	queue q1;
	output(q1);

	queue q2 = {11, 22, 33, 44};
	output(q2);

	queue q3(q2);

	for (int i = 111; i < 222; i = i + 11) {
		q2.push(i);
	}

	output(q2); output(q3);

	q1 = q2;

	for (int x = 0; x < 10; ++x) {
		std::cout << q2.peek() << " ";
		q2.pop();
	}
	std::cout << std::endl;

	output(q1); output(q2);

	q1.clear();
	output(q1); output(q2);

	while (!q2.empty()) {
		std::cout << q2.peek() << " ";
		q2.pop();
	}
	std::cout << std::endl;

	output(q2);
}



