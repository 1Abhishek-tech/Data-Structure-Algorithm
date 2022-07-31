class NumArray {
public:
    NumArray(vector<int>& nums) {
		int size = nums.size();
		segtree.resize(2 * size);
		for (int i = size; i < 2 * size; i++) segtree[i] = nums[i - size];
		for (int i = size - 1; i > 0; i--) segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];     
    }
    
    void update(int index, int val) {
    int pos = index + segtree.size() / 2;
		int diff = val - segtree[pos];
		while (pos) {
			segtree[pos] += diff;
			pos /= 2;
		}
    }
    
    int sumRange(int left, int right) {
    int n = segtree.size() / 2;
		left += n;
		right += n;
		int sum = 0;
		while (left <= right) {
			if ((left % 2) == 1) sum += segtree[left];
			if ((right % 2) == 0) sum += segtree[right];
			left = (left + 1) / 2;
			right = (right - 1) / 2;
		}
		return sum;
    }
  private:
	vector<int> segtree;
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */