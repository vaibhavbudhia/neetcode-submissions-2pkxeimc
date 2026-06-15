class BrowserHistory {
struct Listnode{
    public:
    string val;
    Listnode* next;
    Listnode* prev;

    Listnode(string val){
        this->val = val;
        next = NULL;
        prev = NULL;    
    }
};
    Listnode* curr; 

public:
    BrowserHistory(string homepage) {
        curr = new Listnode(homepage); 
    }
    
    void visit(string url) {
        Listnode* newNode = new Listnode(url);         
        curr->next = newNode;
        newNode->prev = curr;

        curr = curr->next;
    }
    
    string back(int steps) {
        while(curr->prev && steps>0){
            curr = curr->prev;
        steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(curr->next && steps>0){
            curr = curr->next;
        steps--;
        }
        return curr->val;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */