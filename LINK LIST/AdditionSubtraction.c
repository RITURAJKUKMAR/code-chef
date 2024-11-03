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
void addPoly(struct Node *p1,struct Node *p2,struct Node **s)
{
    if(p1==NULL)
        return ;
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
void diffPoly(struct Node *p1,struct Node *p2,struct Node **s)
{
    if(p1==NULL)
        return ;
    else
    {
        if(p1->exponent > p2->exponent)
        {
            insertTerm(&(*s),p1->coefficient,p1->exponent);
            diffPoly(p1->next,p2,&(*s));
        }
        if(p1->exponent < p2->exponent)
        {
            insertTerm(&(*s),p2->coefficient,p2->exponent);
            diffPoly(p1,p2->next,&(*s));
        }
        else if(p1->exponent == p2->exponent)
        {
            insertTerm(&(*s),p1->coefficient-p2->coefficient,p1->exponent);
            diffPoly(p1->next,p2->next,&(*s));
        }
    }
}
int main() {
    struct Node* poly = NULL;
    struct Node* poly1 = NULL;
    struct Node* sum = NULL;
    struct Node* diff = NULL;
    int n, coeff, exp;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }
    printf("First polynomial: ");
    displayPolynomial(poly);
    
    printf("Second polynomial: ");
    displayPolynomial(poly1);

    addPoly(poly,poly1,&sum);
    printf("Sum of polynomials: ");
    displayPolynomial(sum);
    
    diffPoly(poly,poly1,&diff);
    printf("Difference of polynomials: ");
    displayPolynomial(diff);


    return 0;
}