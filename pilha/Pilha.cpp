#include <iostream>
#include "tad/tad.h"
using namespace std;

/*
FUN��O: criaPilha
RESUMO: Cria uma nova pilha vazia
PARAM: void
RETORNO: Pilha* (ponteiro para a pilha);
*/
Pilha* criaPilha(){
	Pilha* p = new Pilha;
	p->topo = NULL;
	return p;
}

/*
FUN��O: vazia
RESUMO: verifica se a pilha est� vazia
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: int (1 se est� vazia, 0 se n�o est�)
*/
int vaziaPilha(Pilha* pilha){
	if( pilha->topo == NULL)
		return 1;
	else return 0;
}

/*
FUN��O: push
RESUMO: empilha novo elemento na pilha
PARAM: Pilha* (ponteiro para a pilha), int (valor a ser empilhado);
RETORNO: Pilha* (ponteiro para a pilha);
*/
Pilha* push(Pilha* pilha, int valor){
	Node* novo = new Node;
	novo->info = valor;
	novo->prox = pilha->topo;
	pilha->topo = novo;
	return pilha;
}

/*
FUN��O: pop
RESUMO: desempilha o elemento no topo da pilha e retorna seu valor
PARAM: Pilha* (ponteiro para a pilha), int (valor a ser desempilhado);
RETORNO: Pilha* (ponteiro para a pilha);
*/
int pop(Pilha* pilha){
    Node* aux = pilha->topo;
    int valor;
    if(!vaziaPilha(pilha)){
        valor = aux->info;
        pilha->topo = (pilha->topo)->prox;
        delete aux;
    } else cout << "pilha vazia!" << endl;
    return valor;
}

/*
FUN��O: top
RESUMO: informa o valor do primeiro elemento da pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: int (valor da informa��o do n� armazenado no topo)
*/
int top(Pilha* pilha){
	if (!vaziaPilha(pilha))
        return (pilha->topo)->info;
    else cout << "pilha vazia!";
}

/*
FUN��O: destroiPilha
RESUMO: exclui todo conte�do da pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: nada
*/
void destroiPilha(Pilha* pilha){
	while (!vaziaPilha(pilha))
        pop(pilha);
    cout << "pilha destru�da com sucesso!" << endl;
}
/*
FUN��O: print
RESUMO: imprime a pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: void
*/
void printPilhaControle(Pilha* pilha){
	Node* aux = pilha->topo;
	cout << "____" << endl;
	while(aux){
		cout << "| " << aux->info << " |\n"<< "____" << endl;
		aux = aux->prox;
	}
	cout << "X" << endl;
}

int buscaPilha(Pilha* pilha, int valor) {
    Node* aux = pilha->topo;
    while(aux != NULL) {
        if(aux->info == valor) {
            return 1; 
        }
        aux = aux->prox;
    }
    return 0;
}

int buscaERemove(Pilha* pilha, int valor) {
    Pilha* auxPilha = criaPilha();
    int encontrado = 0;
    
    while(!vaziaPilha(pilha)) {
        int topo = pop(pilha);
        if(topo == valor) {
            encontrado = 1;
            break;
        }
        push(auxPilha, topo);
    }
    
    while(!vaziaPilha(auxPilha)) {
        push(pilha, pop(auxPilha));
    }
    
    destroiPilha(auxPilha);
    return encontrado;
}

void removePares(Pilha* pilha) {
    Pilha* auxPilha = criaPilha();
    
    while(!vaziaPilha(pilha)) {
        int topo = pop(pilha);
        if(topo % 2 != 0) { 
            push(auxPilha, topo);
        }
    }
    
    while(!vaziaPilha(auxPilha)) {
        push(pilha, pop(auxPilha));
    }
    
    destroiPilha(auxPilha);
}

void removeRepetidos(Pilha* pilha) {
    Pilha* auxPilha = criaPilha();
    Pilha* elementosUnicos = criaPilha();
    
    while(!vaziaPilha(pilha)) {
        int topo = pop(pilha);
        push(auxPilha, topo);
    }
    
    while(!vaziaPilha(auxPilha)) {
        int topo = pop(auxPilha);
        if(!buscaPilha(elementosUnicos, topo)) {
            push(elementosUnicos, topo);
            push(pilha, topo);
        }
    }
    
    destroiPilha(auxPilha);
    destroiPilha(elementosUnicos);
}

	int main() {
    Pilha* p = criaPilha();
    
    push(p, 10);
	push(p, 11);
    push(p, 20);
	push(p, 21);
	push(p, 21);
    push(p, 30);
    push(p, 20);
    push(p, 45);
    
    cout << "Pilha original:" << endl;
    printPilhaControle(p);
    
    cout << "\nBusca por 30: " << (buscaPilha(p, 30) ? "Encontrado" : "Nao encontrado") << endl;
    
    cout << "\nRemove o 20:" << endl;
    buscaERemove(p, 20);
    printPilhaControle(p);
    
    cout << "\nRemove pares:" << endl;
    removePares(p);
    printPilhaControle(p);
    
    cout << "\nRemove repetidos:" << endl;
    removeRepetidos(p);
    printPilhaControle(p);
    
    return 0;
}

