class Solution {
public:
	string longestPalindrome(string s) {

		int n = s.size();
		if (n <= 1) return s;

		bool *dp = (bool *)new bool[n*n];

		int maxlength = 0;
		int pos = 0;

		for (int i = 0; i < n; i++)
		{
			*(dp + i*n + i) = true;

			if (1 > maxlength)
			{
				maxlength = 1;
				pos = i;
			}

			if (i + 1 < n)
			{
				if (s[i] == s[i + 1])
				{
					*(dp + i*n + i + 1) = true;

					if (2 > maxlength)
					{
						maxlength = 2;
						pos = i;
					}
				}
				else
				{
					*(dp + i*n + i + 1) = false;
				}

			}
		}

		for (int j = 2; j < n; j++)
		{
			for (int i = 0; i < n - j; i++)
			{
				if (*(dp + (i + 1)*n + j + i - 1) == true && s[i] == s[j + i])
				{
					*(dp + i*n + j  + i) = true;
					int length = j + 1;
					if (length > maxlength)
					{
						maxlength = length;
						pos = i;
					}
				}
				else
				{
					*(dp + i*n + j + i) = false;
				}

			}
		}

		delete[] dp;
		return s.substr(pos,  maxlength );

	}

};