#include "linkedList.h"
#include <stdio.h>

initializeList(List **list){
  *list = NULL;
}

List* newList(){
    List *list;
    initializeList(&list);

    return list;
}

void insertFirst(List **list,int newItem){
  List *NEW;

  NEW = (List *) malloc(sizeof (List));
  NEW->item = newItem;

  NEW->link = *list;
  *list = NEW;

}

void insertLast(List **list,int x){
  List *TEMP,*NEW;

  NEW = (List *) malloc(sizeof (List));
  NEW->item = x;
  NEW->link = NULL;

  if (*list == NULL)
  *list = NEW;

  else{
    TEMP = *list;

    while (TEMP->link != NULL)
    TEMP = TEMP->link;

    TEMP->link = NEW;
  }
}

int removeFirst(List **list){
  List *AUX;
  int removed;
  if (*list != NULL){
    if ((*list)->link == NULL){
      removed = (*list)->item;
      free (*list);
      *list = NULL;
    }
    else{
      AUX = *list;
      removed = AUX -> item;
      *list = AUX->link;
      free(AUX);
    }
    return (removed);
  }
}

int removeLast(List **list){
  List *P,*ANT;
  int x;
  if ((*list)->link == NULL){
    x = (*list)->item;
    free(*list);
    *list = NULL;
  }
  P = (*list)->link;
  ANT = *list;
  while(P->link != NULL){
    P = P->link;
    ANT = ANT->link;
    x = P->item;
  }
  ANT->link = NULL;
  (free(P));
  return (x);
}

void showList(List *list){
  List *P;
  P = list;

  while (P != NULL){
    printf("\n%d",P->item);
    P = P->link;
  }
}
