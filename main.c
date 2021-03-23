#include <stdio.h>
#include <stdlib.h>

char jogo[3][3];
char jogador1[50], jogador2[50];

void inicializarMatriz(){
    int i,j;
    for(i=0; i < 3; i++){
        for(j=0; j < 3; j++){
            jogo[i][j] = ' ';
        }
    }
}

int eValido(char letra){
    if(letra == 'x' || letra == '0'){
        return 1;
    }else{
        return 0;
    }
}

int coordenadaEhValida(int x , int y){
    if(x >= 0 && x <3 ){
        if(y >= 0 && y < 3){
            return 1;
        }
    }
    return 0;
}

int posicaoVazia(int x , int y){
    if(jogo[x][y] != 'x' && jogo[x][y] != '0'){
        return 1;
    }

    return 0;
}

int ganhouLinhas(){
    int i,j,igual = 1;
    for(i=0; i <3; i++){
        for(j=0; j< 2; j++){
            if(eValido(jogo[i][j]) && jogo[i][j] == jogo[i][j+1]){
                igual++;
            }
        }
        if(igual == 3){
            return 1;
        }

        igual = 1;
    }

    return 0;
}

int ganhouColunas(){
    int i,j,igual = 1;
    for(i=0; i <3; i++){
        for(j=0; j< 2; j++){
            if(eValido(jogo[j][i]) && jogo[j][i] == jogo[j+1][i]){
                igual++;
            }
        }
        if(igual == 3){
            return 1;
        }

        igual = 1;
    }

    return 0;
}

int ganhouDiagPrincipal(){
    int i, igual = 1;
    for(i=0; i < 2; i++){
        if(eValido(jogo[i][i]) && jogo[i][i] == jogo[i+1][i+1]){
            igual++;
        }
    }
    if(igual == 3){
        return 1;
    }else{
        return 0;
    }

}

int ganhouDiagSecundaria(){
    int i, igual = 1;
    for(i=0; i < 2; i++){
        if(eValido(jogo[i][3-i-1]) && jogo[i][3-i-1] == jogo[i+1][3-i-2]){
            igual++;
        }
    }
    if(igual == 3){
        return 1;
    }else{
        return 0;
    }

}

void imprimir(){
    int lin, col;

    printf("\n\t  0    1    2  \n\n");
    for(lin = 0; lin < 3; lin++){
        printf("\t%d", lin);
        for(col = 0; col < 3; col++){
            if(col < 2){
                printf("  %c |",jogo[lin][col]);
            }else{
                printf("  %c ",jogo[lin][col]);
            }

        }

        if(lin < 2){
            printf("\n\t  ------------\n");
        }
    }

}

void jogar(){
    int x, y, valida, jogadas = 0, ganhou = 0, ordem = 1;
    do{

        do{
            imprimir();
            printf("\n\nDigite a coordenada que deseja jogar: ");
            scanf("%d%d", &x, &y);
            valida = coordenadaEhValida(x,y);
            if(valida == 1){
                valida += posicaoVazia(x,y);
            }
        }while(valida != 2);

        if(ordem == 1){
            jogo[x][y] = 'x';
        }else{
            jogo[x][y] = '0';
        }
        jogadas++;
        ordem++;
        if(ordem == 3){
            ordem = 1;
        }
        ganhou += ganhouLinhas();
        ganhou += ganhouColunas();
        ganhou += ganhouDiagPrincipal();
        ganhou += ganhouDiagSecundaria();
    }while(ganhou == 0 && jogadas < 9);

    if(ganhou != 0){
        imprimir();
        if(ordem - 1 == 1){
            printf("\n\nParabens!!Voce venceu %s\n", jogador1);
        }else{
            printf("\n\nParabens!!Voce venceu %s\n", jogador2);
        }
    }else{
        printf("\n\nEmpate!! Ninguem venceu dessa vez!\n\n");
    }
}

int main()
{
    int op;
    printf("Jogador 1 digite seu nome: ");
    fgets(jogador1, 50, stdin);
    printf("Jogador 2 digite seu nome: ");
    fgets(jogador2, 50, stdin);

    do{
        system("cls");
        printf("\n\nPrograma desenvolvido por Jorge Gabriel\n\n");
        printf("-----------------------------------");
        printf("\n\nJogo da Velha\n\n");
        printf("----------------------------------");
        printf("\n\n Para jogar, efetue os seguintes passos: ");
        printf("\n\n 1 - Digite o primeiro valor que corresponde a linha desejada e aperte Space");
        printf("\n\n 2 - Digite o segundo valor que corresponde a coluna desejada e aperte Enter");
        printf("\n\n Obs: Os valores possiveis a serem digitados sao os valores 0 , 1 e 2");
        printf("\n\n----------------------------------");
        inicializarMatriz();
        jogar();
        printf("Deseja jogar novamente?\n1 - Sim\n2 - Nao\n");
        printf("\n\n Informe a opcao desejada: ");
        scanf("%d", &op);
        setbuf(stdin,NULL);
    }while(op == 1);

    return 0;
}
