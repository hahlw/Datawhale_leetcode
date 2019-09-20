/*
其一，对于链表问题，使用快慢指针可以判断是否有环。
其二，本题可以使用数组配合下标，抽象成链表问题。但是难点是要定位环的入口位置。
其三，快慢指针问题，会在环内的[9]->1->5->3->6->8->7->[9]任何一个节点追上，不一定是在[9]处相碰，事实上会在7处碰上。
其四，必须另起一个for循环定位环入口位置[9]。这里需要数学证明。
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        for(int fast = 0; res != fast || fast == 0;) {
            res = nums[res];
            fast = nums[nums[fast]];
        }
        for(int i = 0 ; res != i; i = nums[i]) {
            res = nums[res];
        }
        return res;
    }
};
