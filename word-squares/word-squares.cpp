class Solution {
public:
class Node{
    public:
    bool isend;
    vector<Node*> next{vector<Node*>(26, NULL)};
    Node(){
        isend=false;
    }
};

    void insert(string w, Node* root){
        Node* curr=root;
        for(auto ch: w){
            
            if(curr->next[ch-'a']==NULL){
                curr->next[ch-'a']= new Node();
            }
            curr=curr->next[ch-'a']  ;
        }
        curr->isend=true;
    }
    
   
    void searchSolve(int i, vector<string>& ds, vector<vector<string>>& ans, Node* root, int n){
        if(i==n){
            ans.push_back(ds);
            return ;
        }
        string pre;
        for(int k=0; k<i; k++){
            pre+=ds[k][i];
        }
        vector<string> ss= getPrefix(pre, root);
        if(ss.size()==0) return ;
        for(auto s: ss){
            ds[i]=s;
            searchSolve(i+1, ds, ans, root, n);
        }
        return ;
        
        
        
    }
    vector<string> getPrefix(string& pre, Node* root){
        Node* curr=root;
        vector<string> ans;
        for(auto ch: pre){
            if(curr->next[ch-'a']==NULL) return {};
            curr=curr->next[ch-'a'];
        }
        dfs(curr, ans, pre);
        return ans;
    }
    void dfs(Node* curr, vector<string>& ans, string pre){
        
        if(curr->isend){
            ans.push_back(pre);
            return;
        }
        
        for(int i=0; i<26; i++){
            if(curr->next[i]!=NULL){
                pre.push_back(i+'a');
                dfs(curr->next[i], ans, pre);
                pre.pop_back();
            }
        }
        return ;
        
    }
    
    
    
    
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        Node* root =new Node();
        for(auto w: words){
            insert(w, root);
        }
        vector<vector<string>> ans;
        for(auto w: words){
           vector<string> ds(w.size());
            ds[0]=w;
            searchSolve(1, ds, ans, root, w.size());
             
        }
        return ans;
        
        
    }
};