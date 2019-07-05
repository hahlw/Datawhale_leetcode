public class PalindromicSubstrings{
	
	public int countSubstrings(String s) {
		int ans = 0;
		
		for (int i = 0; i < s.length(); i ++) {
			ans += check(s, i, i);
			ans += check(s, i, i+1);
		}
		
		return ans;
	}
	
	private int check(String s, int i, int j) {
		int count = 0;
		while (i >= 0 && j <= s.length() && s.charAt(i) == s.charAt(j)) {
			i --;
			j ++;
			count ++;
		}
		return count;
	}

}
