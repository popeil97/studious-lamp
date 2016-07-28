# studious-lamp
Stack Data Structure in C++ using nodes, not arrays

class Stack {

private:
    Node *top = nullptr;
    bool empty = false;
   
public:
    void push(int num) {
        if(top == nullptr) {
            top = createNode(num);
        }
        
        else {
            Node *temp = top;
            top = createNode(num);
            top->down = temp;
        }
    }
    
    void pop() {
        
        if(top->down == nullptr) {
            cout << "Stack is Empty" << endl;
            empty = true;
        }
        
        else {
            top = top->down;
        }
    }
    
    double getTop() {
        return top->value;
    }
    
    bool isEmpty() {
        if(empty) {
            return true;
        }
        
        else {
            return false;
        }
    }
    
    Node* createNode(int num) {
        Node *node = new Node;
        node->value = num;
        node->down = nullptr;
        return node;
    }
    
    void printStack() {
        Node *iterator = top;
        
        while(iterator != nullptr) {
            cout << iterator->value << " ";
            iterator = iterator->down;
        }
        
        cout << endl;
    }
    
    
};
