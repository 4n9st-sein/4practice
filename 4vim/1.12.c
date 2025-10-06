#include <stdio.h>

struct rectangle {
	int x;
	int y;
	int width;
	int height;
}

void rect_print (struct rectangle *p) {
	printf("point x: %d\n", p -> x);
	printf("point y: %d\n", p -> y);
	printf("width: %d\n", p -> width);
	printf("height: %d\n", p -> height);
	return 0;
}

int  rect_area (struct rectangle *p) {
	return (p  -> x)*(p  -> x);
}

void rect_movel(struct rectangle *p, int dx, int dy) {
	p -> x = p -> x + dx;
	p -> y = p -> y + dy;
	return;
}



void rect_movel(struct rectangle *p, int dx, int dy) {
	struct rectangle ret {
		p -> x + dx,
		p -> y + dy,
		p -> width,
		p -> height,
	}
	return ret;
} 


void rect_movel(struct rectangle *p,struct rectangle *i, ) {


