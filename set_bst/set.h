#ifndef SET_INCLUDED
#define SET_INCLUDED    1 

#include <iostream>


struct treenode {
	int value;
	treenode* left;
	treenode* right;

	treenode(int val)
		: value(val),
		  left(nullptr),
		  right(nullptr)
   { }

};


treenode* copynodes(treenode* original);

void deallocatenodes(treenode* node);

class set {

	size_t set_size;
	treenode* root;

	static void printhelper(std::ostream &out, treenode* node){
		if (node != nullptr) {
			if (node->left != nullptr) {
				printhelper(out, node->left);
				out << ", ";
			}
			out << node->value;
			if (node->right != nullptr) {
				out << ", ";
				printhelper(out, node->right);
			}
		}
	}

public:

	set() : set_size(0), root(nullptr) { }

	set(const set &s) : set_size(s.set_size), root(nullptr) {
		root = copynodes(s.root);
	}

	set(std::initializer_list<int> init) : set_size(0), root(nullptr) {
		for (auto el : init) {
			insert(el);
		}
	}

	set& operator=(const set &s) {
		if (&s != this) {
			deallocatenodes(root);
			root = copynodes(s.root);
			set_size = s.set_size;
		}
		return *this;
	}

	bool contains(int i) const;

	bool insert(int i);

	void clear();

	size_t size() const;

	bool empty() const;

	void print(std::ostream &out) const {
		out << "{";
		printhelper(out, root);
		out << "}";
	}

	~set() {
		deallocatenodes(root);
	}
};

inline std::ostream& operator<<(std::ostream &out, const set &s) {
	s.print(out);
	return out;
}

#endif

