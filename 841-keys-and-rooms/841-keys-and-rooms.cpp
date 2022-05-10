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

	bool dfs(int source) {
		bool* visited = new bool [N];
		for (int i = 0; i < N; i++) visited[i] = false;
		dfs_helper(source, visited);
		for(int i=0; i<N; i++ ){
		    if(visited[i]==false) return false;
		}
		return true;
	}


};
bool canVisitAllRooms(vector<vector<int>> rooms) {
   Graph g(rooms.size());
   int j=0;
   for(auto room: rooms){
       for(auto key: room){
           g.addEdge(j, key, false);
       }
       j++;
   }
   return g.dfs(0);
   
}
};