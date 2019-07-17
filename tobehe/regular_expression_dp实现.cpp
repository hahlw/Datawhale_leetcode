class Solution {
public:
bool isMatch(string s, string p)
{
	int sdim = s.size();
	int pdim = p.size();

	if (pdim == 0) return sdim == 0;
	if (pdim == 1) return (sdim == 1) && (s[0] == p[0] || p[0] == '.');

	bool **t = new bool *[pdim + 1];

	for (int i = 0; i < pdim + 1; i++)
	{
		t[i] = new bool[sdim + 1];
	}

	t[0][0] = 1;

	for (int i = 1; i < sdim + 1; i++)
	{
		t[0][i] = 0;
	}

	for (int i = 1; i < pdim + 1; i++)
	{
		t[i][0] = p[i - 1] != '*' ? false : i == 1 ? false : (t[i - 1][0] || t[i - 2][0]);
	}

	for (int i = 1; i < pdim + 1; i++)
	{
		for (int j = 1; j < sdim + 1; j++)
		{
			if (p[i - 1] == s[j - 1] || p[i - 1] == '.')
			{
				t[i][j] = t[i - 1][j - 1];
			}
			else
			{
				if (p[i - 1] == '*')
				{
					t[i][j] = ((i > 1&&(p[i-2]==s[j-1] || p[i - 2] == '.')&&t[i ][j - 1]))||t[i - 1][j] || ((i > 1)&&t[i - 2][j]);
				}
				else
				{
					t[i][j] = 0;
				}
			}
		}
	}

	bool res = t[pdim][sdim];
	for (int i = 0; i < pdim; i++)
	{
		delete [] t[i];
        t[i] = NULL;
	}

	delete [] t;
    t = NULL;


	return res;
}
};