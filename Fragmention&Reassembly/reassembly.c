#include <stdio.h>
#include <stdlib.h>
int main()
{   FILE *file;
    int a[30],c[30],d[30],e[30],i=0,nol=0,fin;
    char b[30],line[80];

    file = fopen("out.txt", "r");
    if (file!=NULL)
    {	printf("File opened successfully..\n\nProcessing..\n\n");  }
     else
        printf ("error");
	while (fgets(line,80,file)!=NULL)
	   nol++;
	fclose(file);
    file = fopen("out.txt", "r");

	while (!feof(file)&& i<=nol)
	{   printf("\n file contents are as follows");
		for(i=1;i<=nol;i++)
	    {  fscanf(file,"%d %c %d %d %d",&a[i],&b[i],&c[i],&d[i],&e[i]);
        printf("\n %d    %c    %d    %d    %d",a[i],b[i],c[i],d[i],e[i]);
	    }
	}
	printf ("\nThere are %d fragments in the file",nol);

	for (i=1;i<=nol;i++)
	{ if (a[i]!=i)
	   {  printf ("\nSr. Number incorrect cannot reassembly - Incorrect Packet");
	      exit(1);  } }
	for (i=1;i<nol;i++)
	{ if (b[i]!=b[i+1])
	  {	printf ("\nIdentifier incorrect cannot reassembly - Incorrect Packet");
		exit(1); }  }
	for (i=1;i<nol;i++)
	{  if ((c[i]!=1)||(c[nol]!=0))
	   {	printf ("\nM/F bit incorrect cannot reassembly - Incorrect Packet");
		exit(1);  }  }
	for (i=2;i<nol;i++)
	{  if (e[i]!=e[i-1])
	   {  	printf ("\nFragment size incorrect cannot reassembly - Incorrect Packet");
		exit(1);  }  }
	if (d[1]!=0)
	{  printf ("\nOffset incorrect cannot reassembly - Incorrect Packet");
	   exit(1);  }
	for (i=2;i<nol;i++)
	{  if ((d[i]!=d[i-1]+e[i-1]) || (d[nol]!=d[nol-1]+e[nol]))
	   {  printf ("\nOffset incorrect cannot reassembly - Incorrect Packet");
	      exit(1);  }  }
printf ("\nPacket reassembled\n");
printf ("\nSize of packet= %d \n", d[nol-1]+e[nol]);
fclose(file);
return 0;
}
