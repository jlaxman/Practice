class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
    
        unordered_map<string, int> freq;
        int n= paragraph.size();
        int i=0;
        while(i<n){
            string temp;
            while(i<n && isalpha(paragraph[i])){
                temp+= tolower(paragraph[i]);
                i++;
            }
            if(temp.size()){
                freq[temp]++;
            }
            i++;
        }
        
        for(auto b: banned){
            auto it= freq.find(b);
            if(it!=freq.end()){
                freq.erase(it);
            } 
        }
        int maxfreq=0;
        string cword;
        for(auto m: freq){
            if(m.second> maxfreq){
                maxfreq=m.second;
                cword=m.first;
            }
        }
        return cword;
    
    }
};