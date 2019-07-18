/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */
class Solution {
public:
      int longestValidParentheses(string s) {
		int size = s.size();
		int count = 0;
		stack<int> st;

		int start = 0;

		for(int i = 0; i < size; i++)
		{
			if(s[i] == '(')
			{
				st.push(i);
			}
			else
			{
				if(st.empty())
				{
					start = i+1;
				}
				else
				{
					//int j = st.top();
					st.pop();
					if(st.empty())
					{
						int length = i - start + 1;
						if(length > count)
						{
							count = length;
						}
						
					}
					else
					{
						int j = st.top();
						int length = i - (j + 1) + 1;
						if(length > count)
							count = length;
					}

				}
			}
		}

		return count;
		
    }


};

