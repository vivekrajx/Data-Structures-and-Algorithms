class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged_intervals;
        //edge case: if empty interval, return empty array
        if(intervals.size()==0)
        {   
            return merged_intervals;
        }
         //step 1: sorting the intervals
        sort(intervals.begin(), intervals.end());
        //step 2: storing the first interval in merged intervals
        vector<int> temp_interval = intervals[0];
        
        //step 3: iterating linearly and checking for required condition:
        for(auto it: intervals)
        {
            if(it[0]<=temp_interval[1])
            {    //for example in [1,3] & [2,4] if 2<3
                temp_interval[1] = max(it[1], temp_interval[1]);
            //we put max of right of first pair, and right of 2nd pair
            //it will be max of either the current interval or the right of               resultant merged interval we are storing
            }
            else
            {
                //if not merging...
                //putting resultant of consecutive interval back into
                //merged interval
                merged_intervals.push_back(temp_interval);
                temp_interval = it; //reassign value interval into temp int
            }
        }
          //finally pushing the last merged interval after all itr over
        merged_intervals.push_back(temp_interval);
        return merged_intervals;
    }
};