class Solution {
public
    int minSetSize(vectorint& arr) {
        unordered_mapint, int m;
        for(auto it  arr) m[it]++;      ele - freq
        
         max-heap
        priority_queuepairint, int pq;
         since, max freq element should be at the top. We will put the freq at 
         the first position and respective element at second position
        for(auto it  m)
        {
            pq.push(make_pair(it.second, it.first));    first maxFreq, secondele
        }
        
        int ans = 0;
        int half_len = arr.size()2;
        int n = 0;
        
        while(n  half_len)
        {
            pair top_pair = pq.top();
            pq.pop();
            
            int lenOfele = top_pair.first;
            n += lenOfele; 
            ans++;
        }    
               
        return ans;
    }
};