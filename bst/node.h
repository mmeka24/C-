class Node {
public:
    // Constructor
    Node(int newData);
    ~Node();

    void setNext(Node*);
    Node* getNext();
    void setRight(Node*);
    void setLeft(Node*);
    Node* getLeft();
    Node* getRight();
    int getValue(); //return type = int 
    int getData(); 

    // Pointers
    Node* next;
    Node* left;
    Node* right;
    char* dataStr; 
    int data; //  variable to hold integer data
};
