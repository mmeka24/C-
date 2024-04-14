class Node {
public:
    // Constructor
    Node(int newData);
    ~Node();

    void setNext(Node*);
    void setRight(Node*);
    void setLeft(Node*);
    Node* getNext();
    Node* getLeft();
    Node* getRight();
    int getValue(); //return type = int 
    int getData(); 

    // Pointers
    Node* next;
    Node* left;
    Node* right;
    Node* parent; 
    char* dataStr; 
    int data; //  variable to hold integer data
    int color; // 0 is red, 1 is black 
};