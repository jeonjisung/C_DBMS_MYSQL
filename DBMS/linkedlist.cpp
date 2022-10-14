#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#define MAXLINE 100

typedef char DATA;			//will use char in exmaples

struct linked_list {
	DATA d;
	linked_list* prev;
	linked_list* next;
};

typedef linked_list ELEMENT;
typedef ELEMENT* LINK;

void concatenate(LINK a, LINK b);
int count(LINK head);
int count_it(LINK head);
void delete_list(LINK head);
void find_and_delete(LINK head, DATA x);
LINK string_to_list(LINK p, char s[]);
void wrt_list(LINK hp);
void wrt_rev_list(LINK tp);

LINK hp = NULL;					//hp = head pointer
LINK tp = NULL;					//tp = tail pointer

int main()
{
	char line[MAXLINE];
	LINK p;

	while (1) {
		printf("리스트에 넣을 데이터를 입력하세요 : ");
		assert(fgets(line, MAXLINE, stdin) != NULL);

		if (*line == '\n') {
			break;
		}
		p = string_to_list(NULL, line);
		if (hp == NULL) {
			hp = p;
		}
		else {
			concatenate(hp, p);
		}
	}

	printf("\n forward list => ");
	wrt_list(hp);

	printf("\n reverse list => ");
	wrt_rev_list(tp);

	DATA a;
	printf("리스트에서 삭제하고 싶은 데이터를 입력하세요 : "); a = getchar();
	find_and_delete(hp, a);

	printf("deleted node forward list : ");
	wrt_list(hp);

	printf("deleted node reverse list : ");
	wrt_rev_list(tp);

	delete_list(hp);
	printf("\nbye!\n");

	return 0;
}

//concatenate list a and b with a as head.
void concatenate(LINK a, LINK b)
{
	assert(a != NULL);

	if (a->next == NULL) {
		a->next = b;
		b->prev = a;	//데이터를 연결할 때 반대로도 연결함.
	}
	else {
		concatenate(a->next, b);
	}
}

//count a list recursively.
int count(LINK head)
{
	if (head == NULL) {
		return 0;
	}
	else {
		return (1 + count(head->next));
	}
}

//count a list iteratively.
int count_it(LINK head)
{
	int cnt = 0;

	for (; head != NULL; head->next) {
		cnt++;
	}

	return cnt;
}

//recursive deletion of a list
void delete_list(LINK head)
{
	if (head != NULL) {
		delete_list(head->next);
		free(head);
		//재귀호출을 이용해서 맨 마지막 노드부터 지워온다.
	}
}

//데이터를 찾아서 지우는 함수
void find_and_delete(LINK head, DATA x)
{
	LINK p;
	while (1) {
		p = head;

		if (p == NULL) {
			break;
		}

		if (p->d == x) {	//삭제할 데이터를 찾은 경우
			if (p->prev != NULL && p->next == NULL) {
				//찾은 데이터가 가장 마지막 데이터인 경우
				p->prev->next = NULL;
				tp = p->prev;
				//tp를 삭제된 데이터 이전 데이터로 바꿈
			}
			else if (p->prev == NULL && p->next != NULL) {
				//찾은 데이터가 가장 첫번째 데이터인 경우
				p->next->prev = NULL;
				hp = p->next;
				//hp를 삭제된 데이터 다음 데이터로 바꿈
			}
			else {
				//그외(찾은 데이터가 가운데에 있는 경우)
				p->next->prev = p->prev;
				p->prev->next = p->next;
			}
			head = p->next;

			free(p);
		}
		else {
			head = p->next;
		}
	}
}

//재귀호출을 이용해서 리스트를 만든다.
LINK string_to_list(LINK p, char s[])
{
	DATA d;
	LINK head;

	if (s[0] == '\0')
	{
		return NULL;
	}
	else {
		head = (LINK)malloc(sizeof(ELEMENT));

		if (s[0] == '\n') {
			d = ' ';
			tp = head;
		}
		else {
			d = s[0];
		}
		if (p == NULL) {
			head->prev = NULL;
		}
		else {
			head->prev = p;
		}
		head->next = string_to_list(head, s + 1);

		return head;
	}
}

//hp를 이용해서 처음부터 순서대로 출력
void wrt_list(LINK hp)
{
	LINK p;

	for (p = hp; p != NULL; p = p->next) {
		putchar(p->d);
	}
}

//tp를 이용해서 마지막부터 역순으로 출력
void wrt_rev_list(LINK tp)
{
	LINK p;
	for (p = tp; p != NULL; p = p->prev) {
		putchar(p->d);
	}

}
