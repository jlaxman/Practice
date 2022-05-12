class Solution {
    
    class Graph{
        int V;
        list<int>* l;
        public:
        Graph(int V){
            this->V=V;
            l= new list<int> [V];
        }
        
        void addEdge(int i, int j){
            l[i].push_back(j);
            l[j].push_back(i);
        }
        
        bool containscycle(int source, int out,  bool* visited, int parent){
            visited[source]=true;
            for(int nbr: l[source]){
                if(visited[nbr]==false){
                    if(containscycle(nbr, out, visited, source)==true) return true;
                }
                else if(nbr!=parent && nbr==out){
                    return true;
                }
            }
            return false;
            
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
         Graph g(n+1);
        for(auto e: edges){
            g.addEdge(e[0], e[1]);
        }
       
        for(int i=n-1; i>=0; i--){
            bool* visited= new bool [n+1]{0};
            visited[edges[i][1]]=true;
            if(g.containscycle(edges[i][0], edges[i][1], visited, edges[i][1])==true) return {edges[i][0], edges[i][1]};
        }
        return {};
       
    }
};