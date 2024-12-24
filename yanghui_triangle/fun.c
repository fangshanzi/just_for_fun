/*
    function description:

*/
void fun(double * const l,double * const k,int n)
{
    int i=0,j=1;
    k[0]=1;
    k[n-1]=1;
    while(i<=n-3)
    {
        k[j]=l[i]+l[i+1];
        i++;
        j++;
    }
}
