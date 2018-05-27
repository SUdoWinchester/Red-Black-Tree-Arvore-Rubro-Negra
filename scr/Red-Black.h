#ifndef RED_BLACK_H_INCLUDED
#define RED_BLACK_H_INCLUDED

typedef struct Treeno{
        int info;
        char color;
        struct Treeno *left;
        struct Treeno *right;
        struct Treeno *pai;
}no;

//int altura(no *T);
no* verifica(no* T);
no* recolorir(no *z, no *tio);
no* insere(no **T, int x, no *pai);
no* rotacao_Esquerda(no* T);
no* rotacao_Direita(no* T);
no* create_node(int x, no *pai);
void preOrdem(no *T);

#endif // RED-BLACK_H_INCLUDED
