#include <stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

main()
{
	char ipc[40],*ip3c[40],subnetc[40];
	unsigned int ipu,subnetu,ip,sub;
	int i,s;

	struct in_addr ip_struct,subnet_struct,ip_struct1; 

	printf("Enter the IP address : ");
	scanf("%s",ipc);

	i=inet_aton(ipc,&ip_struct);

	ipu=ntohl(ip_struct.s_addr);

	
	printf("\n Enter the subnet mask address : ");
	scanf("%s",subnetc);

	s=inet_aton(subnetc,&subnet_struct);

	subnetu=ntohl(subnet_struct.s_addr);

	if(i==1 && s==1)
	{
		ip=ipu&subnetu;
		
		ip_struct.s_addr=htonl(ip);

		sub=ipu&(~subnetu);

/* The  inet_ntoa()  function converts the Internet host address in, given
       in network byte order, to a string  in  IPv4  dotted-decimal  notation.
       The  string  is returned in a statically allocated buffder, which subse‐
       quent calls will overwrite.
*/
		ip3c[0]=inet_ntoa(ip_struct);

		printf("\nThe network address is  \t%s\n",*ip3c);	
			
		printf("\n host ip address is \t %x in hexadecimal\n",sub);
	}
	else
	{
		printf("\n Not a valid address");
	}
	} 






