#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};
Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(Node* head){
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;

    head->prev = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}
Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* newTail = tail->prev;
    newTail->next = nullptr;
    tail->prev = nullptr;
    delete tail;
    return head;
}
Node* deleteKthElement(Node* head, int k){
    if(head == NULL) {
        return NULL;
    } 
    int cnt = 0;
    Node* kNode = head;
    while(kNode != NULL) {
        cnt++;
        if(cnt == k) break;
        kNode = kNode->next;
    }
    Node* prev = kNode->prev;
    Node* front = kNode->next;

    if(prev == NULL && front == NULL){
        return NULL;
    }
    else if(prev == NULL) {
        return deleteHead(head);
    }
    else if(front == NULL) {
        return deleteTail(head);
    }
    prev->next = front;
    front->prev = prev;

    kNode->next = nullptr;
    kNode->prev = nullptr;
    delete kNode;
    return head;
}
void deleteGivenNode(Node* temp){
    Node* prev = temp->prev;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = nullptr;
        temp->prev = nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->prev = prev;

    temp->next = temp->prev = nullptr;
    free(temp);
}
Node* insertBeforeHead(Node* head, int val) {
    Node* newHead = new Node(val, head, nullptr);
    head->prev = newHead;

    return newHead;
}
int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    head = insertBeforeHead(head, 10);
    print(head);
    return 0;
}