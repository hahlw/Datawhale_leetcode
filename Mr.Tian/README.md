刷题记录

2019-09-06

41. First Missing Positive

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        if(nums.length == 0)
            return 1;
        for(int i = 0; i < nums.length; i++){
            while(nums[i] > 0 && nums[i] < nums.length){
                int temp = nums[nums[i] - 1];
                if(temp == nums[i])
                    break;
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }
        
        for(int i = 0; i < nums.length; i++){
            if (nums[i] != i+1)
                return i+1;
        }
        return nums.length + 1;
    }
}
```

2019-09-05

189. Rotate Array
```java
class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n;
        int temp;
        for (int i = 0; i < k; i++) {
        	temp = nums[n-1];
        	for(int j = n-1; j > 0; j--) {
        		nums[j] = nums[j - 1];
        	}
        	nums[0] = temp;
        }
    }
}
```

2019-09-04 

28. strStr()
```java
public int strStr(String haystack, String needle) {
    if(needle.length() == 0)
	return 0;
    int l = 0;
    String current = null;
    while(haystack.length() - l >= needle.length()) {
	current = haystack.substring(l, l + needle.length());
	if(current.equals(needle))
	    return l;
    }	
    return 0;
}
```
