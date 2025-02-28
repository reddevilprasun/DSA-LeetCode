class Solution {
public:
    bool isPalindrome(string s){
        if(s.length() == 1) return true;
        int st = 0, end = s.length() - 1;
        while(st < end) {
            if(s[st++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    void getAllPartition(string s, vector<string> &partition, vector<vector<string>> & ans){
        if(s.length() == 0) {
            ans.push_back(partition);
            return;
        }

        for(int i = 0; i < s.length() ; i ++) {
            string past = s.substr(0, i+ 1);
            if(isPalindrome(past)){
                partition.push_back(past);
                getAllPartition(s.substr(i+1), partition,ans);
                partition.pop_back(); // backtracking
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        getAllPartition(s,partition, ans);
        return ans;
    }
};