#include <iostream>
#include <vector>
using namespace std;
 
//função recursiva para DFS
void DFS_visit(vector<vector<int>> &adj, vector<bool> &visited, int s){
    visited[s] = true; //pintando de cinza
    cout << s << endl;
 
    //visitar os vertices adjacente
    //enquanto existir o i na lista de adjacencia
    for(int i : adj[s]){
        if(visited[i] == false){
            DFS_visit(adj, visited, i);
        }
    }
 
    //pintando de preto
    //visited[s] = false;
}
 
void DFS(vector<vector<int>> &adj, int s){
    vector<bool> visited(adj.size(), false);
    DFS(adj, visited, s);
}

int main(){
  vector<<vector<int>> arestas = {{1, 2}, {2, 0}, {0, 3}, {3, 4}};

  return 0;
}
