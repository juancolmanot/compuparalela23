#define N (1<<28)

int main(int argc, char ** argv)
{
	float x,y,z,w = 0.0f;
	float xp,yp,zp,wp = 0.0f;

	for(int i; i<N; ++i) {
		x = xp+1.0f;
		y = yp+2.0f;
		z = zp+4.0f;
		w = wp+8.0f;
		xp = y;
		yp = z;
		zp = w;
		wp = x;
	}
	return (int)(x+y+z+w);
}
