#include <bits/stdc++.h>
using namespace std;

class MyLinkedList {
    // Definition for singly-linked list.
    struct SinglyListNode {
        int val;
        SinglyListNode *next, *prev;
        SinglyListNode(int x) : val(x), next(NULL), prev(NULL) {}
    };
    SinglyListNode *head, *tail;
    int len;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= len) return -1;
        SinglyListNode* p = head;
        for (int i=0; i<index; ++i) p = p->next;
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        SinglyListNode *lnode = new SinglyListNode(val);
        lnode->next = head;
        if (head!=NULL) head->prev = lnode;
        head = lnode;
        ++len;
        if (len == 1) tail = head;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        SinglyListNode *lnode = new SinglyListNode(val);
        lnode->prev = tail;
        if (tail!=NULL) tail->next = lnode;
        tail = lnode;
        ++len;
        if (len == 1) head = tail;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > len) return;
        if (index == 0) addAtHead(val);
        else if (index == len) addAtTail(val);
        else {
            SinglyListNode *lnode = new SinglyListNode(val), *p = head;
            for (int i=0; i<index; ++i) p = p->next;
            p->prev->next = lnode;
            lnode->prev = p->prev;
            lnode->next = p;
            p->prev = lnode;
            ++len;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index+1 > len) return;
        if (len == 1) {
            head = tail = NULL;
            --len;
        }
        else if (index == 0) {
            head = head->next;
            head->prev = NULL;
            --len;
        }
        else if (index == len-1) {
            tail = tail->prev;
            tail->next = NULL;
            --len;
        }
        else {
            SinglyListNode *p = head;
            for (int i=0; i<index; ++i) p = p->next;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            --len;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){
    Solution cl;
    return 0;
}
