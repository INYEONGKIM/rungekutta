/* Runge-Kutta method */
#include<stdio.h>
#include<math.h>
double f(double t, double y) {
	return t*exp(3*t)-2*y;
}

double exacty(double t) {
	//return t*exp(3*t)-t-1;
	return 0;
}

int main(){
	double ynew,t, tol, fval;
	double k1, k2, k3, k4, h, t0, b; //RK4
	double y0 = 0;
	t = t0 = 0.0;
	b = 1.0;
	h = 0.1;
	
	printf("---- Output : h = %.2lf ----\n", h);

	printf("t\t\tRunge-Kutta value\n", h);
	while (t0 <= b) {
		t = t0 + h; //t Áõ°¡
		k1 = h*f(t0, y0);
		k2 = h*f(t0 + h / 2, y0 + k1 / 2.);
		k3 = h*f(t0 + h / 2, y0 + k2 / 2.);
		k4 = h*f(t, y0 + k3);

		ynew = y0 + (k1 + 2 * k2 + 2 * k3 + k4) / 6.;
		printf("k1 = %.4lf\tk2 = %.4lf\tk3 = %.4lf\tk4 = %.4lf\t\n", k1, k2, k3, k4);
		printf("t = %.2lf\tval = %lf\t\n", t, ynew);
		printf("==========================\n");
		//printf("%.2lf\t%lf\t\n", t, ynew);
		t0 = t;
		y0 = ynew;
	}
	return 0;
}
