#include<stdio.h>
#include<stdlib.h>
typedef struct link
  {
    int co;
    int in;
    struct link *prev;
    struct link *next;
  }poly;
poly *l3;
void disp(poly *);
void cal(poly *,int);
void filt(poly *);
void mul(poly*,int);
void pc(poly*,int);
void cz(poly*d);
void cz(poly *d)
  {
    int c=0;
    printf("No of trailing zeros : ");
    while(d->co==0)
      {
	c++;
	d=d->next;
      }
    printf("%d\n",c);
  }
void disp(poly *d)
  {
    while(d->next!=NULL)
      d=d->next;
    while(d->prev!=NULL)
      {
	d=d->prev;
	printf("%d",d->co);
      }
  }
void cal(poly *l3,int m)
  {
    int i;
    for(i=m-1;i>1;i--)
      {
	mul(l3,i);
	filt(l3);
      }
    //cz(l3);
    disp(l3);
    //cz(l3);
  }

void filt(poly *d)
  {
    int c;
    while(d->next!=NULL)
      {
	c=0;
	if(d->co>9)
	  {
	    c=d->co/10;                //store other digits in c
	    d->co=d->co%10;           //get only last digit in l3->co
	    if(d->next->in!=d->in+1)  //creation of new memory after l3
	      {
		d->next->prev=(poly*)malloc(sizeof(poly));
		d->next->prev->prev=d;
		d->next->prev->next=d->next;
		d->next=d->next->prev;
		d->next->in=d->in+1;
		d->next->co=0;
	      }
	  }
	d=d->next;
	d->co=d->co+c;
      }
  }

void mul(poly *d,int i)                //multiplies l1&l2
  {                                      //does not arrenge/clear dup/filter
    while(d->next!=NULL)
      {
	d->co=d->co*i;
	d=d->next;
      }
  }

void pc(poly *d,int m)
  {
    int k=0;
    while(m!=0)
      {
	d->co=m%10;
	m=m/10;
	d->in=k;
	k++;
	d->next=(poly*)malloc(sizeof(poly));
	d->next->prev=d;
	d=d->next;
	d->next=NULL;
      }
  }
int main()
  {
    int n,g;
	printf("Enter number: ");
    scanf("%d",&n);
    l3=(poly*)malloc(sizeof(poly));
    l3->prev=NULL;
    pc(l3,n);
    cal(l3,n);
    printf("\nType a key and press 'enter' to exit :");
    scanf("%d",&g);
    return 0;
  }
