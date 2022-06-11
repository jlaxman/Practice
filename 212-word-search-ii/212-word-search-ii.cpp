class Solution {
    
public:   
    vector<string> ans;
    struct Node{
        string word;
        Node* nxt[26];
        bool isEnd;
        Node(){
            for(int i=0; i<26; i++) nxt[i]=NULL;
            isEnd=false;
        }  
    };

    Node* root;
    void insert(string s){
        Node* curr=root;
        for(auto ch: s){
            if(curr->nxt[ch-'a']==NULL){
                curr->nxt[ch-'a']= new Node();
            }
            curr=curr->nxt[ch-'a'];
        }
        curr->word=s;
        curr->isEnd=true;
    }
    // bool search(string& s){
    //     Node* curr=root;
    //     for(auto ch: s){
    //         if(curr->nxt[ch-'a']==NULL) return false; 
    //         curr=curr->nxt[ch-'a'];
    //     }
    //     return true;
    // }
public:
    bool check(int x, int y, int m, int n){
        return (x>=0 && x<=m-1 && y>=0 && y<= n-1);
    }
    void dfs(int i, int j,  vector<vector<char>>& board, vector<vector<int>>& vis, Node* temp, int m, int n){
        
        if(temp->nxt[board[i][j]-'a']==NULL){
            return ;
        }
        temp=temp->nxt[board[i][j]-'a'];
        if(temp->isEnd){
            ans.push_back(temp->word);
            temp->isEnd=false;
        }
        int dx[4]={1, -1, 0, 0};
        int dy[4]={0, 0, -1, 1};
        vis[i][j]=1;
        for(int k=0; k<4; k++){
            int x=i+dx[k];
            int y= j+dy[k];
            if(check(x, y, m, n) && vis[x][y]==0){
                dfs(x, y, board, vis, temp, m, n);
            }
        }
        
        vis[i][j]=0;
        return ;
        
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        
        root= new Node();
        
        for(auto s: words){
            insert(s);
        }
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m+1, vector<int>(n+1, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                 dfs(i, j, board, vis, root, m, n);
            }
        }
        return ans;
       
    }
};