
#include <stdio.h>

struct point {
	int x;
	int y;
};
enum style {
	SOLID, DASHE, DOTTED,
};
struct line {
	struct point point1, point2;
	enum style style;
}



int point_is_equal (struct point *p1, struct point *p2){
if(p1 -> x == p2 -> x && p1 -> y == p2 -> y )
return 1;
return 0;
}

int main (void) {
struct point a = {1, 2};
struct point b = {1, 2};
struct point c = {2, 2};
printf("%d\n", point_is_equal(&a, &b));
printf("%d\n", point_is_equal(&c, &b));
return 0;
}
