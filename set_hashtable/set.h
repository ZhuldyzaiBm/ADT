#ifndef SET_H_
#define SET_H_

#include <ostream>
#include <list>
#include <cstdlib>
#include <math.h>

bool equal(const std::string& s1, const std::string& s2);

size_t hash(const std::string& s);


class set {

	std::list<std::string>* bucket_array;

	size_t bucket_array_size;

	size_t set_size;

	const double max_load_factor = 3.0;

public:

	set() :
		bucket_array(new std::list<std::string>[4]),
		bucket_array_size(4),
		set_size(0)
	{

	}

	set(const set& s);

	set(std::initializer_list<std::string> ilist);

	set& operator=(const set& s);

	bool insert(std::string val);

	bool contains(std::string val) const;

	bool remove(std::string val);

	void clear();

	size_t size() const;
	
	bool empty() const;
	
	size_t bucketcount() const {
		return bucket_array_size;
	}

	size_t bucketsize(size_t i) const {
		return bucket_array[i].size();
	}
	
	double loadfactor() const {
		return (double)set_size / (double)bucket_array_size;
	}

	double standarddev() const {
		double sum = 0.0;
		double lf = loadfactor();

		for (size_t i = 0; i < bucket_array_size; ++i) {
			double dif = bucket_array[i].size() - lf;
			sum += dif * dif;
		}

		return sqrt(sum / bucket_array_size);
	}

	void print(std::ostream& out) const {
		for (size_t i = 0; i < bucket_array_size; ++i) {
			std::list<std::string> bucket = bucket_array[i];

			out << "bucket[" << i << "] = {";

				bool first = true;

				for (std::string val : bucket) {
					if (first) {
						out << val;
						first = false;
					} else {
						out << ", " << val;
					}
				}

			out << "}" << std::endl;
		}
	}

	~set();
};

inline std::ostream& operator<<(std::ostream& out, const set& s) {
	s.print(out);
	return out;
}

#endif /* SET_H_ */
