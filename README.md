# dl_list
Double Linked List

## API
```C
//Initialsize double linked list.
void dl_list_init(struct dl_list_s *dl_list);
//Add data
int dl_list_add(struct dl_list_s *dl_list,void *data,int at_front);
=>Returns: 1->success, 0->failure (malloc)
//Insert Data.
int dl_list_insert(struct dl_list_s *dl_list,void *data,int at_front);
=>Returns: 1->success, 0->failure (malloc)
//Move dl_list pointer by offset.
void dl_list_move(struct dl_list_s *dl_list,int offset);
=>Comments:Offset can be negative,0,or positive.
if offset + dl_list pointer position < 0 -> dl_list pointer = NULL
if offset + dl_list pointer position >= length -> dl_list pointer = NULL 
//Move dl_list pointer to start.
void dl_list_move_to_start(struct dl_list_s *dl_list);
=>Comments:dl_list pointer moves to the first element of the list.
//Move dl_list pointer to end.
void dl_list_move_to_end(struct dl_list_s *dl_list);
=>Comments:dl_list pointer moves to the last element of the list.
//Get data that is pointed by dl_list pointer.
void *dl_list_get(struct dl_list_s *dl_list);
//Get data that is pointed by dl_list pointer,and move the pointer
by offset.
void *dl_list_get_and_move(struct dl_list_s *dl_list,int offset);
=>Comments:if dl_list pointer == NULL, then dl_list_get returns NULL
//Delete the element that is pointer by dl_list pointer, from dl_list.
void dl_list_delete(struct dl_list_s *dl_list,int move_right);
=>Comments:if dl_list pointer == NULL, then nothing is deleted.
Else the node that the pointer points to, is deleted.
//Get dl_list length
int dl_list_get_length(struct dl_list_s *dl_list);
//Check if dl_list is empty
int dl_list_is_empty(struct dl_list_s *dl_list);
//Erase and free all the nodes in the dl_list
void dl_list_free(struct dl_list_s *dl_list);
//Erase and free all the nodes in the dl_list. Before any node is
deleted free_data function is applied to the data.
void dl_list_freee(struct dl_list_s *dl_list);
```
