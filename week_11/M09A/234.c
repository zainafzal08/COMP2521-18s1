typedef struct _Item {
    int  key;
    // other fields as needed by application
} Item;
typedef struct _Node {
    int  order;    // 2, 3 or 4
    Item data[3];  // items in node
    Link child[4]; // links to subtrees
} Node;
typedef struct _Node* Link;
Link newNode(Item it); // creates new 2-node

int promote(Link p, Link c, Item *ret) {

}
