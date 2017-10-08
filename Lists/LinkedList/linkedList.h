#include <stdlib.h>
#include <stdio.h>

typedef struct NoTag{
  int item;
  struct NoTag *link;
}List;

List* newList();

void insertFirst(List **list,int newItem);

void insertLast(List **list,int x);

int removeFirst(List **list);

int removeLast(List **list);

void showList(List *list);
