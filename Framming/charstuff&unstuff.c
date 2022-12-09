#include<stdio.h>
#include<string.h>
int len,i=0,j=0,cnt=0;
char bit[100], out[100];
int main()
{

printf("Character Stuffing\n");
printf("please enter the string\n");
charstuff();
charunstuff();
}
void charstuff()
{
gets(bit);
len=strlen(bit);
printf("SPECIAL CHARACTER USED FOR FRAME BOUNDRY IS $ \n");
printf("the output after Stuffing is   \n");
printf("$");
out[j++]='$';

for(i=0;i<len;i++)
{
    if( bit[i]=='$')
    { printf("%c",'$');
      out[j++]='$'; 
   }
	     printf("%c",bit[i]);
        out[j++]=bit[i];
} 
printf("$");
out[j]='$';
printf("\n");
}

void charunstuff()
{
len=strlen(out);
printf("the output after D-Stuffing is   \n");
for(i=1;i<len-1;i++)
{
    if(out[i]=='$')
		cnt++;
		if(cnt==2)
		{
			cnt=0;
			continue;	
		}
	printf("%c",out[i]);
}
printf("\n");
} 
