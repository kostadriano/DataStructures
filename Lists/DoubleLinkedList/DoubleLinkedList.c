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
    printf("\n\n1: Inserir Final da Lista\n2: Inserir Inicio da Lista\n3: Exibir a Lista\n4: Remover Final da Lista\n5: Remover Inicio da Lista\n6: Exibir o Maior Numero\n7: Remover Item\n0: Sair\n --->  ");
    scanf("%d",&sel);
    switch (sel) {
      case 1: printf("Digite o numero a ser inserido: ");scanf("%d",&x);inserefinalLista(&L,x);break;
      case 2: printf("Digite o numero a ser inserido: ");scanf("%d",&x);insereinicioLista(&L,x);break;
      case 3: exibeLista(L); break;
      case 4: removefinalLista(&L); break;
      case 5: removeinicioLista(&L); break;
      case 6: printf("%d\n",maiornum(L)); break;
      case 7: scanf("%d",&x); removeitem(&L,x);break;
      case 8: scanf("%d",&x); inserirordem(&L,x); break;
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
  N->prev = NULL;
  N->next = *L;
  if (*L != NULL){
    (*L)->prev = N;
  }
  *L = N;
}

inserefinalLista(no **L,int x){
  no *P,*N;

  N = (no *) malloc(sizeof (no));
  N->info = x;
  N->next = NULL;

  if (*L == NULL){
    N -> prev = NULL;
    *L = N;
  }
  else{
    P = *L;
    while (P->next != NULL){
      P = P->next;
    }
    P->next = N;
    N->prev = P;
  }
}

int removeinicioLista(no **L){
  no *P;
  P = *L;
  if (*L != NULL){
    *L = P->next;
    if (*L != NULL)
    (*L)->prev = NULL;
    free (P);
  }
}

int removefinalLista(no **L){
  no *P,*ANT;
  int x;

  if ((*L)->next == NULL){
    x = (*L)->info;
    free(*L);
    *L = NULL;
    return (x);
  }
  else{
    P = (*L)->next;
    ANT = *L;
    while (P->next != NULL){
      ANT = ANT->next;
      P = P->next;
    }
    ANT->next = NULL;
    x = P->info;
    free(P);
    return (x);
  }
}

exibeLista(no *L){
  no *P;
  P = L;

  while (P != NULL){
    printf("\n%d",P->info);
    P = P->next;
  }
}

int maiornum(no *L){
  no *P;
  P = L;
  int maior = P->info;
  while (P != NULL){

    if (P->info > maior)
    maior = P->info;

    P = P->next;
  }
  return (maior);
}

removeitem(no **L,int x){
  no *P,*PREV,*NEXT;
  P = *L;
  if (*L != NULL){
    while ((P!= NULL)&&(P->info != x)) {
      P = P->next;
    }
    if (P == NULL){
      //item nao encontrado
      return -999;
    }
    if (P == *L){
      *L = P->next;
      (*L)->prev = NULL;
      free (P);
    }
    else{
      if(P->next == NULL){
        PREV = P->prev;
        PREV->next = NULL;
        free (P);
      }
      else {
        PREV = P->prev;
        NEXT = P->next;
        PREV->next = P->next;
        NEXT->prev = P->prev;
        free(P);
      }
    }
  }
}

inserirordem(no **L, int x){
  no *P,*N,*NEXT,*PREV;

  N = (no *) malloc(sizeof (no));
  N->info = x;

  if (*L == NULL){
    N->prev = NULL;
    N->next = N;
    *L = N;
  }
  else{
    
    P = *L;
    while ((P!= NULL)&&(P->info < x)) {
      P = P->next;
    }

    if (P == *L){
      N->next = (*L)->next;
      N->prev = NULL;
      NEXT = (*L)->next;
      NEXT->prev = N;
      *L = N;
    }
    else{
      if(P->next == NULL){
        P->next = N;
        N->next = NULL;
        N->prev = P;
      }
      else {
        PREV = P->prev;
        N->next = P;
        N->prev = PREV;
        PREV->next = N;
        P->prev = N;
      }
    }
  }
}
