class MyLinkedList {
public:
        int val;
        MyLinkedList* next;

    MyLinkedList() {
        val = 0;
        next = NULL;
    }
    
    MyLinkedList* head = NULL;
    
    int get(int index) {
        int count = 0;
        MyLinkedList* temp = head;
            
        while(count<index && temp){
            temp = temp->next;
            count++;
        }
        if(temp == NULL) return -1;
        return temp->val;
    }
    
    void addAtHead(int val) {
        MyLinkedList* newNode = new MyLinkedList();
        newNode->val = val;
        newNode->next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        MyLinkedList* newNode = new MyLinkedList();
        newNode->val = val;

        if(head == NULL){
            head = newNode;
            return;
        }

        MyLinkedList* temp = head;
        while(temp->next){
            temp = temp->next;
        }

        temp->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
         if (index == 0) {
            addAtHead(val);
            return;
        }

        MyLinkedList* temp = head;
        while(temp && index>1){
            temp = temp->next;
            index --;
        }

        if (temp == NULL) return;

        MyLinkedList* newNode = new MyLinkedList();
        newNode -> val = val;
        MyLinkedList* front = temp->next;
        temp->next = newNode;
        newNode->next = front;
    }
    
    void deleteAtIndex(int index) {
         if (head == NULL)
            return;

        if (index == 0) {
            head = head->next;
            return;
        }

        MyLinkedList* temp = head;

        while (temp && index > 1) {
            temp = temp->next;
            index--;
        }

        if (temp == NULL || temp->next == NULL)
            return;

        temp->next = temp->next->next;
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