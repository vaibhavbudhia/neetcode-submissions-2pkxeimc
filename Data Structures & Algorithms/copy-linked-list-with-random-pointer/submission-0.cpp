/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* temp = head;
        Node* prev = NULL;
        Node* newHead = NULL;
        unordered_map<Node*, Node*> mp;

        while(temp){
            Node* newNode = new Node (temp->val);
            
            mp[temp] = newNode;

            if(temp == head){
            newHead = newNode;
            // newHead->random = NULL;            
            }

            else {
            prev->next = newNode;            
            // newNode->random = NULL;            
            }
            prev = newNode; 

            temp = temp->next;
        }

        temp = head;

        while(temp){
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        return newHead;
    }
};
