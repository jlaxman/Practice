class AutocompleteSystem {
public:
    struct Node{
        string word;
        unordered_map<char, Node*> next;
        set<pair<int, string>> pq;
        Node(string s){
            word=s;
        }
    };
    Node* root;
    Node* cur;
    unordered_map<string, int> mpp;
    void insert(string s, int t){
        Node* curr=root;
        string temp;
        for(auto ch: s){
            temp+=ch;
            if(curr->next.find(ch)== curr->next.end()){
                curr->next[ch]=new Node(temp);
            }
            curr=curr->next[ch];
            (curr->pq).insert({t, s});
        }
    }
     void insert_exist(string s, int t){
         
        Node* curr=root;
        for(auto ch: s){
            curr=curr->next[ch];
            auto f=(curr->pq).find({t, s});
            if(f!=curr->pq.end()){
                curr->pq.erase(f);
            }
            curr->pq.insert({t-1, s});
        }
         mpp[s]=t-1;
    }
        
    
   
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root= new Node("");
        cur=root;
        for(int i=0; i<sentences.size(); i++){
            insert(sentences[i], -times[i]);
            mpp[sentences[i]]=-times[i];
        }
        
    }
   
    string in;
    vector<string> prev;
    vector<string> input(char c) {
        vector<string> ans;
        if(c!='#'){
            in.push_back(c);   
            if(cur->next.find(c)!=cur->next.end()){
                cur=cur->next[c];
                auto p=cur->pq;
                int t=3;
                while(!p.empty() && t--){
                    auto it= p.begin();
                    ans.push_back(it->second);
                    p.erase(it);
                }
                
            }else{
                cur->next[c]= new Node(in);
                 cur=cur->next[c];
                return prev={};
            }
            
        }else{
            string temp=in;
            in.clear();
            cur=root;
            if(mpp.find(temp)==mpp.end()){
                mpp[temp]=-1;
                insert(temp, -1);
            }else{
                insert_exist(temp, mpp[temp]);
                
            }
            vector<string> a=prev;
            prev.clear();
            return {};
            
        }
        return prev=ans;
        
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */