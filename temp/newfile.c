#include <stdio.h>
#include <math.h>

#define fn1					(-k*pow(x*x + y*y, -1.5)*dt)		//modified force function
#define num_rot				1									//number of rotations to plot
#define directory			"data/"								//directory for storing data
int main(int argc, char *argv[])
{
	double x0 = 1;
	double y0 = 0;
	double evx0 = 0;
	double evy0 = 1;
	double dv = 1.1;
	double k = 1;
	double dt = 1e-6;
	long int i_min = (long int)1;
	long int i_max = (long int)2;
	int nch_fnm = (int)100;

	double x , y, v, vx, vy;
	int n;
	double det;
	char file_name[nch_fnm];
	FILE *fptr;
	for(long int i = i_min; i < i_max; ++i)
	{
		x = x0;
		y = y0;
		v = i*dv;
		n = 0;
		vx = v*evx0;
		vy = v*evy0;
		snprintf(file_name, nch_fnm, "%s%li", directory, i);	//naming the file
		fptr = fopen(file_name, "w");
		while(n < 2*num_rot + 1)
		{
			fprintf(fptr, "%.6le\n%.6le\n", x, y);	//writing to the file
			det = y;
			x = x + vx*dt;
			y = y + vy*dt;
			vx = vx + fn1*x;
			vy = vy + fn1*y;
			det = det*y;
			if(det <= 0)
			{
				++n;
			}
		}
	}
	return 0;
}

