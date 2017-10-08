#include "linkedList.h"
#include <stdio.h>

void main()
{
  List *list;

  insertFirst(&list, 2);
  insertFirst(&list, 1);
  insertLast(&list, 0);

  removeFirst(&list);

  showList(list);
}
