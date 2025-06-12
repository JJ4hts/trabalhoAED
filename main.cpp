#include <iostream>
#include "Lista.h"
#include "Pilha.h"
#include "Fila.h"
#include "Lista.h"
#include "ArvBB.h"
#include <locale.h>

using namespace std;

int main(){
    //padronizando acentuação
    setlocale(LC_ALL,"");
    /*
    //código de teste da biblioteca lista.h
    Node *lista;
    lista = criaLista();
    lista2 = criaLista();
    int = valor = 0;
    lista = insereOrdLista(lista,4);
    lista = insereOrdLista(lista,-12);
    lista = insereOrdLista(lista,32);
    lista = insereOrdLista(lista,6);
    lista = removeElemLista(lista,-12);
    lista = removeElemLista(lista,33);

    lista2 = insereOrdLista(lista2,4);
    lista2 = insereOrdLista(lista2,-12);
    lista2 = insereOrdLista(lista2,32);
    lista2 = insereOrdLista(lista2,6);
    lista2 = removeElemLista(lista2,-12);
    lista2 = removeElemLista(lista2,33);
    printLista(lista);
    lista = removeElemLista(lista,12);
    Node *pElem = buscaElementoLista(lista,32);
    cout << getElementoLista(pElem) << endl;
    setElementoLista(pElem,101);
    cout << getElementoLista(pElem) << endl;
    valor = maxLista(lista);
    cout << "Maior elemento da lista: " << valor << endl;
    valor = minLista(lista);
    cout << "Menor elemento da lista: " << valor << endl;
    valor = mediaLista(lista);
    cout << "M�dia dos elementos da lista: " << valor << endl;
    valor = lenLista(lista);
    cout << "Quantidade de elementos da lista: " << valor << endl;
    printLista(lista);
    lista = esvaziarLista(lista);
    printLista(lista);
    destroiLista(lista);

    reverseLista(lista);
    printLista(lista);

    valor = isSubLista(lista,lista2);
    cout << "A lista 1 � uma sublista da lista 2? " << valor << endl;
    valor = isSubLista(lista2,lista);
    cout << "A lista 2 � uma sublista da lista 1? " << valor << endl;

*/

   
/*
    Pilha *p;

    p = criaPilha();
    int valor = 0;
    push(p,6);
    push(p,8);
    push(p,12);
    push(p,7);
    printPilhaControle(p);
    pop(p);
    printPilhaControle(p);
    destroiPilha(p);
    valor = buscaPilha(p,8);
    cout << valor << endl;

    valor = buscaERemove(p,8);
    cout << valor << endl;
    printPilhaControle(p);

    removePares(p);
    printPilhaControle(p);
    removeRepetidos(p);
    printPilhaControle(p);

    removeRepetidos(p);
    printPilhaControle(p);

    destroiPilha(p);
    printPilhaControle(p);


*/
/*
    Fila *f;
    f = criaFila();
    enqueue(f,2);
    enqueue(f,4);
    enqueue(f,8);
    enqueue(f,12);
    dequeue(f);
    dequeue(f);
    printFilaControle(f);
*/
/*
    ArvBB *arv;
    arv = criaABB();
    cout << "arvore criada" << endl;
    arv = insereABB(arv, 8);
    arv = insereABB(arv, 3);
    arv = insereABB(arv, 10);
    arv = insereABB(arv, 1);
    arv = insereABB(arv, 6);
    arv = insereABB(arv, 4);
    arv = insereABB(arv, 7);
    arv = insereABB(arv, 14);
    arv = insereABB(arv, 13);
    cout << "Árvore hierárquica:" << endl;
    preOrdemABBHierarquico(arv);
    cout << endl;
    cout << "Percurso RED: ";
    preOrdemABB(arv,printNodeABB);
    cout << endl;
        cout << "Percurso ERD: ";
    emOrdemABB(arv,printNodeABB);
    cout << endl;
        cout << "Percurso EDR: ";
    posOrdemABB(arv,printNodeABB);
    cout << endl;
    cout << "\nNumero de elementos: " << getNumElementosABB(arv) << endl;
    //buscaElemABB(arv,7);
    //buscaElemABB(arv,25);
    arv = removeElemABB(arv,3);
    cout << "Árvore hierárquica:" << endl;
    preOrdemABBHierarquico(arv);
    arv = removeElemABB(arv,8);
    cout << "Árvore hierárquica:" << endl;
    preOrdemABBHierarquico(arv);
    cout << endl;
*/

}