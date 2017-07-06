#include <stdio.h>
#include <stdlib.h>

float **x, **y;
int **root;

int OptimalBST(float p[], float q[], int n)
{
	x = (float **)malloc ( (n + 2) * sizeof(float *));
	y = (float **)malloc ( (n + 2) * sizeof(float *));
	root = (int **)malloc ( (n + 1) * sizeof(int *));
	int i, j, k, l;
	float temp;
	for ( i = 0; i <= (n + 1); ++i)
	{
	 	x[i] = (float *)malloc ( (n + 1) * sizeof(float));
		y[i] = (float *)malloc ( (n + 1) * sizeof(float));
		root[i] = (int *)malloc ( (n + 1) * sizeof(int));
	}
	//printf("%f", root[n + 1][n + 1]);
	for ( i = 0; i <= (n ); ++i)
	{
		for ( j = 0; j <= (n ); ++j)
		{
			root[i][j] = 0;
		}
		//printf("\n");
	}
		for ( i = 0; i <= (n + 1); ++i)
	{
		for ( j = 0; j <= (n ); ++j)
		{
			x[i][j] = 0.0;
		}
		//printf("\n");
	}
		for ( i = 0; i <= (n + 1); ++i)
	{
		for ( j = 0; j <= (n ); ++j)
		{
			y[i][j] = 0.0;
		}
		//printf("\n");
	}
	for (i = 1; i <= (n + 1); ++i)
	{
	 	x[i][i - 1] = q[i - 1];
	 	y[i][i - 1] = q[i - 1];
	}
	for (i = 1; i <= n; ++i)
	{
	  	for (j = 1; j <= (n - i + 1); ++j)
	  	{
	  		k = i + j -1;
  			x[j][k] = 99999;
  			y[j][k] = y[j][k - 1] + p[k] + q[k];
  			for (l = j; l <= k; ++l)
  			{
  				temp = x[j][l - 1] + x[l + 1][k] + y[j][k];
  				if (temp < x[j][k])
  				{
  					x[j][k] = temp;
  					root[j][k] = l;
  				}
  			}
	  	}
	}
	// for ( i = 1; i <= n; ++i)
	// {
	// 	for ( j = 1; j <= n; ++j)
	// 	{
	// 		printf("%d ", root[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// for ( i = 1; i <= (n + 1); ++i)
	// {
	// 	for ( j = 0; j <= n; ++j)
	// 	{
	// 		printf("%0.1f ", x[i][j]);
	// 	}
	// 	printf("\n");
	// }
	return 0; 
}

int print(int i, int j)
{
	if(i > j)
	{
		printf("()");
		return 0;
	}
	else if (i == j)
	{
		printf("(%d)", i);
		return 0;
	}
	int k;
	printf("(%d", root[i][j]);
	k = print(i, root[i][j] - 1);
	k = print(root[i][j] + 1, j);
	printf(")");
	return 0;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int i, j;
	float p[n + 1], q[n+1];
	for ( i = 1; i <= n; ++i)
	{
		scanf("%f ", &p[i]);
	}
	for ( i = 0; i <= (n); ++i)
	{
		scanf("%f ", &q[i]);
	}
	int g = OptimalBST(p, q, n);
	printf("%0.2f\n", x[1][n]);
	g = print(1, n);
	// for ( i = 1; i <= n; ++i)
	// {
	// 	for ( j = 1; j <= n; ++j)
	// 	{
	// 		printf("%0.1f ", root[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// for ( i = 1; i <= (n + 1); ++i)
	// {
	// 	for ( j = 0; j <= n; ++j)
	// 	{
	// 		printf("%0.1f ", x[i][j]);
	// 	}
	// 	printf("\n");
	// }
	return 0;
}