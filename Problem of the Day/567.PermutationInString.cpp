class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1s = s1.size();
        int s2s = s2.size();

        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);

        int left = 0, right = 0;

        if(s1s > s2s) return false;

        // First slide
        while(right < s1s)
        {
            mp1[s1[right] - 'a'] += 1;
            mp2[s2[right] - 'a'] += 1;
            right++;
        }

        right--;

        // Left slides
        while(right < s2s) {
            if(mp1 == mp2) return true;

            right ++;

            if(right != s2s) {
                mp2[s2[right] - 'a'] += 1;
            }

            mp2[s2[left] - 'a'] -=1;

            left++;
        }

        return false;
    }
};