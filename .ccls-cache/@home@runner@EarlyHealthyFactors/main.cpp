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
      raiz->esq = inserir(raiz->dir, valor);
    }
  }
  return raiz;
}

int main() {
  no *raiz = NULL;
  raiz = inserir(raiz, 12);
  raiz = inserir(raiz, 4);
  raiz = inserir(raiz, 16);
  raiz = inserir(raiz, 8);
  raiz = inserir(raiz, 6);
  
  return 0;
}