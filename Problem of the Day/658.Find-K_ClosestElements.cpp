class Solution {
public
    vectorint findClosestElements(vectorint& arr, int k, int x) {
        int n = arr.size();
        
         Take min_heap data structure to store less difference(i.e arr[i] - x) elements at the top
        priority_queuepairint, int, vectorpairint, int, greaterpairint, int  pq;            pair(difference, element)
        
        for(int i=0; in; i++)
            pq.push(make_pair(abs(x - arr[i]), arr[i]));   store the elements w.r.t. less difference at the top
    
        
        vectorint ans;
        for(int i=1; i=k; i++)
        {
            int element = pq.top().second;      Take the top k element and push it to ans
            ans.push_back(element); 
            pq.pop();
        }
        
        sort(ans.begin(), ans.end());        sort in ascending order
        
        return ans;
    }
};