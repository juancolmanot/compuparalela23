static const unsigned int N = 2048;

void roll(float *a) {
	for (int i=0; i<N; ++i) {
		a[i] = a[i] * 17;
	}
}


void unroll(float *a) {
	for (int i=0; i<N; i+=2) {
		a[i] = a[i] * 17;
		a[i+1] = a[i+1] * 17;
	}
}
