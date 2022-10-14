#include <stdlib.h>
#include <stdio.h>

int main(void) {
	char str[100];
	// scanf("%s", &str);  // i love you 입력
	// printf("%s\n", str);  // i 만 출력됩니다.
	fgets(str, 100, stdin);
	printf("%s", str); // i love you 출력됩니다.

	return 0;
}