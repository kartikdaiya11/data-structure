// Inserting Node at nth position in linked list

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


struct Node *Insert(struct Node* head, int data, int n){

    static int track = 1;
    int i;

    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next = NULL;

    if (n <= track){
        if (n == 1){
            temp1->next = head;
            head = temp1;
            track++;
            return head;

        }
        struct Node* temp2 = head;


        for (i = 0; i< n-2; i++){
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
        track++;
        return head;

    }
    else {
        printf("please enter valid position.");
        exit(0);
    }

}

void Print(struct Node *head){

    while (head!= NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){

    struct Node* head=NULL;

    int i, numbers, pos, value;

    printf("how many numbers");
    scanf("%d", &numbers);

    for (i = 0; i < numbers; i++){
        printf("Enter number and position: ");
        scanf("%d %d",&value, &pos);
        head = Insert(head, value, pos);
        Print(head);
    }
//    Insert(2, 1);   //2
//    Insert(3, 2);   //23
//    Insert(4, 1);   //423
//    Insert(5, 2);   //4523


    return 0;

}
