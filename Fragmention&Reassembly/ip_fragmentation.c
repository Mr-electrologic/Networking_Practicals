#include<stdio.h>
int main()
{
    long dsize,mtusize,oset,psize,ndsize;
    int flag=1,i,mf=1;
    char ident='X';
    FILE *f;

    f=fopen("out.txt","w");
    printf ("Enter the size of the data\n");
    scanf ("%ld",&dsize);

    while (flag==1)
    {
        printf ("Enter the size of the Maximum Transfer Unit (MTU-20) should be a multiple of 8 \n");
        scanf ("%ld",&mtusize);
        if ((mtusize-20)%8==0)
            flag=0;
         if (flag == 1)
            printf("Please re-enter the MTU ..... incorrect input \n");
    }
    oset=0;
    psize= mtusize-20;
    for (i=1; oset<dsize; i++)
    {
        fprintf (f,"%d\t%c\t%d\t%ld\t%ld\n", i,ident,mf,oset,psize);
        oset=oset+psize;
    }
    if (oset>=dsize)
    {
        mf=0;
        oset=oset-psize;
        ndsize=dsize-oset;
        if (oset==dsize)
            ndsize=psize;
        fprintf (f,"%d\t%c\t%d\t%ld\t%ld\n", i,ident,mf,dsize,ndsize);
    }
    fclose(f);
    return 0;
}
