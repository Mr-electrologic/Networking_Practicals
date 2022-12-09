#include "inet.h"
#define MAXLINE 512

int main()
{
int n,i,no,y=1;
int j,temp;
int ch=0;
char a[100],b[100];
char buf[MAXLINE];
int sockfd,servlen;
struct sockaddr_in serv_addr,cli_addr;

bzero((char*)&serv_addr,sizeof(serv_addr));
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr(SERV_HOST_ADDR);
serv_addr.sin_port=htons(SERV_TCP_PORT);

if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
{
perror("client can't open socker");
}
if(no=connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
perror("client can't connect to server");
printf("Sockfd:%d\n",sockfd);
exit(0);
}
servlen=sizeof(serv_addr);
printf("connection setup with sockfd:%d\n",sockfd);

while(y!=0)
{
bzero(buf,MAXLINE);
printf("\n1: Concatinate");
printf("\n2: Compare string");
printf("\n3: Count length");
printf("\n4: Copy string");
printf("\n5: Reverse");
printf("\n6: exit");
printf("\n Enter your chooice:\t");
scanf("%d",&ch);

if(ch>=6)
{
if(ch>6)
printf("\n Invalid choice:\t");
exit(1);
}

switch(ch)
{
case 1:
{
bzero(a,MAXLINE);
bzero(b,MAXLINE);
printf("\n Enter the first string:");
scanf("%s",&a);
printf("\n enter the second string:");
scanf("%s",&b);
break;
}
case 2:
{
printf("\n Enter the first string:");
scanf("%s",&a);
printf("\n enter the second string:");
scanf("%s",&b);
break;
}
case 3:
{
printf("\n Enter the first string:");
scanf("%s",&a);
break;
}
case 4:
{
printf("\n Enter the first string:");
scanf("%s",&a);
break;
}
case 5:
{
printf("\n Enter the first string:");
scanf("%s",&a);
break;
}
case 6:
exit(0);
}


if(ch!=0)
{
bzero(buf,MAXLINE);
sprintf(buf,"%d %s %s",ch,a,b);
n=strlen(buf);
buf[n]='\0';
write(sockfd,buf,n);

bzero(buf,MAXLINE);
n=read(sockfd,buf,MAXLINE);
printf("CLINT reading at sockfd:%s\n",buf);
bzero(buf,MAXLINE);
}
else
y=0;
}
close(sockfd);
exit(0);
}
