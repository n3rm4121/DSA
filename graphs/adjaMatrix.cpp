#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class graph{
    public:
        vector<vector<int> > adjMatrix;
        graph(int n){
            adjMatrix.resize(n, vector<int>(n,0));
        }
        
        void addEdge(int u, int v, bool dir){
            adjMatrix[u][v] = 1;
            if(!dir){
                adjMatrix[v][u] = 1;
            }
        }

        void printMatrix(){
            for(auto &row: adjMatrix){
                for(int val : row){
                    cout << val << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    cout << "Enter no. of nodes: ";
    int n;
    cin >> n;

    cout << "Enter no. of edges: ";
    int m;
    cin >> m;

    cout << "Enter '0' for undirected graph and '1' for directed graph: ";
    bool dir;
    cin >> dir;

    graph<int> g(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, dir);
    }
    g.printMatrix();
}