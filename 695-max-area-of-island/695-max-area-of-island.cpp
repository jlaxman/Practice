class Solution {
public:
   class Graph {
	int N;
	list<int> *l;
public:
	Graph(int v) {
		N = v;
		l = new list<int> [v];
	}
	void addEdge(int i, int j, bool undir = true) {
		l[i].push_back(j);
		if (undir == true) {
			l[j].push_back(i);
		}
	}
	
	bool bfs(int s) {
		queue<int> q;
// 		cout << s << endl;
		q.push(s);

		vector<int> visited(N, 1e9);
		visited[s] = 0;

		while (!q.empty()) {
			int curr = q.front();
			q.pop();

			for (int nbr : l[curr]) {
				if (visited[nbr] == 1e9) {
					// cout << nbr << endl;
					visited[nbr] = visited[curr] + 1;
				// 	cout << nbr << " " << visited[nbr] << endl;
					q.push(nbr);
				}
			}
		}
		for(auto c: visited){
		    if(c==1e9) return false;
		}
		return true;

	}
	void dfs_helper(int source, bool* visited) {

		visited[source] = true;
// 		cout << source << ',';
		for (auto nbr : l[source]) {
			if (visited[nbr] == false) {
				dfs_helper(nbr, visited);
			}
		}
	}

	int dfs(int source) {
		bool* visited = new bool [N];
		for (int i = 0; i < N; i++) visited[i] = false;
		dfs_helper(source, visited);
		int cnt=0;
		for(int i=0; i<N; i++ ){
		    if(visited[i]==true) cnt++;
		}
		return cnt;
	}


};

  
int maxAreaOfIsland(vector<vector<int>> grid)
{
    Graph g(grid.size()*grid[0].size());
    int dx[4]={0, 0, +1, -1};
    int dy[4]={+1, -1, 0, 0};
    int row= grid.size();
    int col=grid[0].size();
    for(int r=0; r< row; r++){
        for(int c=0; c<col; c++){
            if(grid[r][c]==0) continue;
            for(int k=0; k<4; k++){
                int R=r+dx[k];
                int C= c+dy[k];
                if(R>=0 && R<row && C>=0 && C< col && grid[R][C]==1){
                    g.addEdge((r*col)+c, (R*col)+C, false);
                }
            }
        }
    }
    int mx=0;
    for(int r=0; r<row; r++){
        for(int c=0; c<col; c++){
            if(grid[r][c]==1){
                mx=max(g.dfs(r*col+c), mx);
            }
        }
    }
    return mx;
    
    
}
};