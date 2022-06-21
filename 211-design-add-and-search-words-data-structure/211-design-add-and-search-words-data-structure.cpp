class WordDictionary {
public:
    class Node{
        public:
        string word;
        bool isend;
        vector<Node*> next{vector<Node*> (26, NULL)};
        Node(string s){
            word=s;
            isend=false;
        }
    };
    // unordered_set<string> st;
    int mx;
    Node* root;
    WordDictionary() {
        root=new Node("");
        mx=0;
    }
    
    void addWord(string word) {
       Node* curr=root;
        string temp;
        for(auto ch: word){
            temp+=ch;
            if(curr->next[ch-'a']==NULL){
                curr->next[ch-'a']= new Node(temp);
            }
            curr=curr->next[ch-'a'];
        }
        curr->isend=true;
        mx=max((int)word.size(), mx);
    }
    
    bool search(string word) {
        if(word.size()>mx) return 0;
         return dfs(root, word, 0);
    }
    bool dfs(Node* curr, string& word, int i){
        if(i==word.size()){
            return curr->isend;
        }
        if(word[i]=='.'){
            
            for(int k=0; k<26; k++){
                if(curr->next[k]!=NULL){
                    if(dfs(curr->next[k], word, i+1)==1) return 1;
                }
            }
            
        }else{
            if(curr->next[word[i]-'a']!=NULL){
                if(dfs(curr->next[word[i]-'a'], word, i+1)==1) return 1;
        
            }else return 0;
        }
        return 0;
    }
    bool dfs1(Node* curr, string word){
        for(int i=0; i<word.size(); i++){
            if(word[i]=='.'){
                for(int k=0; k<26; k++){
                    if(curr->next[k] && dfs1(curr->next[k], word.substr(i+1))) return 1;
                }
                return 0;
            }else{
                if(curr->next[word[i]-'a']!=NULL){
                    curr=curr->next[word[i]-'a'];
                }else return 0;
            }
        }
        return curr->isend;
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */