#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

struct NODE {
	struct NODE* llink;
	char id[20];
	char dept[20];
	char name[20];
	char blood[20];
	float height;
	float weight;
	int year;
	struct NODE* rlink;
};

struct NODE* head;
struct NODE* tail;
char n_id[20], n_dept[20], n_name[20], n_blood[20];
float n_height, n_weight;
int n_year;

void init() {
	head = (struct NODE*)malloc(sizeof(struct NODE));
	tail = (struct NODE*)malloc(sizeof(struct NODE));

	head->rlink = tail;
	head->llink = head;
	tail->rlink = tail;
	tail->llink = head;
}

struct NODE* createnode() {
	struct NODE* node = (struct NODE*)malloc(sizeof(struct NODE));


	printf("id : ");
	scanf("%s", n_id);
	printf("dept : ");
	scanf("%s", n_dept);
	printf("name : ");
	scanf("%s", n_name);
	printf("blood : ");
	scanf("%s", n_blood);
	printf("height : ");
	scanf("%f", &n_height);
	printf("weight : ");
	scanf("%f", &n_weight);
	printf("year : ");
	scanf("%d", &n_year);

	node->year = n_year;
	node->height = n_height;
	node->weight = n_weight;

	for (int i = 0; i < 20; i++)
	{
		node->id[i] = n_id[i];
		node->dept[i] = n_dept[i];
		node->name[i] = n_dept[i];
		node->blood[i] = n_blood[i];
	}
	//���Ϲ��ī�� 
	return (node);
}

void push_back() {
	struct NODE* newnode = createnode();
	struct NODE* p;
	p = tail;
	p->llink->rlink = newnode;
	newnode->llink = p->llink;
	p->llink = newnode;
	newnode->rlink = p;
}

void node_print() {
	struct NODE* p;
	p = head;
	//2.�׷��� p�� ��ĭ�̵������ְڽ�
	p = p->rlink;
	while (p->rlink != tail) {
		//1������ ��µ�9 
		printf("id : %s | dept : %s | name : %s | blood : %s | year : %d | height : %f | weight : %f \n", p->id, p->dept, p->name, p->blood, p->year, p->height, p->weight);
		p = p->rlink;
	}
	printf("id : %s | dept : %s | name : %s | blood : %s | year : %d | height : %f | weight : %f \n", p->id, p->dept, p->name, p->blood, p->year, p->height, p->weight);

}
void remove_node() {
	int num_year, del_count;
	struct NODE* p;

	printf("������ �л��� �������(year) : ");
	scanf("%d", &num_year);


	p = head->rlink;
	while (p->rlink != tail) {
		if (p->year == num_year) {
			p->rlink->llink = p->llink;
			p->llink->rlink = p->rlink;
			free(p);
			return;
		}
		p = p->rlink;
	}

}
void search_node() {
	int num_year;

	struct NODE* p;
	p = head;

	printf("�л��� �������(year) : ");
	scanf("%d", &num_year);

	while (p->rlink != tail) {
		if (p->year == num_year)
			printf("id : %s | dept : %s | name : %s | blood : %s | year : %d | height : %f | weight : %f \n", p->id, p->dept, p->name, p->blood, p->year, p->height, p->weight);
		p = p->rlink;
	}

}

void free_node() {

}

int	main() {
	int menu = 0;
	init();
	while (menu != 5)
	{
		printf("�л� ���� ���� ���α׷�\n--------------------------------\n1. �л� ���� �Է�\n2. �л� ���� ����\n3. �л� �˻�\n4. �л� ���� ���\n5. ���α׷� ����\n--------------------------------\n�޴����� : ");
		scanf("%d", &menu);
		switch (menu) {

		case(1):
			push_back();
			break;
		case(2):
			remove_node();
			break;
		case(3):
			search_node();
			break;
		case(4):
			node_print();
			break;
		case(5):
			init();
			break;
		}
	}
}

typedef struct User {
	char id[30];
	char pass[30];
	struct User* next;
	struct User* prev;
	struct DB* dlink;
} User;
User* current_user = NULL;
User* head, * tail;

typedef struct DB {
	char name[30];
	struct DB* link;
	struct TB* link;
} DB;
DB* db_current = NULL;

typedef struct TB {
	char data;
	struct TB* link;
} TB;
TB* tb_current = NULL;

void userinit() {
	head = (User*)malloc(sizeof(User));
	tail = (User*)malloc(sizeof(User));
	head->next = tail;
	tail->prev = head;
	head->prev = tail->next = NULL;
}