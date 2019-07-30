#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    char a[201];
    int len;
    while(scanf("%s",a)!=EOF)
    {
        len=strlen(a);
        sort(a,a+len);
        puts(a);
        while(next_permutation(a,a+len))
            puts(a);
    }
    return 0;
}
