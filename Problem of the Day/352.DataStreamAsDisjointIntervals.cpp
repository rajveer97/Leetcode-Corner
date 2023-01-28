class SummaryRanges {
public:
    set<int> values;
    SummaryRanges() {
    }
    
    void addNum(int value) {
        values.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;

        if(values.empty())
            return {};
        
        int left = -1, right = -1;

        for(auto value : values) {
            if(left < 0) {
                left = right = value;
            }
            else if(value == right + 1) {
                right = value;
            }
            else {
                intervals.push_back({left, right});
                left = right = value;
            }
        }

        intervals.push_back({left, right});
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */