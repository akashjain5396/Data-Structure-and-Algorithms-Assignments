#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include <math.h>

double complex *C;	
double complex* fft(double complex *a, int n)
{
	if (n==1)
	{
		return a;
	}
	double complex *A0, *A1, *Y0, *Y1, *Y;
	A0= (double complex*)malloc(n/2 * sizeof( double complex ));
	A1= (double complex*)malloc(n/2 * sizeof( double complex ));
	Y0= (double complex*)malloc(n/2 * sizeof( double complex ));
	Y1= (double complex*)malloc(n/2 * sizeof( double complex ));
	Y= (double complex*)malloc(n * sizeof( double complex ));
	double complex wn=cos(2*3.14159265359/(double)n) + sin(2*3.14159265359/(double)n) * I;
	double complex w=1;
	int i,j=0,k;
	for (i = 0; i < n/2; ++i)
	{
		A0[i]=a[j++];
		A1[i]=a[j++];
	}
	Y0=fft(A0,n/2);
	Y1=fft(A1,n/2);
	for (k = 0; k < n/2; ++k)
	{
		Y[k]=Y0[k]+w*Y1[k];
		Y[k+(n/2)]=Y0[k]-w*Y1[k];
		w=w*wn;
	}
	return Y;
}
double complex* fft_inv(double complex *a, int n)
{
	if (n==1)
	{
		return a;
	}
	double complex *A0, *A1, *Y0, *Y1, *Y;
	A0= (double complex*)malloc(n/2 * sizeof( double complex ));
	A1= (double complex*)malloc(n/2 * sizeof( double complex ));
	Y0= (double complex*)malloc(n/2 * sizeof( double complex ));
	Y1= (double complex*)malloc(n/2 * sizeof( double complex ));
	Y= (double complex*)malloc(n * sizeof( double complex ));
	double complex wn=cos(-2*3.14159265359/(double)n) + sin(-2*3.14159265359/(double)n) * I;
	double complex w=1;
	int i,j=0,k;
	for (i = 0; i < n/2; ++i)
	{
		A0[i]=a[j++];
		A1[i]=a[j++];
	}
	Y0=fft(A0,n/2);
	Y1=fft(A1,n/2);
	for (k = 0; k < n/2; ++k)
	{
		Y[k]=Y0[k]+w*Y1[k];
		Y[k+(n/2)]=Y0[k]-w*Y1[k];
		w=w*wn;
	}
	return Y;
}

int	main()
{
	int p;
	scanf("%d",&p);

	int i, n;
	scanf("%d",&n);

	double real, imag;
	C= (double complex*)malloc(n * sizeof( double complex ));
	double complex *Y= (double complex*)malloc(n * sizeof( double complex ));
	
	for (i = 0; i < n; i++)
	{
		scanf("%lf %lf ", &real, &imag);
		C[i] = real + imag * I;
	}	
	
	if (p==0)
	{
		Y = fft(C,n);
	}
	else if(p==1)
	{
		Y = fft_inv(C,n);
		for(i = 0; i < n ; i++ )
		{
			Y[i] = Y[i]/n ;
		}
	}
	printf("%d",n);
	for (i = 0; i < n; i++)
	{
		

		if(abs(creal(Y[i])) < .01 && abs(cimag(Y[i]) > 0.01) )
		{
			printf(" 0 %.1lf", cimag(Y[i]));
		}
		else if(abs(cimag(Y[i]) < 0.01)  && abs(creal(Y[i])) > 0.01)
		{
			printf(" %.1lf 0", creal(Y[i]));
		}
		else if(abs(cimag(Y[i]) < 0.01)  && abs(creal(Y[i])) < 0.01)
		{
			printf(" 0 0");
		}
		else if (abs(cimag(Y[i]) > 0.01)  && abs(creal(Y[i])) > 0.01)
		{
			printf(" %.1lf %.1lf", creal(Y[i]), cimag(Y[i]));
		}
		 //printf(" %.1lf %.1lf", creal(Y[i]), cimag(Y[i]));
	}
	return 0;
}

