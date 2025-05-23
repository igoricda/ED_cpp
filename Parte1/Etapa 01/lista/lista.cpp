#include <iostream>
using namespace std;

//elemento da lista, contem dado e ponteiro p prox elemento
class node{
  public:
    node()
    {
      prox = NULL;  
    }
    node(int dado, node *ptr = NULL);
    int dado;
    node *prox;
};

node::node(int dado, node *ptr){
  node::dado = dado;
  node::prox = ptr;
}

class lista{
  public:
    //metodos
    //construtor
    lista(){
      head = tail = NULL;
    }
    //destrutor
    //~lista();
    int isEmpty();
    void addToHead(int dado);
    void addToTail(int dado);
    void printList();
    void deleteFromHead();
    void deleteFromTail();
  private:
    //informacoes
    node *head;
    node *tail;
};

int lista::isEmpty(){
  return tail == NULL;
}

void lista::addToHead(int dado){
  head = new node(dado, head);
  if(isEmpty()){
    tail = head;
  }
}

void lista::addToTail(int dado){
  if(tail == NULL){
    head = tail = new node(dado);
  }
  else{
    tail->prox = new node(dado);
    tail = tail->prox;
  }
}

void lista::printList(){
  for(node *tmp = head; tmp != NULL; tmp = tmp->prox){
    if(tmp->prox)
      cout <<"[" <<tmp->dado << "]->";
    else {
      cout <<"[" <<tmp->dado << "]\n";
    }
  }
}

void lista::deleteFromHead(){
  if(isEmpty())
    cout << "Lista Vazia\n";
  else{
    node *tmp = head;
    if(head == tail){
      head = tail = NULL;
    } else{
      head = head->prox;
    }
    delete tmp;
  }
}
void lista::deleteFromTail(){
  if(isEmpty())
    cout << "Lista Vazia\n";
  else{
    if(head == tail){
      head = tail = NULL;
    } else{
      node *tmp = head;
      for(tmp = head; tmp->prox != tail; tmp = tmp->prox);
      tail = tmp;
      delete tail->prox;
      tail->prox = NULL;
    }
  }
}

int main(int argc, char const *argv[]){
  lista l;
  
  l.addToTail(8);
  l.addToHead(10);
  l.addToTail(8);
  l.addToHead(2);
  l.addToTail(50);
  l.printList();
  l.deleteFromHead();
  l.printList();
  l.deleteFromTail();
  l.printList();
  return 0;
}
