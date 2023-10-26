```
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int,int> uMap;
        for(int i = 0; i < arr.size(); i++){
            uMap[arr[i]]++;
        }
        unordered_set <int> uniqueFreq;
        for(auto i : uMap){
            if(uniqueFreq.count(i.second)){
                return false;
            }else{
                uniqueFreq.insert(i.second);
            }
        }
        return true;
    }
};

```
