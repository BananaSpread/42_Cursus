#include <stdio.h>
#include <ctype.h>

void pr(char c);

int	main(void)
{
	pr(' ');
	pr('!');
	pr('A');
	pr('*');
	pr('<');
	pr('g');
	pr('z');
	pr(',');
	pr(']');
	pr('"');
	pr('@');
}

void pr(char c)
{
	printf("El valor de %c es %d\n", c, isalpha(c));
}
