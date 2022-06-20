class Solution {
public:
    class Node{
    public:
        string word;
        vector<Node*> next{vector<Node*> (26, NULL)};
        Node(string s){
            word=s;
        }
    };
   int ans;
    void insert(string s, Node* root){
        Node* curr= root;
        string temp;
        for(auto ch: s){
            temp+=ch;
            if(curr->next[ch-'a']==NULL){
                curr->next[ch-'a']= new Node(temp);
            }
            curr=curr->next[ch-'a'];
        }
    }
    void dfs(Node* curr){
        
        int flag=0;
        for(int i=0; i<26; i++){
            if(curr->next[i]!=NULL){
                dfs(curr->next[i]);
                flag=1;
            }
        }
        if(flag==0) ans+=(((curr->word).size())+1);
        return ;
        
    }
    
    
    int minimumLengthEncoding(vector<string>& words) {
        Node* root= new Node("");
        ans=0;
        for(auto w: words){
            reverse(w.begin(), w.end());
            insert(w, root);
        }
        dfs(root);
        return ans;
        
        
  
    }
};