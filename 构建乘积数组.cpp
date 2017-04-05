//给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
//不能使用除法。

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	vector<int> result(A.size(), 1);
		if (A.size() == 0)
			return result;

		vector<int> left(A.size(), 1);
		vector<int> right(A.size(), 1);
		left[0] = A[0];
		for (int i = 1; i < A.size(); ++i)
			left[i] = left[i - 1] * A[i];
		right[A.size() - 1] = A[A.size() - 1];
		for (int i = A.size() - 2; i >= 0; --i)
			right[i] = right[i + 1] * A[i];

		for (int i = 0; i < A.size(); ++i) {
			if (0 <= i - 1)
				result[i] *= left[i - 1];
			if (i + 1 <= A.size() - 1)
				result[i] *= right[i + 1];
		}

		return result;
        
    }
};