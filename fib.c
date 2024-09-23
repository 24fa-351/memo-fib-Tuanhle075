#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int storedFib[50];
unsigned long long int fibRec(int n){
   if (n==1){
      return 0;
   }
   else if (n==2 ||n==3){
      return 1;
   }
   else{
      if (storedFib[n-1]==1){
         storedFib[n-1]=fibRec(n-1);
         
      }
      if (storedFib[n-2]==-1){
         storedFib[n-2]=fibRec(n-2);
      }

      return (fibRec(n-1)+fibRec(n-2));
   }

}
unsigned long long int fibIter(int n){
   if (n==1){
      return 0;
   }
   else if (n==2 ||n==3){
      return 1;
   }
   int terms[100]={0,1};
   int i=2;
   while(i<=n-1){
      terms[i]=(terms[i-1]+terms[i-2]);
      i=i+1;
   }
   return terms[n-1];
}

int main(int argc, char** argv){
   FILE *file_ptr;
   char str[50];
   file_ptr = fopen(argv[3], "r");
   fgets(str, 50, file_ptr);
   fclose(file_ptr);
   int num= atoi(argv[1])+atoi(str);
   if (strcmp(argv[2], "r") == 0){
   printf("%d", fibRec(num));
   }
   else {
      printf("%d", fibIter(num));
   }
   return 0;
}