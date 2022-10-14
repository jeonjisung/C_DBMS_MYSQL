#include "struct.h"
#include <ctype.h>
#define MAX_LEN 10000

User* user_head = NULL;
User* sel_user = NULL;
DB* sel_db = NULL;
TB* sel_tb = NULL;
FD* sel_fd = NULL;
FD* fd_head = NULL;
Data* sel_dt = NULL;

void delete_data(const char* query) {

	char* option = NULL;

	int array[50];
	int index = 0;
	int value = 0;

	option = (char*)malloc(strlen(query));

	scanf("%[^\n]s", query);

	strcpy(option, query);

	int i = 0;
	char* arr[50] = { NULL, };
	char* cut2 = my_strtok(option, " ");

	printf("%s\n", cut2);

	while (cut2 != NULL) {
		arr[i] = cut2;
		i++;
		cut2 = my_strtok(NULL, " ");
	}

	TB* t_temp = sel_db->t_link;

	if (t_temp == NULL) {
		printf("table is NULL\n");
	}
	else {
		while (t_temp != NULL) {
			for (i = 0; i < 30; i++) {
				if (arr[i] != NULL) {
					if (strcmp(t_temp->t_id, arr[i]) == 0) {
						//필드 접속
						if (strcmp(arr[i + 1], "where") == 0) {
							FD* f_temp = t_temp->f_link;

							while (f_temp != NULL) {
								int j = 0;
								for (j; j < 20; j++) {
									if (f_temp != NULL) {
										Data* d_temp = f_temp->dt_link;
										if (strcmp(f_temp->f_id, arr[i + 2]) == 0) {

											if (strcmp(arr[i + 3], "==") == 0) {
												while (d_temp != NULL) {
													for (index = 0; index < 10; index++) {
														for (value = 0; value < 30; value++) {
															if (d_temp != NULL) {
																if (strcmp(arr[i + 4], d_temp->data) == 0) {
																	array[index] = value;

																	int k = 0;
																	int l = 0;

																	FD* f_temp2 = t_temp->f_link;
																	while (f_temp2 != NULL) {
																		Data* cur = f_temp2->dt_link;
																		Data* pre = f_temp2->dt_link;
																		for (k = 0; k <= index; k++) {
																			for (l = 0; l < array[index]; l++) {
																				if (cur == pre) {
																					cur = cur->dt_link;
																				}
																				else {
																					cur = cur->dt_link;
																					pre = pre->dt_link;
																				}
																			}
																			// CHECK empty list
																			if (sel_db->t_link == NULL) {
																				printf("Table is Null.\n");
																			}
																			else {
																				if (f_temp2->dt_link == cur) {
																					f_temp2->dt_link = cur->dt_link;
																				}
																				else {
																					pre->dt_link = cur->dt_link;
																				}
																				// FREE cur
																				free(cur);
																			}
																			f_temp2 = f_temp2->f_link;
																		}
																	}
																	d_temp = f_temp->dt_link;
																}
																d_temp = d_temp->dt_link;
															}
														}
													}
												}
											}
											else if (strcmp(arr[i + 3], "!=") == 0) {
												while (d_temp != NULL) {
													for (index = 0; index < 10; index++) {
														for (value = 0; value < 30; value++) {
															if (d_temp != NULL) {
																if (strcmp(arr[i + 4], d_temp->data) != 0) {
																	array[index] = value;

																	int k = 0;
																	int l = 0;

																	FD* f_temp2 = sel_db->t_link->f_link;
																	while (f_temp2 != NULL) {
																		for (k = 0; k <= index; k++) {
																			Data* cur = f_temp2->dt_link;
																			Data* pre = f_temp2->dt_link;
																			for (l = 0; l < array[index]; l++) {
																				if (cur == pre) {
																					cur = cur->dt_link;
																				}
																				else {
																					cur = cur->dt_link;
																					pre = pre->dt_link;
																				}
																			}
																			printf("%s\t", cur->data);
																			if (sel_db->t_link == NULL) {
																				printf("Table is Null.\n");
																			}
																			else {
																				if (f_temp2->dt_link == cur) {
																					f_temp2->dt_link = cur->dt_link;
																				}
																				else {
																					pre->dt_link = cur->dt_link;
																				}
																				// FREE cur
																				free(cur);
																			}
																			f_temp2 = f_temp2->f_link;
																		}
																	}
																	d_temp = f_temp->dt_link;
																}
																d_temp = d_temp->dt_link;
															}
														}
													}
												}
											}
										}
										f_temp = f_temp->f_link;
									}
								}
							}
						}
					}
				}
			}
			t_temp = t_temp->t_link;
		}
	}
}

void select_data(const char* query) {
	char* option = NULL;

	int array[50];
	int index = 0;
	int value = 0;

	option = (char*)malloc(strlen(query));

	scanf("%[^\n]s", query);

	strcpy(option, query);

	int i = 0;
	char* arr[50] = { NULL, };
	char* cut2 = my_strtok(option, " ");

	while (cut2 != NULL) {
		arr[i] = cut2; // (~) 사이의 문자 배열 저장 // 여기까지는 문자열 배열단위로 잘 출력
		i++;
		cut2 = my_strtok(NULL, " ");
	}
	i = 0;

	// 테이블을 찾는다
	TB* t_temp = sel_db->t_link;

	if (t_temp == NULL) {
		printf("table is NULL\n");
	}
	else {
		while (t_temp != NULL) {
			for (; i < 50; i++) {
				if (arr[i] != NULL) {
					if (strcmp(arr[i], "*") == 0) {
						while (strcmp(t_temp->t_id, arr[i + 2]) != 0) {
							t_temp = t_temp->t_link;
						}
						//테이블 입장
						if (strcmp(t_temp->t_id, arr[i + 2]) == 0) {
							if (arr[i + 3] != NULL) {
								if (strcmp(arr[i + 3], "where") == 0) {
									FD* f_temp = t_temp->f_link;

									while (f_temp != NULL) {
										int j = 0;
										for (j; j < 20; j++) {
											if (f_temp != NULL) {
												Data* d_temp = f_temp->dt_link;
												if (strcmp(f_temp->f_id, arr[i + 4]) == 0) {

													if (strcmp(arr[i + 5], "==") == 0) {
														while (d_temp != NULL) {
															for (index = 0; index < 10; index++) {
																for (value = 0; value < 30; value++) {
																	if (d_temp != NULL) {
																		if (strcmp(arr[i + 6], d_temp->data) == 0) {
																			array[index] = value;

																			int k = 0;
																			int l = 0;

																			FD* f_temp2 = sel_db->t_link->f_link;

																			while (f_temp2 != NULL) {
																				Data* d_temp2 = f_temp2->dt_link;
																				for (k = 0; k <= index; k++) {
																					for (l = 0; l < array[index]; l++) {
																						d_temp2 = d_temp2->dt_link;
																					}
																					printf("%s\t", d_temp2->data);
																					f_temp2 = f_temp2->f_link;
																				}
																			}
																			printf("\n");
																		}
																		d_temp = d_temp->dt_link;
																	}
																}
															}
														}
													}
													else if (strcmp(arr[i + 5], "!=") == 0) {
														while (d_temp != NULL) {
															for (index = 0; index < 10; index++) {
																for (value = 0; value < 30; value++) {
																	if (d_temp != NULL) {
																		if (strcmp(arr[i + 6], d_temp->data) != 0) {
																			array[index] = value;

																			int k = 0;
																			int l = 0;

																			FD* f_temp2 = sel_db->t_link->f_link;

																			while (f_temp2 != NULL) {
																				Data* d_temp2 = f_temp2->dt_link;
																				for (k = 0; k <= index; k++) {
																					for (l = 0; l < array[index]; l++) {
																						d_temp2 = d_temp2->dt_link;
																					}
																					printf("%s\t", d_temp2->data);
																					f_temp2 = f_temp2->f_link;
																				}
																			}
																			printf("\n");
																		}
																		d_temp = d_temp->dt_link;
																	}
																}
															}
														}
													}
												}
												f_temp = f_temp->f_link;
											}
										}
									}
								}
							}
							else {
								FD* f_temp = t_temp->f_link;
								FD* select_fd = t_temp->f_link;

								printf("\n-----------------------------\n");
								while (f_temp != NULL) {
									printf("%s ", f_temp->f_id);
									f_temp = f_temp->f_link;
								}
								printf("\n");
								int i = 1;
								while (select_fd != NULL) {
									Data* temp = select_fd->dt_link;
									while (temp != NULL) {
										for (i = 1; i < 7; i++) {
											if (temp != NULL) {
												printf("%s\t ", temp->data);
												temp = temp->dt_link;
											}
										}
										printf("\n");
									}
									select_fd = select_fd->f_link;
								}
							}
						}
					}
				}
			}
			t_temp = t_temp->t_link;
		}
	}
}

void all_data() {
	FD* f_temp = sel_db->t_link->f_link;

	while (f_temp != NULL) {
		sel_fd = f_temp;
		Data* temp = f_temp->dt_link;
		int i = 1;
		while (temp != NULL) {
			printf("-----------------------------\n");
			printf("%d st\n", i++);
			printf("data : %s\n", temp->data);

			temp = temp->dt_link;
		}
		f_temp = f_temp->f_link;
	}
}


void insert_field(const char* query) {

	char* option = NULL;
	option = (char*)malloc(strlen(query));

	scanf("%[^\n]s", query);

	strcpy(option, query);

	// 문자열 정리 후 나누기
	char* str = NULL;

	char* cut = strtok_s(str, " ", &option); // 테이블 이름 cut에 저장

	char* cut2 = strtok_s(str, " ", &option);
	remove_garo(option, ',');
	remove_last_garo(option);
	remove_first_garo(option);

	char* arr[50] = { NULL, };
	int i = 0;
	char* cut3 = my_strtok(option, " ");

	while (cut3 != NULL) {
		arr[i] = cut3;
		i++;
		cut3 = my_strtok(NULL, " ");
	}

	// 테이블을 찾는다
	TB* t_temp = sel_db->t_link;

	if (t_temp == NULL) {
		printf("Table is Null.\n");
	}
	else {
		while (t_temp != NULL) {
			// table 접속 완료
			if (strcmp(t_temp->t_id, cut) == 0) {
				sel_tb = t_temp;
				if (sel_tb = t_temp) {
					//필드를 찾는다.
					FD* f_temp = sel_tb->f_link;

					if (f_temp == NULL) {
						printf("Filed is Null.\n");
					}
					else {
						i = 0;
						while (f_temp != NULL) {
							//form에 맞게 찾기
							sel_fd = f_temp;
							for (int j = 0; j < 10; j++) {
								Data* dt = (Data*)malloc(sizeof(Data));
								Data* dt_temp = sel_fd->dt_link;
								//Data insert == Add
								for (; i < 50; i++) {
									if (strcmp(f_temp->form, "int") == 0) {

										dt->data = NULL;
										dt->dt_link = NULL;

										dt->data = (char*)malloc(strlen(arr[i]));
										strcpy(dt->data, arr[i]);

										if (dt_temp == NULL) {
											sel_fd->dt_link = dt;
										}
										else {
											while (dt_temp->dt_link != NULL) {
												dt_temp = dt_temp->dt_link;
											}
											dt_temp->dt_link = dt;
										}
										i++;
										break;
									}
									else if (strcmp(f_temp->form, "varchar") == 0) {

										/*확인 필요*/
										dt->data = NULL;
										dt->dt_link = NULL;

										dt->data = (char*)malloc(strlen(arr[i]));
										strcpy(dt->data, arr[i]);

										if (dt_temp == NULL) {
											sel_fd->dt_link = dt;
										}
										else {
											while (dt_temp->dt_link != NULL) {
												dt_temp = dt_temp->dt_link;
											}
											dt_temp->dt_link = dt;
										}
										i++;
										break;
									}
									else {
										printf("예외입니다.");
									}
								}
								break;
							}
							f_temp = f_temp->f_link;
						}
					}
				}
			}
			t_temp = t_temp->t_link;
		}
	}
}

void all_fd() {
	FD* temp = sel_tb->f_link;

	int i = 1;

	if (temp == NULL) {
		printf("Field is NULL\n");
	}
	else {
		while (temp != NULL) {
			printf("-----------------------------\n");
			printf("%d st\n", i++);
			printf("ID : %s\n", temp->f_id);
			printf("FORM : %s\n", temp->form);
			printf("SIZE : %s\n", temp->size);
			/*printf("TYPE : %s\n", temp->t_type);*/

			temp = temp->f_link;
		}
	}
}
void select_tb(const char* id) {

	TB* t_temp = sel_db->t_link;

	if (t_temp == NULL) {
		printf("Table is Null.\n");
	}
	else {
		//scanf("%s", id);
		while (t_temp != NULL) {
			if (strcmp(t_temp->t_id, id) == 0) {
				printf("Table '%s'\n", id);
				sel_tb = t_temp;
			}
			t_temp = t_temp->t_link;
		}
	}
}

void drop_tb(const char* id) {
	TB* pre = sel_db->t_link;
	TB* cur = sel_db->t_link;
	// CHECK empty list
	if (sel_db->t_link == NULL) {
		printf("Table is Null.\n");
	}
	else {
		while (cur != NULL) {
			//scanf("%s", id);
			//CHECK ID, PASS
			if (strcmp(cur->t_id, id) == 0) {
				if (sel_db->t_link == cur) {
					sel_db->t_link = cur->t_link;
				}
				else {
					pre->t_link = cur->t_link;
				}
				// FREE cur
				free(cur);
				break;
			}
			// MOVE cur, pre 
			if (cur == pre) {
				cur = cur->t_link;
			}
			else {
				cur = cur->t_link;
				pre = pre->t_link;
			}
		}
	}
}


void create_tb(const char* id) {
	TB* tb = (TB*)malloc(sizeof(TB));

	TB* temp = sel_db->t_link;

	tb->t_id = NULL;
	tb->t_link = NULL;
	tb->f_link = NULL;

	tb->t_id = (char*)malloc(strlen(id));

	char* option = NULL;
	option = (char*)malloc(strlen(id));

	scanf("%[^\n]s", id);
	strcpy(option, id);

	// tb->t_id에 담긴 값을 변환시켜 줌
	char* str = NULL;
	char* cut = strtok_s(str, "(", &option);

	remove_garo(cut, ' ');
	// cut : () 이전의 값
	// tb->t_id : ()이후의 값

	char* c = option;

	change_garo(c, '(');
	remove_garo(c, ')');

	char* arr[50] = { NULL, };
	int i = 0;
	char* cut2 = my_strtok(c, " ");

	while (cut2 != NULL) {
		arr[i] = cut2;	// ( ~ ) 사이의 문자 배열 저장 // 여기까지는 문자열 배열단위로 잘 출력
		i++;
		cut2 = my_strtok(NULL, " ");
	}

	strcpy(tb->t_id, cut);
	if (temp == NULL) {

		sel_db->t_link = tb;

		sel_tb = sel_db->t_link;

		i = 0;
		for (int j = 0; j < 3; j++) {
			FD* fd = (FD*)malloc(sizeof(FD));
			FD* f_temp = sel_tb->f_link;
			for (; i <= 10; i++) {
				if (arr[i] != NULL) {
					if (sel_tb->f_link == NULL) {
						if (strcmp(arr[i], "int") == 0) {

							fd->form = (char*)malloc(strlen(arr[i]));
							fd->size = (char*)malloc(strlen(arr[i]));
							strcpy(fd->form, arr[i]);
							strcpy(fd->size, arr[i]);
						}
						else if (strcmp(arr[i], "varchar") == 0) {

							fd->form = NULL;

							fd->form = (char*)malloc(strlen(arr[i]));
							strcpy(fd->form, arr[i]);
						}
						/*arr[i] > 47 && arr[i] < 58*/
						else if (isdigit(*arr[i])) {

							fd->size = (char*)malloc(strlen(arr[i]));

							strcpy(fd->size, arr[i]);
						}
						else if (strcmp(arr[i], ",") == 0) {
							sel_tb->f_link = fd;
							i++;
							break;
						}
						else {
							fd->f_id = NULL;
							fd->f_link = NULL;
							fd->dt_link = NULL;

							fd->f_id = (char*)malloc(strlen(arr[i]));
							strcpy(fd->f_id, arr[i]);
						}
					}
					else {
						while (f_temp->f_link != NULL) {
							f_temp = f_temp->f_link;
						}
						if (arr[i] != NULL) {
							if (strcmp(arr[i], "int") == 0) {

								fd->form = NULL;
								fd->size = NULL;

								fd->form = (char*)malloc(strlen(arr[i]));
								fd->size = (char*)malloc(strlen(arr[i]));
								strcpy(fd->form, arr[i]);
								strcpy(fd->size, arr[i]);
							}
							else if (strcmp(arr[i], "varchar") == 0) {

								fd->form = NULL;

								fd->form = (char*)malloc(strlen(arr[i]));
								strcpy(fd->form, arr[i]);
							}
							else if (isdigit(*arr[i])) {

								fd->size = NULL;

								fd->size = (char*)malloc(strlen(arr[i]));
								strcpy(fd->size, arr[i]);
							}
							else if (strcmp(arr[i], ",") == 0) {
								f_temp->f_link = fd;
								i++;
								break;
							}
							else {

								fd->f_id = NULL;
								fd->f_link = NULL;
								fd->dt_link = NULL;

								fd->f_id = (char*)malloc(strlen(arr[i]));
								strcpy(fd->f_id, arr[i]);
							}
						}
					}
				}
			}
		}
	}
	else {
		//while (temp->f_link != NULL) { //nullpoint
		//	temp = temp->t_link;
		//}
		temp->t_link = tb;

		sel_tb = temp->t_link;

		i = 0;
		for (int j = 0; j < 5; j++) {
			FD* fd = (FD*)malloc(sizeof(FD));
			FD* f_temp = sel_tb->f_link;
			for (; i < 50; i++) {
				if (arr[i] != NULL) {
					if (f_temp == NULL) {
						if (strcmp(arr[i], "int") == 0) {
							printf("int : %s\n", arr[i]);

							fd->form = (char*)malloc(strlen(arr[i]));
							fd->size = (char*)malloc(strlen(arr[i]));
							strcpy(fd->form, arr[i]);
							strcpy(fd->size, arr[i]);
						}
						else if (strcmp(arr[i], "varchar") == 0) {
							printf("varchar : %s\n", arr[i]);

							fd->form = NULL;

							fd->form = (char*)malloc(strlen(arr[i]));
							strcpy(fd->form, arr[i]);
						}
						else if (isdigit(*arr[i])) {
							printf("size : %s\n", arr[i]);

							fd->size = (char*)malloc(strlen(arr[i]));

							strcpy(fd->size, arr[i]);
						}
						else if (strcmp(arr[i], ",") == 0) {
							printf(", : %s\n", arr[i]);
							sel_tb->f_link = fd;
							i++;
							break;
						}
						else {
							printf("else : %s\n", arr[i]);

							fd->f_id = NULL;
							fd->f_link = NULL;
							fd->dt_link = NULL;

							fd->f_id = (char*)malloc(strlen(arr[i]));
							strcpy(fd->f_id, arr[i]);
						}
					}
					else {
						while (f_temp->f_link != NULL) {
							f_temp = f_temp->f_link;
						}
						if (arr[i] != NULL) {
							if (strcmp(arr[i], "int") == 0) {
								printf("int : %s\n", arr[i]);

								fd->form = NULL;
								fd->size = NULL;

								fd->form = (char*)malloc(strlen(arr[i]));
								fd->size = (char*)malloc(strlen(arr[i]));
								strcpy(fd->form, arr[i]);
								strcpy(fd->size, arr[i]);
							}
							else if (strcmp(arr[i], "varchar") == 0) {
								printf("varchar : %s\n", arr[i]);

								fd->form = NULL;

								fd->form = (char*)malloc(strlen(arr[i]));
								strcpy(fd->form, arr[i]);
							}
							else if (strcmp(arr[i], "30") == 0) {
								printf("size : %s\n", arr[i]);

								fd->size = NULL;

								fd->size = (char*)malloc(strlen(arr[i]));
								strcpy(fd->size, arr[i]);
							}
							else if (strcmp(arr[i], ",") == 0) {
								printf(", : %s\n", arr[i]);
								f_temp->f_link = fd;
								i++;
								break;
							}
							else {
								printf("else : %s\n", arr[i]);

								fd->f_id = NULL;
								fd->f_link = NULL;
								fd->dt_link = NULL;

								fd->f_id = (char*)malloc(strlen(arr[i]));
								strcpy(fd->f_id, arr[i]);
							}
						}
					}
				}
			}
		}
	}
}

void all_tb() {
	TB* temp = sel_db->t_link;

	int i = 1;
	while (temp != NULL) {
		printf("-----------------------------\n");
		printf("%d st\n", i++);
		printf("TABLE : %s\n", temp->t_id);
		/*printf("TYPE : %s\n", temp->t_type);*/

		temp = temp->t_link;
	}
}
void remove_db(const char* id) {
	DB* pre = sel_user->d_link;
	DB* cur = sel_user->d_link;
	// CHECK empty list
	if (sel_user->d_link == NULL) {
		printf("DataBase is null.\n");
	}
	else {
		//scanf("%s", id);
		while (cur != NULL) {
			//CHECK ID, PASS
			if (strcmp(cur->d_id, id) == 0) {
				if (sel_user->d_link == cur) {
					sel_user->d_link = cur->d_link;
				}
				else {
					pre->d_link = cur->d_link;
				}
				// FREE cur
				free(cur);
				break;
			}
			// MOVE cur, pre 
			if (cur == pre) {
				cur = cur->d_link;
			}
			else {
				cur = cur->d_link;
				pre = pre->d_link;
			}
		}
	}
}

void select_db(const char* id) {

	DB* d_temp = sel_user->d_link;

	if (d_temp == NULL) {
		printf("DataBase is Null.\n");
	}
	else {
		//scanf("%s", id);
		while (d_temp != NULL) {
			if (strcmp(d_temp->d_id, id) == 0) {
				printf("DataBase '%s'\n", id);
				sel_db = d_temp;
			}
			d_temp = d_temp->d_link;
		}
	}
}

void add_db(const char* id) {

	DB* db = (DB*)malloc(sizeof(DB));
	//DB* temp = db_head;
	DB* temp = sel_user->d_link;

	db->d_id = NULL;
	db->d_link = NULL;
	db->t_link = NULL;

	db->d_id = (char*)malloc(strlen(id));

	scanf("%s", id);

	strcpy(db->d_id, id);

	if (temp == NULL) {
		sel_user->d_link = db;
	}
	else {
		while (temp->d_link != NULL) {
			temp = temp->d_link;
		}
		temp->d_link = db;
	}
}
//DB 세이브
void db_exit() {
	FILE* save = fopen("db.txt", "wt");
	if (sel_user != NULL) {
		while (sel_user->d_link != NULL) {
			DB* temp = sel_user->d_link;
			fprintf(save, "%s\n", temp->d_id);
			temp = temp->d_link;
		}
		free(sel_user->d_link);
	}
}

void all_db() {
	DB* temp = sel_user->d_link;

	int i = 1;
	while (temp != NULL) {
		printf("-----------------------------\n");
		printf("%d st Database\n", i++);
		printf("NAME : %s\n", temp->d_id);

		temp = temp->d_link;
	}
}

void remove_user(const char* id, const char* pass) {
	User* pre = user_head;
	User* cur = user_head;
	// CHECK empty list
	if (user_head == NULL) {
		printf("User in Null.\n");
	}
	else {
		scanf("%s", id);
		while (cur != NULL) {
			//CHECK ID, PASS
			if (strcmp(cur->u_id, id) == 0) {
				printf("PW : ");
				scanf("%s", pass);
				if (strcmp(cur->u_pass, pass) == 0) {
					if (user_head == cur) {
						user_head = cur->u_link;
					}
					else {
						pre->u_link = cur->u_link;
					}
					// FREE cur
					free(cur);
					break;
				}
				else {
					printf("Password is null. \n");
				}
			}
			// MOVE cur, pre 
			if (cur == pre) {
				cur = cur->u_link;
			}
			else {
				cur = cur->u_link;
				pre = pre->u_link;
			}
		}
	}
}
void add_user(const char* id, const char* pass) {

	User* user = (User*)malloc(sizeof(User));

	User* temp = user_head;

	user->u_id = NULL;
	user->u_link = NULL;
	user->d_link = NULL;

	user->u_id = (char*)malloc(strlen(id));
	user->u_pass = (char*)malloc(strlen(pass));

	scanf("%s", id);
	printf("PW : ");
	scanf("%s", pass);

	strcpy(user->u_id, id);
	strcpy(user->u_pass, pass);

	if (user_head == NULL) {
		user_head = user;
	}
	else {
		while (temp->u_link != NULL) {
			temp = temp->u_link;
		}
		temp->u_link = user;
	}
}

//void remove_duplicates(const char* id, const char* pass) {
//	User* cur = user_head;
//	User* ser = user_head, * pre = user_head;
//	if (cur == NULL) {
//		return;
//	}
//	while (cur->u_link != NULL) {
//		ser = cur->u_link;
//		pre = cur;
//
//		while (ser->u_link != NULL) {
//			if (strcmp(ser->u_id, cur->u_id) == 0) {
//				pre->u_link = ser->u_link;
//			}
//			else {
//				pre = ser;
//			}
//			ser = ser->u_link;
//		}
//		cur = cur->u_link;
//	}
//}

//유저 불러오기
//void user_txt() {
//
//	char u_id[30], u_pass[30];
//
//	FILE* load = fopen("source.txt", "rt");
//	if (load != NULL) {
//		User* user = NULL;
//		while (feof(load) == 0) {
//			user = (User*)malloc(sizeof(User));
//			User* u_temp = user_head;
//
//			user->u_id = NULL;
//			user->u_link = NULL;
//			user->d_link = NULL;
//
//			fscanf(load, "%s %s\n", &user->u_id, user->u_pass);
//
//			strcpy(user->u_id, u_id);
//			strcpy(user->u_id, u_pass);
//
//			if (user_head == NULL) {
//				user_head = user;
//			}
//			else {
//				while (u_temp->u_link != NULL) {
//					u_temp = u_temp->u_link;
//				}
//				u_temp->u_link = user;
//			}
//		}
//	}
//}

//유저 세이브
void user_exit() {
	FILE* save = fopen("source.txt", "wt");
	if (user_head != NULL) {
		while (user_head->u_link != NULL) {
			User* temp = user_head;
			fprintf(save, "%s %s\n", temp->u_id, temp->u_pass);
			user_head = user_head->u_link;
		}
		free(user_head);
	}
}

void all_user() {
	User* temp = user_head;

	int i = 1;
	while (temp != NULL) {
		printf("-----------------------------\n");
		printf("%d st User\n", i++);
		printf("ID : %s\n", temp->u_id);
		printf("PW : %s\n", temp->u_pass);

		temp = temp->u_link;
	}
}

void select_user(const char* id, const char* pass) {
	User* u_temp = user_head;

	if (user_head == NULL) {
		printf("User is Null.\n");
	}

	else {
		scanf("%s", id);
		while (u_temp != NULL) {
			if (strcmp(u_temp->u_id, id) == 0) {
				printf("PW : ");
				scanf("%s", pass);
				if (strcmp(u_temp->u_pass, pass) == 0) {
					printf("Welcome [%s].\n", id);
					sel_user = u_temp;
				}
				else {
					printf("Password is Null.\n");
					break;
				}
			}
			u_temp = u_temp->u_link;
		}
	}
}

// HEAD
void list_init() {
	user_head = NULL;
}
int main() {
	User* user = user_head;

	char cmd, id, pass;

	/*user_txt();*/
	while (1) {
		printf("->");
		scanf("%s ", &cmd);
		if (strcmp("make", &cmd) == 0) {
			add_user(&id, &pass);
			/*remove_duplicates(&id, &pass);*/
		}
		else if (strcmp("userlist", &cmd) == 0) {
			all_user();
		}
		else if (strcmp("delete", &cmd) == 0) {
			remove_user(&id, &pass);
		}
		else if (strcmp("select", &cmd) == 0) {
			select_user(&id, &pass);
			while (1) {
				printf("->");
				scanf("%s", &cmd);
				if (strcmp("make", &cmd) == 0) {
					add_db(&id);
				}
				else if (strcmp("dblist", &cmd) == 0) {
					all_db();
				}
				else if (strcmp("use", &cmd) == 0) {
					select_db(&id);
					while (1) {
						printf("->");
						scanf("%s", &cmd);
						if (strcmp("create", &cmd) == 0) {
							create_tb(&id);
						}
						else if (strcmp("tblist", &cmd) == 0) {
							all_tb();
						}
						else if (strcmp("drop", &cmd) == 0) {
							drop_tb(&id);
						}
						else if (strcmp("insert", &cmd) == 0) {
							insert_field(&id);
						}
						else if (strcmp("select", &cmd) == 0) {
							select_data(&id);
						}
						else if (strcmp("delete", &cmd) == 0) {
							delete_data(&id);
						}
						else if (strcmp("break", &cmd) == 0) {
							printf("Exit Table");
							break;
						}
					}
				}
				else if (strcmp("drop", &cmd) == 0) {
					remove_db(&id);
				}
				else if (strcmp("break", &cmd) == 0) {
					printf("Exit database.\n");
					db_exit();
					break;
				}
			}
		}
		else if (strcmp("break", &cmd) == 0) {
			printf("Exit jsql.");
			user_exit();
			break;
		}
	}
	/*add_user("a", "a");
	add_user("b", "b");
	add_user("c", "c");
	all_user();
	printf("------------------------- user\n\n");

	select_user("a", "a");
	add_db("a_1");
	add_db("a_2");
	add_db("a_3");
	all_db();
	printf("------------------------- db a\n\n");

	select_user("b", "b");
	add_db("b_1");
	add_db("b_2");
	add_db("b_3");
	all_db();
	printf("------------------------- db b\n\n");

	select_user("c", "c");
	all_db();
	printf("------------------------- db c\n\n");
	select_user("a", "a");
	all_db();
	remove_db("a_2");
	all_db();
	select_db("a_3");
	create_tb("tbname(id int , name varchar(20) , what? varchar(5) ,)");*/
	/*create_tb("tbname2(id int , name varchar(20) , what? varchar(5) ,)");*/
	//create_tb("tbname2(name varchar(30) , id int ,)");
	/*create_tb("tbname2(id int , nsmister varchar(30) , ququque varchar(30) ,)");*/
	/*select_tb("tbname2");
	all_fd();*/
	//insert_field("tbname value (1, 'yt', 'create')");
	//insert_field("tbname value (2, 'sm', 'idontknow')");
	//insert_field("tbname value (3, 'yh', 'idontknow')");
	//insert_field("tbname value (4, 'jh', 'idontknow')");
	//insert_field("tbname value (5, 'yt', 'idontknow')");
	//insert_field("tbname value (6, 'js', 'create')");

	//insert_field("tbname2 value ('js', 1)");
	//insert_field("tbname2 value ('sm', 2)");
	/*select_data("* from tbname where name == 'jisung'");*/
	/*select_data("* from tbname where what? != 'idontknow'"); */
	//delete_data("from tbname where what? != 'idontknow'");

	//select_data("* from tbname");
	//select_data("* from tbname2");
	/*all_tb();
	select_tb(" tbname");
	all_fd();*/
}
