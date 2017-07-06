#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n , i, j;
	scanf("%d",&n);
	int coins[n];
	for (i = 1 ; i <= n ; ++i)
	{
		scanf("%d", &coins[i]);
	}
	int max[n];
	max[0] = 0;
	max[1] = coins[1];
	for (i = 2; i <= n; ++i)
	{
		if( max[i-1] > (coins[i] + max[i-2]) )
		{
			max[i] = max[i-1];
		}
		else
		{
			max[i] = coins[i] + max[i-2];
		}
	}
	int select[n];
	j = 0;
	for (i = n; i >= 1; )
	{
		if (i > 1)
		{
			if (max[i] == (coins[i] + max[i-2]) )
			{
				select[j++] = coins[i];
				i = i - 2;
			}
			else
			{
				i = i - 1;
			}
		}
		else			
		{
			select[j++] = coins[i--];
		}
	}
	if (max[n] == max[n-1])
	{
		int select2[n];
		int k=0;
		for (i = n-1; i >= 1; )
		{
			if (i > 1)
			{
				if (max[i] == (coins[i] + max[i-2]) )
				{
					select2[k++] = coins[i];
					i = i - 2;
				}
				else
				{
					i = i - 1;
				}
			}
			else			
			{
				select2[k++] = coins[i--];
			}
		}
		if (k < j)
		{
			for ( i = k-1 ; i >= 0; --i)
			{
				if (i != 0)
				 {
				 	printf("%d ", select2[i]);
				 }
				 else
				 {
				 	printf("%d\n", select2[i]);
				 } 
			}
			return 0;
		}				
	}	
	for ( i = j-1 ; i >= 0; --i)
	{
		if (i != 0)
		 {
		 	printf("%d ", select[i]);
		 }
		 else
		 {
		 	printf("%d\n", select[i]);
		 } 
	}
	return 0;
}
