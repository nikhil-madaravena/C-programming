#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int num[10]={0};
    char s[1000];
    scanf("%[^\n]%*c",s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='0'){
            num[0]++;
        }else if(s[i]=='1'){
            num[1]++;
        }else if(s[i]=='2'){
            num[2]++;
        }else if(s[i]=='3'){
            num[3]++;
        }else if(s[i]=='4'){
            num[4]++;
        }else if(s[i]=='5'){
            num[5]++;
        }else if(s[i]=='6'){
            num[6]++;
        }else if(s[i]=='7'){
            num[7]++;
        }else if(s[i]=='8'){
            num[8]++;
        }else if(s[i]=='9'){
            num[9]++;
        }
    }    
    for(int i=0;i<10;i++){
        printf("%d ",num[i]);
    }
    printf("\n");
    return 0;
}
