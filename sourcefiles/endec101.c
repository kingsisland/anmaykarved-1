#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char decode(char *a)
{
	//char s[5];
	//s=a;
	if(strcmp(a,"2")==0)
	{
		return 'a';
	}
	else if(strcmp(a,"22")==0)
	{
		return 'b';
	}
	else if(strcmp(a,"222")==0)
	{
		return 'c';
	}
	else if(strcmp(a,"3")==0)
	{
		return 'd';
	}
	else if(strcmp(a,"33")==0)
	{
		return 'e';
	}
	else if(strcmp(a,"333")==0)
	{
		return 'f';
	}
	else if(strcmp(a,"4")==0)
	{
		return 'g';
	}
	else if(strcmp(a,"44")==0)
	{
		return 'h';
	}
	else if(strcmp(a,"444")==0)
	{
		return 'i';
	}
	else if(strcmp(a,"5")==0)
	{
		return 'j';
	}
	else if(strcmp(a,"55")==0)
	{
		return 'k';
	}
	else if(strcmp(a,"555")==0)
	{
		return 'l';
	}
	else if(strcmp(a,"6")==0)
	{
		return 'm';
	}
	else if(strcmp(a,"66")==0)
	{
		return 'n';
	}
	else if(strcmp(a,"666")==0)
	{
		return 'o';
	}
	else if(strcmp(a,"7")==0)
	{
		return 'p';
	}
	else if(strcmp(a,"77")==0)
	{
		return 'q';
	}
	else if(strcmp(a,"777")==0)
	{
		return 'r';
	}
	else if(strcmp(a,"7777")==0)
	{
		return 's';
	}
	else if(strcmp(a,"8")==0)
	{
		return 't';
	}
	else if(strcmp(a,"88")==0)
	{
		return 'u';
	}
	else if(strcmp(a,"888")==0)
	{
		return 'v';
	}
	else if(strcmp(a,"9")==0)
	{
		return 'w';
	}
    else if(strcmp(a,"99")==0)
	{
		return 'x';
	}
	else if(strcmp(a,"999")==0)
	{
		return 'y';
	}
	else if(strcmp(a,"9999")==0)
	{
		return 'z';
	}
	else if(strcmp(a,"0")==0)
	{
		return ' ';
	}
}
int main()
{
	
	int ch,i,j=0,ch3,ch1,ch2,shift,messlen,keylen,excep=0,k2,k=0,p=0,pos1,pos2,count=0,len=0,count1=0;
	char mess3[5000],mess1[5000],mess2[5000],k3[100],sub[500],z;
	struct k
	{
		char alpha[26];
		int code[26];
		char codes[26][5];
	}k1;
	char decode(char*);
	for(i=0;i<26;i++)
	{
		k1.alpha[i]=97+i;
	}
	
	/*for(i=0;i<26;i++)
	{
		printf("%c\n",k1.codes[i]);
	}*/
	
	for(i=2;i<=9;i++)
	{
		//printf("%d\n",p);
		for(k=1;k<=111;k=k*10+1)
		{
			//printf("%d\n",i*k);
			k1.code[p]=i*k;	
			//printf("%d\n",k1.code[p]);
			p++;
		}
		if(i==7)
		{
			k1.code[p]=7777;
			p++;
		//	printf("%d\n",k1.code[p]);
		}
		if(i==9)
		{
			k1.code[p]=9999;
		//	printf("%d\n",k1.code[p]);
		}
	}
	/*for(i=2;i<=9;i++)
	{
		//printf("%d\n",p);
		for(j=1;j<=3;j++)
		{
			//printf("%d\n",i*k);
			for(k=0;k<j;k++)
			{
				k1.codes[count1][k]=i+48;	
			}
			k1.codes[count1][k]='\0';
			count1++;
		}
		if(i==7)
		{
			k1.codes[count1][]={'7','7','7','7','\0'};
			count1++;
		//	printf("%d\n",k1.code[p]);
		}
		if(i==9)
		{
			k1.codes[count1][]={'9','9','9','9','\0'};
		//	printf("%d\n",k1.code[p]);
		}
	}*/
	
	printf("Welcome to Endec101\n");
	printf("A program for encoding messages and decoding cryptograms\n");
	printf("To encrypt a cryptogram you need two things\n 1. Cipher\n 2. Key\n");
	printf("Cipher is the set of rules used to encode the information.\nKey determines the arrangement of those rules.\n");
	printf("For example:\n HACKATHON can be encoded as MFHPFYMTS where the cipher is shifting of letters and key is 5,\n");
	printf(" so every letter is shifted by 5 in the alphabetical order.\nWe hope you enjoy it!\n");
	printf("Choose the difficulty level for your encrpytion\n");
	printf(" 1 for Easy\n 2 for Medium\n 3 for Hard\nChoice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			{
				printf("You have chosen easy level, here we deal with phone Message cipher");
				printf(" In a Phone Message cipher the way you encode a letter remains same \nalong the length of the sentence.");
				printf(" Here we are working on the Phone Message Cipher where the cipher is replacing of letters with a combination of numbers");
				printf("Algoritm for encoding:\n\n");
				printf("Each letter of the message is encrpted by replacing it with a combination of numbers.\n");
				printf("Press enter to continue");
				getche();
				printf("Enter 0 for encoding the message\nEnter 1 for decoding the message\n");
				printf("Enter your choice ");
				scanf("%d",&ch1);
				if(ch1==0)
				{
					printf("Enter the message:\n");
					fflush(stdin);
					gets(mess1);
					
					messlen=strlen(mess1);
					for(i=0;i<messlen;i++)
					{
						mess1[i]=tolower(mess1[i]);
						if(mess1[i]==' ')
							{
								printf("0/");
							}
						for(j=0;j<26;j++)
						{
							if(mess1[i]==k1.alpha[j])
							{
								printf("%d/",k1.code[j]);
							}
						    
						}
					}
				}
				else if(ch1==1)
				{
					
					printf("Enter the message:\n");
					fflush(stdin);
					gets(mess1);
					pos1=0;
					messlen=strlen(mess1);
					for(i=0;i<messlen;i++)
					{
						if(mess1[i]=='/')
							{   count=0;
								pos2=i;
								//printf("%d%d\n",pos1,pos2);
								if(pos1==0)
								{
									len=pos2-pos1;
								}
								else
								{
									len=pos2-pos1-1;
								}
								//printf("%d\n",len);
								while(count<len)
								{
									if(pos1==0)
									sub[count]=mess1[pos1+count];
									else
									sub[count]=mess1[pos1+count+1];
									count++;
								}
								sub[count]='\0';
								printf("%c",decode(sub));
								//printf("%s\n",sub);
								pos1=pos2;
								//printf("%c",decode(sub));
								/*for(j=0;j<26;j++)
								{
									if(strcmp(sub,&k1.codes[j])==0)
									{
										printf("%c",k1.alpha[j]);
									}
								}*/
								//printf("%c",k1.alpha[j]);
							}
					}
				}
				else
				{
					printf("Invalid Choice");
				}
				break;
			}
		case 2:
			{
				printf("You have chosen medium level, here we deal with monoalphabetic ciphers");
				printf(" In a monoalphabetic cipher the way you encode a letter remains same \nalong the length of the sentence.");
				printf(" Here we are working on the Ceasar Cipher where the cipher is shifting of letters and \nthe key is a number used to encode a message.\n\n");
				printf("Algoritm for encoding:\n\n");
				printf("Each letter of the message is encrpted by shifting it forward by same number.\n");
				printf("Press enter to continue");
				getche();
				printf("Enter 0 for encoding the message\nEnter 1 for decoding the message\n");
				printf("Enter your choice ");
				scanf("%d",&ch2);
				if(ch2==0)
				{
					printf("Enter the message:\n");
					fflush(stdin);
					gets(mess2);
					fflush(stdin);
					printf("Enter the key:\n");
					scanf("%d",&k2);
					messlen=strlen(mess2);
					//printf("%d\n",keylen);
					for(i=0;i<messlen;i++)
					{ 
						//printf("%d\n",j);
						//j=0;
						if((mess2[i]>=65 && mess2[i]<=90) && (k2>=0 && k2<=26))
						{
							mess2[i]=mess2[i]+k2;
							if(mess2[i]>90)
							{
								mess2[i]=(mess2[i]-90)+64;
							}
						}
						else if((mess2[i]>=97 && mess2[i]<=122) && (k2>=0 && k2<=26))
						{
							mess2[i]=mess2[i]+k2;
							if(mess2[i]<0)
							{   
								excep=mess2[i]+256;
								mess2[i]=(excep-122)+96;
								//printf("%d\n",mess3[i]);
							}
						    if(mess2[i]>122)
							{
								mess2[i]=(mess2[i]-122)+96;
								//printf("%d\n",mess3[i]);
							}
						}
					}	
					printf("%s",mess2);
				}
				else if(ch2==1)
				{
					printf("Enter the message:\n");
					fflush(stdin);
					gets(mess2);
					fflush(stdin);
					printf("Enter the key:\n");
					scanf("%d",&k2);
					messlen=strlen(mess2);
					for(i=0;i<messlen;i++)
					{ 
						
						if(mess2[i]>=65 && mess2[i]<=90 && (k2>=0 && k2<=26))
						{
							mess2[i]=mess2[i]-k2;
							if(mess2[i]<65)
							{
								mess2[i]=(mess2[i]-64)+90;
							}
						
						}
						
						else if(mess2[i]>=97 && mess2[i]<=122 && (k2>=0 && k2<=26))
						{
							mess2[i]=mess2[i]-k2;
							if(mess2[i]<97)
							{
								mess2[i]=(mess2[i]-96)+122;
							}
							
						}	
					}
					printf("%s",mess2);
					}
				else
				{
					printf("Invalid Choice");
				}
				break;
			}
		case 3:
			{
				printf("You have chosen hard level, here we deal with polyalphabetic ciphers");
				printf(" In a polyalphabetic cipher the way you encode a letter changes \nalong the length of the sentence.");
				printf(" Here we are working on the Vigenere Cipher where the cipher is shifting of letters and \nthe key is a word used to encode a message.\n\n");
				printf("Algoritm for encoding:\n\n");
				printf("Each letter of the message is encrpted by shifting it forward by some number.\n");
				printf("This number is determined by the alphabetical postion of the letters of key.\n");
				printf("The first letter of the message is shifted by the alphabetical position of first letter of the key and so on.\n\n");
				printf("Press enter to continue");
				getche();
				printf("Enter 0 for encoding the message\nEnter 1 for decoding the message\n");
				printf("Enter your choice ");
				scanf("%d",&ch3);
				if(ch3==0)
				{
					printf("Enter the message:\n");
					fflush(stdin);
					gets(mess3);
					fflush(stdin);
					printf("Enter the key:\n");
					gets(k3);
					messlen=strlen(mess3);
					keylen=strlen(k3);
					//printf("%d\n",keylen);
					for(i=0;i<messlen;i++)
					{ 
						//printf("%d\n",j);
						if(j==keylen)
						{
							//printf("Here\n");
							j=0;
						}
						if((mess3[i]>=65 && mess3[i]<=90) && (k3[j]>=65 && k3[j]<=90))
						{
							shift=k3[j]-65;
							mess3[i]=mess3[i]+shift;
							if(mess3[i]>90)
							{
								mess3[i]=(mess3[i]-90)+64;
							}
							j++;
						}
						else if((mess3[i]>=65 && mess3[i]<=90)&& (k3[j]>=97 && k3[j]<=122))
						{
							shift=k3[j]-97;
							mess3[i]=mess3[i]+shift;
							if(mess3[i]>90)
							{
								mess3[i]=(mess3[i]-90)+64;
							}
							j++;
						}
						else if((mess3[i]>=97 && mess3[i]<=122) && (k3[j]>=97 && k3[j]<=122))
						{
							shift=k3[j]-97;
							//printf("%d\n",shift);
							mess3[i]=mess3[i]+shift;
							//printf("%d\n",mess3[i]);
							if(mess3[i]<0)
							{   
								excep=mess3[i]+256;
								mess3[i]=(excep-122)+96;
								//printf("%d\n",mess3[i]);
							}
						    if(mess3[i]>122)
							{
								mess3[i]=(mess3[i]-122)+96;
								//printf("%d\n",mess3[i]);
							}
							j++;
						}
						else if((mess3[i]>=97 && mess3[i]<=122)&& (k3[j]>=65 && k3[j]<=90))
						{
							shift=k3[j]-65;
							//printf("%d\n",shift);
							mess3[i]=mess3[i]+shift;
							//printf("%d\n",mess3[i]);
							if(mess3[i]<0)
							{   
								excep=mess3[i]+256;
								mess3[i]=(excep-122)+96;
								//printf("%d\n",mess3[i]);
							}
							if(mess3[i]>122)
							{
								mess3[i]=(mess3[i]-122)+96;
								
							}
							j++;
						}
						else if(mess3[i]<97 || mess3[i]>122)
						{
							mess3[i]=mess3[i];
						}				
					}
					
					printf("%s",mess3);
				}
				else if(ch3==1)
				{
					printf("Enter the message:\n");
					fflush(stdin);
					gets(mess3);
					fflush(stdin);
					printf("Enter the key:\n");
					gets(k3);
					messlen=strlen(mess3);
					keylen=strlen(k3);
					for(i=0;i<messlen;i++)
					{ 
						if(j==keylen)
						{
							j=0;
						}
						if(mess3[i]>=65 && mess3[i]<=90 && k3[j]>=65 && k3[j]<=90) 
						{
							shift=k3[j]-65;
							mess3[i]=mess3[i]-shift;
							if(mess3[i]<65)
							{
								mess3[i]=(mess3[i]-64)+90;
							}
							j++;
						}
						else if(mess3[i]>=65 && mess3[i]<=90 && k3[j]>=97 && k3[j]<=122) 
						{
							shift=k3[j]-97;
							mess3[i]=mess3[i]-shift;
							if(mess3[i]<65)
							{
								mess3[i]=(mess3[i]-64)+90;
							}
							j++;
						}
						else if(mess3[i]>=97 && mess3[i]<=122 && k3[j]>=97 && k3[j]<=122)
						{
							shift=k3[j]-97;
							//printf("%d\n",shift);
							mess3[i]=mess3[i]-shift;
							//printf("%d\n",mess3[i]);
							if(mess3[i]<97)
							{
								mess3[i]=(mess3[i]-96)+122;
							}
							j++;
						}
						else if(mess3[i]>=97 && mess3[i]<=122 && k3[j]>=65 && k3[j]<=90)
						{
							shift=k3[j]-65;
							mess3[i]=mess3[i]-shift;
							//printf("%d",shift);
							if(mess3[i]<97)
							{
								mess3[i]=(mess3[i]-96)+122;
							}
							j++;
						}				
					}
					printf("%s",mess3);
				}
				else
				{
					printf("Invalid Choice");
				}

			}
	}
	printf("Press Enter to Exit");
	scanf("%c",&z);
}
