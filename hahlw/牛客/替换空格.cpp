class Solution {
public:
	void replaceSpace(char *str,int length) {
        int blankCnt=0;
        for(int i=0;i<length;i++)
            if(str[i]==' ')blankCnt++;
        for(int j=length-1;j>=0;j--){
            if(str[j]!=' ')str[j+blankCnt*2]=str[j];
            else{
                blankCnt--;
                str[j+blankCnt*2]='%';
                str[j+blankCnt*2+1]='2';
                str[j+blankCnt*2+2]='0';
            }
        }
	}
};