#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ft_save()
{
	FILE* stream = fopen("source.txt", "w"); //파일 스트림 생성 & 열기 
	int input = 0;

	if (stream == NULL)
		puts("파일을 여는 중 오류가 발생했습니다.");
	printf("데이터를 입력 해주세요 : ");

	while (input != EOF) {
		input = fgetc(stdin); //표준 입력 스트림(키보드) 이용해서 입력
		fputc(input, stream); //입력받은 한글자 파일 스트림에 출력 
	}

	int file_state = fclose(stream); //파일 닫기(파일 스트림 닫기)

	if (file_state == EOF)
		puts("파일을 닫는 중 오류가 발생했습니다.");
}

void ft_read()
{
	char name[10];
	FILE* stream = fopen("source.txt", "r");		//파일을 이렇게 연다 (r로!)

	while (!feof(stream))		//파일의 끝인 경우에 1을 반환하는 함수 (feof)
	{
		fscanf(stream, "%s", name);	//name에 이름을 저장
		printf("%s ", name);
	}

	fclose(stream);
}

int main(void) {

	ft_save();
	ft_read();

	return 0;
}