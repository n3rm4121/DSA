#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <queue>
using namespace std;
class graph{
    public:
        unordered_map<int, list<int>> adj;
        
        void addEdge(int u, int v, int dir){
            adj[u].push_back(v);
            if(dir == 0){
                adj[v].push_back(u);
            }
        }
    
        void BFS(int start){
            unordered_set<int> visited;
            queue<int> bfsQueue;

            visited.insert(start);
            bfsQueue.push(start);
            while(!bfsQueue.empty()){
                int current_vertex = bfsQueue.front();
                cout << current_vertex << " ";
                bfsQueue.pop();

                for(auto neighbour : adj[current_vertex]){
                    if(visited.find(neighbour) == visited.end()){
                        visited.insert(neighbour);
                        bfsQueue.push(neighbour);
                    }
                }
               
            }
        }
        void DFSUtil(int start, unordered_set<int> &visited){
            visited.insert(start);
            cout << start << " ";

            for(auto neighbour : adj[start]){
                if(visited.find(neighbour) == visited.end()){
                    DFSUtil(neighbour, visited);
                }
            }
            
        }

        void DFS(int start){
            unordered_set<int> visited;
            DFSUtil(start, visited);
        }
        void print(){
            for(auto& i : adj){
                cout << i.first << "->";
                for(auto& j : i.second){
                    cout<< j << ", ";
                }
                cout << endl;
            }
        }
};
int main() {
    cout << "no. of Edges: ";
    int n;
    cin >> n;
    cout << "no. of nodes: ";
    int m;
    cin >> m;
    
    cout << "dir; ";
    int dir;
    cin >> dir;
    graph g;
    for(int i = 0; i <n;i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u,v,dir);
    }
    cout << "BFS traversal: ";
    g.BFS(0);
    cout << endl;
    cout << "DFS traversal : ";
    g.DFS(0);
    return 0;
}