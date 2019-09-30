//这个题应该是蛮难的一道题了，可以转换为两个链表的公共节点！
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
        if(pHead1 == NULL && pHead2 == NULL) return NULL;
        int len1 = getLength(pHead1);
        int len2 = getLength(pHead2);
        
        if(len1 < len2){
            ListNode* temp = pHead1;
            pHead1 = pHead2;
            pHead2 = temp;
        }
        int gap = len1 - len2;
        while(gap > 0){
            pHead1 = pHead1->next;
            gap--;
        }
        
        while(pHead1 != pHead2){
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
    }
    int getLength(ListNode* head){
        ListNode* cur = head;
        int length = 0;
        while(cur != NULL){
            length++;
            cur = cur->next;
        } 
        return length;
    }
};
//之后的话还要区分给定的树是什么样的书，二叉搜索树还是一般树！一般树的话应该把两个节点的路径保存起来，然后找到公共节点！
//二叉搜索树的话：如果当前节点的值值比给定的两个节点都大的话，那就在它的左子树中找，如果比给定的两个节点都小的话，那就在他的右子树中找，指导找到第一个在
//给定的两个节点中间的值！
