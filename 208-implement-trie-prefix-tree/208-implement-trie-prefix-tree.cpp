class node{
    public:
      string word;
      unordered_map<char, node*> next;
      bool isWord;
      node(string s){
           this->word=s;
          isWord=0;
       }
    };
class Trie {
public:
    
    node* root;
    Trie() {
        root= new node("");
    }
    
    void insert(string word){
        node* curr=root;
        string temp;
        for(auto ch: word){
            temp+=ch;
            if(curr->next.find(ch)==end(curr->next)){
                (curr->next)[ch]= new node(temp);
            }
            curr=curr->next[ch];
        }
        curr->isWord=1;
        
    }
    
    bool search(string word) {
        node* curr=root;
        for(auto ch: word){
            if(curr->next.find(ch)==end(curr->next)){
                return 0;
            }
            curr=curr->next[ch];
        }
        return curr->isWord;
        
    }
    
    bool startsWith(string prefix) {
        node* curr=root;
        for(auto ch: prefix){
            if(curr->next.find(ch)==end(curr->next)){
                return 0;
            }
            curr=curr->next[ch];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */