// Question name: 

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int r;
    scanf("%d", &r);
    for(int i = 0; i < r; i++){
        char aberturas[101] = {0};
        char exp[101] = {0};
        scanf("%100s", exp);
        int in = 0;
        int isValid = 1;
        for(int z = 0; exp[z] && isValid; z++){   
            if(exp[z] == '(' || exp[z] == '[' || exp[z] == '{'){
                aberturas[in++] = exp[z];
            }
            else{
                in -= 1;
                char uAber = aberturas[in];

                if(!((exp[z] == ')' && uAber == '(') || (exp[z] == ']' && uAber == '[') || (exp[z] == '}' && uAber == '{'))){
                    isValid = 0;
                }
        
            }
        }
        if(isValid && in == 0){
            printf("True\n");
        }
        else printf("False\n");
    }
    return 0;
}