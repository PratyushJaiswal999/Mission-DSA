class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;   // hash map called mpp to count how many times each number appears in the array.
        for(int num : nums)
            mpp[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for(auto& [num,count]:mpp){
            minHeap.push({count,num});
            if(minHeap.size()>k)
                minHeap.pop();
        }

        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
