刷题记录

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
