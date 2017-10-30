#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef struct linklist
  {
    int data;
    struct linklist *next;
  }list;
void ccc(list**);
void hitcopy(int*,int*,list**,list**);
int hitinsert(int*,int*,list**,list**,int,int);
int final(int*,list**);
void eraserow(int*,list**,int);
void erasecol(int*,list**,int);
void erasebox(int*,list**,int);
int ce(int*);
int rcalk(list*,int);
int rfindk(list**,int);
int ccalk(list*,int);
int cfindk(list**,int);
int bcalk(list*,int);
int bfindk(list**,int);
void gotoxy(int anubhaw, int y)
{
  COORD c;
  c.X = anubhaw;
  c.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void create(int *n,list **a)
  {
    list *p;
    int i,j,k;
    for(i=0;i<9;i++)
      {
	for(j=0;j<9;j++)
	  {
	    *(a+(9*i)+j)=(list*)malloc(sizeof(list));
	    p=*(a+(9*i)+j);
	    p->next=NULL;
	    if(*(n+(9*i)+j)==0)
	      {
		for(k=1;k<=9;k++)
		  {
		    p->next=(list*)malloc(sizeof(list));
		    p=p->next;
		    p->data=k;
		    p->next=NULL;
		  }
	      }
	  }
      }
  }
void delrow(int *n,list **a)
  {
    int i,j;
    for(i=0;i<9;i++)
      {
	for(j=0;j<9;j++)
	  {
	    if(*(n+(9*i)+j)!=0)
	      eraserow(n+(9*i),a+(9*i),*(n+(9*i)+j));
	  }
      }
  }
void eraserow(int *n,list **a,int e)
  {
    int i;
    list *p,*z;
    for(i=0;i<9;i++)
      {
	if(*(n+i)==0)
	  {
	    p=*(a+i);
	    while(p->next!=NULL)
	      {
		if(p->next->data==e)
		  {
		    z=p->next;
		    p->next=p->next->next;
		    free(z);
		  }
		else
		  p=p->next;
	      }
	  }
      }
  }
void delcol(int *n,list **a)
  {
    int i,j;
    for(i=0;i<9;i++)
      {
	for(j=0;j<9;j++)
	  {
	    if(*(n+(9*j)+i)!=0)
	      erasecol(n+i,a+i,*(n+(9*j)+i));
	  }
      }
  }
void erasecol(int *n,list **a,int e)
  {
    int i;
    list *p,*z;
    for(i=0;i<9;i++)
      {
	if(*(n+(9*i))==0)
	  {
	    p=*(a+(9*i));
	    while(p->next!=NULL)
	      {
		if(p->next->data==e)
		  {
		    z=p->next;
		    p->next=p->next->next;
		    free(z);
		    break;
		  }
		else
		  p=p->next;
	      }
	  }
      }
  }
void delbox(int *n,list **a)
  {
    int i,j,k,l;
    for(i=0;i<9;i=i+3)
      {
	for(j=0;j<9;j=j+3)
	  {
	    for(k=i;k<i+3;k++)
	      {
		for(l=j;l<j+3;l++)
		  {
		    if(*(n+(9*k)+l)!=0)
		      erasebox(n+(9*i)+j,a+(9*i)+j,*(n+(9*k)+l));
		  }
	      }
	  }
      }
  }
void erasebox(int *n,list **a,int e)
  {
    int i,j;
    list *p,*z;
    for(i=0;i<3;i++)
      {
	for(j=0;j<3;j++)
	  {
	    if(*(n+(9*i)+j)==0)
	      {
		p=*(a+(9*i)+j);
		while(p->next!=NULL)
		  {
		    if(p->next->data==e)
		      {
			z=p->next;
			p->next=p->next->next;
			free(z);
			break;
		      }
		    else
		      p=p->next;
		  }
	      }
	  }
      }
  }
void findone(int *n,list **a)
  {
    int i,j;
    list *p;
    for(i=0;i<9;i++)
      {
	for(j=0;j<9;j++)
	  {
	    p=*(a+(9*i)+j);
	    if(*(n+(9*i)+j)==0 && p->next->next==NULL)
	      {
		*(n+(9*i)+j)=p->next->data;
		free(p->next);
		p->next=NULL;
	      }
	  }
      }
  }
void findrow(int *n,list **a)
  {
    int i,k,j,c,d;
    list *p;
    for(i=0;i<9;i++)
      {
	for(k=1;k<=9;k++)
	  {
	    c=0;
	    for(j=0;j<9;j++)
	      {
		if(*(n+(9*i)+j)==0)
		  c=c+rcalk(*(a+(9*i)+j),k);
	      }
	    if(c==1)
	      {
		d=rfindk(a+(9*i),k);
		*(n+(9*i)+d)=k;
		p=*(a+(9*i)+d);
		free(p->next);
		p->next=NULL;
	      }
	  }
      }
  }
int rcalk(list *a,int k)
  {
    int c=0;
    while(a->next!=NULL)
      {
	if(a->next->data==k)
	  c++;
	a=a->next;
      }
    return c;
  }
int rfindk(list **a,int k)
  {
    list *p;
    int i;
    for(i=0;i<9;i++)
      {
	p=*(a+i);
	while(p->next!=NULL)
	  {
	    if(p->next->data==k)
	      return i;
	    p=p->next;
	  }
      }
    return -1;
  }
void findcol(int *n,list **a)
  {
    int i,k,j,c,d;
    list *p;
    for(i=0;i<9;i++)
      {
	for(k=1;k<=9;k++)
	  {
	    c=0;
	    for(j=0;j<9;j++)
	      {
		if(*(n+(9*j)+i)==0)
		  c=c+ccalk(*(a+(9*j)+i),k);
	      }
	    if(c==1)
	      {
		d=cfindk(a+i,k);
		*(n+(9*d)+i)=k;
		p=*(a+(9*d)+i);
		free(p->next);
		p->next=NULL;
	      }
	  }
      }
  }
int ccalk(list *a,int k)
  {
    int c=0;
    while(a->next!=NULL)
      {
	if(a->next->data==k)
	  c++;
	a=a->next;
      }
    return c;
  }
int cfindk(list **a,int k)
  {
    list *p;
    int i;
    for(i=0;i<9;i++)
      {
	p=*(a+(9*i));
	while(p->next!=NULL)
	  {
	    if(p->next->data==k)
	      return i;
	    p=p->next;
	  }
      }
    return -1;
  }

void findbox(int *n,list **a)
  {
    int i,j,k,l,c,d,z;
    list *p;
    for(i=0;i<9;i=i+3)
      {
	for(j=0;j<9;j=j+3)
	  {
	    for(z=1;z<=9;z++)
	      {
		c=0;
		for(k=i;k<i+3;k++)
		  {
		    for(l=j;l<j+3;l++)
		      {
			if(*(n+(9*k)+l)==0)
			  c=c+bcalk(*(a+(9*k)+l),z);
		      }
		  }
		if(c==1)
		  {
		    d=bfindk(a+(9*i)+j,z);
		    p=*(a+(9*i)+(9*(d/3))+j+(d%3));
		    *(n+(9*i)+(9*(d/3))+j+(d%3))=z;
		    free(p->next);
		    p->next=NULL;
		  }
	      }
	  }
      }
  }
int bcalk(list *a,int k)
  {
    int c=0;
    while(a->next!=NULL)
      {
	if(a->next->data==k)
	  c++;
	a=a->next;
      }
    return c;
  }
int bfindk(list **a,int k)
  {
    int i;
    list *p;
    for(i=0;i<9;i++)
      {
	p=*(a+(9*(i/3))+(i%3));
	while(p->next!=NULL)
	  {
	    if(p->next->data==k)
	      return i;
	    p=p->next;
	  }
      }
    return -1;
  }
int check(int *n)
  {
    int i,j;
    for(i=0;i<9;i++)
      {
	for(j=0;j<9;j++)
	  {
	    if(*(n+(9*i)+j)==0)
	      return 1;
	  }
      }
    return 0;
  }
void display(int *n,int *q,int o)
  {
    int i,j,g=0,h=0;
    gotoxy(0,13);
    printf("\n Solution \n\n");
    for(i=0;i<9;i++)
      {
	g=0;
	for(j=0;j<9;j++)
	  {
	    g++;
	    if(*(q+(9*i)+j)==0)
	      {
		    if(*(n+(9*i)+j)!=0)
		      printf("%d",*(n+(9*i)+j));
		    else
              printf("%d",*(n+(9*i)+j));
		  }
	    else
	      printf("%d",*(n+(9*i)+j));
	    (g==3 || g==6)?(printf("|")):(printf(" "));
	  }
	printf("\n");
	h++;
	if(h==3 || h==6)
	  printf("-----|-----|-----\n");
      }
  }
int final(int *n,list **a)
  {
    int c=0;
    
    while(check(n)!=0)
      {
	c++;
	if(c==20)
	  break;
	delrow(n,a);
	delcol(n,a);
	delbox(n,a);
	findone(n,a);
	delrow(n,a);
	delcol(n,a);
	delbox(n,a);
	findrow(n,a);
	delrow(n,a);
	delcol(n,a);
	delbox(n,a);
	findcol(n,a);
	delrow(n,a);
	delcol(n,a);
	delbox(n,a);
	findbox(n,a);
      }
    return c;
  }
int hitinsert(int *n,int *m,list **a,list **b,int i,int j)
  {
    int k;
    list *p,*u;
    p=*(a+(9*i)+j);
    while(p->next!=NULL)
      {
	    p=p->next;
	    hitcopy(n,m,a,b);
	    *(m+(9*i)+j)=p->data;
	    u=*(b+(9*i)+j);
	    u->next=NULL;
	    if(final(m,b)<=19)
	      {
	        hitcopy(m,n,0,0);
	        return 1;
	      }
	    ccc(b);
      }
    return 0;
  }
void ccc(list **b)
  {
    int i,j,k,l,c;
    list *p;
    for(i=0;i<9;i++)
      {
	    for(j=0;j<9;j++)
	      {
	        c=0;
	        p=*(b+(9*i)+j);
	        while(p->next!=NULL)
	          {
		        c++;
		        p=p->next;
	          }
	        for(k=c-1;k>=0;k--)
	          {
		        p=*(b+(9*i)+j);
		        for(l=1;l<=k;l++)
		        p=p->next;
		        free(p->next);
		        p->next=NULL;
	          }
	      }
      }
  }

void hitcopy(int *n,int *m,list **a,list **b)
  {
    int i,j;
    list *p,*q;
    for(i=0;i<9;i++)
      {
	for(j=0;j<9;j++)
	  {
	    *(m+(9*i)+j)=*(n+(9*i)+j);
	  }
      }
    if(a!=0)
      {
	for(i=0;i<9;i++)
	  {
	    for(j=0;j<9;j++)
	      {
		*(b+(9*i)+j)=(list*)malloc(sizeof(list));
		p=*(b+(9*i)+j);
		q=*(a+(9*i)+j);
		p->next=NULL;
		while(q->next!=NULL)
		  {
		    p->next=(list*)malloc(sizeof(list));
		    p=p->next;
		    q=q->next;
		    p->data=q->data;
		    p->next=NULL;
		  }
	      }
	  }
      }
  }
int main()
  {
    int n[9][9],m[9][9],q[9][9],f;
    char v;
    list *a[9][9],*b[9][9];
    int i,j,c=0,ii,jj;
    gotoxy(50,0);
    printf("SUDOKU SOLVER");
    gotoxy(48,1);
    printf("----------------");
    gotoxy(0,3);
    printf("Enter Sudoku(Enter '0' for blanks) : \n");
    for(i=0;i<9;i++)
      {
	for(j=0;j<9;j++)
	  {
	    scanf("%d",&n[i][j]);
	    if(n[i][j]==-1)
	      {
		main();
		exit(1);
	      }
	    q[i][j]=n[i][j];
	  }
      }
    create(&n[0][0],&a[0][0]);
	if(final(&n[0][0],&a[0][0])<19)
	  {
	    display(&n[0][0],&q[0][0],c);
	    fflush(stdin);
	    printf("\nType any Character and press 'Enter'' to continue : ");
	    fflush(stdin);
	    scanf("%c",&v);
	    exit(0);
	  }
	printf("Sudoku Solver Version 2 failed :( \n");
	printf("Here comes Version 3 :)");
	for(i=0;i<9;i++)
	  {
	    for(j=0;j<9;j++)
	      {
		if(n[i][j]!=0)
		  continue;
		f=hitinsert(&n[0][0],&m[0][0],&a[0][0],&b[0][0],i,j);
		if(f==1)
		  break;
	      }

	    if(f==1)
	      break;
	  }
	display(&n[0][0],&q[0][0],c);
	if(f!=1)
	  printf("Sorry... will surely do this in version 4\n");
	printf("\nType any Character and press 'Enter' to continue : ");
	fflush(stdin);
	scanf("%c",&v);
	fflush(stdin);
	return 0;
  }
