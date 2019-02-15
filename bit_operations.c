#include <stdio.h>

unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y ) {	//Exercise 2.6
	unsigned mask = ~(~0 << n);
	unsigned shifted_mask = mask << (p + 1 - n);
	return ((y&mask) << (p + 1 - n)) | (x& ~shifted_mask);
}

unsigned invert(unsigned x, int p, int n) {		//Exercise 2.7
	unsigned mask = ~(~0 << n);
	unsigned shifted_mask = mask << (p + 1 - n);
	return (x & ~shifted_mask) | (~x & shifted_mask);
}

unsigned rightrot(unsigned x, int n) {	//Exercise 2.8
	unsigned y = x >> n;
	unsigned mask = ~(~0 << n);
	unsigned not_mask = ~mask;
	return (y & not_mask) | (x & mask);
}

int main() {
	unsigned x = ~0;
	unsigned y = getbits(x, 3, 1);
	y = setbits(x, 3, 1, y);
	printf("setbits: x is: %u and y is: %u\n",x, y);
	
	y = invert(x, 3, 1);
	printf("invert: x is: %u and y is: %u\n", x, y);

	y = rightrot(x, 1);
	printf("rightrot: x is: %u and y is: %u\n", x, y);
	return 0;
}
