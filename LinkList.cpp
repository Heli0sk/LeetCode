#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 65;
const int INF=0x3f3f3f3f;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* CreatLinkList(int *nums, int n){
	cout<<"\n===== Creating LinkList ====="<<endl;
	ListNode *head = new ListNode(-1), *cur;
	ListNode *realHead = head;
	for(int i=0;i<n;i++){
		cur = new ListNode(nums[i]);
		head->next = cur;
		head = head->next;
		cout<<nums[i]<<" ";
	}
	head = realHead->next;
	delete realHead;
	cout<<endl<<"===== Creat Complete =====\n"<<endl;
	return head;
}


void AddtoTail(ListNode *head, int num){
	ListNode *tmp = new ListNode(num);
	ListNode *cur = head;
	while(cur->next!=NULL){
		cur = cur->next;
	}
	cur->next = tmp;
}

// 需要注意的是，对于头插操作，则必须使用指针的引用或者二级指针等方式，
// 否则，使用按值传递的方式进行修改，可能会导致链表无法发生头插操作。
void AddtoHead(ListNode *&head, int num){
    ListNode *cur = new ListNode(num, head);
    head = cur;
}

// 删除第n个节点
int deleteNodebyIndex(ListNode *&head, int n){
	int removedValue = 0;
	if (n == 1) {
        ListNode *newHead = head->next;
        removedValue = head->val;
        delete head;
        head = newHead;
        return removedValue;
    }
    ListNode *cur = head;
    // cur->next 是要被删除的节点
    for (int i = 2; i < n && cur != NULL; i++)
        cur = cur->next;

    if (cur == NULL || cur->next == NULL) {
		cout<<"ERROR! The index is bigger than the length of linklist !"<<endl;
		return removedValue;
    }
    ListNode *tmp = cur->next;
    cur->next = tmp->next;
    removedValue = tmp->val;
    delete tmp;
    return removedValue;
}

// 删除所有值为num的节点，使用了虚拟头结点
void deleteNodebyValue(ListNode *&head, int num){
	ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *cur = dummy;
    while (cur != NULL && cur->next != NULL) {
        if (cur->next->val == num) {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        } else {
            cur = cur->next;
        }
    }
    head = dummy->next;
    delete dummy;
}

// 修改第n个节点的值为newValue
void ModifyNodebyIndex(ListNode *head, int n, int newValue){
	for(int i=1;i<n;i++)
		head = head->next;
	head->val = newValue;
}

int GetLength(ListNode *head){
	int length = 0;
	while(head!=NULL){
		length++;
		head = head->next;
	}
	return length;
}

// ��������
int SearchNode(ListNode *head, int target){
	return 0;
}

void PrintLinkList(ListNode *head){
	while(head){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}


void DestoryLink(ListNode *head){
	if(head==NULL){
		cout<<"===== The LinkList is NULL ====="<<endl;
		return;
	}
	cout<<"\n===== Destory LinkList ====="<<endl;
	ListNode *cur = head->next;
	
	while(cur){
		cout<<head->val<<" ";
		delete head;
		head = cur;
		cur = cur->next;
	}
	cout<<head->val<<" ";
	delete head;
	cout<<endl<<"===== Destory Complete ====="<<endl;
}


ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *fast = head, *slow = head;
	for(int i=0;i<n;i++)
		fast = fast->next;

	if(fast == NULL){
		ListNode *newHead = head->next;
		delete head;
		return newHead;
	}

	while(fast->next){
		fast = fast->next;
		slow = slow->next;
	}

	ListNode *tmp = slow->next;
	slow->next = tmp->next;
	delete tmp;
	return head;
}

// the list is sorted
ListNode* deleteDuplicates(ListNode* head) {
	if(head == NULL) return head;
	ListNode *cur = head;
	while(cur->next){
		if(cur->val == cur->next->val){
			cur->next = cur->next->next;
		}
		else cur = cur->next;
	}
	return head;
	
}


ListNode* rotateRight(ListNode* head, int k) {
	if(head == NULL) return head;
	int length = 0;
	ListNode *cur = head;
	while(cur!=NULL){
	    ++length;
	    cur = cur->next;
	}
	cout<<"Before %: "<<k<<endl;
	k = k % length;
	cout<<"After %: "<<k<<endl;
	// k < length now;
	ListNode *fast = head, *slow = head;
	while(k--){
		cout<<k;
	    fast = fast->next;
	    cout<<"--|";
	}
	cout<<fast->val<<endl;
	while(fast->next){
	    fast = fast->next;
	    slow = slow->next;
	}
	cout<<fast->val<<"  "<<slow->val<<endl;
	fast->next = head;
	head = slow->next;
	slow->next = NULL;
	return head;
}


ListNode* swapPairs(ListNode* head) {
	if(head == NULL || head ->next == NULL) return head;
	ListNode *slow = head, *fast = head->next, *dummy = new ListNode(0, head);
	head = dummy;
	while(fast->next && fast->next->next){
		slow->next = fast->next;
		fast->next = slow;
		dummy->next = fast;
		dummy = slow;
		slow = slow->next;
		fast = slow->next;
	}
	dummy->next = fast;
	slow->next = fast->next;
	fast->next = slow;
	dummy = head;
	head = dummy->next;
	delete dummy;
	return head;
}

// REVERSE the List
ListNode* reverseList(ListNode* head) {
	if(head == NULL) return head;
	ListNode *fast=head, *slow=NULL, *t=fast->next;
	while(fast){
		t=fast->next;
		fast->next = slow;
		slow = fast;
		fast = t;
	}
	return slow;
}


ListNode* FindKthToTail(ListNode* pListHead, int k) {
	ListNode *fast = pListHead, *slow = pListHead;
	for(int i=0;i<k;i++)
		fast = fast->next;
	if(fast == NULL) return pListHead;
	while(fast){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

int main()
{

	int nums[] = {1,2,3,4,5,6};
//	int length;
	ListNode *head = CreatLinkList(nums, 6);
	ListNode *res = FindKthToTail(head, 4);
	cout<<res->val<<endl;
	PrintLinkList(head);
	DestoryLink(head);

	return 0;
}

