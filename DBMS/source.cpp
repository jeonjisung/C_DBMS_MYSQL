#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ft_save()
{
	FILE* stream = fopen("source.txt", "w"); //���� ��Ʈ�� ���� & ���� 
	int input = 0;

	if (stream == NULL)
		puts("������ ���� �� ������ �߻��߽��ϴ�.");
	printf("�����͸� �Է� ���ּ��� : ");

	while (input != EOF) {
		input = fgetc(stdin); //ǥ�� �Է� ��Ʈ��(Ű����) �̿��ؼ� �Է�
		fputc(input, stream); //�Է¹��� �ѱ��� ���� ��Ʈ���� ��� 
	}

	int file_state = fclose(stream); //���� �ݱ�(���� ��Ʈ�� �ݱ�)

	if (file_state == EOF)
		puts("������ �ݴ� �� ������ �߻��߽��ϴ�.");
}

void ft_read()
{
	char name[10];
	FILE* stream = fopen("source.txt", "r");		//������ �̷��� ���� (r��!)

	while (!feof(stream))		//������ ���� ��쿡 1�� ��ȯ�ϴ� �Լ� (feof)
	{
		fscanf(stream, "%s", name);	//name�� �̸��� ����
		printf("%s ", name);
	}

	fclose(stream);
}

int main(void) {

	ft_save();
	ft_read();

	return 0;
}