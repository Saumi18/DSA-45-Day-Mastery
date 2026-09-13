// tuple stores multiple values of different types
// tuple<int,int,char> = {frequency, availableTime, task}
// get<0> = first element
// get<1> = second element
// get<2> = third element
// Example: {2, 4, 'A'}
// get<0> = 2
// get<1> = 4
// get<2> = 'A'

class Solution {
public:
    vector<char> getSchedule(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char task : tasks){
            freq[task - 'A']++;
        }

        priority_queue<pair<int,char>> maxHeap;

        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                maxHeap.push({freq[i], 'A' + i});
            }
        }

        queue<tuple<int,int,char>> q;
      
        vector<char> ans;
        int time = 0;
        while(!maxHeap.empty() || !q.empty()){
            time++
            if(!maxHeap.empty()){
                auto [f, task] = maxHeap.top();
                maxHeap.pop();

                ans.push_back(task);

                f--;

                if(f > 0){
                    q.push({f, time + n + 1, task});
                }
            }
            else{
                ans.push_back('i');
            }
            if(!q.empty() && get<1>(q.front()) == time){
                auto [f, availableTime, task] = q.front();
                q.pop();
                maxHeap.push({f, task});
            }
        }
        return ans;
    }
};
