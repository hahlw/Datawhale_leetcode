#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct zb{
    int wide;
    int high;
    zb():wide(0),high(0){}
};
static bool cmp(const zb &a,const zb &b){
	if (a.wide == b.wide)
		return a.high < b.high;
	return a.wide < b.wide;
}
void f_index(vector<int>&h,int num){
    int lo = 0;
    int n = h.size();
    int hi = n - 1;
    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        if(h[mid]>num) 
            hi = mid;
        else
            lo = mid + 1;
    }
    h[hi] = num;
}
int max_cnt(vector<int>h){
    vector<int> cur;
    cur.push_back(h[0]);
    for (int i = 1; i < h.size();i++){
        if(h[i]>=cur.back())
            cur.push_back(h[i]);
        else {
            f_index(cur, h[i]);
        }
    }
    for(auto a:cur)
        cout << a << endl;
    return cur.size();
}
int main(){
    int num;
    cin >> num;
    vector<zb> zb_v;
    while(num--){
        zb new_zb =zb();
        cin >> new_zb.wide >> new_zb.high;
        zb_v.push_back(new_zb);
    }
    sort(zb_v.begin(), zb_v.end(), cmp);
    vector<int> h_v;
    for(auto a:zb_v)
        h_v.push_back(a.high);
    for(auto a:h_v)
        cout << a << endl;
    int res = max_cnt(h_v);
    cout << res << endl;
    system("pause");
    return 0;
}