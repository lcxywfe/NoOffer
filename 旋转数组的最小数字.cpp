//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

class Solution {
private:
    int find(vector<int>& rotateArray, int l, int r) {
        if (l >= r)
            return rotateArray[l];
        if (r - l == 1)
            return rotateArray[l] < rotateArray[r] ? rotateArray[l] : rotateArray[r];
        if (rotateArray[r] > rotateArray[l])
            return rotateArray[l];
        
        int mid = (l+r)/2;
        if (rotateArray[mid-1] > rotateArray[mid])
            return rotateArray[mid];
        if (rotateArray[mid] > rotateArray[mid+1])
            return rotateArray[mid+1];
        
        if (rotateArray[mid] > rotateArray[r])
            return find(rotateArray, mid+1, r);
        else if (rotateArray[mid] < rotateArray[r])
            return find(rotateArray, l, mid-1);
        else if (rotateArray[l] < rotateArray[mid])
            return find(rotateArray, l, mid-1);
        else if (rotateArray[l] > rotateArray[mid])
            return find(rotateArray, mid+1, r);
        else
            return find(rotateArray, mid+1, r) < find(rotateArray, l, mid-1) ? find(rotateArray, mid+1, r) : find(rotateArray, l, mid-1);
    }
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0)
            return 0;
        return find(rotateArray, 0, rotateArray.size()-1);
    }
};