#ifndef DL_LIST_H
#define DL_LIST_H

struct dl_list_node_s{
	void *data;
	struct dl_list_node_s *next;
	struct dl_list_node_s *prev;
};

struct dl_list_s{
	int length;
	struct dl_list_node_s *head;
	struct dl_list_node_s *tail;
	struct dl_list_node_s *c_node;
};

void dl_list_init(struct dl_list_s *dl_list);
//if at_front != 0:
//head              tail        head                 tail
//|		    |	  ->    |		     |
//d1 d2 d3 d4 d5 d6 d7		N d1 d2 d3 d4 d5 d6 d7
//else:
//head              tail        head                 tail
//|		    |	  ->    |		     |
//d1 d2 d3 d4 d5 d6 d7		d1 d2 d3 d4 d5 d6 d7 N
int dl_list_add(struct dl_list_s *dl_list,void *data,int at_front);
//if at_front != 0:
//	c_node			 c_node
//	|		->	 |
//d1 d2 d3 d4 d5 d6 d7     d1 d2 d3 N d4 d5 d6 d7
//else:
//	c_node			   c_node
//	|		->	   |
//d1 d2 d3 d4 d5 d6 d7     d1 d2 N d3 d4 d5 d6 d7
int dl_list_insert(struct dl_list_s *dl_list,void *data,int at_front);
//offset = -1
//	c_node			   c_node
//	|		->	   |
//d1 d2 d3 d4 d5		d1 d2 d3 d4 d5
void dl_list_move(struct dl_list_s *dl_list,int offset);
void dl_list_move_to_start(struct dl_list_s *dl_list);
void dl_list_move_to_end(struct dl_list_s *dl_list);
void *dl_list_get(struct dl_list_s *dl_list);
void *dl_list_get_and_move(struct dl_list_s *dl_list,int offset);
//if move_right != 0:
//	c_node			      c_node
//	|		->	      | 
//d1 d2 d3 d4 d5 d6 d7		d1 d2 d4 d5 d6 d7
//else:
//	c_node			   c_node
//	|		->	   |
//d1 d2 d3 d4 d5 d6 d7		d1 d2 d4 d5 d6 d7
void dl_list_delete(struct dl_list_s *dl_list,int move_right);
int dl_list_get_length(struct dl_list_s *dl_list);
int dl_list_is_empty(struct dl_list_s *dl_list);
void dl_list_free(struct dl_list_s *dl_list);
void dl_list_freee(struct dl_list_s *dl_list,void (*free_data)(void *));

#endif
