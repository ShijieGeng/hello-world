#include <stdio.h>
#include <math.h>
const double PI = acos(-1.0);
const double eps = 1e-5;
// h和r之间函数关系
double f(double R, double h){
	double alpha = 2 * acos(R/(R-h));
	double d = 2 * sqrt(R*R-(R-h)*(R-h));
	double s1 = alpha * R * R / 2 - d * (R-h) / 2;
	double s2 = PI * R * R / 2;
	return s1/s2;
}
double solve(double R, double r){
	double left = 0, right = R, mid;
	while(right - left > eps){
		mid = (left + right) / 2;
		if(f(R, mid) > r)
			right = mid;
		else
			left = mid;
	}
	return mid;
}
int main(){
	double R, r;
	scanf("%lf%lf", &R, &r);
	printf("%.4f\n", solve(R, r));
	return 0;
}