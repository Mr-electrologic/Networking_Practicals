#include "inet.h"
#define MAXLINE 512

int main()
{
 int cnt,n,i,no,y=1;

 char buf1[MAXLINE];
 int sockfd,newsockfd,clilen;
 struct sockaddr_in serv_addr,cli_addr;      

 if ((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
 {
  perror("server can't open socket:\n");
  printf("sockfd:%d\n",sockfd);
  exit(0);
 }

 bzero((char*)&serv_addr,sizeof(serv_addr));
 serv_addr.sin_family=AF_INET;
 serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
 serv_addr.sin_port=htons(SERV_TCP_PORT);

if (bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
 perror("server can't bind address:");
 printf("sockfd:%d\n",sockfd);
 exit(0);
}
  
listen(sockfd,5);

clilen=sizeof(cli_addr);

printf("Server sockfd:%d\n",sockfd);

newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);
printf("newsockfd for client:%d\n",newsockfd);

while(y!=0)
{

 n=read(newsockfd,buf1,MAXLINE);

 if(n<0)break;
 if ((strncmp(buf1,"exit",4))!=0)
 {
   printf("SERVER reading from sockfd:%s\n",buf1);
   n=strlen(buf1);
   
   no=write(newsockfd,buf1,n);
   bzero(buf1,MAXLINE);   
 }
else
 {
  printf("Client closed the connection\n");
  y=0;
 }
}   
close(newsockfd);
close(sockfd); 
  
}
