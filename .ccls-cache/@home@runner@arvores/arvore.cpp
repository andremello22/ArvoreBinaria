#include <iostream>
using namespace std;
struct t_no {
  int id;
  struct t_no *dir;
  struct t_no *esq;
} typedef no;

no *inserir(no *raiz, int valor) {
  if (raiz == NULL) {
    no *aux = (no *)malloc(sizeof(no));
    aux->id = valor;
    aux->dir = NULL;
    aux->esq = NULL;
    return aux;
  } else {
    if (valor > raiz->id) {
      raiz->dir = inserir(raiz->dir, valor);
    } else {
      raiz->esq = inserir(raiz->esq, valor);
    }
  }
  return raiz;
}
int qtd_elementos(no *raiz) {
  if (raiz == NULL) {
    return 0;
  }
  return 1 + qtd_elementos(raiz->dir) + qtd_elementos(raiz->esq);
}
int calc_altura(no *raiz){
  if(raiz==NULL){
    return -1;
  }
  else{
    int direita = calc_altura(raiz->dir);
    int esquerda = calc_altura(raiz->esq);
    if(direita > esquerda){
      return  1+ direita;
    }
    else{
      return 1+ esquerda;
    }
  }
}
int main() {
  no *raiz = NULL;
  raiz = inserir(raiz, 12);
  raiz = inserir(raiz, 4);
  raiz = inserir(raiz, 16);
  raiz = inserir(raiz, 8);
  raiz = inserir(raiz, 6);
  raiz = inserir(raiz, 20);
  cout<<"a altura da arvore e: "<<calc_altura(raiz)<<endl;
  cout << "a quantidade de elementos e: " << qtd_elementos(raiz);
  return 0;
}