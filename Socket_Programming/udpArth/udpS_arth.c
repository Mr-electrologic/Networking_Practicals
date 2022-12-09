#include "inet.h"
#define MAXLINE 512


int main()
{
int cnt,n,i,no,y=1;
int j,temp;
int p,out,opnd1,opnd2,op;
char a[100],b[100];
int length,length1,count=0;
char buf1[MAXLINE];
int sockfd,newsockfd,clilen,childpaid;;
struct sockaddr_in serv_addr,cli_addr;

if((sockfd=socket(AF_INET,SOCK_DGRAM,0))<0)
{
perror("Server can't open socker:\n");
printf("Sockfd:%d\n",sockfd);
exit(0);
}

bzero((char*)&serv_addr,sizeof(serv_addr));
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
serv_addr.sin_port=htons(SERV_UDP_PORT);

if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
perror("server can't bind address:");
printf("sockfd:%d\n",sockfd);
exit(0);
}

clilen=sizeof(cli_addr);
printf("server sockfd:%d\n",sockfd);
bzero(buf1,MAXLINE);


while(y!=0)
{
n=recvfrom(sockfd,buf1,MAXLINE,0,(struct sockaddr*)&cli_addr,&clilen);
sscanf(buf1,"%d %d %d",&op,&opnd1,&opnd2);
bzero(buf1,MAXLINE);

switch(op)
{
case 1:
{
out=opnd1+opnd2;
sprintf(buf1,"output of Addition:%d",out);
break;
}

case 2:
{
if(opnd1>opnd2)
{
out=opnd1-opnd2;
sprintf(buf1,"output of substraction:%d",out);
} 
else
sprintf(buf1,"error opnd1 must be greater then opnd2");
break;
}

case 3:
{
out=opnd1*opnd2;
sprintf(buf1,"output of multiplication:%d",out);
break;
}

case 4:
{
if(opnd1>opnd2 &&opnd2!=0)
{
out=opnd1/opnd2;
sprintf(buf1,"output of division:%d",out);
}
else
if(opnd1<opnd1)
sprintf(buf1,"error in I/P opnd1 must be greater then opnd2");
else
if(opnd2==0){
sprintf(buf1,"error in I/P opnd2!=0");
break;
}

case 5:

exit(0);
}


n=strlen(buf1);
no=sendto(sockfd,buf1,n,0,(struct sockaddr*)&cli_addr,clilen);
bzero(buf1,MAXLINE);
}


close(sockfd);
}
}

