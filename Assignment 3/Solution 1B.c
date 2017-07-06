#include <stdio.h>

int *item, *value, **soln;

int knapsack(int i, int j)
{
	int temp;
	if (soln[i][j] < 0)
	{
		if (item[i] > j)
		{
			temp = knapsack(i-1, j);
		}
		else
		{
			if ((knapsack(i-1, j-item[i]) + value[i] ) > knapsack(i-1, j))
			{
				temp = knapsack(i-1, j-item[i]) + value[i];
			}
			else
			{
				temp = knapsack(i-1, j);
			}
		}
		soln[i][j] = temp;
	}
	return soln[i][j];
}

int main(int argc, char const *argv[])
{
	int n, i, j, cap;
	scanf("%d\n", &n);
	item = (int *) malloc ((n+1) * sizeof(int));
	value = (int *) malloc ((n+1) * sizeof(int));
	soln = (int **) malloc ((n + 1) * sizeof(int *));
	for (i = 1; i <= n; ++i)
	{
		scanf("%d %d ", &item[i], &value[i]);
	}
	int temp, temp0;
	for (i = 1; i <= n; ++i)
	{		
		for (j = i+1; j <= n; ++j)
		{
			if (item[i] > item[j])
			{
				temp = item[i];
				item[i] = item[j];
				item[j] = temp;
				temp0 = value[i];
				value[i] = value[j];
				value[j] = temp0;
			}
		}
	}	
	scanf("%d", &cap);
	for (i = 0; i <= n; ++i)
	{
		soln[i] = (int *) malloc ((cap + 1) * sizeof(int));
	}
	for ( i = 0; i <= n; ++i)
	{
		for (j = 0; j <= cap; ++j)
		{
			if(i == 0 || j == 0)
			{
				soln[i][j] = 0;
			}
			else
			{
				soln[i][j] = -1;
			}
		}
	}

	int x = knapsack(n, cap) ;
	// for(i=0;i<=n;i++)
	// {
	// 	for(j=0;j<=cap;j++)
	// 	{
	// 		printf("%d ", soln[i][j]);
	// 	}
	// 	printf("\n");
	// }
	
	int sack[n], k=0;
	for (i = n, j=cap; i > 0 && j > 0; )
	{
		if((j - item[i]) >=0 )
		{
			if (soln[i][j] == soln[i-1][j])
			{
				i--;
			}
			else if (soln[i][j] == value[i] + soln[i-1][j-item[i]])
			{
				sack[k++] = item[i];
				j = j - item[i];
				i--;
			}			
		}
		else
		i--;
	}
	
	for (i = 0; i < k; ++i)
	{		
		for (j = i; j < k; ++j)
		{
			if (sack[i] > sack[j])
			{
				temp = sack[i];
				sack[i] = sack[j];
				sack[j] = temp;
			}
		}
	}
	for ( i = 0; i < k; ++i)
	{
		printf("%d ", sack[i]);
	}
	return 0;
}