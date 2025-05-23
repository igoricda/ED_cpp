#include <iostream>
using namespace std;

typedef int tipo;
#define MAX 100


class node
{
    private:
        tipo dado;
        node* proximo;
        node* anterior;
        friend class lista;
};

class lista{

    public:
        lista();
        ~lista();
        bool isEmpty();
        void add(node *atual, const tipo& dado);
        void addToTail(const tipo& dado);
        void addToHead(const tipo& dado);
        void remove(node *atual);
        void removeHead();
        void removeTail();
        void print();
    private:
        node* head;
        node* tail;
        
};

lista::lista(){
    head = new node;
    tail = new node;
    head->proximo = tail;
    tail->anterior = head;
}

lista::~lista(){
    delete head;
    delete tail;
}

bool lista::isEmpty(){
    return(head->proximo == tail);
}

void lista::add(node* atual, const tipo& dado){
    node* novo = new node;
    novo->dado = dado;
    novo->proximo = atual;
    novo->anterior = atual->anterior;
    atual->anterior->proximo = novo;
    atual->anterior = novo;
}

void lista::addToTail(const tipo& dado){
    add(tail,dado);
}

void lista::addToHead(const tipo& dado){
    add(head->proximo,dado);
}

void lista::print(){
    
    for(node* tmp = head->proximo; tmp != tail; tmp = tmp->proximo){
        cout << tmp->dado << " ";
    }
    cout << endl;
}

void lista::remove(node *atual){
    //salvar o no antecessor
    node* antecessor = atual->anterior;
    //salvo o no sucessor
    node* sucessor = atual->proximo;
    antecessor->proximo = sucessor;
    sucessor->anterior = antecessor;
    delete atual;
}

void lista::removeHead(){
    remove(head->proximo);
}

void lista::removeTail(){
    remove(tail->anterior);
}

int main(int argc, char const *argv[]){
    lista dupla;
    dupla.addToHead(1);
    dupla.addToTail(2);
    dupla.addToHead(0);
    dupla.addToTail(3);
    dupla.print();
    dupla.removeHead();
    dupla.removeTail();
    dupla.print();
    return 0;

}