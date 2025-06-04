// Question name: faísca e fumaça
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int r;
    char sinais[2];
    scanf("%d", &r);
    char trilhas[r][61];
    for(int i =0; i < r; i++){
        char trilha[61];
        scanf(" %s", trilha);
        int clocks;
        scanf("%d", &clocks);

        for(int z = 0; z < clocks; z++){
            if(trilha[0] == 'X'){
                trilha[0] = 'O';
            }
            else{
                trilha[0] = 'X';
                int pos = 1;
                int isDesligado = 0;
                do{
                    isDesligado = 0;
                    if(trilha[pos] == 'X'){
                        trilha[pos] = 'O';
                    }
                    else{
                        trilha[pos] = 'X';
                        isDesligado = 1;
                    }
                    pos++;
                }while(pos < strlen(trilha) && isDesligado);
            }
        }
        for(int w = 0; trilha[w]; w++){
            printf("%c", trilha[w]);
            trilhas[i][w] = trilha[w];
        }
        printf("\n");
    }

    
    char ultimo;
    for(int i = 0; trilhas[r-1][i] == 'X' ||  trilhas[r-1][i] == 'O'; i++){
        ultimo = trilhas[r-1][i];
    }

    
    int t = 0;
    char ult = 'a';
    for(int i= 0; i < r; i++){
        if(i > 0){
            if(t % 2 == 0){
                sinais[0] = '@';
                sinais[1] = '$';
            }
            else{
                sinais[0] = '#';
                sinais[1] = '%';
            }

            if(ultimo == trilhas[i][0]){
                printf("%c", sinais[0]);
            }
            else{
                printf("%c", sinais[1]);
            }
            // printf("\n%d %c %c\n", t, ultimo, trilhas[i][0]);

            t++;
        }
        
        for(int z = 0; trilhas[i][z]; z++){
            if(trilhas[i][z] == 'X' || trilhas[i][z] == 'O'){
                printf("%c",trilhas[i][z]);
                t++;
                ultimo = trilhas[i][z];
            }
        }
    }
    return 0;
}