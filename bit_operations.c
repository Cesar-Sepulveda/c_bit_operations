#include <stdio.h>

unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y ) {	//Exercise 2.6
	x = x & ~(~(~0 << n)) << (++p - n);
	y = (y & ~(~0 << n)) << (++p - n);
	x = x | y;
	return x;
}

unsigned invert(unsigned x,int p, int n) {		//Exercise 2.7
	x = x ^ (~(~0 << n) << (++p - n));
	return x;
}

unsigned rightrot(unsigned x, int n) {	//Exercise 2.8
	x = x & ~(~0 >> n) << (n + 1);
	return x;
}

int main() {
	unsigned x = ~0;
	unsigned y = getbits(x, 3, 1);
	printf("getbits x is: %u and y is: %d\n", x, y);
	y = setbits(x, 3, 1, y);
	printf("setbits x is: %u and y is: %u\n",x, y);
	y = invert(x, 3, 1);
	printf("invert x is: %u and y is: %u\n", x, y);
	y = rightrot(x, 1);
	printf("rightrot x is: %u and y is: %u\n", x, y);
	return 0;
}
