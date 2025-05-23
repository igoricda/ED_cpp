#include <iostream>
using namespace std;

typedef string tipo;

class cnode{
  private:
    tipo elemento;
    cnode* next;

  friend class listacircular;
};
 
class listacircular{
  public:
    listacircular();
    bool isEmpty();
    tipo front(); //elemento no cursor
    tipo back(); //elemento depois do cursor
    void add(tipo dado); //adiiciona depois do cursor
    void remove(); //remove antes do cursor
    void advance(); //caminha com o cursor
    void printList();
  private:
    cnode* cursor;
};

listacircular::listacircular() : cursor(NULL){}

bool listacircular::isEmpty(){return cursor == NULL;}

tipo listacircular::back(){ return cursor->elemento;}

tipo listacircular::front(){ return cursor->next->elemento;}

void listacircular::advance(){
  cursor = cursor->next;
}

void listacircular::add(tipo dado){
  cnode* v = new cnode;
  v->elemento = dado;

  if(isEmpty()){
    v->next = v;
    cursor = v;
  }
  else{
    v->next = cursor->next;
    cursor->next = v;
  }
}

void listacircular::remove(){
  cnode* old = cursor->next;
  if(old == cursor){
    cursor = NULL;
  }
  else{
    cursor->next = old->next;
  }
  delete(old);
}

void listacircular::printList(){
  if(isEmpty()){
    cout << "Lista Vazia\n";
  }
  else{
    for(cnode* tmp = cursor->next; tmp != cursor; tmp = tmp->next){
      cout <<"[" <<tmp->elemento << "]->";
    }
    cout << '['<<cursor->elemento <<']' <<endl;
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
    listacircular fila;
    int length;
};
queue::queue(): fila(), length(0){}

int queue::size(){
  return length;
}

bool queue::isEmpty(){return length == 0;}

tipo queue::front(){
  if(isEmpty()){
    return "Lista vazia\n";
    
  }
  else {
    return fila.front(); 
  }
}

void queue::enqueue(tipo x){
  length++;
  fila.add(x); 
  fila.advance();
}

void queue::dequeue(){
  length--;
  fila.remove();
}

void queue::imprime(){
  fila.printList();
}

int main(int argc, char const *argv[]){
  queue q;

  q.enqueue("Primeiro");
  q.enqueue("Segundo");
  q.enqueue("Ultimo");
  q.imprime();
  cout << q.front() << endl;
  q.dequeue();
  q.imprime();
  q.dequeue();
  q.imprime();
  q.dequeue();
  q.imprime();
  cout << q.size() << endl;
  

  return 0;
}
