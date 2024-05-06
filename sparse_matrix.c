#include<stdio.h>
struct sparse{
    int row;
    int col;
    int val;
};

int main(){
    int m,n,size=0;
    printf("Enter matrix size: ");
    scanf("%d %d",&m,&n);
    int a[m][n];
    printf("Enter matrix elements: ");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0)
            size++;
        }
    }
    int k=0;
    struct sparse s[size];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=0){
                s[k].row=i;
                s[k].col=j;
                s[k].val=a[i][j];
                k++;
            }
        }
    }

    printf("Original Matrix : \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("Sparse Matrix : \n");
    for(int i=0;i<size;i++){
        printf("%d %d %d\n",s[i].row,s[i].col,s[i].val);
    }
}