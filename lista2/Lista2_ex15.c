#include<stdio.h>
#include<math.h>

int main()
{    
    int base = 3, i, result;
    
    for (i=0;i<=7;i++){
        result = pow(base,i);
        printf("%d\n", result);
    }
    
    return 0;
}
