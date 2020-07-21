// https://www.spoj.com/problems/HOLI/
// status :
#include<bits/stdc++.h>

using namespace std;

class Graph{
    int v; 
    list<pair<int, long long int>> *l;

    public:
        Graph(int n){
            v = n;
            l = new list<pair<int, long long int> >[v+1];
        }

        void add_edge(int u, int v, long long int w){
            l[u].push_back(make_pair(u,w));
            l[v].push_back(make_pair(v,w));
        } 

        int dfsHelper(int source, bool* visited, int* nodeCount, long long int& ans){
            visited[source] = true;
            nodeCount[source] = 1;
            for(auto itr: l[source]){
                if(!visited[itr.first]){
                    nodeCount += dfsHelper(itr.first, visited, nodeCount, ans);
                    ans += 2*min(nodeCount[itr.first], v-nodeCount[itr.first]) * itr.second;
                }
            }
            return nodeCount[source];
        }

        long long int dfs(){
            bool* visited = new bool[v+1]{0};
            int* nodeCount = new int[v+1]{0};

            long long int ans = 0;
            dfsHelper(1,visited,nodeCount,ans);
            return ans;
        }
};

int main(){
    int t;
    cin>>t;
    int i = 1;
    while(t--)
    {
        int n;
        cin>>n;
        Graph g(n);
        while(n>1)
        {
            n--;
            int i,j;long long int k;
            cin>>i>>j>>k;
            g.add_edge(i,j,k);
        }
        cout<< "Case #"<<i<<": "<<g.dfs()<<endl;
        i++;
    }
}
