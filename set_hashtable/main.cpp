#include <random>
#include <iostream>
#include <sstream>

#include "set.h"

std::string create(std::string str, int x) {

	std::stringstream ss;
	ss << str << x;
	return ss.str();
}

void output_stats(const set& s) {

	std::cout << "size: " << s.size() << " buckets: " << s.bucketcount()
			  << ", load factor: " << s.loadfactor() << ", Bucket size stdev: "
			  << s.standarddev() << std::endl;
}

int main(int argc, char* argv[]) {

	set kaz;

	kaz.insert("aqtobe");
	kaz.insert("atyrau");

	std::cout << kaz.contains("Aqtobe") << "\n";
	std::cout << kaz.contains("AqToBe") << "\n";

	kaz.insert("SHYMKENT");
	std::cout << kaz.contains("szymkent") << "\n";

	kaz.insert("Almaty");
	kaz.insert("Taraz");
	kaz.insert("Qaraghandy");
	kaz.insert("Qostanay");
	kaz.insert("Kokshetau");

	std::cout << "before removal\n";
	std::cout << kaz << "\n";
	kaz.remove("qostanay");
	std::cout << "after removal\n";

	std::cout << kaz << "\n";
	std::cout << kaz.size() << "\n";

	auto kaz2 = kaz; // Copy constructor.
	std::cout << kaz2 << "\n";

	output_stats(kaz);
	output_stats(kaz2);

	kaz2 = kaz;      // Assignment.
	kaz = kaz;       // Self assignment. // @suppress("Assignment to itself")

	set someset1;

	for (size_t k = 0; k != 8000; ++k) {
		someset1.insert(create("aa", rand()));
		someset1.insert(create("bb", rand()));
	}

	auto someset2 = someset1;

	std::cout << std::endl;

	output_stats(someset1);
	output_stats(someset2);

	return 0;
}

