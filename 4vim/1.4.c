
#include<stdio.h>
#include<stdlib.h>

struct list{
  struct list *prev;
  struct list *next;
  int data;
};

static struct list head = {.prev = NULL, .next = NULL, .data = 0};
struct list *push(int data);
struct list *next_node(struct list *node);
struct list *prev_node(struct list *node);
struct list *get_nth(size_t n);
void  *print_node(const struct list *node);

int main(void){
  struct list *a = push(10);
  struct list *b = push(20);
  struct list *c = push(30);

  printf("a: "); print_node(a);
  printf("a->next: "); print_node(next_node(a));
  printf("b->prev: "); print_node(prev_node(b));

  struct list *second = get_nth(1);
  if(second) {
    printf("2nd element: ");
    print_node(second);
} else {
  fprintf(stderr, "2nd elment not found\n");
}
struct list *p = head.next;
while (p) {
  struct list *tmp = p -> next;
  free(p);
  p = tmp;
}
return 0;
}



struct list *push(int data){
    struct list *p = &head;
    while(p -> next != NULL){
      p = p -> next;
    }
    struct list *new_node = malloc(sizeof(*new_node));
    if(!new_node) {
      fprintf(stderr, "malloc failed\n");
      return NULL;
    }

    new_node -> data = data;
    new_node -> next = NULL;
    new_node -> prev = p;

    p-> next = new_node;

    return new_node;
}

struct list *next_node(struct list *node) {
  if (!node) return NULL;
  return node-> next;
}
struct list *prev_node(struct list *node) {
  if (!node) return NULL;
  return node-> prev;
}

struct list *get_nth(size_t n) {
  struct list *p = head.next;
  size_t idx = 0;
  while (p != NULL) {
    if (idx == n) return p;
    p = p -> next;
    idx++;
    }
    return NULL;
}

void *print_node(const struct list *node){
  if (!node) {
    printf("(NULL)\n");
    return;
    }
    printf("data=%d\n", node -> data);
}
