#include <stdio.h>
#include <string.h>

int num;

int sequence[101], min, best[101], sort[101];

void find(int n)
{
     int i;
     if (n > min)
        return ;
     if (sequence[n] == num) {
        for (i = 0; i <= n; i++)
            best[i] = sequence[i];
        best[i] = 0;
        min = n;
        return;
     }
     for (i = 0; i <= n; i++) {
         sequence[n+1] = sequence[i]+sequence[n];
         if (sequence[n+1] > num)
            break;
         if (n+1 > sort[sequence[n+1]])
            continue;
         else
            sort[sequence[n+1]] = n+1;
         find(n+1);
     }
}

int main()
{
    int i;
    sequence[0] = 1;
    num = 0;
    memset(sort, 100, sizeof(sort));
    while (scanf("%d", &num), num) {
          min = 100;
          find(0);
          for (i= 0; best[i]; i++)
              printf("%d ", best[i]);
          printf("\n");
    }
    
    return 0;
}