#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct Historia
{
    char antagonista[256];
    char protagonista[256];
    unsigned short int dificuldade;
};

struct Tropa
{
    char *name;
    short int quantidade;
    short int defesa;
    unsigned short int velocidade;
    unsigned short int dano;
    unsigned short int round;
};

struct Exercito
{
    struct Tropa tropas[5];
};

int menu();

void historia(struct Historia *ptr);

int batalha(struct Exercito *player, struct Exercito *bot);

int selectMoves(int defesa);

int selectTropas(struct Exercito *ptr);

int main() {
    time_t t;
    /* Intializes random number generator */
    srand((unsigned)time(&t));

    int selectMenu = menu();

    while (selectMenu == 0)
    {
        // Novo jogo
        struct Historia inputs = (struct Historia){"", "", 0};
        historia(&inputs);

        printf("\n dificuldade: %d \n", inputs.dificuldade);

        if (inputs.dificuldade == 3)
        {
            printf("\033[H\033[J");
            printf("|------------------GAME OVER-----------------|\n");
            printf("|Você perdeu a maior parte dos seus recursos,|\n");
            printf("|sua população ficou furiosa,                |\n");
            printf("| e você tomou um golpe de estado            |\n");
            printf("|--------------------------------------------|\n");
        }
        else
        {
            struct Exercito player;
            struct Exercito bot;
            struct Tropa tropa;

            tropa.name = "Escudeiro";
            tropa.defesa = 0;
            tropa.velocidade = 2;
            tropa.dano = 3;
            tropa.round = 0;

            player.tropas[0] = tropa;

            tropa.name = "Arqueiro";
            tropa.defesa = -1;
            tropa.velocidade = 2;
            tropa.dano = 4;
            tropa.round = 0;

            player.tropas[1] = tropa;

            tropa.name = "Mago";
            tropa.defesa = 2;
            tropa.velocidade = 3;
            tropa.dano = 8;
            tropa.round = 0;

            player.tropas[2] = tropa;

            tropa.name = "Trabuco";
            tropa.defesa = -1;
            tropa.velocidade = 4;
            tropa.dano = 16;
            tropa.round = 0;

            player.tropas[3] = tropa;

            tropa.name = "Cavalaria";
            tropa.defesa = 4;
            tropa.velocidade = 1;
            tropa.dano = 2;
            tropa.round = 0;

            player.tropas[4] = tropa;

            tropa.name = "Escudeiro";
            tropa.defesa = 0;
            tropa.velocidade = 2;
            tropa.dano = 3;
            tropa.round = 0;

            bot.tropas[0] = tropa;

            tropa.name = "Arqueiro";
            tropa.defesa = -1;
            tropa.velocidade = 2;
            tropa.dano = 4;
            tropa.round = 0;

            bot.tropas[1] = tropa;

            tropa.name = "Mago";
            tropa.defesa = 2;
            tropa.velocidade = 3;
            tropa.dano = 8;
            tropa.round = 0;

            bot.tropas[2] = tropa;

            tropa.name = "Trabuco";
            tropa.defesa = -1;
            tropa.velocidade = 4;
            tropa.dano = 16;
            tropa.round = 0;
            bot.tropas[3] = tropa;

            tropa.name = "Cavalaria";
            tropa.defesa = 4;
            tropa.velocidade = 1;
            tropa.dano = 2;
            tropa.round = 0;
            bot.tropas[4] = tropa;

            if (inputs.dificuldade == 0)
            {
                player.tropas[0].quantidade = 30;
                player.tropas[1].quantidade = 20;
                player.tropas[2].quantidade = 20;
                player.tropas[3].quantidade = 20;
                player.tropas[4].quantidade = 30;

                bot.tropas[0].quantidade = 20;
                bot.tropas[1].quantidade = 10;
                bot.tropas[2].quantidade = 10;
                bot.tropas[3].quantidade = 10;
                bot.tropas[4].quantidade = 20;
            }
            else if (inputs.dificuldade == 1)
            {
                player.tropas[0].quantidade = 30;
                player.tropas[1].quantidade = 20;
                player.tropas[2].quantidade = 10;
                player.tropas[3].quantidade = 20;
                player.tropas[4].quantidade = 30;

                bot.tropas[0].quantidade = 30;
                bot.tropas[1].quantidade = 20;
                bot.tropas[2].quantidade = 10;
                bot.tropas[3].quantidade = 20;
                bot.tropas[4].quantidade = 30;
            }
            else if (inputs.dificuldade == 2)
            {
                player.tropas[0].quantidade = 20;
                player.tropas[1].quantidade = 10;
                player.tropas[2].quantidade = 10;
                player.tropas[3].quantidade = 10;
                player.tropas[4].quantidade = 20;

                bot.tropas[0].quantidade = 30;
                bot.tropas[1].quantidade = 20;
                bot.tropas[2].quantidade = 10;
                bot.tropas[3].quantidade = 20;
                bot.tropas[4].quantidade = 30;
            }

            int gameover = batalha(&player, &bot);

            if (gameover == 1)
            {
                printf("\033[H\033[J");
                printf("DERROTA\n");
                printf("Seu exercito foi derrotado pelo %s\n", inputs.antagonista);

            } else {
                printf("\033[H\033[J");
                printf("VITORIA\n");
                printf("Seu exerceito venceu o %s \n",inputs.antagonista);
            }
        }

        selectMenu = menu();
    }

    return 0;
}

int menu()
{
    int select = 3;

    printf("\n Bem Vindo ao Jogo RPG \n");
    printf("\n |---------------|");
    printf("\n | Novo Jogo : 0 |");
    printf("\n | Continuar : 1 |");
    printf("\n |    Sair   : 2 |");
    printf("\n |---------------| \n");
    printf("\n Digite um numero: ");
    scanf("%d", &select);

    if (select < 0 || select > 2)
    {
        printf("\033[H\033[J");
        return menu();
    }

    return select;
}

void historia(struct Historia *ptr)
{

    printf("Há muito tempo viviam dois reis em um período muito pácifico,");
    printf("os dois reinavam com grande equilíbrio e orgulho,");
    printf("o reino mais ao sul detinha os recursos hídricos e uma terra abrasada,");
    printf("e o reino mais ao norte continha 90%c das plantações do continente,", 37);
    printf("por isso fizeram um acordo econômico,");
    printf("o rei do norte pagava uma taxa de 100 moedas de ouro mensalmente para ajudar o rei do sul,");
    printf("mas em um belo dia por causas desconhecidas o rei do norte acaba morrendo...\n\n");
    printf("Alguns dias após o velório do antigo rei. \n");
    printf("Um dos guardas da muralha grita - soldados se aproximando !!!\n");
    printf("O guarda real diz: \n - Quem vem lá ? ");

    scanf(" %[^\n]%*c", ptr->antagonista);
    //ptr->antagonista = &antagonista;
    printf("\n - Abram o portão !!!\n");

    printf("A chegada de %s ao castelo deixa as pessoas assustadas pois todos ali sabiam da rivalidade entres os dois castelos,\n", ptr->antagonista);

    printf(" então ele se aproxima do palácio real e pergunta ao sacerdote local:\n");
    printf(" - Quem é o novo herdeiro ?");
    scanf(" %[^\n]%*c", ptr->protagonista);
    printf("\nO rei %s vai até o trono se encontrar com o mais novo rei, o %s\n", ptr->antagonista, ptr->protagonista);
    printf("\n - Saudações %s, o que o taz aqui ?", ptr->protagonista);
    printf("\n - Como vc deve saber eu e o seu pai temos algumas pendências em aberto.");
    printf("\n - E quais pendênicias seriam essas ?");
    printf("\n - Como você sabe a fonte de água para as suas plantações é minha,");
    printf(" e teremos que reajustar o valor para 1000 moedas de ouro, então negócio fechado ? \n\n");

    ptr->dificuldade = ptr->dificuldade + selectDif();

    if (ptr->dificuldade != 0)
    {
        printf("Algum tempo depois volta o %s ao castelo de %s e diz:\n", ptr->antagonista, ptr->protagonista);
        printf("Ó tão sábio %s, meu povo morre de fome e precisa da sua ajuda novamente, podemos aumentar a taxa para 8000 moedas de ouro?\n", ptr->protagonista);
        ptr->dificuldade = ptr->dificuldade + selectDif();
        if (ptr->dificuldade != 1)
        {
            printf("novamente retorna o %s ao seu castelo e diz:\n", ptr->antagonista, ptr->protagonista);
            printf("Meu povo precisa de recursos, aumentaremos a taxa para 27000 moedas, você continuará pagando ou morrerá de sede?\n");
            ptr->dificuldade = ptr->dificuldade + selectDif();
        }
    }
}

int selectDif()
{
    int dif = 2;
    printf(" 0 - para recusar \n");
    printf(" 1 - para aceitar\n");
    scanf("%d", &dif);
    if (dif == 0 || dif == 1)
    {
        return dif;
    }
    else
    {
        return selectDif();
    }
}

int batalha(struct Exercito *player, struct Exercito *bot)
{

    int round = 0;
    int playerGameOver = 5;
    int botGamerOver = 5;

    while (playerGameOver > 0 && botGamerOver > 0)
    {

        round++;
        playerGameOver = 0;
        botGamerOver = 0;
        for (int i = 0; i < 5; i++)
        {
            if (player->tropas[i].quantidade > 0)
            {

                int defesa[5];
                for (int i = 0; i < 5; i++)
                {
                    defesa[i] = 0;
                    for (int index = 0; index < 5; index++)
                    {
                        if (player->tropas[index].defesa == i)
                        {
                            defesa[i] = defesa[i] + player->tropas[index].dano;
                        }
                    }
                }
                playerGameOver++;
                if (player->tropas[i].round + player->tropas[i].velocidade - round == 0)
                {
                    printf("\033[H\033[J");
                    printf("\n\n");

                    printf("|---------------------------------MINHAS TROPAS------------------------------------|\n");
                    printf("| Rodada: %02d | 0 Escudeiro | 1 Arqueiro  |   2 Mago    | 3 Trabuco   | 4 Cavalaria |\n", round);
                    printf("| Quantidade |      %02d     |     %02d      |      %02d     |      %02d     |      %02d     |\n", player->tropas[0].quantidade, player->tropas[1].quantidade, player->tropas[2].quantidade, player->tropas[3].quantidade, player->tropas[4].quantidade);
                    printf("| Dano       |      %02d     |     %02d      |      %02d     |      %02d     |      %02d     |\n", player->tropas[0].dano, player->tropas[1].dano, player->tropas[2].dano, player->tropas[3].dano, player->tropas[4].dano);
                    printf("| Defesa     |      %02d     |     %02d      |      %02d     |      %02d     |      %02d     |\n", defesa[0], defesa[1], defesa[2], defesa[3], defesa[4]);
                    printf("| Movimento  |      %02dº    |     %02dº     |      %02dº    |      %02dº    |      %02dº    |\n", player->tropas[0].round + player->tropas[0].velocidade - round, player->tropas[1].round + player->tropas[1].velocidade - round, player->tropas[2].round + player->tropas[2].velocidade - round, player->tropas[3].round + player->tropas[3].velocidade - round, player->tropas[4].round + player->tropas[4].velocidade - round);
                    printf("|----------------------------------------------------------------------------------|\n");

                    for (int i = 0; i < 5; i++)
                    {
                        defesa[i] = 0;
                        for (int index = 0; index < 5; index++)
                        {
                            if (bot->tropas[index].defesa == i)
                            {
                                defesa[i] = defesa[i] + bot->tropas[index].dano;
                            }
                        }
                    }
                    printf("\n\n");
                    printf("|----------------------------------TROPAS INIMIGAS---------------------------------|\n");
                    printf("| Rodada: %02d | 0 Escudeiro | 1 Arqueiro  |   2 Mago    | 3 Trabuco   | 4 Cavalaria |\n", round);
                    printf("| Quantidade |      %02d     |     %02d      |      %02d     |      %02d     |      %02d     |\n", bot->tropas[0].quantidade, bot->tropas[1].quantidade, bot->tropas[2].quantidade, bot->tropas[3].quantidade, bot->tropas[4].quantidade);
                    printf("| Dano       |      %02d     |     %02d      |      %02d     |      %02d     |      %02d     |\n", bot->tropas[0].dano, bot->tropas[1].dano, bot->tropas[2].dano, bot->tropas[3].dano, bot->tropas[4].dano);
                    printf("| Defesa     |      %02d     |     %02d      |      %02d     |      %02d     |      %02d     |\n", defesa[0], defesa[1], defesa[2], defesa[3], defesa[4]);
                    printf("| Movimento  |      %02dº    |     %02dº     |      %02dº    |      %02dº    |      %02dº    |\n", bot->tropas[0].round + bot->tropas[0].velocidade - round, bot->tropas[1].round + bot->tropas[1].velocidade - round, bot->tropas[2].round + bot->tropas[2].velocidade - round, bot->tropas[3].round + bot->tropas[3].velocidade - round, bot->tropas[4].round + bot->tropas[4].velocidade - round);
                    printf("|----------------------------------------------------------------------------------|\n");
                    printf("\n");

                    printf("De a ordem para tropa %s\n", bot->tropas[i].name);
                    int move = selectMoves(player->tropas[i].defesa);
                    if (move == 1)
                    {
                        player->tropas[i].round = round;
                        printf("Escolha uma tropa inimiga:\n");
                        int tropa = selectTropas(&bot);
                        // Rodar dano
                        // Verificar se tropa atacada está defendida
                        int dano = player->tropas[i].dano;
                        if (bot->tropas[0].defesa == tropa)
                        {
                            dano = abs(dano - bot->tropas[4].dano);
                        }

                        if (bot->tropas[2].defesa == tropa)
                        {
                            dano = abs(dano - bot->tropas[4].dano);
                        }

                        if (bot->tropas[4].defesa == tropa)
                        {
                            dano = abs(dano - bot->tropas[4].dano);
                        }

                        bot->tropas[tropa].quantidade = bot->tropas[tropa].quantidade - dano;
                    }
                    else if (move == 2)
                    {
                        player->tropas[i].round = round;
                        // Escolha Defender
                        printf("Escolha uma tropa pra defender:\n");
                        int tropa = selectTropas(&player);
                        player->tropas[i].defesa = tropa;
                    }
                }
            }
        }

        // Bot
        for (int i = 0; i < 5; i++)
        {
            if (bot->tropas[i].quantidade > 0)
            {
                botGamerOver++;
                if (bot->tropas[i].round + bot->tropas[i].velocidade - round == 0)
                {
                    int move = 0;
                    if (bot->tropas[i].defesa != -1)
                    {
                        move = rand() % 2;
                    }
                    if (move == 0)
                    {
                        for (int index = 0; index < 5; index++)
                        {
                            if (player->tropas[index].quantidade > 0)
                            {
                                // Tropas vivas
                                int select = rand() % 2;
                                if (select == 1)
                                {
                                    // Rodar dano
                                    // Verificar se tropa atacada está defendida
                                    int dano = bot->tropas[i].dano;
                                    if (player->tropas[0].defesa == index)
                                    {
                                        dano = dano - player->tropas[0].dano;
                                        if(dano < 0){
                                            dano = bot->tropas[i].dano;
                                        }
                                    }

                                    if (player->tropas[2].defesa == index)
                                    {
                                        dano = dano - player->tropas[2].dano;
                                        if(dano < 0){
                                            dano = bot->tropas[i].dano;
                                        }
                                    }

                                    if (player->tropas[4].defesa == index)
                                    {
                                        dano = dano - player->tropas[4].dano;
                                        if(dano < 0){
                                            dano = bot->tropas[i].dano;
                                        }
                                    }

                                    player->tropas[index].quantidade = player->tropas[index].quantidade - dano;

                                    printf("A tropa %s do inimigo atacara o %s com dano %d \n", bot->tropas[i].name, player->tropas[index].name, dano);
                                    index = 5;
                                }
                            }
                        }
                    }
                    else if (move == 1)
                    {
                        // Escolha Defender
                        for (int index = 0; index < 5; index++)
                        {
                            if (bot->tropas[index].quantidade > 0)
                            {
                                // Tropas vivas
                                int select = rand() % 2;
                                if (select == 1)
                                {

                                    // Defender
                                    printf("Inimgo defendeu %s com %s \n", bot->tropas[i].name, bot->tropas[index].name);
                                    bot->tropas[i].defesa = index;
                                    index = 5;
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("\nPressione qualquer tecla para continuar \n");
        getchar();
        getchar();
    }

    // Game Over

    if (playerGameOver == 0)
    {
        // Pederu
        return 1;
    }
    else
    {
        // Ganahou
        return 0;
    }
}

int selectMoves(int defesa)
{
    int dif = 3;
    printf(" 0 - Esperar\n");
    printf(" 1 - Atacar \n");
    if (defesa != -1)
    {
        printf(" 2 - Defender\n");
    }

    scanf("%d", &dif);
    if (dif == 0 || dif == 1 || dif == 2)
    {
        return dif;
    }
    else
    {
        printf("\033[H\033[J");
        return selectDif();
    }
}

int selectTropas(struct Exercito *ptr)
{
    int tropa = -1;
    scanf("%d", &tropa);
    if (ptr->tropas[tropa].quantidade > 0)
    {
        return tropa;
    }
    else
    {
        printf("\033[H\033[J");
        return selectTropas(ptr);
    }
}