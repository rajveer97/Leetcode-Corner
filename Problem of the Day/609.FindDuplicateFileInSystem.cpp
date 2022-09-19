class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> ump;
        
        for(auto path : paths)
        {
            stringstream str(path);
            string file;
            string dir;
            
            getline(str, dir, ' ');
            
            while(getline(str, file, ' '))
            {
                string content = file.substr(file.find('(') + 1, file.find(')') - file.find('(')-1);
                string name = dir + '/' + file.substr(0, file.find('('));
                ump[content].push_back(name);
            }
        }
        
        vector<vector<string>> ans;
        
        for(auto x : ump)
        {
            if(x.second.size()>1)
                ans.push_back(x.second);
        }
        
        return ans;
    }
};