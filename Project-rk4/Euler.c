//[simple harmonic motion equation]


#include <stdio.h>

double k = 1.0; //[N/m]
double m = 1.0;//[kg]
double c = 0.1;//[N*s/m]



double f(double x, double y) {
	return -(c / m) * y - (k / m) * x;
}



int main_3() {


	FILE* fp = fopen("C:\\Users\\wlvud\\data.csv", "w");  

	if (fp == NULL) {
		printf("Can't save file!\n");
		return -1;
	}


	double x0 = 0.0, y0 = 1.0;
	double h = 0.01;
	int n = 1000;
	double x = x0, y = y0;
	double t = 0.0;


	fprintf(fp, "t,x,y\n");
	fprintf(fp, "%.6f,%.6f,%.6f\n", t,x,y);


	for (int i = 1; i <= n; i++) {
		x = x + h * y;
		y = y + h * f(x, y);
		t = t + h;
		
		fprintf(fp, "%.6f,%.6f,%.6f\n", t, x, y);
	}

	fclose(fp);
	printf("clear\n");
	return 0;
}
