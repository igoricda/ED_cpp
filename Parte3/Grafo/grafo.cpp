#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class grafo{
  int num_vertices;
  list<int>* adjlista;
  int *cor; //0 - branco, 1 - cinza, 2 - preto

  public:
    grafo(int vertices);
    void aresta(int fonte, int destino);
    void bfs(int s);
    void DFS(int s);
    void DFS_visit(vector<bool> &visited, int s);
};

grafo::grafo(int vertices){
  num_vertices = vertices;
  adjlista = new list<int>[vertices];
  cor = new int[vertices];
}

void grafo::aresta(int fonte, int destino){
  adjlista[fonte].push_back(destino);
  adjlista[destino].push_back(fonte);
}

void grafo::bfs(int s){

  //Lista de cores dos vertices
  for(int i = 0; i < num_vertices; i++)
      cor[i] = 0;

  cor[s] = 1;  
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int atual = q.front();
    q.pop();
    for(int x : adjlista[atual]){
      if(cor[x] == 0){
        cor[x] = 1;
        q.push(x);
      }
    }
    cor[atual] = 2;
  }

}

//função recursiva para DFS
void grafo::DFS_visit(vector<bool> &visited, int s){
    visited[s] = true; //pintando de cinza
    cout << s << endl;
 
    //visitar os vertices adjacente
    //enquanto existir o i na lista de adjacencia
    for(int i : adjlista[s]){
        if(visited[i] == false){
            DFS_visit(visited, i);
        }
    }
 
    //pintando de preto
    //visited[s] = false;
}
 
void grafo::DFS( int s){
    vector<bool> visited(adjlista->size(), false);
    DFS_visit(visited, s);
}

int main(){
  grafo g(4);
  g.aresta(0, 1);
  g.aresta(0, 2);
  g.aresta(1, 2);
  g.aresta(2, 3);
  
  g.DFS(0);


  return 0;

}
