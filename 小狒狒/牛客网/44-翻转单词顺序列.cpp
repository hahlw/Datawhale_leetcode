//二刷！加油！
class Solution {
public:
    void Reverse( string &str, int s, int e)
    {
        while(s<e){
            swap(str[s++], str[e--]);//注意这里的自增自减运算！
        }
    }
    
    string ReverseSentence(string str) {
        //Step1:先整体进行翻转
        Reverse(str, 0, str.size()-1);
        int s = 0, e = 0;
        int i = 0;//用来挨个翻转每个单词！
        while(i<str.size()){
            //遇到空格，直接跳过
            while(i<str.size() && str[i] == ' '){
                i++;//目的是要调到下一个单词
            }
            e = s = i;//记录单词的第一个字符的位置
            //如果当前i不是空格，那就找这个单词的最后一个字符，也就是一直找到那个使得str[i] == ' '的i的位置！
            while(i<str.size() && str[i] != ' '){
                i++;
                e++;
            }
            //找到之后就交换
            Reverse(str, s, e-1);//翻转这个单词！
        }
        return str;
    }
};
