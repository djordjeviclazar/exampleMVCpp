#include <stdio.h>

int MinPeriod(int* a, int n)// n is even integer
{
	int T = 1, longitude = 1, index = 1, comparingIndex = 0;

	for (index; index < n; index++)
	{
		if (a[index] == a[comparingIndex])
		{
			comparingIndex++;
			T = (index + 1) / longitude;
			continue;
		}
		else
		{
			comparingIndex = 0;
			if (a[comparingIndex] == a[index])
			{
				continue;
			}
			else
			{
				T = 1;
				longitude = index + 1;
			}
		}
	}

	if (n % longitude != 0) { T = 1; } // last segment is not full period

	return T;
}

int main()
{
	int n = 8, 
		a1[8] = { 2, 5, 3, 4, 2, 5, 3, 4 }, 
		a2[8] = { 2, 5, 3, 2, 5, 3, 2, 5 }, 
		a3[8] = { 2, 2, 2, 2, 2, 2, 2, 2 };

	printf("Period a1: T1 = %d \r\n", MinPeriod(a1, n));
	printf("Period a2: T2 = %d \r\n", MinPeriod(a2, n));
	printf("Period a3: T3 = %d \r\n", MinPeriod(a3, n));

	getchar();
	return 0;
}