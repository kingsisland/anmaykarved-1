#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
void ar(int*);
void tictctoe(int,int*,char,char);
int checkwin(int*,int);
void cpuplay(int*,char);
int checkcpunextmove(int*);
int checkplayernextmove(int*);
int checknextmove(int*);
int checkcpunextmoveadv(int*);
int checknextmoveadv(int*);
int clone(int*,int);
int checktwozeroone(int*,int);
int playerplay(int*,char);
void add(int,char);
void gotoxy(int anubhaw, int y)
{
  COORD c;
  c.X = anubhaw;
  c.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void ar(int *a)
  {
  	int anubhaw=50,y=2,i,j;
  	for(i=0;i<=2;i++)
  	  {
  	  	gotoxy(anubhaw,y);
	    for(j=0;j<=2;j++)
  	  	  {
  	  	  	printf("%d  ",*(a+(3*i)+j));
			  }
	    y++;
	    printf("\n");
		}
  }
void tictactoe(int t,int *a,char s1,char s2)
  {
  	int z,i,j,win0,win1;
	for(i=t;;i++)
  	  {
		//ar(a);
		if(i%2==0)
  	  	  cpuplay(a,s2);
  	  	else
  	  	  {
		    z=playerplay(a,s1);
  	  	    if(z==0)
  	  	      {
  	  	  	    i--;
  	  	  	    continue;
		      }
	      } 
        win0=checkwin(a,0);
        win1=checkwin(a,1);
        if(win1==1)
          {
			gotoxy(23,17);
			printf("You Won");
			break;
	      }
        else if(win0==1)
               {
                 gotoxy(22,17);
				 printf("You lose");
            	 break;
               }
		for(j=0;j<=8;j++)
		  {
		  	if(*(a+j)==2)
		  	  break;
	      }
		if(j>8)
		  {
		    gotoxy(24,17);
			printf("Draw");  	  	  
		    break;
	      }
	    //ar(a);
  	  }
  }
int checkwin(int *a,int fn)
  {
  	int i,j,d;
  	
	//printf("\ninside checkwin");
	for(i=0;i<=2;i++)
  	  {
  	  	for(j=0;j<=2;j++)
  	  	  {
  	  	    if(*(a+(3*i)+j)!=fn)
			  break;
		  }
		if(j>2)
		  return 1;
	//	printf("not in rows\n");
	  }
	for(i=0;i<=2;i++)
	  {
	  	for(j=0;j<=2;j++)
	  	  {
	  	  	if(*(a+(3*j)+i)!=fn)
	  	  	  break;
		  }
		if(j>2)
		  return 1;
	//	printf("not in columns\n");
	  }
	for(i=0;i<=2;i++)
	  {
	    if(*(a+(3*i)+i)!=fn)
	      break;
	  }
	if(i>2)
	  return 1;
	//printf("not in leading diagonal\n");
    if(*(a+2)==fn && *(a+4)==fn && *(a+6)==fn)
      return 1;
    //printf("not in other diagonal\n");
    return 0;
  }
void cpuplay(int *a,char s2)
  {
  	int d,p,i;
	p=checktwozeroone(a,0);   //checks for direct winning case finds single empty box to put 0 (banana)
  	if(p<10)
  	  goto c;
  	p=checktwozeroone(a,1);   //finds single emppty box to put 0 (bigadna)
    if(p<10)
      goto c;
    p=checknextmoveadv(a);    //checks whether in the next chance, player doesn't win clarly
    if(p<10)
      goto c;
    p=checkcpunextmoveadv(a); //checks whether in next chance cpu can win clearly
    if(p<10)
      goto c;
    p=checknextmove(a);    //checks whether in next chance 
    if(p<10)
      goto c;
    p=checkplayernextmove(a); //keeps 1 check form or not. keeps 0 check form or not
    if(p<10)
      goto c;
    p=checkcpunextmove(a);  //keeps 0 and check cpu form or not
    if(p<10)
      goto c;
    d=rand();
    for(i=0;i<=4;i++)
      {
	    if(d%5==i)
	      {
		    if(*(a+(2*i))==2)
		      {
		        p=(2*i)+1;
		        break;
		      }
          }
      } 
    if(i<=4)
      goto c; 
    if(*(a+4)==2)
      {
        p=5;
        goto c;
      }
	
    for(i=0;;i++)
      {
      	if(*(a+i)==2)
      	  {
			//printf("general\n");
			p=i+1;
			break;
	      }
	  }
	c:
	//printf(" value of p after cpu play : %d\n",p);
	*(a+p-1)=0;
	add(p,s2);
  }
int checkcpunextmove(int *a)
  {
  	int i,b[9],count=0;
  	for(i=0;i<=8;i++)
  	  b[i]=*(a+i);
  	if(b[4]==2)
  	  {
  	  	b[4]=0;
  	  	count=clone(b,0);
  	  	b[4]=2;
  	  	if(count>0)
  	  	  return 5;
	  }  
  	for(i=0;i<=8;i++)
  	  {
  	    count=0;
		if(b[i]==2)
  	      {
  	      	b[i]=0;
  	      	count=clone(b,0);
  	      	b[i]=2;
  	      	if(count>0)
  	      	  {
			    //printf("\ncheckcpunextmove\n");  
  	      	    return i+1;
  	          }
			}
	  }
	return 10;
  }
  	
int checkplayernextmove(int *a)
  {
  	int i,b[9],count=0;
  	for(i=0;i<=8;i++)
  	  b[i]=*(a+i);
  	if(b[4]==2)
  	  {
  	  	b[4]=1;
  	  	count=clone(b,1);
  	  	b[4]=2;
  	  	if(count>0)
  	  	  return 5;
	  }  
  	for(i=0;i<=8;i++)
  	  {
  	    count=0;
		if(b[i]==2)
  	      {
  	      	b[i]=1;
  	      	count=clone(b,1);
  	      	b[i]=2;
  	      	if(count>0)
  	      	  {
			    //printf("\ncheckplayernextmove\n");
				return i+1;
		      }
			    
			}
	  }
	return 10;
  }
  	
  
int checknextmove(int *a)
  {
  	int i,b[9],count1=0,count0=0;
  	for(i=0;i<=8;i++)
  	  b[i]=*(a+i);
  	if(b[4]==2)
  	  {
  	  	b[4]=1;
  	  	count1=clone(b,1);
  	  	b[4]=0;
  	  	count0=clone(b,0);
  	  	b[4]=2;
  	  	if(count1>0 && count0>0)
  	  	  return 5;
	  }
  	for(i=0;i<=8;i++)
  	  {
  	    count1=0;
  	    count0=0;
		if(b[i]==2)
  	      {
  	      	b[i]=1;
  	      	count1=clone(b,1);
  	      	b[i]=0;
  	      	count0=clone(b,0);
  	      	b[i]=2;
  	      	if(count1>0 && count0>0)
  	      	  {
			    //printf("\nchecknextmove\n");
				return i+1;
		      }
			}
	  }
	return 10;
  	
  	
  }
int checkcpunextmoveadv(int *a)
  {
  	int i,b[9],count;
  	for(i=0;i<=8;i++)
  	  b[i]=*(a+i);
  	for(i=0;i<=8;i++)
  	  {
  	    count=0;
		if(b[i]==2)
  	      {
  	      	b[i]=0;
  	      	count=clone(b,0);
  	      	b[i]=2;
  	      	if(count>1)
  	      	  {
			    //printf("\ncheckcpunextmoveadv\n");
  	      	    return i+1;
  	          }
			}
	  }
	return 10;
  }
int checknextmoveadv(int *a)
  {
  	int i,b[9],count;
  	for(i=0;i<=8;i++)
  	  b[i]=*(a+i);
  	for(i=0;i<=8;i++)
  	  {
  	    count=0;
		if(b[i]==2)
  	      {
  	      	b[i]=1;
  	      	count=clone(b,1);
  	      	b[i]=2;
  	      	if(count>1)
  	      	  {
  	      	  	//printf("\nchecknextmoveadv");
				return i+1;
		      } 
		  }
	  }
	return 10;
  }
int clone(int *b,int fn)
  {
  	int i,j,empty,zero,count=0,p;
	for(i=0;i<=2;i++)
  	  {
  	  	empty=0;
  	  	zero=0;
		for(j=0;j<=2;j++)
  	  	  {
  	  	  	if(*(b+(3*i)+j)==2)
  	  	  	  empty++;
  	  	  	if(*(b+(3*i)+j)==fn)
  	  	  	  zero++;
  	  	  }
		if(empty==1 && zero==2)
		  count++;
	  }
	for(i=0;i<=2;i++)
	  {
	  	empty=0;
	  	zero=0;
		for(j=0;j<=2;j++)
	  	  {
	  	  	if(*(b+(3*j)+i)==2)
	  	  	  empty++;
			if(*(b+(3*j)+i)==fn)
			  zero++;
	      }
	    if(empty==1 && zero==2)
	      count++;
      } 
    empty=0;
    zero=0;
    for(i=0;i<=2;i++)
      {
        if(*(b+(3*i)+i)==2)
          {
		    p=(3*i)+i+1;
            empty++;
          }
        if(*(b+(3*i)+i)==fn)
          zero++;
	  }
	if(empty==1 && zero==2)
	  count++;
	empty=0;
	zero=0;
  	for(i=0;i<=2;i++)
  	  {
  	  	for(j=0;j<=2;j++)
  	  	  {
  	  	  	if(i+j==2)
  	  	  	  {
  	  	  	  	if(*(b+(3*i)+j)==2)
  	  	  	  	  {
					p=(3*i)+j+1;	
  	  	  	  	    empty++;
  	  	  	      }
  	  	  	  	if(*(b+(3*i)+j)==fn)
  	  	  	  	  zero++;
			  }
		  }
		
	  }
	if(empty==1 && zero==2)
		  count++;
	return count;
  }
int checktwozeroone(int *a,int fn)
  {
  	int i,j,empty,zero,p;
  	for(i=0;i<=2;i++)
  	  {
  	  	empty=0;
  	  	zero=0;
		for(j=0;j<=2;j++)
  	  	  {
  	  	  	if(*(a+(3*i)+j)==2)
  	  	  	  {
				p=(3*i)+j+1;	
  	  	  	    empty++;
  	  	      }
  	  	  	if(*(a+(3*i)+j)==fn)
  	  	  	  zero++;
  	  	  }
		if(empty==1 && zero==2)
		  return p;
	  }
	for(i=0;i<=2;i++)
	  {
	  	empty=0;
	  	zero=0;
		for(j=0;j<=2;j++)
	  	  {
	  	  	if(*(a+(3*j)+i)==2)
	  	  	  {
		   		p=(3*j)+i+1;  
	  	  	    empty++;
			  }
			if(*(a+(3*j)+i)==fn)
			  zero++;
	      }
	    if(empty==1 && zero==2)
	      return p;
      } 
    empty=0;
    zero=0;
    for(i=0;i<=2;i++)
      {
        if(*(a+(3*i)+i)==2)
          {
		    p=(3*i)+i+1;
            empty++;
          }
        if(*(a+(3*i)+i)==fn)
          zero++;
	  }
	if(empty==1 && zero==2)
	  return p; 
	empty=0;
	zero=0; 
  	for(i=0;i<=2;i++)
  	  {
  	  	for(j=0;j<=2;j++)
  	  	  {
  	  	  	if(i+j==2)
  	  	  	  {
  	  	  	  	if(*(a+(3*i)+j)==2)
  	  	  	  	  {
					p=(3*i)+j+1;	
  	  	  	  	    empty++;
  	  	  	      }
  	  	  	  	if(*(a+(3*i)+j)==fn)
  	  	  	  	  zero++;
			  }
		  }
	  }
	if(empty==1 && zero==2)
	  return p;
	return 10;
  }

  
int playerplay(int *a,char s1)
  {
  	int p;
  	gotoxy(84,17);
  	printf("    ");
  	gotoxy(86,17);
  	//printf("Make your play");
    fflush(stdin);
  	scanf("%d",&p);
  	gotoxy(82,5);
  	printf("           ");
  	if(*(a+p-1)==2)
  	  *(a+p-1)=1;
  	else
  	  {
  	    gotoxy(82,5);
		printf("Wrong move\n");
  	    return 0;
      }
	add(p,s1);
	gotoxy(84,17);
	
    return 1;
	
  }
void add(int p,char c)
  {
  	int anubhaw,y;
  	//printf("Adding at : %d",p);
  	anubhaw=47+((p-1)%3)*7;
  	y=15+((p-1)/3)*3;
	gotoxy(anubhaw,y);
    printf("%c%c%c",c,c,c);
    gotoxy(anubhaw,y+1);
    printf("%c%c%c",c,c,c);
  }
int main()
  {
    int i,t,a[9],anubhaw=50,y=5,j,z=1;
    d:
    gotoxy(52,0);
    printf("TIC-TAC-TOE");
    gotoxy(50,1);
    printf("---------------");
    gotoxy(0,3);
    for(i=0;i<=8;i++)
      a[i]=2;
    char s1,s2,toss;
    srand(time(NULL));
	printf("Choose your symbol (X or O) : ");
	fflush(stdin);
	scanf("%c",&s1);
	if(s1!='X' && s1!='x' && s1!='O' && s1!='o' && s1!='0')
	  {
	  	printf("\nInvalid Character");
	  	printf("\nType any character and press 'Enter' to continue\n");
	  	fflush(stdin);
	  	scanf("%c",&toss);
	  	fflush(stdin);
	  	system("cls");
	  	goto d;
	  }
	if(s1=='x')
	  s1='X';
	if(s1=='o' || s1=='0')
	  s1='O';
	(s1=='X')?s2='O':(s2='X');
    printf("\n\nEnter any Character to begin Toss : ");
    fflush(stdin);
    scanf("%c",&toss);
 	if(rand()%2==0)
      {
        printf("\n\nYou won the toss");
	    t=1;
      }
	else
	  {
		printf("\n\nYou lose the toss");
		t=0;
	  }
    for(i=0;i<=2;i++)
  	  {
  	  	gotoxy(anubhaw,y);
	    for(j=0;j<=2;j++)
  	  	  {
  	  	  	printf("%d    ",z);
  	  	  	z++;
		  }
	    y+=2;
	  }
	for(i=6;i<=8;i=i+2)
	  {
	  	gotoxy(48,i);
		  printf("----------------");

	  }
	for(i=53;i<=60;i=i+4)
      {
      	for(j=4;j<=10;j++)
      	  {
      	  	gotoxy(i,j);
            printf("|");
          }
	  }
	for(i=17;i<=21;i=i+3)
	  {
	  	gotoxy(45,i);
		  printf("---------------------");

	  }  
	for(i=52;i<=60;i=i+6)
      {
      	for(j=14;j<=23;j++)
      	  {
      	  	gotoxy(i,j);
            printf("|");
          }
	  }
	gotoxy(80,14);
	printf("Make your Move");
	gotoxy(83,16);
	printf("--------");
	for(i=16;i<=18;i++)
	  {
	  	gotoxy(82,i);
	  	printf("|");
	  	gotoxy(82+9,i);
	  	printf("|");
	  }
	gotoxy(83,18);
	printf("--------");
    
	gotoxy(0,4);
	tictactoe(t,a,s1,s2);
	gotoxy(17,16);
    printf("-----------------");
    gotoxy(17,18);
    printf("-----------------");
    for(i=16;i<=18;i++)
      {
      	gotoxy(17,i);
      	printf("|");
      	gotoxy(33,i);
      	printf("|");
      }
    
    gotoxy(0,25);
    printf("Type any Character and press 'Enter' to exit : ");
    fflush(stdin);
    scanf("%c",&toss);
  }
   
