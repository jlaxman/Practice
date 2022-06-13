class Solution {
// public:
//     int stoi(string& t){
//         return ((t[0]-'0')*1000) +((t[1]-'0')*100)+((t[2]-'0')*10)+(t[3]-'0');
//     }
vector<string> neighbours(string& t){
    
    vector<string> res;
    for(int k: {0, 1, 2, 3}){
        string temp=t;
        temp[k]=(temp[k] - '0' -1 + 10) % 10 + '0';
        res.push_back(temp);
        temp=t;
        temp[k]=(temp[k] - '0' +1 + 10) % 10 + '0';
        res.push_back(temp);
    }
    return res;
}
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> vis;
         vis.insert("0000");
         for(auto t: deadends){
             vis.insert(t);
             if(t=="0000") return -1;
         }
        
        queue<string> q;
        q.push("0000");
        int flag=0;
        int d=0;
    while(!q.empty()){
            
        int sz= q.size();
        for(int s=0; s<sz; s++){
                string curr =q.front();
                q.pop();
                if(target== curr){
                   return d;
                }
            vector<string> nbrs= neighbours(curr);
            for(auto nbr: nbrs){
                if(vis.find(nbr)==vis.end()){
                    vis.insert(nbr);
                    q.push(nbr);
                }
            }

                
            
        }
        d++;
            
    }
       
    return -1;
        
        
        
        
    }
};