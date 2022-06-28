class Solution {
public:
    string reverse(string s){
         int n=s.size();
        for(int i=0; i<n/2; i++){
            swap(s[i], s[n-i-1]);
        }
        return s;
        
    }
    class Node{
        public:
    
        vector<Node*> next{vector<Node*>(26, NULL)};
        bool isend;
        int ind;
        vector<int> pr;
        Node(){
            isend=false;
            ind=-1;
        }
    };
    void insert(Node* root, string& w, int i){
        Node* curr=root;
        int j=0;
        for(auto ch: w){
            if( curr->next[ch-'a']==NULL){
                curr->next[ch-'a']=new Node();
            }
            if(checkPalindrome(w, j, w.size()-1)){
                curr->pr.push_back(i);
            }
            curr=curr->next[ch-'a'];
            
            j++;
        }
        curr->isend=true;
        curr->ind=i;
        return ;
    }
    bool checkPalindrome(string& s, int f, int b){
        int n=s.size();
        int p1 = f;
        int p2 = b;
        while (p1 < p2) {
            if (s[p1] != s[p2]) return false;
            p1++; p2--;
        }
        return true;
    }
    
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Node* root= new Node();
        // Node* root1= new Node();
        int k=0;
        for(auto w: words){
            string s=reverse(w);
            insert(root, s, k);
            // insert(root1, w, k);
            k++;
        }
        vector<vector<int>> ans;
        for(int i=0; i<words.size(); i++){
            string s=words[i];
            Node* curr=root;
          for(int k=0; k<s.size(); k++){
              if(curr->isend && checkPalindrome(s, k, s.size()-1) ){
                  ans.push_back({i, curr->ind});
              }
              if(curr->next[s[k]-'a']){
                  curr=curr->next[s[k]-'a'];
              }else{
                  curr=NULL;
                  break;
              } 
          }
            if(curr==NULL) continue;
            if(curr->isend && curr->ind!=i){
                ans.push_back({i, curr->ind});
            }
            for(int n: curr->pr){
                ans.push_back({i, n});
                cout<< i<<" "<<n<<endl;
            }
          
        }
        return ans;
        
    }
};