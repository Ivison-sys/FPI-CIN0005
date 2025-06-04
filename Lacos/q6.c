// Question name: Protótipo de Ctrl+F
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    char matriz[n][n][51];
    for(int i= 0; i < n; i++){
        for(int z= 0; z < n; z++){
            char palavra[51];
            scanf(" %50s", palavra);
            strcpy(matriz[i][z], palavra);
        }
    }
    
    char alvo[51];
    while(scanf(" %50s", alvo) != EOF){
        int reps = 0, t = strlen(alvo);
        char aux[300] = {0};
        for(int i= 0; i < n; i++){
            for(int z = 0; z < n; z++){
                char s[51];
                strcpy(s, matriz[i][z]);
                int x = 0;
                for(int w = 0; s[w];){
                    if(x == t){
                        x = 0;
                        if(strcmp(aux, alvo) == 0){
                            printf("(%d,%d)\n", i, z);
                            break;
                        }
                        strcpy(aux, "");
                        w++;
                    }
                    else{
                        int len = strlen(aux);
                        aux[x] = s[w+x];
                        x++; 
                    }
                }
            }
        }
    }

    return 0;
}