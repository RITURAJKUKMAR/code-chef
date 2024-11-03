#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
    struct node* next;
    struct node* prev;   // Additional pointer for doubly linked list
};

struct node* head=NULL;
struct node* cur=NULL;

struct node* node_new(int val){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void addSong(int songId){
    struct node *t,*newsong = node_new(songId);
    // Consider the case when list is empty too
    if(head==NULL)
        head=newsong;
    else
    {
        t=head;
        while(t->next!=NULL)
            t=t->next;
        t->next=newsong;
        newsong->prev=t;
        cur=head;
    }
    
}

void nextSong(){
    cur=cur->next;
    
}

void prevSong(){
    cur=cur->prev;
    
}

void switchSong(int songId){
    struct node *t=head;
    while(t->next!=NULL)
    {
        if(t->value==songId)
        {
            cur=t;
            break;
        }
    }
}

int current(){
    return cur->value;
    
}

int main() {
    head=NULL;
    cur=NULL;
    int n;
    scanf("%d",&n);
    while(n--){
        int q;
        scanf("%d",&q);
        if(q==1){
            int songId;
            scanf("%d",&songId);
            addSong(songId);
        }
        else if(q==2){
            nextSong();
        }
        else if(q==3){
            prevSong();
        }
        else if(q==4){
            int songId;
            scanf("%d",&songId);
            switchSong(songId);
        }
        else{
            int ans = current();
            printf("%d\n",ans);
        }
    }
}