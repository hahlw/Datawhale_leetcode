刷题记录

```java
// 2019-09-04 
// 28. strStr()
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
