#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <limits>
#include <vector>

class Random {
	private:
		unsigned seed;
		std::mt19937 gen;
		std::uniform_int_distribution<int> dist;
	public: 
        Random(const unsigned seed): seed(seed), gen(seed), dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) {}
		int getRand();
		void reset();
		void setSeed(const unsigned seed);
		unsigned getSeed() const;
		std::vector<int> randIntVector(const long n);
};
#endif
