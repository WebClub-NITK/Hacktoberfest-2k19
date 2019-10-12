#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
  int c, n;
  FILE *fp = fopen("output.txt","w");
  fprintf(fp,"random numbers : \n");

  for (c = 1; c <= 100000; c++) {
    n = rand() % 100 + 1;
    fprintf(fp,"%d ", n);
  }
  fclose(fp);

  return 0;
}
