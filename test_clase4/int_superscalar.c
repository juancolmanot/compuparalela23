#define N (1<<28)

int main(int argc, char ** argv)
{
	unsigned long a,b,c,d = 0UL;
	unsigned long ap,bp,cp,dp = 0UL;

	for(int i; i<N; ++i) {
		a = ap+1;
		b = bp+2;
		c = cp+4;
		d = dp+8;
		ap = b;
		bp = c;
		cp = d;
		dp = a;
	}
	return (int)(a+b+c+d);
}
