class Solution {
public:
class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int V){
        this->V=V;
        l= new list<int> [V];
    }
    void addEdge(int i, int j){
        l[i].push_back(j);
    }
    bool contains_cycle(int s, bool* visited, bool* stack){
        visited[s]=true;
        stack[s]=true;
        for(int nbr: l[s]){
            if(visited[nbr]==false){
                if(contains_cycle(nbr, visited, stack)==true) return true;
            }else if(stack[nbr]==true){
                return true;
            }
        }
        stack[s]=false;
        return  false;
        
        
    }
    
    
};

bool canFinish(int n, vector<vector<int>> preq) {
    Graph g(n);
    for(auto course: preq){
        g.addEdge(course[1], course[0]);
    }
    bool* visited= new bool [n];
    bool* stack= new bool [n];
    for(int i=0; i<n; i++){
        visited[i]=false;
        stack[i]=false;
    }
    for(int i=0; i<n; i++){
        if(visited[i]==false){
            if(g.contains_cycle(i, visited, stack)==true) return false;
        }
    }
    return true;
    
        
}
};