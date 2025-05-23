#include <iostream>
using namespace std;

typedef int tipo;

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
    tipo front();
  private:
    //informacoes
    node *head;
    node *tail;
};

tipo lista::front(){
  return head->dado;
}
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
  if(isEmpty()){
    cout  << "Lista Vazia\n";
  }
  else{
    for(node *tmp = head; tmp != NULL; tmp = tmp->prox){
      if(tmp->prox)
        cout <<"[" <<tmp->dado << "]->";
      else {
        cout <<"[" <<tmp->dado << "]\n";
      }
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

class queue{
  public:
    queue(); //construtor
    bool isEmpty(); //retorna se esta vazio
    void enqueue(tipo x); //insere no fim
    void dequeue(); //remove do inicio
    int size();
    void imprime();
    tipo front();
  private:
    lista fila;
    int length;
};

queue::queue(): fila(), length(0){}

int queue::size(){
  return length;
}

bool queue::isEmpty(){return length == 0;}

tipo queue::front(){
  if(isEmpty()){
    cout << "Lista vazia" << endl;
    return -1;
  }
  else {
    return fila.front(); 
  }
}

void queue::enqueue(tipo x){
  length++;
  fila.addToTail(x); 
}

void queue::dequeue(){
  length--;
  fila.deleteFromHead();
}

void queue::imprime(){
  fila.printList();
}

int main(int argc, char const *argv[]){
  queue q;

  q.enqueue(6);
  q.enqueue(4);
  q.enqueue(9);
  q.imprime();
  q.dequeue();
  q.imprime();
  q.dequeue();
  q.imprime();
  q.dequeue();
  q.imprime();
  q.enqueue(90);
  q.imprime();
  cout << q.size() << endl;
  

  return 0;
}
