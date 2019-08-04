//【方法一】奇妙的方法，没理解
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        while( p1 != p2 ){
            if(p1 != NULL) p1=p1->next;
            if(p2 != NULL) p2=p2->next;
            if( p1!=p2 ){                                                                                                                                                                                                                                                                                                                                                                                 
                if( p1 == NULL) p1 = pHead2;
                if( p2 == NULL) p2 = pHead1;
            }
        }
        return p1;
    }
};
//【方法二】：常规，利用长度差，复杂度m+n
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL || pHead2 == NULL) return NULL;
        int length1 = getLength(pHead1);
        int length2 = getLength(pHead2);
        if(length2 > length1){
            ListNode *temp = pHead1;
            pHead1 = pHead2;
            pHead2 = temp;
        }
        int gap = length1 - length2;
        //让长的先走，一直到走到一起！
        while(gap>0){
            pHead1 = pHead1->next;
            gap--;
        }
        //这个才是核心，上面的是为了保证一次一起遍历！
        //如果不相等就各自一起一齐走！走到相等为止！
        while(pHead1 != pHead2){
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
    }
    
    int getLength(ListNode* pHead){
        ListNode *cur = pHead;
        int result = 0;
        while(cur != NULL){
            result++;
            cur = cur->next;
        }
        return result;
    }
};
