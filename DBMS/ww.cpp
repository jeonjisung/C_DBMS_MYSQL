#include <stdlib.h>
#include <stdio.h>

int main(void) {
	char str[100];
	// scanf("%s", &str);  // i love you �Է�
	// printf("%s\n", str);  // i �� ��µ˴ϴ�.
	fgets(str, 100, stdin);
	printf("%s", str); // i love you ��µ˴ϴ�.

	return 0;
}