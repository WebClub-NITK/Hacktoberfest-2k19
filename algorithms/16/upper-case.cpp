#include <stdio.h>
int main(void)
{
  int i;
  char a[10000];
  for(i=0;i<10000;i++)
  {
    scanf("%c",&a[i]);
    if(a[i]=='\n')
      break;
  }
  for(i=0;i<10000;i++)
  {
    if(a[i]>89&&a[i]<123)
    {
      a[i]=a[i]-32;
    }
    printf("%c",a[i]);
  }
  return 0;
}
