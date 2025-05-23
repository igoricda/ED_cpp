#include <iostream>
using namespace std;

typedef int tipo;
#define MAX 100

//friend class -> classe amiga, é uma classe que tem acessi a todos os dados e métodos privados da outra
class node{
	//informações 
	private:
		tipo dado;
		node* prox;
		node* anterior;
		friend class lista;
};

class lista{
	public:
		//construtor
		lista();
		//destrutor
		~lista();
		int isEmpty();
		//adicionar um nó a lista
		void add(node* atual, const tipo &dado);
		void addtoTail(const tipo &dado);
		void addtoHead(const tipo &dado);
		void remove(node* atual);
		void removeHead();
		void removeTail();
		void removeInMid(int position);
		void print();
		void print_inv();
		tipo front();
		tipo back();
	private:
		node* head;
		node* tail;
		//nesta implementação o dummy é tanto o head quanto o tail
};

lista::lista(){
	head = new node;
	tail = new node;
	head->prox = tail;
	tail->anterior = head;
}

tipo lista::front(){
	return head->prox->dado;
}

tipo lista::back(){
	return tail->anterior->dado;
}


lista::~lista(){
	delete head;
	delete tail;
}

int lista::isEmpty(){
	if(head->prox == tail){
		return 1;
	}else{
		return 0;
	}
}

//esse método adiciona na esquerda
void lista::add(node* atual, const tipo &dado){
	node* novo = new node;
	novo->dado = dado;
	novo->prox = atual;
	novo->anterior = atual->anterior;
	atual->anterior->prox = novo;
	atual->anterior = novo;
}

void lista::addtoTail(const tipo &dado){
	//adiciono um novo nó ao fim da lista
	//antes do dummy tail
	add(tail, dado);
}

void lista::addtoHead(const tipo &dado){
	//adiciono após o head
	add(head->prox, dado);
}

void lista::print(){

	for(node* tmp = head->prox; tmp != tail; tmp = tmp->prox){
		cout << tmp->dado << " ";
	}
	cout << endl;
}

void lista::print_inv(){
	for(node* tmp = tail->anterior; tmp != head; tmp = tmp->anterior){
		cout << tmp->dado << " ";
	}
	cout << endl;
}

void lista::remove(node* atual){
	//salvar nó antecessor
	node* antecessor = atual->anterior;
	//salvo o nó que vem depois
	node *sucessor = atual->prox;
	antecessor->prox = sucessor;
	sucessor->anterior = antecessor;
	delete atual;
}

void lista::removeHead(){
	remove(head->prox);
}

void lista::removeTail(){
	remove(tail->anterior);
}

void lista::removeInMid(int position){
	node* tmp = head->prox;
	while(tmp->prox != tail && position){
		tmp = tmp->prox;
		position--;
	}
	remove(tmp);
}

class deque : public lista{
//ele conseguiu acessar as coisas públicas da lista
	public:
		void insereinicio(tipo e);
		void inserefim(tipo e);
		void removeinicio();
		void removefim();
		int size();
		bool isempty();
		tipo front();
		tipo back();
		//lista de elemento (coloquei como público e deu certo o print?)
		lista dq;
	private:
		//n elementos
		int n = 0;
};

//funções de inserção

void deque::insereinicio(tipo e){
	n++;
	dq.addtoHead(e);
}

void deque::inserefim(tipo e){
	n++;
	dq.addtoTail(e);
}

//funções de remoção

void deque::removeinicio(){
	n--;
	dq.removeHead();
}

void deque::removefim(){
	n--;
	dq.removeTail();
}

int deque::size(){
	return n;
}

bool deque::isempty(){
	if(n == 0)
		return true;
	else
		return false;
}

tipo deque::front(){
	return dq.front();
}

tipo deque::back(){
	return dq.back();
}

int main(){
	deque d;

	d.insereinicio(1);
	d.insereinicio(2);
	d.insereinicio(3);
	d.dq.print();
	d.inserefim(1);
	d.inserefim(2);
	d.inserefim(3);
	d.dq.print();
	cout << d.front() << endl;
	d.removeinicio();
	cout << d.front() << endl;

	return 0;
}