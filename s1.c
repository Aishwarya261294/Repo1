#include <stdio.h>
int main()
{
  int i, j, flag;
  int k;
  int t;

  scanf("%d", &t);
  int a[t];
  int b[t];
  for(i = 0; i <=t; i++) {
    scanf("%d", &a[i]);
    scanf("%d", &b[i]);
  }
        for(i = m + 1; i < n; ++i) {
            flag = 0;
            for(j = 2; j <= i/2; ++j) {
                if(i % j == 0){
                    flag = 1;
                    break;
                }
            }
        if(flag == 0)
        printf("%d ",i);
        }

  return 0;
}
