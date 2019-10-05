#include "random.hpp"
#include <vector>

/*Random(const unsigned seed): seed(seed), gen(seed), dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) {}*/

void Random::reset() {
	gen.seed(seed);
	dist.reset();
}

int Random::getRand() {
	return dist(gen);
}

void Random::setSeed(const unsigned seed) {
	this->seed = seed;
	gen.seed(seed);
	dist.reset();
}
 
unsigned Random::getSeed() const {
	return seed;
}

std::vector<int> Random::randIntVector(const long n) {
	std::vector<int> randVect(n);
	for (int i = 0; i < n; i++) {
		randVect[i] = getRand();
	}
	return randVect;
}
