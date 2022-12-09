#include<stdio.h>
#include<string.h>

int len,i,j=0,cnt=0;
char bit[25],out[25];

int main()
{
printf("please enter the sequence of bits(0 and 1) for transmission\n");
bitstuff();
printf("The sequence of bits after de-stuffing is\n");
bitunstuff();
}

void bitstuff()
{
gets(bit);
len=strlen(bit);

printf("the output after bit stuffing is \n");
printf("01111110 "); //flag start delimiter

for(i=0;i<=len;i++) 
{
    if(bit[i]=='1')
    cnt++;  //incrementing counter for 1's

    printf("%c",bit[i]); //printing the bit 
    out[j++]=bit[i];
   
    if(bit[i]=='0') 
      cnt=0; // re-initialize the counter
    if(cnt==5)
    {
	printf("%c",'0');// stuff a 0 in the o/p display bit string
	 out[j++]='0'; // stuff a 0 in the o/p bit string
	  
 	cnt=0; // re-initialize the counter
    }
}  // end of the i/p string

printf("01111110"); //flag end delimiter
printf("\n");

len=strlen(out);
for(i=0;i<=len;i++) 
printf("%c",out[i]);
printf("\n");
}
void  bitunstuff()
{
len=strlen(out);
printf("the output after D-Stuffing is   \n");
for(i=0;i<len;i++)
{
    if(out[i]=='1')
       cnt++;

	if(out[i]=='0')
	{
	  if(cnt>0 && cnt<5)
	    cnt=0;	
	  if( cnt==5)
          {  i=i+1;  //i++
             cnt=0;        	
	     if (out[i]=='1')
                cnt++;
             else
                cnt=0;
          }
	}
	printf("%c",out[i]);
}
printf("\n");
}
