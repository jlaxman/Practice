class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size() <= 0) return 0;
        auto comp=[](auto& x, auto& y){
            return x[1]<y[1];
        };
        sort(courses.begin(), courses.end(),comp);
       
        priority_queue<int> q;
        int sum = 0;
        for(auto i : courses) {
            sum += i[0];
            q.push(i[0]);
            if(sum > i[1]) {
                sum -= q.top();
                q.pop();
            }
        }
        return q.size(); 
    }
};