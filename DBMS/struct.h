#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Data{
	char* data;
	struct Data* dt_link;
} Data;

typedef struct FD {
	char *f_id;
	char *form;
	char *size;
	struct FD* f_link;
	struct Data* dt_link;
} FD;

typedef struct TB {
	char *t_id;
	struct TB* t_link;
	struct FD* f_link;
} TB;


typedef struct DB {
	char *d_id;
	struct DB* d_link;
	struct TB* t_link;
} DB;


typedef struct User {
	char* u_id;
	char* u_pass;
	struct User* u_link;
	struct DB* d_link;
} User;

char* my_strtok(char* str, const char* str2) {
	static char* pCurrent;
	char* pDelimit;

	if (str != NULL)pCurrent = str;
	else str = pCurrent;

	if (*pCurrent == NULL) return NULL;

	//문자열 점검
	while (*pCurrent)
	{
		pDelimit = (char*)str2;

		while (*pDelimit) {
			if (*pCurrent == *pDelimit) {
				*pCurrent = NULL;
				++pCurrent;
				return str;
			}
			++pDelimit;
		}
		++pCurrent;
	}
	// 더이상 자를 수 없다면 NULL반환
	return str;
}

void remove_garo(char* str, char ch)
{
	unsigned len = strlen(str) + 1;
	for (; *str != '\0'; str++, len--)
	{
		if (*str == ch)
		{
			strcpy_s(str, len, str + 1);
			str--;
		}
	}
}

void change_garo(char* str, char ch) {
	for (; *str != '\0'; str++) {
		if (*str == ch) {
			*str = ' ';
		};
	}
}

void remove_last_garo(char* str) {
	int i = 0;
	while (str[i]) {
		i++;
	}
	str[i - 1] = '\0';
}

void remove_first_garo(char* str) {
	int i = 0;
	for (i = 1; str[i]; i++) {
		str[i - 1] = str[i];
	}
	str[i - 1] = '\0';
}

