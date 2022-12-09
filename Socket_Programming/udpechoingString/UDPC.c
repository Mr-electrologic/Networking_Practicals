#include "inet.h"
#define MAXLINE 512

int main()
{
int n,i,no,y=1;

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
printf("CLINT:");
fgets(buf,MAXLINE,stdin);
n=strlen(buf);
buf[n-1]='\0';
no=sendto(sockfd,buf,n,0,(struct sockaddr*)&serv_addr,servlen);

if((strcmp(buf,"exit"))!=0)
{
bzero(buf,MAXLINE);
n=recvfrom(sockfd,buf,MAXLINE,0,(struct sockaddr*)&serv_addr,&servlen);
printf("CLINT READING at sockfd:%s\n",buf);

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
else
{
y=0;
}
}
close(sockfd);
exit(0);
}

