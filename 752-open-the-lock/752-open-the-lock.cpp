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
        unordered_map<string, int> vis;
         vis["0000"]=1;
         for(auto t: deadends){
             vis[t]=INT_MAX;
             if(t=="0000") return -1;
         }
        
        queue<string> q;
        q.push("0000");
        int flag=0;
      while(!q.empty()){
            string curr =q.front();
            q.pop();
            if(target== curr){
                flag=1;
               break;
            }
            vector<string> nbrs= neighbours(curr);
            for(auto nbr: nbrs){
                if(vis[nbr]==0){
                    vis[nbr]=vis[curr]+1;
                    q.push(nbr);
                }
            }
    }
       
    return flag? vis[target]-1: -1;
        
        
        
        
    }
};