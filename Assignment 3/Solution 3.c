#include <stdio.h>

int main(int argc, char const *argv[])
{
	int m, n, x;
	scanf("%d %d %d", &m, &n, &x);
	int matrix[m][n];
	int i, j, p, q, k, area = 0, tempa, x1, y1, x2, y2;
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			matrix[i][j] = 0;
		}
	}
	
	for (i = 0; i < x; ++i)
	{
		scanf("%d %d ", &p, &q);
		matrix[p][q] = 1;		
	}
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if (matrix[i][j] == 0)
			{
				tempa = 1;
				if (area == 0)
				{
					area = tempa;
					x1 = i;
					x2 = i;
					y1 = j;
					y2 = j;
				}				
				for (k = j+1; k < n ; ++k)
				{
					if (matrix[i][k] == 0)
					{
						tempa = k - j + 1;
					}
					else
					{
						break;						
					}
				}				
				for (p = i+1;  p < (i + k - j + 1) ; ++p)
				{
					for (q = j;  q < k ; ++q)
					{
						if (matrix[p][q] == 0)
						{
							tempa = (p - i + 1) * (q - j + 1);
							if((tempa > area) && ((p - i) == (q - j)))
							{
								area = tempa;
								x1 = i;
								x2 = p;
								y1 = j;
								y2 = q;
								// printf("%d %d %d %d", x1, y1, x2, y2);
	
							}
						}
						else
						{
							k = q;
							break;						
						}						
					}
				}
			}
		}
	}
	if (area == 0)
	{
		printf("0");
	}
	else
	{
		printf("%d %d %d %d", x1, y1, x2, y2);
	}
	
	// for (i = 0; i < m; ++i)
	// {
	// 	for (j = 0; j < n; ++j)
	// 	{
			
	// 	}
	// }
	// for (p = 0; p < m; ++p)
	// 			{
	// 				for (q = 0; q < n; ++q)
	// 				{
						
	// 				}
	// 			}
	// for (p = i; p >= 0; --p)
	// 			{
	// 				for (q = j; q >=0; --q)
	// 				{
						
	// 				}
	// 			}
	return 0;
}