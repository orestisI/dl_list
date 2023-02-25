#include"dl_list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ex_s{
	int id;
	char *name;
};

struct ex_s *ex_init(int id,const char *name){
	struct ex_s *ex = (struct ex_s *)malloc(sizeof(struct ex_s));
	ex->id = id;
	ex->name = (char *)malloc(strlen(name) + 1);
	strcpy(ex->name,name);
	return ex;
}

void ex_free(void *v){
	struct ex_s *ex = (struct ex_s *)v;
	free(ex->name);
	free(ex);
}

void ex_print(void *v){
	struct ex_s *ex = (struct ex_s *)v;
	printf("------\n");
	printf("Id = %d\n",ex->id);
	printf("Name = %s\n",ex->name);
	printf("------\n");
}

void add_test(){
	printf("add_test->start\n");
	struct dl_list_s dl_list;
	dl_list_init(&dl_list);

	struct ex_s *t1,*t2,*t3,*t4;
	t1 = ex_init(1,"orestis");
	t2 = ex_init(2,"arnty");
	t3 = ex_init(3,"romina");
	t4 = ex_init(4,"ippokraths");
	
	dl_list_add(&dl_list,t1,1);
	dl_list_add(&dl_list,t2,0);
	dl_list_add(&dl_list,t3,0);
	dl_list_add(&dl_list,t4,1);

	void *tmp;
	dl_list_move_to_start(&dl_list);
	//
	printf("move 1\n");
	for (int i=0; i<dl_list.length; i++){
		tmp = dl_list_get(&dl_list);
		ex_print(tmp);
		dl_list_move(&dl_list,1);
	}
	//
	printf("move -1\n");
	dl_list_move_to_end(&dl_list);
	for (int i=0; i<dl_list.length; i++){
		tmp = dl_list_get(&dl_list);
		ex_print(tmp);
		dl_list_move(&dl_list,-1);
	}
	//
	printf("get and move\n");
	dl_list_move_to_start(&dl_list);
	for (int i=0; i<dl_list.length; i++){
		tmp = dl_list_get_and_move(&dl_list,1);
		ex_print(tmp);
	}
	dl_list_freee(&dl_list,ex_free);
	printf("add_test->end\n");
}

void insert_test(){
	printf("insert_test->start\n");
	struct dl_list_s dl_list;
	dl_list_init(&dl_list);

	struct ex_s *t1,*t2,*t3,*t4;
	t1 = ex_init(1,"orestis");
	t2 = ex_init(2,"arnty");
	t3 = ex_init(3,"romina");
	t4 = ex_init(4,"ippokraths");
	
	dl_list_add(&dl_list,t1,1);
	dl_list_move_to_start(&dl_list);
	dl_list_insert(&dl_list,t2,0);
	dl_list_insert(&dl_list,t3,0);
	dl_list_insert(&dl_list,t4,1);

	void *tmp;
	//
	printf("move 1\n");
	dl_list_move_to_start(&dl_list);
	for (int i=0; i<dl_list.length; i++){
		tmp = dl_list_get_and_move(&dl_list,1);
		ex_print(tmp);
	}
	dl_list_freee(&dl_list,ex_free);
	printf("insert_test->end\n");
}

void delete_test(){
	printf("insert_test->start\n");
	struct dl_list_s dl_list;
	dl_list_init(&dl_list);

	struct ex_s *t1,*t2,*t3,*t4;
	t1 = ex_init(1,"orestis");
	t2 = ex_init(2,"arnty");
	t3 = ex_init(3,"romina");
	t4 = ex_init(4,"ippokraths");
	
	dl_list_add(&dl_list,t1,1);
	dl_list_move_to_start(&dl_list);
	dl_list_insert(&dl_list,t2,0);
	dl_list_insert(&dl_list,t3,0);
	dl_list_insert(&dl_list,t4,1);

	void *tmp;
	tmp = dl_list_get(&dl_list);
	ex_print(tmp);
	dl_list_delete(&dl_list,1);
	dl_list_move_to_start(&dl_list);
	for (int i=0; i<dl_list.length; i++){
		tmp = dl_list_get_and_move(&dl_list,1);
		ex_print(tmp);
	}
	dl_list_move_to_start(&dl_list);
	tmp = dl_list_get(&dl_list);
	dl_list_delete(&dl_list,1);
	dl_list_move_to_start(&dl_list);
	for (int i=0; i<dl_list.length; i++){
		tmp = dl_list_get_and_move(&dl_list,1);
		ex_print(tmp);
	}
	dl_list_move_to_end(&dl_list);
	dl_list_delete(&dl_list,0);
	tmp = dl_list_get(&dl_list);
	ex_print(tmp);
	dl_list_free(&dl_list);
	ex_free(t1);
	ex_free(t2);
	ex_free(t3);
	ex_free(t4);
	printf("delete_test->end\n");
}

void crash_test(){
	printf("crash_test->start\n");
	struct dl_list_s dl_list;
	dl_list_init(&dl_list);

	struct ex_s *t1,*t2,*t3,*t4;
	t1 = ex_init(1,"orestis");
	t2 = ex_init(2,"arnty");
	t3 = ex_init(3,"romina");
	t4 = ex_init(4,"ippokraths");
	
	int op;
	for (int i=0; i<100000; i++){
		op = rand()%5;
		if (op == 0){
			int t = rand()%4;
			int w = rand()%2;
			if (t == 0){
				dl_list_add(&dl_list,t1,w);
			}
			else if (t == 1){
				dl_list_add(&dl_list,t2,w);
			}
			else if (t == 2){
				dl_list_add(&dl_list,t3,w);
			}
			else{
				dl_list_add(&dl_list,t4,w);
			}
		}
		else if (op == 1){
			int l = dl_list.length;
			if (l > 0){
				dl_list_move_to_start(&dl_list);
				dl_list_move(&dl_list,(rand()%l)*(2*(rand()%2) - 1));
				int t = rand()%4;
				int w = rand()%2;
				if (t == 0){
					dl_list_insert(&dl_list,t1,w);
				}
				else if (t == 1){
					dl_list_insert(&dl_list,t2,w);
				}
				else if (t == 2){
					dl_list_insert(&dl_list,t3,w);
				}
				else{
					dl_list_insert(&dl_list,t4,w);
				}
			}
		}
		else if (op == 2){
			dl_list_move_to_start(&dl_list);
			void *tmp = dl_list_get(&dl_list);
			if (tmp != NULL){
				ex_print(tmp);
			}
		}
		else if (op == 3){
			int l = dl_list.length;
			if (l > 0){
				dl_list_move_to_start(&dl_list);
				dl_list_move(&dl_list,(rand()%l)*(2*(rand()%2) - 1));
				dl_list_delete(&dl_list,rand()%2);
			}
		}
		else if (op == 4){
			dl_list_free(&dl_list);
		}
	}
	dl_list_free(&dl_list);
	ex_free(t1);
	ex_free(t2);
	ex_free(t3);
	ex_free(t4);
	printf("crash_test->end\n");
}
int main(){
	//add_test();
	//insert_test();
	//delete_test();
	crash_test();

	return 1;
}
