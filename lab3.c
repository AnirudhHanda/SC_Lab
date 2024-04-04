#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

// Forward declaration of addSorted function
void addSorted(LinkedList *list, int data);

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addLast(LinkedList *list, int data) {
    Node *newNode = createNode(data);
    list->size++;
    if(list->head == NULL) {
        list->head = list->tail = newNode;
        return;
    }
    
    list->tail->next = newNode;
    list->tail = newNode;
}

void create(LinkedList *list, int n) {
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        addSorted(list, data); // Now addSorted is properly declared
    }
}

void addSorted(LinkedList *list, int data) {
    Node *newNode = createNode(data);
    list->size++;
    
    if(list->head == NULL || list->head->data >= data) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node *current = list->head;
        while(current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    
    if(newNode->next == NULL) {
        list->tail = newNode;
    }
}

void print(LinkedList *list) {
    Node *ptr = list->head;
    while(ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

LinkedList* createList() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = list->tail = NULL;
    list->size = 0;
    return list;
}

// Rest of your code remains unchanged

LinkedList* unionOperation(LinkedList *setA, LinkedList* setB){
    LinkedList *result = createList();
    Node *ptr1 = setA->head;
    Node *ptr2 = setB->head;
    
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->data < ptr2->data){
            addLast(result, ptr1->data);
            ptr1 = ptr1->next;
        } else if(ptr2->data < ptr1->data){
            addLast(result, ptr2->data);
            ptr2 = ptr2->next;
        } else{
            addLast(result, ptr1->data);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    
    while(ptr1 != NULL){
        addLast(result, ptr1->data);
        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL){
        addLast(result, ptr2->data);
        ptr2 = ptr2->next;
    }
    
    return result;
}

LinkedList* intersectionOperation(LinkedList *setA, LinkedList *setB){
    LinkedList *result = createList();
    Node *ptr1 = setA->head;
    Node *ptr2 = setB->head;
    
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->data == ptr2->data){
            addLast(result, ptr1->data);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if(ptr1->data < ptr2->data){
            ptr1 = ptr1->next;
        } else{
            ptr2 = ptr2->next;
        }
    }
    
    return result;
}

int testDistributivity(LinkedList *setA, LinkedList *setB, LinkedList *setC){
    LinkedList *BintC = intersectionOperation(setB, setC);
    LinkedList *AunBintC = unionOperation(setA, BintC);
    
    LinkedList *AunB = unionOperation(setA, setB);
    LinkedList *AunC = unionOperation(setA, setC);
    LinkedList *AunBintAunC = intersectionOperation(AunB, AunC);
    
    printf("A U (B int C): ");
    print(AunBintC);
    printf("(A U B) int (A U C): ");
    print(AunBintAunC);
    
    Node *ptr1 = AunBintC->head;
    Node *ptr2 = AunBintAunC->head;
    
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data != ptr2->data){
            return 0;
        } else {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    
    return 1;
}

int testCom(LinkedList *setA, LinkedList *setB){
    LinkedList *result1 = unionOperation(setA, setB);
    LinkedList *result2 = unionOperation(setB, setA);
    
    printf("A U B: ");
    print(result1);
    printf("B U A: ");
    print(result2);
    
    Node *ptr1 = result1->head;
    Node *ptr2 = result2->head;
    
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data != ptr2->data){
            return 0;
        } else {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    
    return 1;
}

int testAssocitativity(LinkedList *setA, LinkedList *setB, LinkedList *setC){
    LinkedList *BunC = unionOperation(setB, setC);
    LinkedList *AunBunC1 = unionOperation(setA, BunC);
    
    LinkedList *AunB = unionOperation(setA, setB);
    LinkedList *AunBunC2 = unionOperation(AunB, setC);
    
    printf("A U (B U C): ");
    print(AunBunC1);
    printf("(A U B) U C: ");
    print(AunBunC2);
    
    Node *ptr1 = AunBunC1->head;
    Node *ptr2 = AunBunC2->head;
    
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data != ptr2->data){
            return 0;
        } else {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    
    return 1;
}

int main()
{
    int lA, lB, lC;
    printf("Enter lA, lB and lC: ");
    scanf("%d %d %d", &lA, &lB, &lC);
    
    LinkedList *setA = createList();
    LinkedList *setB = createList();
    LinkedList *setC = createList();
    printf("Enter SetA: \n");
    create(setA, lA);
    printf("Enter SetB: \n");
    create(setB, lB);
    printf("Enter SetC: \n");
    create(setC, lC);
    printf("SetA: ");
    print(setA);
    printf("SetB: ");
    print(setB);
    printf("SetC: ");
    print(setC);
    
    if(testCom(setA, setB)){
        printf("\nCommutativity: TRUE\n");
    } else{
        printf("\nCommutativity: FALSE\n");
    }
    
    int distTest = testDistributivity(setA, setB, setC);
    if(distTest){
        printf("\nDistributivity: TRUE\n");
    } else{
        printf("\nDistributivity: FALSE\n");
    }
    
    int assTest = testAssocitativity(setA, setB, setC);
    if(assTest){
        printf("\nAssociativity: TRUE");
    } else{
        printf("\nAssociativity: FALSE");
    }

    printc("\n");

    return 0;
}
