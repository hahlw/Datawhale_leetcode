class Solution
{
public:
  //Insert one char from stringstream
    string s;
    char hash[256] = {0};
    void Insert(char ch)
    {
        s += ch;//把字符流中一个一个的字符存入到字符串！
        hash[ch]++;//把每个字符添加到hash表中！
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        //当所有的流种得字符都添加到hash表后，进行判断！
        for(int i=0; i<s.size(); i++){
            //如果是第一个第一次出现的，那就直接return就好了！第一个第一次出现的一定是1！！！
            if(hash[s[i]] == 1)
                return s[i];
        }
        return '#';
    }
};
