#include"dl_list.h"
#include<stdlib.h>

void dl_list_init(struct dl_list_s *dl_list){
	dl_list->length = 0;
	dl_list->head = NULL;
	dl_list->tail = NULL;
	dl_list->c_node =  NULL;
}

int dl_list_add(struct dl_list_s *dl_list,void *data,int at_front){
	struct dl_list_node_s *dl_list_node;
	dl_list_node = (struct dl_list_node_s *)malloc(sizeof(struct dl_list_node_s));
	if (dl_list_node == NULL) return 0;
	dl_list->length = dl_list->length + 1;
	dl_list_node->data = data;
	if (dl_list->head == NULL){
		dl_list_node->next = NULL;
		dl_list_node->prev = NULL;
		dl_list->head = dl_list_node;
		dl_list->tail = dl_list_node;
	}
	else{
		if (at_front){
			struct dl_list_node_s *tmp = dl_list->head;
			tmp->prev = dl_list_node;
			dl_list_node->next = tmp;
			dl_list_node->prev = NULL;
			dl_list->head = dl_list_node;
		}
		else{
			struct dl_list_node_s *tmp = dl_list->tail;
			tmp->next = dl_list_node;
			dl_list_node->next = NULL;
			dl_list_node->prev = tmp;
			dl_list->tail = dl_list_node;
		}
	}
	return 1;
}

int dl_list_insert(struct dl_list_s *dl_list,void *data,int at_front){
	struct dl_list_node_s *c_node = dl_list->c_node;
	if (c_node == NULL) return 0;
	struct dl_list_node_s *N = (struct dl_list_node_s *)malloc(sizeof(struct dl_list_node_s));
	if (N == NULL) return 0;
	dl_list->length = dl_list->length + 1;
	N->data = data;
	if (at_front){
		struct dl_list_node_s *tmp = c_node->next;
		c_node->next = N;
		N->prev = c_node;
		N->next = tmp;
		if (tmp == NULL){
			dl_list->tail = N;
		}
		else{
			tmp->prev = N;
		}
	}
	else{
		struct dl_list_node_s *tmp = c_node->prev;
		c_node->prev = N;
		N->next = c_node;
		N->prev = tmp;
		if (tmp == NULL){
			dl_list->head = N;
		}
		else{
			tmp->next = N;
		}
	}
	return 1;
}

void dl_list_move(struct dl_list_s *dl_list,int offset){
	struct dl_list_node_s *c_node = dl_list->c_node;
	int itter = 0;
	if (offset >= 0){
		while(itter < offset && c_node != NULL){
			c_node = c_node->next;
			dl_list->c_node = c_node;
			itter++;
		}
	}
	else{
		while(offset < itter && c_node != NULL){
			c_node = c_node->prev;
			dl_list->c_node = c_node;
			itter--;
		}
	}
}

void dl_list_move_to_start(struct dl_list_s *dl_list){
	dl_list->c_node = dl_list->head;
}

void dl_list_move_to_end(struct dl_list_s *dl_list){
	dl_list->c_node = dl_list->tail;
}

void *dl_list_get(struct dl_list_s *dl_list){
	if (dl_list->c_node != NULL) return (dl_list->c_node)->data;
	return NULL;
}

void *dl_list_get_and_move(struct dl_list_s *dl_list,int offset){
	void *data = dl_list_get(dl_list);
	dl_list_move(dl_list,offset);
	return data;
}

void dl_list_delete(struct dl_list_s *dl_list,int move_right){
	struct dl_list_node_s *c_node = dl_list->c_node;
	if (c_node == NULL) return;
	dl_list->length = dl_list->length - 1;
	struct dl_list_node_s *left,*right;
	right = c_node->next;
	left = c_node->prev;
	if (right == NULL){
		dl_list->tail = left;
		if (left == NULL){
			dl_list->head = NULL;
		}
		else{
			left->next = NULL;
		}
	}
	else{
		right->prev = left;
		if (left == NULL){
			dl_list->head = right;
		}
		else{
			left->next = right;
		}
	}
	if (move_right){
		dl_list->c_node = right;
	}
	else{
		dl_list->c_node = left;
	}
	free(c_node);
}

int dl_list_get_length(struct dl_list_s *dl_list){
	return dl_list->length;
}

int dl_list_is_empty(struct dl_list_s *dl_list){
	return dl_list->head == NULL;
}

void dl_list_free(struct dl_list_s *dl_list){
	if (dl_list->head != NULL){
		struct dl_list_node_s *tmp = dl_list->head;
		struct dl_list_node_s *itter = tmp->next;
		while (itter != NULL){
			free(tmp);
			tmp = itter;
			itter = itter->next;
		}
		free(tmp);
	}
	dl_list->length  = 0;
	dl_list->head = NULL;
	dl_list->tail = NULL;
	dl_list->c_node = NULL;
}

void dl_list_freee(struct dl_list_s *dl_list,void (*free_data)(void *)){
	if (dl_list->head != NULL){
		struct dl_list_node_s *tmp = dl_list->head;
		struct dl_list_node_s *itter = tmp->next;
		while (itter != NULL){
			free_data(tmp->data);
			free(tmp);
			tmp = itter;
			itter = itter->next;
		}
		free_data(tmp->data);
		free(tmp);
	}
	dl_list->length  = 0;
	dl_list->head = NULL;
	dl_list->tail = NULL;
	dl_list->c_node = NULL;
}
