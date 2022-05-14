#include <cstdio>
long long s;
int n = 1;
int main() {
	scanf("%lld", &s);
	while ((s -= n) > n++);
	printf("%d", --n);
}
