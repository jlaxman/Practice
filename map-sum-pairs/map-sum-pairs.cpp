class MapSum {
public:
    struct Node{
        string word;
        unordered_map<char, Node*> next;
        bool isend;
        int sum;
        Node(string s){
            isend=false;
            sum=0;
            word=s;
        }
    };
    Node* root;
    unordered_map<string, int> mpp;
    MapSum() {
        root= new Node("");
    }
    
    void insert(string key, int val) {
        Node* curr=root;
        string temp;
        for(auto ch: key){
            temp+=ch;
            if(curr->next.find(ch)== curr->next.end()){
                curr->next[ch]= new Node(temp);
            }
            curr=curr->next[ch];
           
        }
        Node* cur=root;
        if(curr->isend){
            for(auto ch: key){
                cur=cur->next[ch];
                cur->sum -= (mpp[key]);
                cur->sum += val;
            }
             mpp[key]=val;
            
        }else{
            for(auto ch: key){
                cur=cur->next[ch];
                cur->sum += val;
            }
            mpp[key]=val;
            curr->isend=true;
        }
        
        
    }
    
    int sum(string prefix) {
         Node* curr=root;
        for(auto ch: prefix){
            if(curr->next.find(ch)== curr->next.end()){
               return 0;
            }
            curr=curr->next[ch];
        }
        return curr->sum;
        
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */