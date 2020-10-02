
#include <stdio.h>

int main(){
    int c, n, f = 1;
    
    printf("Enter a number to calculate its factorial\n");
    scanf("%d", &n);
    if(n>=0){
        for (c = 1; c <= n; c++)
            f = f * c;
    
        printf("Factorial of %d = %d\n", n, f);
    }
    else
        printf("Number Should be greater than zero\n");
    return 0;
}
