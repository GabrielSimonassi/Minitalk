#include <stdio.h>
#include <string.h>

void	chartobin(char c)
{
	int i;
	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			printf("1");
		else
			printf("0");
		i--;
	}
	printf("\n\n");
}	

int	main(void)
{
	char msg[6];
	int i, len;

	printf("\n try it out:");
	scanf("%s", msg);

	i = 0;
	len = strlen(msg);
	while (len > i)
	{
		chartobin(msg[i]);
		i++;
	}
	return (0);
}
