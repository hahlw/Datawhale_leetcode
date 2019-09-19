//按行排序
//时间复杂度：O(n)，其中 n = len(s)
//空间复杂度：O(n)
class Solution {
    public String convert(String s, int numRows) {

        if (numRows == 1) return s;

        List<StringBuilder> rows = new ArrayList<>();
        for (int i = 0; i < Math.min(numRows, s.length()); i++)
            rows.add(new StringBuilder());

        int curRow = 0;
        boolean goingDown = false;

        for (char c : s.toCharArray()) {
            rows.get(curRow).append(c);
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        StringBuilder ret = new StringBuilder();
        for (StringBuilder row : rows) ret.append(row);
        return ret.toString();
    }


    //按行排序2
    //行 0 中的字符位于索引 k  = (2 * numRows  - 2) 处;
    //行 numRows-1 中的字符位于索引 k = (2⋅numRows−2)+numRows−1 处;
    //内部的 行 i 中的字符位于索引 k=(2⋅numRows−2)+i 以及 (k+1)=(2⋅numRows−2)−i 处;
    //时间空间复杂读如上
    public String convert(String s, int numRows) {

        if (numRows == 1) return s;

        StringBuilder ret = new StringBuilder();
        int n = s.length();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret.append(s.charAt(j + i));
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret.append(s.charAt(j + cycleLen - i));
            }
        }
        return ret.toString();
    }

    //技巧
    public String convert3(String s, int numRows) {

        if(numRows == 1) return s;
        //存储每一行下一次的插入下标
        int[] rowIdx = new int[numRows];
        char[] chars = new char[s.length()];
        int n = 0;
        int burketSize = numRows * 2 - 2;
        int burketNum = chars.length / burketSize; 
        int rem = chars.length % burketSize;
        for(int i = 1; i < numRows; i ++){
        	int flag = i == 1 ? 1 : 2;
        	n = flag * burketNum + (rem >= i ? ( 1 + (burketSize - rem + 1 < i ? 1 : 0)) : 0);
        	rowIdx[i] = rowIdx[i-1] + n;
        }
        int flag = -1;
        int curRow = 0;
        for(char c : s.toCharArray()){
        	chars[rowIdx[curRow]] = c;
        	rowIdx[curRow] = rowIdx[curRow] + 1;
        	 if (curRow == 0 || curRow == numRows - 1) flag = -flag;
             curRow += flag;
        }
        return new String(chars);
    }
    
    //技巧,高效
    public String convert(String s, int numRows) {
		int curRow = 0;
		// 存储当前行
		int side = numRows * 2 - 2;
		// 查找工具
		char[] chars1 = s.toCharArray();
		char[] chars2 = new char[s.length()];
		boolean turn = true;
		int j = 0, i = 0;
		if (numRows == 1) {
			return s;
		}
		while (curRow + side * j < s.length()) {
			chars2[i] = chars1[curRow + side * j];
			j++;
			i++;
		}
		curRow++;
		j = curRow;
		while (curRow != numRows - 1) {
			if (turn && j < s.length()) {
				chars2[i] = chars1[j];
				i++;
				j += side - 2 * curRow;
				turn = !turn;
				continue;
			} else if (!turn && j < s.length()) {
				chars2[i] = chars1[j];
				i++;
				j += 2 * curRow;
				turn = !turn;
				continue;
			} else {
				curRow++;
				j = curRow;
				turn = true;
				continue;
			}
		}
		j = 0;
		while (curRow + side * j < s.length()) {
			chars2[i] = chars1[curRow + side * j];
			j++;
			i++;
		}
		s = new String(chars2);
		return s;
	}
}
