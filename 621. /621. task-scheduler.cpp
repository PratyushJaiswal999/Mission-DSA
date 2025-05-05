class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char task : tasks)
            freq[task-'A']++;
        
        int maxfreq = *max_element(freq.begin(),freq.end());
        int maxcount = count(freq.begin(),freq.end(),maxfreq);

        int partcount = maxfreq-1;
        int partlen = n+1;
        int emp = partcount * partlen + maxcount;

        return max((int)tasks.size(),emp);

    }
};
