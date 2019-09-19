刷题记录

2019-09-18

50. Pow(x, n)

```java
class Solution {
    public double myPow(double x, int n) {
        long N = n;
        if (N < 0){
            x = 1 / x;
            N = -N;
        }
        return pow(x, N);
    }
    
    private double pow(double x, long n){
        if(n == 0)
            return 1.0;
        double half = pow(x, n/2);
        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
}
```

2019-09-17

58. Length of Last Word

```java
class Solution {
    public int lengthOfLastWord(String s) {
        int count = 0, r = s.length() - 1;
        boolean begin = false;
        for(;r >= 0; r--){
            if(s.charAt(r) == ' ' && !begin)
                continue;
            
            if(Character.isLetter(s.charAt(r))){
                count ++;
                begin = true;
            }
            else if(begin)
                break;
        }
        return count;
    }
}
```

2019-09-16

1191. K-Concatenation Maximum Sum

```python
class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        def kadane(arr):
            cur_ans, ans = 0, 0
            for num in arr:
                cur_ans = max(cur_ans + num, num)
                ans = max(ans, cur_ans)
            return ans
        
        if k == 1:
            return kadane(arr)
        
        s = sum(arr)
        if s <= 0:
            return kadane(arr*2) %  (10**9+7)
        else:
            return (s * (k-2) + kadane(arr*2)) % (10**9+7)
```


2019-09-15

1189. Maximum Number of Balloons

```python
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        # b a l o n
        count = [0, 0, 0, 0, 0]
        for i in range(len(text)):
            if text[i] == 'b':
                count[0] += 1
            elif text[i] == 'a':
                count[1] += 1
            elif text[i] == 'l':
                count[2] += 1
            elif text[i] == 'o':
                count[3] += 1
            elif text[i] == 'n':
                count[4] += 1
        return min(min(min(min(count[0], count[1]), count[2] // 2), count[3]//2), count[4])
```

2019-09-10

274. H-index

```java
class Solution {
    public int hIndex(int[] citations) {
        if(citations.length == 0)
            return 0;
        Arrays.sort(citations);
        int count = 0;
        for(int i = citations.length - 1; i >= 0; i--){
            if(citations[i] >= citations.length - i){
                count ++;
            }
            else{
                break;
            }
        }
        return count;
    }
}
```


2019-09-09

69. Sqrt(x)

```java
class Solution {
    public int mySqrt(int x) {
        long a = x;
        while (a * a > x) {
            a = (a + x / a) / 2;
        }
        return (int)a;
    }
}
```

2019-09-08

14. Longest Common Prefix

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0)
        	return "";
        String prefix = strs[0];
        for(int i = 1; i < strs.length; i++) {
        	while (strs[i].indexOf(prefix) != 0) {
        		prefix = prefix.substring(0, prefix.length()-1);
        		if (prefix.isEmpty())
        			return "";
        	}
        }
        
        return prefix;
    }
}
```

2019-09-07

299. Bulls and Cows

```java
public String getHint(String secret, String guess) {
    int A = 0, B = 0;
    ArrayList<Character> list = new ArrayList<>();
    HashMap<Character, Integer> hashmap = new HashMap<>();
    for(int i = 0; i < secret.length(); i++) {
	char current = secret.charAt(i);
	if (secret.charAt(i) == guess.charAt(i))
	    A++;
	else {
	    list.add(guess.charAt(i));
	    if (hashmap.containsKey(current))
		hashmap.put(current, hashmap.get(current) + 1);
	    else
		hashmap.put(current, 1);
	}
    }

    for(Character i : list) {
	if (hashmap.containsKey(i)){
	    B++;
	    hashmap.put(i, hashmap.get(i) - 1);
	    if (hashmap.get(i) == 0)
		hashmap.remove(i);
	}
    }
    return A + "A" + B + "B";
}
```


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
