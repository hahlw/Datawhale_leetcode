/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */
class Solution {
public:
    int ladderLength1(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>word_set(wordList.begin(),wordList.end());
        if(!word_set.count(endWord))return 0;
        unordered_map<string,int>pathcnt;
        pathcnt[beginWord]=1;
        queue<string>q;
        q.push(beginWord);
        while(!q.empty()){
            string word=q.front();
            q.pop();
            for(int i =0;i<word.size();i++){
                string newword=word;
                for(char ch='a';ch<='z';ch++){
                    newword[i]=ch;
                    if(word_set.count(newword)&&newword==endWord)return pathcnt[word]+1;

                    if(word_set.count(newword)&&!pathcnt.count(newword)){
                        q.push(newword);
                        pathcnt[newword]=pathcnt[word]+1;
                    }
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>word_set(wordList.begin(),wordList.end());

        queue<string>q;
        q.push(beginWord);
        int res=0;

        while(!q.empty()){
            int ss=q.size();

            for(int i =0;i<ss;i++){
                string word=q.front();q.pop();
                if(word==endWord)return res+1;
                for(int j=0;j<word.size();j++){
                    string new_word=word;
                    for(char ch='a';ch<='z';ch++){
                        new_word[j]=ch;
                        if(word_set.count(new_word)&&new_word!=word){
                            q.push(new_word);
                            word_set.erase(new_word);
                        }    
                    }
                }   
            }
            res++;
        }
        return 0;
    }
};

