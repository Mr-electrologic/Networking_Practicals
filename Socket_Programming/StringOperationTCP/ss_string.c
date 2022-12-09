#include "inet.h"
#define MAXLINE 512

int main()
{
int cnt,n,i,no,y=1;
int j,temp;
int p,op;
char a[100],b[100];
int length,length1,count=0;
char buf1[MAXLINE];
int sockfd,newsockfd,clilen,childpaid;
struct sockaddr_in serv_addr,cli_addr;

if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
{
perror("Server can't open socker:\n");
printf("Sockfd:%d\n",sockfd);
exit(0);
}

bzero((char*)&serv_addr,sizeof(serv_addr));
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
serv_addr.sin_port=htons(SERV_TCP_PORT);

if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
perror("server can't bind address:");
printf("sockfd:%d\n",sockfd);
exit(0);
}

listen(sockfd,5);
clilen=sizeof(cli_addr);
printf("server sockfd:%d\n",sockfd);
newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);
printf("newsockfd for clint:%d\n",newsockfd);
while(y!=0)
{
bzero(a,MAXLINE);
bzero(b,MAXLINE);
n=recvfrom(newsockfd,buf1,MAXLINE);
sscanf(buf1,"%d %s %s",&op,&a,&b);
bzero(buf1,MAXLINE);

switch(op)
{
case 1:
{
strcat(a,b);

sprintf(buf1,"output of Concatination is: %s",a);

break;
}


case 2:
{
if(strcmp(a,b)==0)
{
sprintf(buf1,"output of compare String is same");
}
else
{
sprintf(buf1,"output of compare String is different");
}
break;
}

case 3:
{
length=strlen(a);
sprintf(buf1,"output of counting the length is: %d",length);
break;
}

case 4:
{
for(i=0;a[i] != '\0';i++)
{
b[i]=a[i];
}
b[i] = '\0';
sprintf(buf1,"output of copy string 1 & 2 is:%s %s",a,b);

break;
}

case 5:
{
  i=0;
  j=strlen(a)-1;

while(i<j)
 {
   temp=a[i];
   a[i]=a[j];
   a[j]=temp;
   i++;
   j--;
  }
sprintf(buf1,"output of reversing the string is: %s",a);
break;
}

case 6:
exit(0);
}

n=strlen(buf1);
no=write(newsockfd,buf1,n);
bzero(buf1,MAXLINE);
}
close(newsockfd);
close(sockfd);
}
