#include <stdlib.h>
#include <stdio.h>

typedef struct NoTag{
  int info;
  struct NoTag *link;
}no;

void main(){
  no *L;
  int sel,x;
  iniLista(&L);


  while (sel != 0){
    printf("\n\n1: Inserir Final da Lista\n2: Inserir Inicio da Lista\n3: Exibir a Lista\n4: Remover Final da Lista\n5: Remover Inicio da Lista\n0: Sair\n --->  ");
    scanf("%d",&sel);
    switch (sel) {
      case 1: printf("Digite o numero a ser inserido: ");scanf("%d",&x);inserefinalLista(&L,x);break;
      case 2: printf("Digite o numero a ser inserido: ");scanf("%d",&x);insereinicioLista(&L,x);break;
      case 3: exibeLista(L); break;
      case 4: removefinalLista(&L); break;
      case 5: removeinicioLista(&L); break;
    }
  }
}

iniLista(no **L){
  *L = NULL;
}

insereinicioLista(no **L,int x){
  no *N;

  N = (no *) malloc(sizeof (no));
  N->info = x;

  if (*L == NULL){
    *L = N;
    (*L)->link = N;
  }
  else{
    N->link = (*L)->link;
    (*L)->link = N;
  }
}

inserefinalLista(no **L,int x){
  no *N;

  N = (no *) malloc(sizeof (no));
  N->info = x;

  if (*L == NULL){
    *L = N;
    (*L)->link = N;
  }
  else {
    N->link = (*L)->link;
    (*L)->link = N;
    *L = N;
  }
}

int removeinicioLista(no **L){
  no *AUX;
  int x;
  if (*L != NULL){
    if ((*L)->link == *L){
      x = (*L)->info;
      free (*L);
      *L = NULL;
    }
    else{
      AUX = (*L)->link;
      x = AUX -> info;
      (*L)->link = AUX->link;
      free(AUX);
    }
    return (x);
  }
}

int removefinalLista(no **L){
  no *P,*ANT;
  int x;
  if ((*L)->link == *L){
    x = (*L)->info;
    free(*L);
    *L = NULL;
  }
  else{
      P = (*L)->link;
      ANT = *L;
    do {
      ANT = ANT->link;
      P = P->link;
    }while (P->link != (*L)->link);

    ANT->link = (*L)->link;
    *L = ANT;
    (free(P));
    return (x);
  }
}

exibeLista(no *L){
  no *P;
  P = L->link;

  do {
    printf("\n%d",P->info);
    P = P->link;
  }while (P != L->link);
}
