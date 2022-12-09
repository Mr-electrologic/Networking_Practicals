#include "inet.h"
#define MAXLINE 512

int main()
{
 int n,i,no,y=1;
 char buf[MAXLINE];
 int sockfd;
 struct sockaddr_in serv_addr,cli_addr;  
 
 bzero((char*)&serv_addr,sizeof(serv_addr));  
 serv_addr.sin_family=AF_INET;  
 serv_addr.sin_addr.s_addr=inet_addr(SERV_HOST_ADDR);
 serv_addr.sin_port=htons(SERV_TCP_PORT); 

 if ((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
 	perror("client can't open socket");
 
if (no=connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
 perror("client can't connect to server");
 printf("sockfd:%d\n",sockfd);
 exit(0); 
}

printf("Connection setup with sockfd:%d\n",sockfd);

while(y!=0)
{

   bzero(buf,MAXLINE);
   printf("CLIENT:");
   fgets(buf,MAXLINE,stdin);
   n=strlen(buf);
   buf[n-1]='\0';
   no=write(sockfd,buf,n);

  
   if((strcmp(buf,"exit"))!=0)
 {

    bzero(buf,MAXLINE);   
    n=read(sockfd,buf,MAXLINE);
    printf("CLIENT reading at sockfd: %s\n",buf);
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
