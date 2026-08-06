class Solution {
public:
    int calculateHour(vector<int>& piles, int k, long long h) {
        long long hour = 0;
        for(int p:piles) {
            hour += (p + k - 1)/k;
            if(hour > h) return hour;
        }
        return hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int end = *max_element(piles.begin(), piles.end());

        while(st <= end) {
            int mid = st + (end - st)/2;

            if(calculateHour(piles,mid,h) <= h) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return st;
    }
};