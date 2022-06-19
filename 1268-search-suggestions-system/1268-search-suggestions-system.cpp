class Solution {
    struct Node{
        string word;
        unordered_map<char, Node*> next;
        set<string> st;
        Node(string s){
            word=s;
        }
    };
    Node* root;
    void insert(string s){
        Node* curr=root;
        string temp;
        for(auto ch: s){
            temp+=ch;
            if(curr->next.find(ch)== curr->next.end()){
                curr->next[ch]=new Node(temp);
            }
            curr=curr->next[ch];
            (curr->st).insert(s);
        }
    }
    vector<vector<string>> search(string s){
        vector<vector<string>> res;
        Node* curr=root;
        for(auto ch: s){
            if(curr->next.find(ch)!=curr->next.end()){
                curr=curr->next[ch];
                auto p=curr->st;
                int t=3;
                vector<string> ans;
                while(!p.empty() && t--){
                    auto it= p.begin();
                    ans.push_back(*it);
                    p.erase(it);
                }
                res.push_back(ans);  
            }else{
                curr->next[ch]= new Node(curr->word+ch);
                curr=curr->next[ch];
                res.push_back({});
            }
        }
        return res;
    }
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root= new Node("");
        for(auto p: products){
            insert(p);
        }
        return search(searchWord);
        
        
        
    }
};