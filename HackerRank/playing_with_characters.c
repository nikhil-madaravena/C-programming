#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() 
{
    char a;
    char ch[100];
    char chh[100];
    
    scanf("%c", &a);
    scanf("%s\n",ch);
    scanf("%[^\n]%*c",chh);
    
    printf("%c\n%s\n%s\n",a,ch,chh);

    return 0;
}
