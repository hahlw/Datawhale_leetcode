/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */
class Solution {
public:
	/*
		首先判断两个数组的总长度，如果是奇数直接查找total/2，如果是偶数则需要计算total/2和total/2+1的和然后求平均。
	*/
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total=nums1.size()+nums2.size();
        if(total%2==0){
            return (findK(nums1,0,nums2,0,total/2)+findK(nums1,0,nums2,0,total/2+1))/2.0;
        }
        else{
            return findK(nums1,0,nums2,0,total/2+1);
        }
    }
    /*
		找第K个数。
		我们用每个数组当前查找的位置和数组的长度来计算当前可以查找的长度。
		我们每次都保证可查长度较短的为num1，较长的为num2.
		举个例子：
		1.如果k==1，此时我们直接返回两个数组的第一个数字的最小值即可。
		2.如果当前的num1的可查长度为0，那么第K个数就是num2[j+k-1].(j是num2可查位置的下标)
		3.如果待查的k/2大于num1的可查长度（left=num1.size(）-i)，那么我们在num1里面查left的长度，在num2里面查k-left的长度。
		4，一直递归下去。 
	*/
    int findK(vector<int>nums1,int i,vector<int>&nums2,int j,int k){
        /*
        i,j分别是接下来在nums1和nums2要查的起始位置
         */
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1-i>n2-j)return findK(nums2,j,nums1,i,k);
        else if((n1-i)==0)return nums2[j+k-1];
        else if(k==1)return min(nums1[i],nums2[j]);
        else{
            int left=min(k/2,n1-i);
            int right=k-left;
            if(nums1[i+left-1]==nums2[j+right-1]){
                return nums1[i+left-1];
            }
            else if(nums1[i+left-1]>nums2[j+right-1]){
                return findK(nums1,i,nums2,j+right,k-right);
            }
            else{
                return findK(nums1,i+left,nums2,j,k-left);
            }

        }
    }
};

