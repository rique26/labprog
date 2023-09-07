#include<stdio.h>

int main()
{
    int i;
    int c = 0, f = 0;
    
    for (i=1;i<=10;i++){
        
        c += 10;
        f = (c*1.8)+32;
        
        printf("Celsius: %d\tFahrenheit: %d\n", c, f);
        
    }
    return 0;
}
