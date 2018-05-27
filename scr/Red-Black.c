#include <stdio.h>
#include <stdlib.h>
#include "Red-Black.h"

int altura(no *T) {
   if (T == NULL)
      return -1; // altura da árvore vazia
   else {
      int he = altura (T->left);
      int hd = altura (T->right);
      if (he < hd)
        return hd + 1;
      else
        return he + 1;
   }
}

no* recolorir(no *T, no *tio) {
     T->pai->color = 'p';
     tio->color = 'p';
     T->pai->pai->color = 'v';
     return 0;
}

no* verifica(no *T){
    no* tio;

    if(T == NULL) {
    	
    }

    while(T->pai->color == 'v') {
        if(T->pai == T->pai->pai->left) {
            tio = T->pai->pai->right;
            if(tio->color == 'v') {
                recolorir(T, tio);
                T = T->pai->pai;
               return verifica(T);
            }else{
                if(T == T->pai->left){
                    rotacao_Direita(T);
                    recolorir(T, tio);
                    T = T->pai->pai;
                    return verifica(T);
                }else{
                    rotacao_Esquerda(T);
                    rotacao_Direita(T->pai);
                    recolorir(T, tio);
                    T = T->pai->pai;
                    return verifica(T);
                }
            }
        }else{
            tio = T->pai->pai->left;
            if(tio->color == 'v'){
                recolorir(T, tio);
                T = T->pai->pai;
               return verifica(T);
           }else{
                if(T == T->pai->right){
                    rotacao_Esquerda(T);
                    recolorir(T, tio);
                    T = T->pai->pai;
                    return verifica(T);
                }
                else{
                    rotacao_Direita(T);
                    rotacao_Esquerda(T->pai);
                    recolorir(T, tio);
                    T = T->pai->pai;
                    return verifica(T);
                }
            }
        }
    }
    return 0;
}

no* insere(no **T, int x, no *pai){
    if( (*T) == NULL) {
        return create_node(x, pai);
    }

    pai = &(*T);

    if( x < (*T)->info){
        pai = (*T);
        (*T)->left = insere(&((*T)->left), x, pai);
    }
    else{
        pai = (*T);
        (*T)->right = insere(&((*T)->left), x, pai);
    }

    (*T)->color = 'p';
    return verifica(*T);
}


 no *create_node(int x, no* pai){
        no *new_no = (no*)malloc(sizeof(no));
        new_no->info = x;
        new_no->color = 'v';
        new_no->left = NULL;
        new_no->right = NULL;
        new_no->pai = pai;

        return new_no;
}

void preOrdem(no *T){
    if(T != NULL) {
        printf("%d%c\n", T->info, T->color);
        preOrdem(T->left);
        preOrdem(T->right);
    }
}

no* rotacao_Esquerda(no *z) {
    no *q;
    q = z->right;
    z->right = q->left;
    q->left = z;
    return q;
}

no* rotacao_Direita(no *z) {
    no *q;
    q = z->left;
    z->left = q->right;
    q->right = z;
    return q;
}
