// https://www.codechef.com/FLPAST01/problems/POLMUL
// Is this FFT ?
// polynomial multiplication using linked lists
// Status: All test cases passed

#include<stdio.h>
#include<stdlib.h>

struct node{
   long long int coefficient;
   long long int degree;
   struct node* next; 
};

typedef struct node node;

node* createNode(long long int coefficient,long long int degree){
    node* temp = (node*)malloc(sizeof(node));
    if(temp != NULL){
        temp->coefficient = coefficient;
        temp->degree = degree;
        temp->next = NULL;
    }
    return temp;
}

void input(node **p, node **q,int N, int M){
    node* temp;
    long long int coeff;

    // taking first polynomial
    scanf("%lld",&coeff);
    *p = createNode(coeff,0);
    temp = *p;
    for(int i = 1 ; i < N ; i++){
        scanf("%lld",&coeff);
        temp->next = createNode(coeff,i);
        temp = temp->next;
    }

    // taking second polynomial
    scanf("%lld",&coeff);
    *q = createNode(coeff,0);
    temp = *q;
    for(int i = 1 ; i < M ; i++){
        scanf("%lld",&coeff);
        temp->next = createNode(coeff,i);
        temp = temp->next;
    }
}


void print(node *head){
    while(head != NULL){
        printf("%lld ",head->coefficient);
        head = head->next;
    }
    printf("\n");
}

void standardize(node** result,long long int res[], int N, int M){
    for(int i = 0 ; i < N+M-1 ; i++)
        res[i] = 0;
    node *temp = *result;
    while(temp != NULL){
        res[temp->degree] += temp->coefficient;
        temp = temp->next;
    }
}

void multiplication(node **p, node **q, int N, int M, long long int res[]){
    node* temp1 = *p;
    node* temp2 = *q;
    node* result = NULL;
    node* temp3 = NULL;
    int start = 1;
    while(temp1 != NULL){
        while(temp2 != NULL){
            long long int coeff = temp1->coefficient * temp2->coefficient;
            long long int degree = temp1->degree + temp2->degree;
            if(start == 1){
                temp3 = createNode(coeff, degree);
                result = temp3;
                start = 0;
            }
            else{
                temp3->next = createNode(coeff, degree);
                temp3 = temp3->next;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
        temp2 = *q;
    }
    standardize(&result,res, N, M);
}



int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        node *p = NULL, *q = NULL;
        int N, M;
        scanf("%d%d",&N,&M);
        long long int result[N+M-1];
        // take two polynomials p and q as input
        input(&p,&q,N,M); 
        multiplication(&p, &q, N, M, result);
        for(int i = 0 ; i < N+M-1 ; i++)
            printf("%lld ",result[i]);
        printf("\n");
    }
    return 0;
}

