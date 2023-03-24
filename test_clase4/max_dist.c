#include <math.h>

struct point {
	double x;
	double y;
};

double
max_dist(struct point const *a, const unsigned int size) {
	double result = 0.0;
	unsigned int i = 0;
	for(i=0; i<size; ++a, ++i) {
		double dst = 0.0;
		dst = sqrt((a->x * a->x) + (a->y * a->y));
		if (dst>result)
			result = dst;
	}
	return result;
}
