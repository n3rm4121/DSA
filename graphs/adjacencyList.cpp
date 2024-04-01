
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>
class graph{
    public:
    unordered_map<T, list<T>> adjList;
    
    void addEdge(T u, T v, bool dir){
        // dir == 0 -> undirected graph
        // dir == 1 -> directed graph
        adjList[u].push_back(v);
        if(dir == 0){
            adjList[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto i: adjList){
            cout << i.first << "-> ";
            for(auto j : i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }
        
};
int main() {
    graph<int> g;
    cout << "Enter no. of nodes: ";
    int m;
    cin >> m;
    cout << "Enter no. of edges: ";
    int n;
    cin >> n;
    cout << "Its a directed or undirected graph: (enter '0' for undirected and '1' for directed)";
    bool dir;
    cin >> dir;
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, dir);
    }

    g.printAdjList();
    return 0;
}