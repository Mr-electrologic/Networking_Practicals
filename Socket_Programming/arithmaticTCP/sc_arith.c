#include "inet.h"
#define MAXLINE 512

main()
{
 int n,i,no,y=1;
 int opnd1,opnd2,ch=0;
 char buf[MAXLINE];
 int sockfd,servlen;
 struct sockaddr_in serv_addr,cli_addr;  
 
 bzero((char*)&serv_addr,sizeof(serv_addr));  
 serv_addr.sin_family=AF_INET;  
 serv_addr.sin_addr.s_addr=inet_addr(SERV_HOST_ADDR);
 serv_addr.sin_port=htons(SERV_TCP_PORT); 

 if ((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
 {
  perror("client can't open socket");
 }

if (no=connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
 perror("client can't connect to server");
 printf("sockfd:%d\n",sockfd);
 exit(0); 
}

servlen=sizeof(serv_addr);
printf("Connection setup with sockfd:%d\n",sockfd);

while(y!=0)
{

   bzero(buf,MAXLINE);
   printf("\n1: Addition");
   printf("\n2: Subtraction");
   printf("\n3: Multiplication");
   printf("\n4: Division");
   printf("\n5: Exit");
   printf("\nEnter your choice : \t");
   scanf("%d",&ch); 

   if(ch >= 5)
   { 
	if (ch > 5)
         	printf("\nInvalid choice : \t");
 	exit(1);
   }

   printf("\n Enter the first operand:");
   scanf("%d",&opnd1);
   printf("\n Enter the second operand:");
   scanf("%d",&opnd2);
   
   if(ch!=0) 
   {
        bzero(buf,MAXLINE);
 	sprintf(buf,"%d  %d  %d",ch,opnd1,opnd2);
   	n=strlen(buf);
        buf[n]='\0';
        write(sockfd,buf,n);

    	bzero(buf,MAXLINE);   
	n=read(sockfd,buf,MAXLINE);
	printf("CLIENT reading at sockfd: %s\n",buf);
	bzero(buf,MAXLINE);   
   }
else
  y=0;
}
close(sockfd); 
exit(0);
}  
