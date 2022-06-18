class Solution {
public:
    struct Node{
        string word;
        unordered_map<char, Node*> next;
        bool isend;
        Node(string s){
            word=s;
            isend=false;
        }
    };
    Node* root;
    
    void insert(string key){
     Node* curr=root;
        string temp;
        for(auto ch: key){
            temp+=ch;
            if(curr->next.find(ch)==curr->next.end()){
                curr->next[ch]=new Node(temp);
            }
            curr=curr->next[ch];
        }
        curr->isend=true;
        
    }
    string search(string word){
        Node* curr=root;
        for(auto ch: word){
            if(curr->next.find(ch)==curr->next.end()){
               return word;
            }
            curr=curr->next[ch];
            if(curr->isend){
                return curr->word;
            }
        }
        return word;
     }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        root= new Node("");
        for(auto w: dictionary){
            insert(w);
        }
        string ans;
        stringstream ss(sentence);
        string word;
        while(ss>> word){
            ans+= search(word);
            ans+=" ";
        }
        if(ans.size()) ans.pop_back();
        return ans;
        
        
    }
};