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
    void addToHead(tipo dado);
    void addToTail(tipo dado);
    void printList();
    void deleteFromHead();
    void deleteFromTail();
    tipo front(); //Retorna o primeiro elemento da lista
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

void lista::addToHead(tipo dado){
  head = new node(dado, head);
  if(isEmpty()){
    tail = head;
  }
}

void lista::addToTail(tipo dado){
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

class stack{
  public:
    stack();
    int size(); //funcao que retorna tamanho da pilha
    bool empty(); //pilha vazia?
    tipo top(); //retorna o primeiro elemento da pilha
    void push(tipo dado); //empilha
    void pop(); //desempilha
    void imprime();
  private:
    lista pilha; //lista de elementos
    int n; //numero de elementos
};

stack::stack() : pilha(), n(0){} 

int stack::size() //retorna o tamanho
{
  return n;
}

bool stack::empty(){return n == 0;}

tipo stack::top(){
  if(empty()){
    cout << "Pilha Vazia\n";
    return 0;
  }
  else
    return pilha.front(); //retorna o elemento do topo da pilha
}

void stack::push(tipo dado){
  //incrementa o tamanho da pilha
  ++n;
  //adiciona no topo
  pilha.addToHead(dado);
}

void stack::pop(){
  if(empty())
    cout << "Pilha já está vazia\n";
  else{
    pilha.deleteFromHead(); //remover o primeiro elemento
    --n; //decrementar o tamanho
  }
}

void stack::imprime(){
  pilha.printList();
}

int main(int argc, char const *argv[]){
  stack p;
  
  p.push(6);
  p.push(7);
  p.imprime();
  p.pop();
  cout << p.size() << endl;
  p.imprime();
  p.push(34);
  p.push(10);
  p.imprime();
  p.pop();
  p.pop();
  p.imprime();
  cout << p.size() << endl;
  p.pop();
  p.imprime();
  cout << p.size() << endl;
  

  return 0;
}
