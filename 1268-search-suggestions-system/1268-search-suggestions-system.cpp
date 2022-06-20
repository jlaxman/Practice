class Solution {
    struct Node{
        string word;
       vector<Node *> next{vector<Node *> (26, NULL)};
        bool isend;
        Node(string s){
            word=s;
            isend=false;
        }
    
    };
    void insert(string s, Node* root){
        Node* curr=root;
        string temp;
        for(auto ch: s){
            temp+=ch;
            if(curr->next[ch-'a']==NULL){
                curr->next[ch-'a']=new Node(temp);
            }
            curr=curr->next[ch-'a'];
        }
        curr->isend=true;
    }
    void dfs(Node* cur, vector<string>& ans){
        if(ans.size()==3){
            return ;
        }
        if(cur==NULL) return ;
        if(cur->isend){
            ans.push_back(cur->word);
        }
        for(int i=0; i<26; i++){
            if(cur->next[i]!=NULL){
                dfs(cur->next[i], ans);
            }
        }
        return ;
    }
   
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n=products.size();
        Node* root= new Node("");
        for(auto pr: products){
            insert(pr, root);
        }
        Node* cur=root;
        vector<vector<string>> res;
        for(auto ch: searchWord){
            if(cur->next[ch-'a']!=NULL){
             cur=cur->next[ch-'a'];
             vector<string> ans;
             dfs(cur, ans);
             res.push_back(ans);
             cout<<ch<<endl;
            }else{
                cur->next[ch-'a']=new Node("");
                cur=cur->next[ch-'a'];
                res.push_back({});
            }
            
                
        }
        
        
        return res;
        
        
        
    }
};