// Method 1:
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int p1 = 0, p2 = 1;
        int time = 0;
        while(p1 < colors.length() && p2 < colors.length())
        {
            if(colors[p1] == colors[p2])
            {
                if(neededTime[p1] <= neededTime[p2])
                {
                    time += neededTime[p1];
                    p1 = p2;
                    p2++;
                }
                else
                {
                    time += neededTime[p2];
                    p2++;
                }
            }
            else
            {
                p1 = p2;
                p2++;
            }
        }

        return time;
    }
};

//-----------------------------------------------------------

// Method 2: 
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();

        int totalTime = 0;
        char c = '*';
        int prevTime = 0;

        for(int i=0; i<n; i++)  {
            if(c == colors[i])
            {
                if(prevTime < neededTime[i])
                {
                    totalTime += prevTime;
                    prevTime = neededTime[i];
                }
                else
                {
                    totalTime += neededTime[i];
                }  
            }
            else 
            {
                c = colors[i];
                prevTime = neededTime[i];
            }
        }

        return totalTime;
    }
};
