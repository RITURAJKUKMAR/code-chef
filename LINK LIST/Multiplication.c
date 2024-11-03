#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*poly == NULL || exp > (*poly)->exponent) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        struct Node* current = *poly;
        while (current->next != NULL && current->next->exponent > exp) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}
void addPoly(struct Node *p1,struct Node *p2,struct Node **s)
{
    if(p1==NULL && p2==NULL)
        return;
    else if(p1!=NULL && p2==NULL)
    {
        insertTerm(&(*s),p1->coefficient,p1->exponent);
        addPoly(p1->next,p2,&(*s));
    }
    else if(p1==NULL && p2!=NULL)
    {
        insertTerm(&(*s),p2->coefficient,p2->exponent);
        addPoly(p1,p2->next,&(*s));
    }
    else
    {
        if(p1->exponent > p2->exponent)
        {
            insertTerm(&(*s),p1->coefficient,p1->exponent);
            addPoly(p1->next,p2,&(*s));
        }
        if(p1->exponent < p2->exponent)
        {
            insertTerm(&(*s),p2->coefficient,p2->exponent);
            addPoly(p1,p2->next,&(*s));
        }
        else if(p1->exponent == p2->exponent)
        {
            insertTerm(&(*s),p1->coefficient+p2->coefficient,p1->exponent);
            addPoly(p1->next,p2->next,&(*s));
        }
    }
}

void displayPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        if (poly->next != NULL && poly->next->coefficient > 0) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

void multilplication(struct Node *p1,struct Node *p2,struct Node **MP1,struct Node **MP2,struct Node **MUL)
{
    struct Node *t1=p1;
    while(t1!=NULL)
    {
        insertTerm(&(*MP1),t1->coefficient*p2->coefficient,t1->exponent+p2->exponent);
        t1=t1->next;
    }
    t1=p1;
    struct Node *t2=p2->next;
    while(t1!=NULL)
    {
        insertTerm(&(*MP2),t1->coefficient*t2->coefficient,t1->exponent+t2->exponent);
        t1=t1->next;
    }
    addPoly(*MP1,*MP2,&(*MUL));
}

int main() {
    struct Node* poly = NULL,*poly2=NULL,*MP1=NULL,*MP2=NULL,*MUL=NULL;
    int n, coeff, exp;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }

    printf("First polynomial: ");
    displayPolynomial(poly);
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    printf("Second polynomial: ");
    displayPolynomial(poly2);

    printf("Product of polynomials: ");
    multilplication(poly,poly2,&MP1,&MP2,&MUL);
    displayPolynomial(MUL);

    return 0;
}