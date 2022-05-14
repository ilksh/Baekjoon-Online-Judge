#include <stdio.h>

int main(void)
{
	int A, B, C; 
	int T; 

	scanf("%d", &T);

	A = T / 300;
	B = T % 300 / 60;
	C = T % 300 % 60 / 10;
	if (300 * A + 60 * B + 10 * C != T) // if (T % 10)
	{
		printf("-1");
		return 0;
	}
	printf("%d %d %d", A, B, C);

	return 0;
}
