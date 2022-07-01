class Solution {
public:
    class Node{
        public:
        vector<Node*> next{vector<Node*>(26, NULL)};
        vector<string> list;
        bool isend;
        Node(){
            isend=false;
        }
    };
    void insert(Node* root, string t, string s){
        Node* curr=root;
        for(auto ch:t){
            if( curr->next[ch-'a']==NULL){
                curr->next[ch-'a']= new Node();
            }
            curr=curr->next[ch-'a'];
        }
        curr->isend=true;
        curr->list.push_back(s);
    }
    void dfs(Node* curr, vector<vector<string>>& ans){
        
        for(int i=0; i<26; i++){
            if(curr->next[i]!=NULL){
                dfs(curr->next[i], ans);
            }
        }
        if(curr->isend){
            ans.push_back(curr->list);
            return ;
        }
        return ;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        Node* root= new Node();
        for(auto s: strs){
            string t=s;
            sort(t.begin(), t.end());
            insert(root, t, s);
        }
        vector<vector<string>> ans;
        dfs(root, ans);
        return ans;
        
    }
};