class Solution {
public:
	void replaceSpace(char *str,int length) {
      //Step1: 边界检查
      if(str==NULL && length < 0) return;
      int numOfBlanks = 0, oldStrLength = 0;
      int i = 0;
      //Step2：获取字符串的长度以及字符串中空格的个数
      while( str[i] != '\0')
      {
          oldStrLength++;
          if(str[i] == ' ')
          {
              numOfBlanks++;
          }
	  i++;
      }
      //Step3：计算新的字符串的长度
      int newStrLength = oldStrLength + 2 * numOfBlanks;
      //Step4: 新判断字符串长度是否越界
      if(newStrLength > length)
          return;
          
      //Step4: 倒着插入20%,因为从前往后移动的次数太多了！   
      int p1 = oldStrLenth;
      int p2 = newStrLength;
      while( p1>=0 && p1 < p2)
      {
          //思想就是遇到空格就插，没遇到就把之前的继续就好了，然后下一个！
          if(str[p1] == ' ')
          {
              str[p2--] = '0';
              str[p2--] = '2';
              str[p2--] = '%';
          }
          else
          {
              str[p2--] = str[p1];
          }
          p1--;// 控制循环的进行~
      }
      return;
	}
};
