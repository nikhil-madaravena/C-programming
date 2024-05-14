#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
    int amax=0,omax=0,xmax=0;
    for(int i=1;i<=k;i++){
        for(int j = i+1;j<=n;j++){
            if((i&j)<k && (i&j)>amax)
            amax=(i&j);
            if((i|j)<k && (i|j)>omax)
            omax=(i|j);
            if((i^j)<k && (i^j)>xmax)
            xmax=(i^j);
        }
    }
    printf("%d\n%d\n%d\n",amax,omax,xmax);
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
