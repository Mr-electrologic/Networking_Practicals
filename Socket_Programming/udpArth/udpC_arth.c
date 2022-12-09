#include "inet.h"
#define MAXLINE 512


int main()
{
int n=0,i,no,y=1;
int j,temp;
int opnd1,opnd2,ch=0;

char a[100],b[100];
char buf[MAXLINE];
int sockfd,servlen; 
struct sockaddr_in serv_addr,cli_addr;

bzero((char*)&serv_addr,sizeof(serv_addr));
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr(SERV_HOST_ADDR);
serv_addr.sin_port=htons(SERV_UDP_PORT);

if((sockfd=socket(AF_INET,SOCK_DGRAM,0))<0)
{
perror("client can't open socker");
}
bzero((char*)&cli_addr,sizeof(cli_addr));
cli_addr.sin_family=AF_INET;
cli_addr.sin_addr.s_addr=htonl(INADDR_ANY);
cli_addr.sin_port=htons(0);

if(bind(sockfd,(struct sockaddr*)&cli_addr,sizeof(cli_addr))<0)
{
perror("clint can't connect to server");
printf("sockfd:%d\n",sockfd);
exit(0);
}

servlen=sizeof(serv_addr);
printf("connection setup with sockfd:%d\n",sockfd);

while(y!=0) 
{
bzero(buf,MAXLINE);
printf("\n1: Addition");
printf("\n2: substraction");
printf("\n3: Multiplication");
printf("\n4: Division");
printf("\n5: exit");
printf("\n Enter your chooice:\t");
scanf("%d",&ch);

if (ch>=5)
{
if (ch>5)
printf("\n Invalid choice:\t");
exit(1);
}
printf("\n Enter the first operand:");
scanf("%d",&opnd1);
printf("\n enter the second operand:");
scanf("%d",&opnd2);
printf("\nchoice: %d",ch);
if (ch!=0)
{
printf("\nlength1: %d",n);
bzero(buf,MAXLINE);
sprintf(buf,"%d %d %d",ch,opnd1,opnd2);
n=strlen(buf);
buf[n]='\0';
printf("\nlength2: %d",n);
no=sendto(sockfd,buf,n,0,(struct sockaddr*)&serv_addr,servlen);

bzero(buf,MAXLINE);
//n=read(sockfd,buf,MAXLINE);

no=recvfrom(sockfd,buf,MAXLINE,0,(struct sockaddr*)&serv_addr,&servlen);
printf("CLINT reading at sockfd:%s\n",buf);
bzero(buf,MAXLINE);
}
else
{
y=0;
}
}
close(sockfd);
exit(0);
}

