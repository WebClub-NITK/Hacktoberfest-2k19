int Number_of_pairs(int *a,int n,int x)
{
      int i,j,count=0;
        for(i=0;i<n;++i)
        for(j=i+1;j<n;++j)
                if(a[i]+a[j]==x)
                        ++count;
        return count;
}
