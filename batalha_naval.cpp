#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void limpaTela(){

    system("CLS");

}

void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10]){

    int linha, coluna;
    for(linha = 0; linha < 10; linha++){
        for(coluna = 0; coluna < 10; coluna++){
            tabuleiro[linha][coluna] = 'A';
            mascara[linha][coluna] = '*';
        }

    }



}

void exibeTabuleiro(char tabuleiro[10][10], char mascara[10][10]){
    int linha, coluna;
    for(linha = 0; linha < 10; linha++){
        for(coluna = 0; coluna < 10; coluna++){
            //cout << " " <<tabuleiro[linha][coluna];
            cout << " " <<mascara[linha][coluna];
        }

        cout << "\n";


    }


}

void jogo(){

    ///váriaveis gerais
    char tabuleiro[10][10], mascara[10][10];        //Tabuleiro do jogo
    int linha, coluna;                              //Auxiliar de Navegação
    int linhaJogada, colunaJogada;                  //Posição escolhida pelo jogador
    int estadoDeJogo = 1;                           // 1 = jogo ocorrendo   0 = fim de jogo


    iniciaTabuleiro(tabuleiro, mascara);

    while(estadoDeJogo == 1){
        exibeTabuleiro(tabuleiro, mascara);

        cout << "\n Digite uma Linha:";
        cin >> linhaJogada;
        cout << "\Digite uma Coluna:";
        cin >> colunaJogada;

        mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];
    }




}

void menuInicial(){
    //opção escolhida pelo usuario
    int opcao = 0;

    // enquanto o jogador não digitar uma opção valida o menu aparece novamente
    while(opcao < 1 || opcao >3){

        limpaTela();
        cout << "Bem Vindo ao Jogo\n";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\n\n\nEscolha uma das alternativas e aperte ENTER";
        cin  >> opcao; //leitura da opção

        switch(opcao){

        case 1:
        //inicia o jogo
            cout << "Jogo Iniciado\n\n";
            jogo();

        break;


        case 2:
        //Mostra informações do jogo
            cout << "informações do Jogo";


        break;

        case 3:
            cout << "Até mais";
        break;

    }

}


}

int main(){

    menuInicial();


    return 0;
}
