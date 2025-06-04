// Question name: Índice de plágio
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char inp1[501], inp2[501];
    char l1[50][101], l2[50][101];
    scanf("%[^\n]%*c%[^\n]%*c", inp1, inp2);
    int p1 = 0;
    int ip = 0;
    // Formando o vetor l1
    for(int i = 0; inp1[i]; i++){
        if(inp1[i] != ' '){
            l1[p1][ip] = tolower(inp1[i]);
            ip++;
        }
        else{
            l1[p1][ip] = '\0';
            p1++;
            ip = 0;
        }
    }
    l1[p1][ip] = '\0';

    // Formando o vetor l2
    int p2 = 0;
    ip = 0;
    for(int i = 0; inp2[i]; i++){
        if(inp2[i] != ' '){
            l2[p2][ip] = tolower(inp2[i]);
            ip++;
        }
        else{
            l2[p2][ip] = '\0';
            p2++;
            ip = 0;
        }
    }
    l2[p2][ip] = '\0';
    
    int t = 0;

    for(int i = 0; i <= p1; i++){
        int aux = 0;
        for(int z = 0; z <= p2; z++){
            int isIgual = 1;
            if(strcmp(l1[i],l2[z]) != 0){
                isIgual = 0;
            }
            if(isIgual){
                // printf("%s -- %s (%d, %d)\n", l1[i], l2[z], i, z);
                aux++;
                l2[z][0] = '\0';
            } 
        }
        if(aux){
            t++;
        }
    }
    // printf("%d %d %d\n", t, p1, p2);
    printf("%.1f", ((float)t/(p1+p2+2))*100);

    return 0;
}