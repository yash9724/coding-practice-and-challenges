// https://www.hackerrank.com/challenges/journey-to-the-moon/problem
// status : accepted

#include<iostream>
#include<iterator>
#include<list>
#include<map>
#include<vector>
#include<queue>

using namespace std;

class Graph{
    map<int, list<int>> adjList;

    public:
        Graph(){

        }

        void addEdge(int u, int v, bool isbidir=true){
            adjList[u].push_back(v);
            if(isbidir)
                adjList[v].push_back(u);
        }

        bool vertexIsEmpty(int i){
            return adjList[i].empty();
        }

        void printGraph(){
            for(auto pair: adjList){
                cout << pair.first << " ----> ";
                for(int j : pair.second) 
                    cout << j << ", ";
                cout << endl;
            }
        }

        int bfsUtil(int src, map<int, bool>& visited){

            queue<int> q;
            int ele = 0;

            q.push(src);
            ele++;
            visited[src] = true;

            while(!q.empty()){
                int node = q.front();
                cout << node << " ";
                q.pop();

                for(int nei : adjList[node]){
                    if(!visited[nei]){
                        visited[nei] = true;
                        q.push(nei);
                        ele++;
                    }
                }

                cout << endl;
            }

            return ele;
        }

        void bfs(vector<int>& comp, int n){
            map<int, bool> visited;

            for(int i = 0 ; i < n ; i++){
                if(!visited[i]){
                    int x = bfsUtil(i, visited);
                    comp.push_back(x);
                }
            }
        }
};

long long int pairs(int n, vector<vector<int>>& ast){

    // construct graph
    Graph g;
    for(int i = 0 ; i < ast.size() ; i++){
        g.addEdge(ast[i][0], ast[i][1]);
    }

    g.printGraph();
    vector<int> comp;
    g.bfs(comp, n);
    long long int ans = 0, sum,squares;
    for(int i = 0; i < comp.size() ; i++){
        cout << comp[i] << " ";
        
    }

    cout << endl;

    for(int i = 0; i < comp.size() ; i++){
        sum += comp[i];
        squares += comp[i]*comp[i];
    }
    ans = (sum*sum - squares)/2;
    return ans;
}

int main(){
    int n, p;
    cin >> n >> p;

    vector<vector<int>> ast(p);
    for(int i = 0 ; i < p ; i++){
        ast[i].resize(2);
        cin >> ast[i][0] >> ast[i][1];
    }

    for(int i = 0 ; i < p ; i++){
        cout << ast[i][0] << " " << ast[i][1] << endl;
    }

    long long int ans = pairs(n, ast);
    cout << ans;

}