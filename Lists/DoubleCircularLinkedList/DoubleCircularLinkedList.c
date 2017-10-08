#include <stdlib.h>
#include <stdio.h>

typedef struct NoTag{
  int info;
  struct NoTag *next;
  struct NoTag *prev;
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
  no *N,*P;

  N = (no *) malloc(sizeof (no));
  N->info = x;

  if (*L == NULL){ // LISTA VAZIA
    N->prev  = N;
    N->next = N;
    *L = N;
  }
  else{
    P = (*L)->prev;
    P->next = N;
    N->next = (*L);
    N->prev = P;
    (*L)->prev = N;
    *L = N;
  }
}

inserefinalLista(no **L,int x){
  no *N,*P;

  N = (no *) malloc(sizeof (no));
  N->info = x;

  if (*L == NULL){ // LISTA VAZIA
    N->prev  = N;
    N->next = N;
    *L = N;
  }
  else{
    P = (*L)->prev;
    P->next = N;
    N->next = (*L);
    N->prev = P;
    (*L)->prev = N;
  }
}

int removeinicioLista(no **L){
  int x;
  no *P,*AUX;

  if ((*L)->next == *L){
    x = (*L)->info;
    free(*L);
    *L = NULL;
    return (x);
  }
  else {
    P = *L;
    AUX = P->prev;
    *L = P->next;
    (*L)->prev = AUX;
    AUX->next = *L;
    x = P->info;
    free (P);
    return (x);
  }
}

int removefinalLista(no **L){
  no *P,*AUX;
  int x;

  if ((*L)->next == *L){
    x = (*L)->info;
    free (*L);
    *L = NULL;
    return (x);
  }
  else{
    P = (*L)->prev;
    AUX = P->prev;
    AUX->next = *L;
    (*L)->prev = AUX;
    x = P->info;
    free(P);
    return (x);
  }
}

exibeLista(no *L){
  no *P;
  P = L;

  do{
    printf("\n%d",P->info);
    P = P->next;
  }while (P != L);
}
