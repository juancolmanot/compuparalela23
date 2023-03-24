#define N (1<<28)

int main(int argc, char ** argv)
{
	unsigned long a,b,c,d = 0UL;
	unsigned long ap,bp,cp,dp = 0UL;
	float x,y,z,w = 0.0f;
	float xp,yp,zp,wp = 0.0f;

	for(int i; i<N; ++i) {
		a = ap+1UL;
		b = bp+2UL;
		c = cp+4UL;
		d = dp+8UL;
		ap = b;
		bp = c;
		cp = d;
		dp = a;
		x = xp+1.0f;
		y = yp+2.0f;
		z = zp+4.0f;
		w = wp+8.0f;
		xp = y;
		yp = z;
		zp = w;
		wp = x;
	}
	return (int)(a+b+c+d) + (int)(x+y+z+w);
}
