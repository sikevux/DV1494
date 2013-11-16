#include <stdio.h>
#include <math.h>

int main() {
	float a = 4;
	float b = -12;
	float c = 1;
	float d = -3;
	float r,p,q,t,s,root;

	r = b/a;
	p = (c/a) - (pow(r,2)/3);
	q = (d/a) - ((c*r)/(3*a)) + ((2*pow(r,3))/27);
	t = ((4*pow(p,3)) + (27*pow(q,2)))/27;
	s = pow((sqrt(t)-q)/2,1/3.0);
	root = s - (p/(3*s)) - (r/3);

	printf("Roten är %f\n", root);
	return 0;
}
