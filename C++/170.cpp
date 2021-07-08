class TwoSum {
public:
    /** Initialize your data structure here. */
    vector<int> nums={};
    TwoSum() {
        nums={};
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums.push_back(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if(nums.empty()){   //不加这句nums空的时候find会报错，IDE上是好的，不知道啥原因
            return false;
        }
        sort(nums.begin(),nums.end());
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			if (nums[l] + nums[r] == value) {
				return true;
			}
			else if (nums[l] + nums[r] > value) {
				--r;
			}
			else {
				++l;
			}
		}
