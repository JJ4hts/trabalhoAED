#include <iostream>
#include "tad/tad.cpp"
using namespace std;

// Fun��o para criar uma �rvore Bin�ria de Busca (ABB)
ArvBB* criaABB(){
    // Retorna NULL, que representa uma �rvore vazia
    return NULL;
}

// Fun��o para verificar se a ABB est� vazia
int vaziaABB(ArvBB* raiz){
    // Se a raiz for NULL (ou seja, a �rvore est� vazia), retorna 1
    // Caso contr�rio, retorna 0
    if(!raiz)
        return 1;
    else return 0;
}

// Fun��o para imprimir a informa��o no n� atual para a impress�o em n�veis
void printABBHierarquico(ArvBB *nodeArv){
    // Imprime o valor do campo 'info' do n�
    cout << " " << nodeArv->info << "\n            ";
}

// Fun��o para imprimir a informa��o no n� atual
void printNodeABB(ArvBB *nodeArv){
    // Imprime o valor do campo 'info' do n�
    cout << " " << nodeArv->info << " ";
}


// Fun��o para visitar um n� e executar uma fun��o nele
void visitABB(ArvBB *nodeArv, void (*func)(ArvBB*)){
    // Executa a fun��o 'func' no n�
    func(nodeArv);
}


// Fun��o para realizar uma travessia em pr�-ordem da �rvore com visualiza��o hierarquica
void preOrdemABBHierarquico(ArvBB *raiz, int nivel = 0,int ehRaiz=1){
    // Verifica se a �rvore n�o est� vazia
    if (!vaziaABB(raiz)){
        // Visita a raiz e imprime seu valor
        if(ehRaiz){
            cout << "raiz:";
            ehRaiz = 0; //imprimiu a raiz principal da �rvore
        }
        visitABB(raiz,printABBHierarquico);
        if(raiz->esq){
                for(int i = 0; i<nivel; i++)
                    cout << "            ";
                cout << "<<filhoEsq:";
        }
        // Realiza a travessia em pr�-ordem da sub�rvore esquerda
        preOrdemABBHierarquico(raiz->esq,nivel+1,ehRaiz);
        if(raiz->dir){
                for(int i = 0; i<nivel; i++)
                    cout << "            ";
                cout << ">>FilhoDir:";
        }
        // Realiza a travessia em pr�-ordem da sub�rvore direita
        preOrdemABBHierarquico(raiz->dir,nivel+1,ehRaiz);
    }
}

// Fun��o para realizar uma travessia em pr�-ordem da �rvore (RED)
//executa a fun��o recebida como par�metro em cada n�
void preOrdemABB(ArvBB *raiz,void (*func)(ArvBB*)){
    // Verifica se a �rvore n�o est� vazia
    if (!vaziaABB(raiz)){
        // Visita a raiz e imprime seu valor
        visitABB(raiz,func);
        //cout << " << ";
        // Realiza a travessia em pr�-ordem da sub�rvore esquerda
        preOrdemABB(raiz->esq,func);
        //cout << " >> ";
        // Realiza a travessia em pr�-ordem da sub�rvore direita
        preOrdemABB(raiz->dir,func);
    }
}

// Fun��o para realizar uma travessia em ordem da �rvore (ERD)
void emOrdemABB(ArvBB *raiz,void (*func)(ArvBB*)){
    // Verifica se a �rvore n�o est� vazia
    if (!vaziaABB(raiz)){
        // Realiza a travessia em ordem da sub�rvore esquerda
        //cout << " << ";
        emOrdemABB(raiz->esq,func);
        // Visita a raiz e imprime seu valor
        visitABB(raiz,func);
        //cout << " >> ";
        // Realiza a travessia em ordem da sub�rvore direita
        emOrdemABB(raiz->dir,func);
    }
}

// Fun��o para realizar uma travessia em p�s-ordem da �rvore (EDR)
void posOrdemABB(ArvBB *raiz,void (*func)(ArvBB*)){
    // Verifica se a �rvore n�o est� vazia
    if (!vaziaABB(raiz)){
        // Realiza a travessia em p�s-ordem da sub�rvore esquerda
        //cout << " << ";
        posOrdemABB(raiz->esq,func);
        //cout << " >> ";
        // Realiza a travessia em p�s-ordem da sub�rvore direita
        posOrdemABB(raiz->dir,func);
        // Visita a raiz e imprime seu valor
        visitABB(raiz,func);
    }
}

int numElementos=0;

void addElem(ArvBB *node){
    numElementos++;
}

int getNumElementosABB(ArvBB *raiz){
    numElementos = 0;
    preOrdemABB(raiz,addElem);
    return numElementos;
}

// Fun��o para retornar o m�ximo entre dois inteiros
int max(int a, int b){
    // Se 'a' for maior que 'b', retorna 'a'
    // Caso contr�rio, retorna 'b'
    if(a>b)
        return a;
    else return b;
}

// Fun��o para calcular a altura da �rvore Bin�ria de Busca (ABB)
int alturaABB(ArvBB *raiz){
    // Se a �rvore estiver vazia, retorna -1
    if(vaziaABB(raiz))
        return -1;
    // Caso contr�rio, retorna 1 mais o m�ximo entre as alturas das sub�rvores esquerda e direita
    else return 1 + max(alturaABB(raiz->esq),alturaABB(raiz->dir));
}

// Fun��o para criar um novo n� na �rvore Bin�ria de Busca (ABB)
ArvBB* novoNoABB(int elem){
    // Cria um novo n�
    ArvBB* novo = new ArvBB;
    // Atribui o valor do elemento ao campo 'info' do novo n�
    novo->info = elem;
    // Inicializa os ponteiros 'esq' e 'dir' do novo n� como NULL
    novo->esq = NULL;
    novo->dir = NULL;
    // Retorna o novo n�
    return novo;
}

// Fun��o para inserir um elemento na ABB
ArvBB* insereABB(ArvBB *raiz, int elem){
    // Verifica se a ABB est� vazia
    if(vaziaABB(raiz)){
        // Se a ABB estiver vazia, cria um novo n� com o elemento
        ArvBB* novo = novoNoABB(elem);
        // A raiz se torna o novo n�
        raiz = novo;
    }else{
        // Se o elemento for menor que o valor da raiz
        if(elem < raiz->info)
            // Insere o elemento na sub�rvore esquerda
            raiz->esq = insereABB(raiz->esq, elem);
        else
            // Sen�o, insere o elemento na sub�rvore direita
            raiz->dir = insereABB(raiz->dir, elem);
    }
    // Retorna a raiz da ABB
    return raiz;
}

// Fun��o para buscar um elemento na �rvore Bin�ria de Busca (ABB)
ArvBB* buscaElemABB(ArvBB *raiz, int elem){
    // Verifica se a �rvore n�o est� vazia
    if(!vaziaABB(raiz)){
        // Se o valor do n� atual � igual ao elemento procurado
        if (raiz->info == elem){
            cout << "Elemento " << elem << " encontrado!" << endl;
            // Retorna o n� que cont�m o elemento
            return raiz;
        }
        // Se o elemento � menor que o valor do n� atual
        else if(elem < raiz->info)
            // Busca o elemento na sub�rvore esquerda
            raiz = buscaElemABB(raiz->esq,elem);
        else
            // Se o elemento � maior que o valor do n� atual, busca o elemento na sub�rvore direita
            buscaElemABB(raiz->dir,elem);
    }else{ // Se a �rvore est� vazia, imprime uma mensagem indicando que o elemento n�o foi encontrado
        cout << "Elemento " << elem << " n�o encontrado!" << endl;
        return raiz;
    }
}

// Fun��o para remover um elemento de uma �rvore Bin�ria de Busca (ABB)
ArvBB* removeElemABB(ArvBB * raiz, int elem){
    // Verifica se a �rvore est� vazia
    if(!vaziaABB(raiz)){
        // Se o elemento � menor que o n� atual, procura na sub�rvore esquerda
        if(elem < raiz->info){
            raiz->esq = removeElemABB(raiz->esq,elem);
        }
        // Se o elemento � maior que o n� atual, procura na sub�rvore direita
        else if (elem > raiz->info){
            raiz->dir = removeElemABB(raiz->dir,elem);
        }
        // Se o elemento � igual ao n� atual, remove o n�
        else{
            ArvBB *aux = raiz;
            // Se o n� atual n�o tem filho � esquerda, substitui o n� pelo filho � direita
            if(raiz->esq == NULL){
                raiz = raiz->dir;
                delete aux;
            }
            // Se o n� atual n�o tem filho � direita, substitui o n� pelo filho � esquerda
            else if (raiz->dir == NULL){
                raiz = raiz->esq;
                delete aux;
            }
            // Se o n� atual tem ambos os filhos, substitui o n� pelo menor elemento da sub�rvore direita
            else{
                aux = raiz->dir;
                while(aux->esq)
                    aux = aux->esq;
                raiz->info = aux->info;
                raiz->dir = removeElemABB(raiz->dir,aux->info);
            }
        }
        // Retorna a raiz da �rvore
        return raiz;
    }
    // Se a �rvore est� vazia, retorna NULL
    else return NULL;
}
