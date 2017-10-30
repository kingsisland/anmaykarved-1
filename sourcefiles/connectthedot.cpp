#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#define C 4
#define R 4
typedef struct dotdot
  {
  	int left;
  	int up;
  	int right;
  	int down;
  	int data;
  }dot;
int checkrange(int,int,int,int);
int checkxy(int,int,int);
int checkx(int,dot**);
int checkoverlap(int,int,dot**,int);
void alter(int,int,dot**,int);
int countbox(dot**,int,int);
void addline(int,int,dot**);
void score(int,int,char*,char*);
void gotoxy(int anubhaw, int bhalotia)
{
  COORD c;
  c.X = anubhaw;
  c.Y = bhalotia;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void display(int r,int c,dot **a)
  {
  	int i,j;
  	dot *p;
  	gotoxy(0,4);
	for(i=0;i<r;i++)
  	  {
  	    for(j=0;j<c;j++)
  	      {
  	      	p=*(a+(c*i)+j);
  	      	printf("%5d",p->data);
  	      }
  	    printf("\n\n\n");
	  }
  }
void create(int r,int c,dot **a)
  {
  	int i,j;
  	dot *p;
  	for(i=0;i<r;i++)
  	  {
  	  	for(j=0;j<c;j++)
  	  	  {
  	  	  	p=(dot*)malloc(sizeof(dot));
  	  	  	p->left=1;p->up=1;p->right=1;p->down=1;
  	  	  	p->data=(i*c)+j+1;
  	  	  	*(a+(i*c)+j)=p;
		  }
      }
  	for(i=0;i<c;i++)
  	  {
  	  	p=*(a+i);
		p->up=2;
		p=*(a+(c*(r-1))+i);
		p->down=2;
	  }
	for(j=0;j<r;j++)
	  { 
 	  	p=*(a+(c*j)+0);
	  	p->left=2;
		p=*(a+(c*j)+c-1);
		p->right=2;
	  }
  }
void score(int p1,int p2,char *p1n,char *p2n)
  {
  	gotoxy(C+(C*4)+5,9);
  	printf("        SCORE");
  	gotoxy(C+(C*4)+5,10);
  	printf("--------------------");
	gotoxy(C+(C*4)+5,12);
  	printf("%10s %10s",p1n,p2n);
  	gotoxy(C+(C*4)+5,13);
  	printf("-----------------------");
  	gotoxy(C+(C*4)+5,15);
  	printf("%8d   %8d",p1,p2);
  	fflush(stdin);
  }
void play(int r,int c,dot **a,char *p1n,char *p2n,int t)
  {
  	int h=0,i,x,y,p1=0,p2=0,box=0;
	for(i=t;;i++)
  	  {
		score(p1,p2,p1n,p2n);
		gotoxy(c+(c*4)+5,3);
		printf("                                  ");
		gotoxy(c+(c*4)+5,3);
		if(i%2==0)
		  printf("Make Your move %s",p1n);
		else
		  printf("Make Your move %s",p2n);
		gotoxy(c+(c*4)+5,5);
		printf("Enter x and y (space seperated) and press 'ENTER': ");
  	  	scanf("%d %d",&x,&y);
  	  	fflush(stdin);
  	  	gotoxy(c+(c*4)+5,5);
  	  	printf("                                           ");
  	  	gotoxy(c+(c*4)+5,7);
  	  	printf("                   ");
  	  	if(h==1)
  	  	{
			
		if(checkrange(x,y,r,c)==1 || checkxy(x,y,c)==1 ||  checkx(x,a)==1 || checkoverlap(x,y,a,c)==1)
  	  	  {
  	  	  	gotoxy(c+(c*4)+5,7);
  	  	  	printf("INVALID MOVE");
		    i--;
  	  	  	continue;
		  }
	    }
	    gotoxy(c+(c*4)+5,7);
	    printf("Nice Move");
	    h=1;
		addline(x,y,a);
		alter(x,y,a,c);
		box=countbox(a,r,c);
		if(box>(p1+p2))
		  {
		  	if(i%2==0)
		  	  p1=p1+(box-(p1+p2));
		  	else
		  	  p2=p2+(box-(p1+p2));
		  }
		if(box==(r-1)*(c-1))
		       break;
  	  }
  	gotoxy(c+(c*4)+7,17);
  	printf("-------------------");
  	gotoxy(c+(c*4)+7,19);
  	printf("-------------------");
  	for(i=17;i<=19;i++)
  	  {
  	  	gotoxy(c+(c*4)+6,i);
  	  	printf("|");
  	  	gotoxy(c+(c*4)+25,i);
  	  	printf("|");
	  }
	gotoxy(c+(c*4)+10,18);
	if(p1>p2)
	  printf("%s WON",p1n);
	else if(p2>p1)
	       printf("%s WON",p2n);
	     else
	       printf("DRAW");
	gotoxy(0,24);
  }
int checkrange(int x,int y,int r,int c)
  {
  	if(x<1 || x>(r*c) || y<1 || y>(r*c))
  	  return 1;
  	else 
  	  return 0;
  }  
int checkxy(int x,int y,int c)
  {
  	int diff;
  	diff=x-y;
  	if(diff==1 || diff==c || diff==-1 || diff==-c)
  	  return 0;
  	else
  	  return 1;
  }

int checkx(int x,dot **a)
  {
  	dot *p;
  	p=*(a+x-1);
  	if((p->left==0 || p->up==0 || p->right==0 || p->down==0)&&(p->left==1 || p->up==1 || p->right==1 || p->down==1))
  	  return 0;
  	else
  	  return 1;
  }
int checkoverlap(int x,int y,dot **a,int c)
  {
  	int ch;
  	dot *p;
  	ch=x-y;
  	p=*(a+x-1);
	  switch(ch)
  	  {
  	  	
		case 1:
  	  		if(p->left==1)
  	  		  return 0;
  	  		else
  	  		  return 1;
  	  	case C:
  	    	if(p->up==1)
  	  		  return 0;
  	  		else
  	  		  return 1;
  	  	case -1:
  	  		if(p->right==1)
  	  		  return 0;
  	  		else
  	  		  return 1;
  	  	case -C:
  	  		if(p->down==1)
  	  		  return 0;
  	  		else
  	  		  return 1;
		}
  }
void addline(int x,int y,dot **a)
  {
  	int ch;
  	ch=x-y;
  	switch(ch)
  	  {
  	  	case 1:
  	  		gotoxy(((((x-1)%C))*5),(((x-1)/C)*3)+4);
  	  		printf("---");
  	  		break;
  	  	case C:
  	  		gotoxy(((((x-1)%C)*5)+4),((((x-1)/C)-1)*3)+5);
  	  		printf("|");
  	  		gotoxy(((((x-1)%C)*5)+4),((((x-1)/C)-1)*3)+6);
  	  		printf("|");
  	  		break;
  	  	case -1:
  	  	    gotoxy((((x%C))*5),(((x-1)/C)*3)+4);
  	  		printf("---");
  	  		break;
  	  	case -C:
  	  		gotoxy((((((x-1)%C))*5)+4),((((x-1)/C))*3)+5);
  	  		printf("|");
  	  		gotoxy((((((x-1)%C))*5)+4),((((x-1)/C))*3)+6);
  	  		printf("|");
  	  		break;
  	  		
		}
  }
void alter(int x,int y,dot **a,int c)
  {
  	int ch;
  	dot *p,*q;
  	ch=x-y;
  	p=*(a+x-1);
	switch(ch)
  	  {
  	  	case 1:
			q=*(a+x-2);
  	  		p->left=0;
  	  		q->right=0;
  	  		break;
  	  	case C:
			q=*(a+x-1-c);
  	  		p->up=0;
  	  		q->down=0;
  	  		break;
  	  	case -1:
			q=*(a+x);
  	  		p->right=0;
  	  		q->left=0;
  	  		break;
  	  	case -C:
			q=*(a+x-1+c);
  	  		p->down=0;
  	  		q->up=0;
  	  		break;
	  }
  }
int countbox(dot **a,int r,int c)
  {
  	int i,j,count=0;
  	dot *p,*q,*z,*s;
  	for(i=0;i<r-1;i++)
  	  {
  	  	for(j=0;j<c-1;j++)
  	  	  {
  	  	  	p=*(a+(c*i)+j);
  	  	  	q=*(a+(c*i)+j+1);
  	  	  	z=*(a+(c*(i+1))+j+1);
  	  	  	s=*(a+(c*(i+1))+j);
  	  	  	if(p->right==0 && q->down==0 && z->left==0 && s->up==0)
  	  	  	  count++;
		  }
	  }
	return count;
  }
int main()
  {
  	dot *a[R][C];
  	int i,r=R,c=C,t;
  	char toss,p1n[10],p2n[10];
  	gotoxy(52,0);
  	printf("CONNECTING THE DOTS");
  	gotoxy(50,1);
  	printf("-----------------------");
  	srand(time(NULL));
  	create(r,c,&a[0][0]);
  
  	//play(r,c,&a[0][0]);
  	gotoxy(0,4);
  	printf("Player 1 - Enter your name : ");
  	gets(p1n);
  	gotoxy(0,5);
  	printf("Player 2 - Enter your name : ");
  	gets(p2n);
  	gotoxy(0,4);
    printf("                                            ");
    gotoxy(0,5);
    printf("                                            ");
  	gotoxy(0,4);
  	printf("Press 'ENTER' to begin Toss ");
    fflush(stdin);
    scanf("%c",&toss);
    gotoxy(0,6);
    if(rand()%2==0)
      {
        printf("%s won the toss",p1n);
	    t=0;
      }
	else
	  {
		printf("%s won the toss",p2n);
		t=1;
	  }
    gotoxy(0,8);
    printf("Press 'ENTER' to continue  ");
    fflush(stdin);
    scanf("%c",&toss);
    fflush(stdin);
	gotoxy(0,4);
	printf("                                                    ");
	gotoxy(0,6);
	printf("                                                    ");
	gotoxy(0,8);
	printf("                                                    ");
    display(r,c,&a[0][0]);
	for(i=3;i<=18;i++)
	  {
	    gotoxy(c+(c*4)+3,i);
	    printf("|");
      }
    play(r,c,&a[0][0],p1n,p2n,t);
    printf("Press 'ENTER' to Exit");
    scanf("%c",&toss);
  	return 0;
  }
  
