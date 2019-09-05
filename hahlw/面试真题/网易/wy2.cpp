#include<bits/stdc++.h>
using namespace std;

int max_len(char* str) {
	int res = -1;
	int k = 2;
	int lo = 0, hi = 0, len = strlen(str);
    int fir = -1, sec = -1;
    if (len <= 2){
		return len;
    }
	while (k >= 0 && hi<len) {
		if (str[hi++] != 'N'){
            if(k==2&&fir==-1){
                fir = hi - 1;
            }
            if(k==1&&sec==-1){
                sec = hi - 1;
            }
            k--;
        }
		if (k >= 0) {
			res = max(res, hi - lo);
		}
		if (k<0) {
            int tmp=hi-1;
            lo = fir + 1;
            fir = sec;
            sec = tmp;
            k++;
        }
	}
	return res;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
        char str[50001];
        cin >> str;
        int res = max_len(str);
        cout << res << endl;
	}
	//system("pause");
	return 0;
}