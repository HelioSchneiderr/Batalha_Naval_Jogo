#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void limpaTela(){

    system("CLS");

}

void menuInicial();

void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10]){

    int linha, coluna;
    for(linha = 0; linha < 10; linha++){
        for(coluna = 0; coluna < 10; coluna++){
            tabuleiro[linha][coluna] = 'A';
            mascara[linha][coluna] = '*';
        }

    }



}

void exibeMapa(){

int cont;
    for(cont = 0; cont < 10; cont++){

        if(cont == 0){
            cout << "     ";
        }
        cout << cont << " ";
    }
    cout << "\n";
    for(cont = 0; cont < 10; cont++){

        if(cont == 0){
            cout << "     ";
        }
        cout << "| ";
    }
    cout << "\n";

}

void exibeTabuleiro(char tabuleiro[10][10], char mascara[10][10], bool mostraMascara){

    //mapa indicador de colunas

    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };

    int linha, coluna;
    for(linha = 0; linha < 10; linha++){

        cout << linha << " - ";
        for(coluna = 0; coluna < 10; coluna++){


           switch(mascara[linha][coluna]){

           case 'A':
           cout << blue << " " << mascara[linha][coluna] << normal;
                break;
           case 'P':
            cout << " " << mascara[linha][coluna];
                break;
           default:
            cout << " " << mascara[linha][coluna];
                break;


           }


        }

        cout << "\n";

    }

    if(mostraMascara == true){

        for(linha = 0; linha < 10; linha++){

        cout << linha << " - ";
        for(coluna = 0; coluna < 10; coluna++){
            //cout << " " <<tabuleiro[linha][coluna];
            cout << " " <<mascara[linha][coluna];
        }
    }

}


}

void posicionaBarcos (char tabuleiro[10][10]){

    int cont;

    for(cont = 0; cont < 10; cont++){

        int linhaBarco = rand()%10;
        int colunaBarco = rand()%10;

        tabuleiro[linhaBarco][colunaBarco] = 'p';

    }



}
void verificaTiro(char tabuleiro[10][10], int linhaJogada, int colunaJogada, int *pontos, string *mensagem){

    switch(tabuleiro[linhaJogada][colunaJogada]){

            case 'p':
                *pontos = *pontos + 10;
                *mensagem = "Voce acertou um barco pequeno! (+10 Pontos)";
                break;

            case 'A':
                *mensagem = "Você acertou a água";
                break;
        }

}

void jogo(string nomeDoJogador){

    ///Variáveis Gerais
    char tabuleiro[10][10],mascara[10][10];             //Tabuleiro do Jogo
    int linha,coluna;                                   //Auxiliares de navegação
    int linhaJogada, colunaJogada;                      //Posicao escolhida pelo jogador
    int estadoDeJogo = 1;                               //1 = Jogo Acontecendo, 0 = Fim de Jogo
    int pontos = 0;                                     //Pontuação do Jogador
    int tentativas = 0, maximoDeTentativas = 5;         //Tentativas do jogador
    int opcao;                                          //Opções de fim de jogo
    string mensagem = "Bem vindo ao jogo!";             //Mensagem de feedback para o jogador

    //Inicia o tabuleiro com água
    iniciaTabuleiro(tabuleiro,mascara);

    //Posiciona barcos aleatoriamente
    posicionaBarcos(tabuleiro);

    while(tentativas < maximoDeTentativas){

        limpaTela();

        //Exibe o mapa de indicações
        exibeMapa();

        //Exibe tabuleiro
        exibeTabuleiro(tabuleiro,mascara, false);

        cout << "\nPontos:" << pontos << ", Tentativas Restantes:" << maximoDeTentativas - tentativas;
        cout << "\n" << mensagem;

        //Verificação de dados
        linhaJogada = -1;
        colunaJogada = -1;

        while( (linhaJogada < 0 || colunaJogada < 0) ||  (linhaJogada > 9 || colunaJogada > 9)) {

            cout << "\n" << nomeDoJogador << ", digite uma linha:";
            cin >> linhaJogada;
            cout <<  "\n" << nomeDoJogador << ", digite uma coluna:";
            cin >> colunaJogada;

        }

        //Verifica o que aconteceu
        verificaTiro(tabuleiro, linhaJogada, colunaJogada, &pontos, &mensagem);

        //Reveka o que está no tabuleiro
        mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];

        tentativas++;

    }


        cout << "Fim de jogo, o que deseja fazer";
        cout << "\n1 - Jogar Novamente";
        cout << "\n2 - Ir para o Menu";
        cout << "\n3 - Sair";
        cin >> opcao;

        switch(opcao){

            case 1:

                jogo(nomeDoJogador);
                break;

            case 2:
                menuInicial();
                break;

            case 3:
                limpaTela();
                break;



        }




}


void menuInicial(){
    //opção escolhida pelo usuario
    int opcao = 0;

    string nomeDoJogador;

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
            cout << "Qual seu nome";
            cin >> nomeDoJogador;
            jogo(nomeDoJogador);

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

    //gerar números aleatorios
    srand( (unsigned)time(NULL));


    menuInicial();


    return 0;
}
