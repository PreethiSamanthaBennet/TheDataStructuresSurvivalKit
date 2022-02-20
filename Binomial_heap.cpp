#include <iostream>
#include <climits>
using namespace std;

// Structure of Node
class Node{
  public:
    int data;
    int degree;
    Node* parent;
    Node* child; 
    Node* sibling;
};
/***************************************/
Node* root = NULL;

// link two heaps by making h1 as a child of h2.
int binomialLink(Node* h1, Node* h2){
    h1->parent = h2;
    h1->sibling = h2->child;
    h2->child = h1;
    h2->degree = h2->degree + 1;
}
/***************************************/
Node* createNode(int n){
    Node *new_node = new Node;
    new_node->data = n;
    new_node->parent = NULL;
    new_node->sibling = NULL;
    new_node->child = NULL;
    new_node->degree = 0;
    return new_node;
}
/***************************************/
Node *merge(Node *h1, Node *h2){

    if (h1 == NULL)
        return h2;

    if (h2 == NULL)
        return h1;

    Node *res = NULL;

    // check degree whether which one is greater or which one is smaller
    if (h1->degree <= h2->degree)
        res = h1;

    else if (h1->degree > h2->degree)
        res = h2;

    // traverse till if any of heap gets empty
    while (h1 != NULL && h2 != NULL){

        // if degree of h1 is smaller, increment h1
        if (h1->degree < h2->degree)
            h1 = h1->sibling;

        // Link h1 with h2 in case of equal degree
        else if (h1->degree == h2->degree){
            Node *sib = h1->sibling;
            h1->sibling = h2;
            h1 = sib;
        }

        // if h2 is greater
        else{
            Node *sib = h2->sibling;
            h2->sibling = h1;
            h2 = sib;
        }
    }
    return res;
}
/***************************************/
Node *Union(Node *h1, Node *h2){

    if (h1 == NULL && h2 == NULL)
       return NULL;

    Node *res = merge(h1, h2);

    // Traverse the merged list and set the values according to the degree of nodes
    Node *prev = NULL, *curr = res,
         *next = curr->sibling;

    while (next != NULL){

        if ((curr->degree != next->degree) || ((next->sibling != NULL) && (next->sibling)->degree == curr->degree)){
            prev = curr;
            curr = next;
        }
        
        else{
            if (curr->data <= next->data){
                curr->sibling = next->sibling;
                binomialLink(next, curr);
            }

            else{
                if (prev == NULL)
                    res = next;

                else
                    prev->sibling = next;

                binomialLink(curr, next);
                curr = next;
            }
        }
        next = curr->sibling;
    }
    return res;
}
/***************************************/
void Insert(int x){

    root = Union(root, createNode(x));

}
/***************************************/
void display(Node *h){

    while (h){
        cout << h->data << " ";
        display(h->child);
        h = h->sibling;
    }
}
/***************************************/
int revertList(Node*h){

    if (h->sibling != NULL){
        revertList(h->sibling);
        (h->sibling)->sibling = h;
    }

    else
        root = h;
}
/***************************************/
Node *extractMin(Node *h){

    if (h == NULL)
       return NULL;

    Node *min_node_prev = NULL;
    Node *min_node = h;

    // Find minimum value
    int min = h->data;
    Node *curr = h;
    
    //if the current sibling is not null
    while (curr->sibling != NULL){

        if ((curr->sibling)->data < min){
            min = (curr->sibling)->data;
            min_node_prev = curr;
            min_node = curr->sibling;
        }
        curr = curr->sibling;
    }
    cout << "The Minimum Element is : " << min_node->data << endl;
    
    // If there is a single Node
    if (min_node_prev == NULL && min_node->sibling == NULL)
        h = NULL;

    else if (min_node_prev == NULL)
        h = min_node->sibling;

    // Remove min node from list
    else
        min_node_prev->sibling = min_node->sibling;

    // Set root and list of min node
    if (min_node->child != NULL){
        revertList(min_node->child);
        (min_node->child)->sibling = NULL;
    }
    // Do union of root h and children
    return Union(h, root);

}
/***************************************/
Node *Search(Node *h, int data){

    if (h == NULL)
        return NULL;

    // check if key is equal to the root's data
    if (h->data == data)
        return h;

    Node *res = Search(h->child, data);
    
    if (res != NULL)
       return res;

    return Search(h->sibling, data);
}
/***************************************/

void decreaseKey(Node *H, int old_data,int new_data){

    // First check whether element is present or not
    Node *node = Search(H, old_data);

    // return if the Node is not present
    if (node == NULL)
        return;

    // Reduce the value to the minimum
    node->data = new_data;
    Node* parent = node->parent;

    // Update the heap according to reduced value
    while (parent != NULL && node->data < parent->data){
        swap(node->data, parent->data);
        node = parent;
        parent = parent->parent;
    }
}
/***************************************/
Node *deleteNode(Node *h, int data){

    // Check if heap is empty or not
    if (h == NULL)
        return NULL;

    // Reduce the value of element to minimum
    decreaseKey(h, data, INT_MIN);

    // Delete the minimum element from heap
    return extractMin(h);
}
/***************************************/
int main(){


    Node*p;
    Node *H;
    
    int choice, x, y, z;
    
    cout << "Insert an Element: 1 \n";
    cout << "Extract the Minimum Element: 2 \n";
    cout << "Decrease Key: 3 \n";
    cout << "Delete an Element: 4 \n";
    cout << "Display Heap: 5\n";
    cout << "Exit: 6\n\n";
  
  
    do{
        cout << "\nEnter your choice : ";
        cin >> choice;
  
        switch(choice){
    
            case (1):
                cout << "Enter the value to be Inserted to the Heap : ";
                cin >> x;
                Insert(x);
                break;
                
            case (2):
                p = extractMin(root);
                break;
        
            case (3):
                cout << "Enter the key to be decreased: ";
                cin >> x;
                cout << "Enter the new key value: ";
                cin >> y;
                decreaseKey(root, x, y);
                break;
                
            case (4):
                cout << "Enter the key to be deleted: ";
                cin >> z;
                root = deleteNode(root, z);
                break;
                
            case (5):
                display(root);
                cout << endl;
                break;
                
            case (6):
                break;
                
            default:
                cout << "Enter a value between 1 and 6 \n";
        }
    }while(choice != 6);

    return 0;
}


