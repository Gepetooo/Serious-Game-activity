#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

void linhaCol(int lin, int col);
void box(int lin1, int col1, int lin2, int col2);
int menu(int lin1, int col1, int qtd, char lista[5][40]);
void textColor(int letras, int fundo);

enum
{
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY,
    DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

enum
{
    _BLACK=0, _BLUE=16, _GREEN=32, _CYAN=48, _RED=64, _MAGENTA=80, _BROWN=96,
    _LIGHTGRAY=112, _DARKGRAY=128, _LIGHTBLUE=144, _LIGHTGREEN=160, _LIGHTCYAN=176,
    _LIGHTRED=192, _LIGHTMAGENTA=208, _YELLOW=224, _WHITE=240
};

void textColor(int letra, int fundo)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letra + fundo);
    
    CONSOLE_FONT_INFOEX font;
    font.cbSize = sizeof(font);
    font.nFont = 0;
    font.dwFontSize.X = 0;  // Largura da fonte (0 = mantém o mesmo que o padrão)
    font.dwFontSize.Y = 27; // Altura da fonte (24 = tamanho maior)
    font.FontFamily = FF_DONTCARE;
    font.FontWeight = FW_NORMAL;
    wcscpy(font.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &font);
}

void linhaCol(int lin, int col)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){col-1, lin-1});
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void box(int lin1, int col1, int lin2, int col2)
{
    int i,j , tamlin, tamcol;
    tamlin = lin2 - lin1;
    tamcol = col2 - col1;

    for (i=col1; i<=col2; i++)
	{
        linhaCol(lin1,i);
        printf("%c",196);
        linhaCol(lin2,i);
        printf("%c",196);
    }

    for (i=lin1; i<=lin2; i++)
	{
        linhaCol(i,col1);
        printf("%c",179);
        linhaCol(i,col2);
        printf("%c",179);
    }

    for (i=lin1+1;i<lin2;i++)
	{
        for(j=col1+1;j<col2;j++)
		{
            linhaCol(i,j);printf(" ");
        }
    }

    linhaCol(lin1,col1);
    printf("%c",218);
    linhaCol(lin1,col2);
    printf("%c",191);
    linhaCol(lin2,col1);
    printf("%c",192);
    linhaCol(lin2,col2);
    printf("%c",217);
}

void resetTextColor()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    
    CONSOLE_FONT_INFOEX font;
    font.cbSize = sizeof(font);
    font.nFont = 0;
    font.dwFontSize.X = 0;  // Largura da fonte 
    font.dwFontSize.Y = 16; // Altura da fonte 
    font.FontFamily = FF_DONTCARE;
    font.FontWeight = FW_NORMAL;
    wcscpy(font.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &font);
}


int menu(int lin1, int col1, int qtd, char lista[5][40])
{
    int opc=1, lin2, col2, linha,i,tamMaxItem, tecla;

    tamMaxItem = strlen(lista[0]);
    for(i=1; i<qtd;i++)
	{
        if(strlen(lista[i])>tamMaxItem)
		{
            tamMaxItem = strlen(lista[i]);
        }
    }
    lin2 = lin1+(qtd*2+2);
    col2 = col1+tamMaxItem+4;

    box(lin1,col1,lin2,col2);

    while(1)
	{
        linha=lin1+2;
        for(i=0;i<qtd;i++)
		{          
            if(i+1==opc)
			{
                textColor(RED, BLACK);
            } else
			{
                textColor(WHITE, BLACK);
            }
            linhaCol(linha,col1+2);
            printf("%s",lista[i]);
            linha +=2;
        }
       
        linhaCol(1,1);
        tecla= getch();
        linhaCol(22,1);
        if(tecla==27)
		{
            opc=0; break;
        }
        else if(tecla==13)
		{
            break;
        }
        else if(tecla==72)
		{
            if(opc>1)opc--;
        }
        else if(tecla==80 )
		{
            if (opc<qtd)opc++;
        }
    }
	resetTextColor();
    return opc;
}

struct personagem
{

    char nome[50];
    float forca;
    float agilidade;
    float hp;

}; typedef struct personagem personagem;

struct inimigo
{
    char nome[50];
    float agilidade;
    float hp;
    float forca;
}; typedef struct inimigo inimigo;

struct arma
{
    float dano;
}; typedef struct arma arma;

void delay(int seconds)
{
    int mil = 1000 * seconds;
    clock_t stime = clock();
    while (clock() < stime + mil);
}


void Tela_de_inicio()
{
	int i;
	int b;
	b = i + 1;
	for(i = 0; i < b; i++)
    {
        b++;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t  ==================================================================\n"
        		"\t\t\t\t\t\t\t\t\t\t  =                                                                =\n"
        		"\t\t\t\t\t\t\t\t\t\t  = ____            _                    ____                      =\n"
        		"\t\t\t\t\t\t\t\t\t\t  =/ ___|  ___ _ __(_) ___  _   _ ___   / ___| __ _ _ __ ___   ___ =\n"
    			"\t\t\t\t\t\t\t\t\t\t  =\\___ \\ / _ \\ '__| |/ _ \\| | | / __| | |  _ / _` | '_ ` _ \\ / _ \\=\n"
        		"\t\t\t\t\t\t\t\t\t\t  = ___) |  __/ |  | | (_) | |_| \\__ \\ | |_| | (_| | | | | | |  __/=\n"
        		"\t\t\t\t\t\t\t\t\t\t  =|____/ \\___|_|  |_|\\___/ \\__,_|___/  \\____|\\__,_|_| |_| |_|\\___|=\n"
        		"\t\t\t\t\t\t\t\t\t\t  =                                                                =\n"
        		"\t\t\t\t\t\t\t\t\t\t  ==================================================================\n\n\n\n\n\n\n\n\n\n\n"
        		"\t\t\t\t\t\t\t\t\t\t\t\t    Pressione espaco para comecar!\n", i + 1);
        delay(1.1);
        system("cls");
        delay(1);
        if(kbhit())
        {
            break;
        }
    }
}
void GameOver()
{
	int i;
	int b;
	b = i + 1;
	char texto2[] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t  ____                         ___                 \n"
                    "\t\t\t\t\t\t\t\t\t\t / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __ \n"
                    "\t\t\t\t\t\t\t\t\t\t| |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|\n"
                    "\t\t\t\t\t\t\t\t\t\t| |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |   \n"
                    "\t\t\t\t\t\t\t\t\t\t \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|   \n\t\t\t\t\t\t\t\t\t\t\t";
    for (int i = 0; texto2[i] != '\0'; i++)
	{
		putchar(texto2[i]);
        fflush(stdout);    
        Sleep(1);        
        if (kbhit())
		{
        	system("cls");
        	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t  ____                         ___                 \n"
                    "\t\t\t\t\t\t\t\t\t\t / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __ \n"
                    "\t\t\t\t\t\t\t\t\t\t| |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|\n"
                    "\t\t\t\t\t\t\t\t\t\t| |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |   \n"
                    "\t\t\t\t\t\t\t\t\t\t \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|   \n\t\t\t\t\t\t\t\t\t\t  ");
            system("pause");
			break;
		}
    }
}
void Tela_De_Vitoria()
{
	int i;
	int b;
	b = i + 1;
	for(i = 0; i < b; i++)
    {
        b++;
        printf("Parabens garoto\n\n");
        printf("      __   _____  _   _  __        _____ _   _      _ \n"
                     "\\ \\ / / _ \\| | | | \\ \\      / /_ _| \\ | |    | |\n"
                    "  \\ V / | | | | | |  \\ \\ /\\ / / | ||  \\| |    | |\n"
                    "   | || |_| | |_| |   \\ V  V /  | || |\\  |    |_|\n"
                    "   |_| \\___/ \\___/     \\_/\\_/  |___|_| \\_|    (_)\n\nTO BE CONTINUE");
        delay(1.1);
        system("cls");
        delay(1);
        if(kbhit())
        {
            break;
        }
    }
                    
}


void iniciarJogo()
{
    system("cls");
    printf("\nJogando...\n\n");

    int esc;

               
    printf("\t\t\t\t\t================================\n");
    printf("\t\t\t\t\t=        seja bem vindo        =\n");
    printf("\t\t\t\t\t=              ao              =\n");
    printf("\t\t\t\t\t=         serious game         =\n");
    printf("\t\t\t\t\t================================\n");


    // Solicita o nome do personagem ao jogador
    char nome[50];
    printf("Digite o nome do seu personagem: ");
    fgets(nome, 50, stdin);
    fflush(stdin);

    // Exibe o nome informado pelo jogador
    printf("\n\nSeu personagem se chama: %s\n\n", nome);

    system("pause");
    system("cls");

    // Início da aventura
    printf("Sua jornada comeca agora, %s!\n", nome);
    printf("Prepare se para enfrentar desafios e descobrir segredos incriveis!\n\n");

    printf("Escolha seu personagem:\n\n");

	personagem jogador;
    jogador.forca = 0;
    jogador.agilidade = 0;
    jogador.hp = 0;
    
    personagem mago;
    mago.forca = 5.0;
    mago.agilidade = 7.0;
    mago.hp = 75.0;

    personagem cavaleiro;
    cavaleiro.forca = 10.0;
    cavaleiro.agilidade = 40.0;
    cavaleiro.hp = 150.0;


    personagem arqueiro;
    arqueiro.forca = 10.0;
    arqueiro.agilidade = 30.0;
    arqueiro.hp = 100.0;

    inimigo natasha;
    natasha.forca = 15.0;
    natasha.hp = 150.0;
    natasha.agilidade = 4.0;
    
    inimigo poly;
    poly.forca = 20.0;
    poly.hp = 200.0;
    poly.agilidade = 8.0;
    
    inimigo victor;
    victor.forca = 25.0;
    victor.hp = 250,0;
    victor.agilidade = 12.0;
    
    inimigo eliane;
    eliane.forca = 30.0;
    eliane.hp = 300,0;
    eliane.agilidade = 16.0;
    
    
	do
	{
		do
		{
	        system("cls"); // Limpa a tela
	        printf("1- Mago:\n");
	        printf("\033[0;35m"); // Muda a cor para roxo
	   		printf("           /:\\\n");
	   		printf("          /;:.\\\n");
	   		printf("         //;:. \\\n");
	   		printf("        ///;:.. \\\n");
	  		printf("  _--\"////;:... \\\\\\--_\n");
	   		printf("--__   \"--_--\"   __--\n");
	   		printf("    \"\"\"--_--\"\"\"\n\n\n");
	       
	    	printf("Forca do Mago: %.2f\n\nDestreza do Mago: %.1f\n\nhp do Mago: %.1f\n\n\n", mago.forca, mago.agilidade, mago.hp);
	    	printf("\033[0m"); // Retorna a cor ao normal
	        printf("\n2- Cavaleiro:\n");
	        printf("\033[0;33m"); // Muda a cor para amarelo
	   		printf("             />\n");
	   		printf("            /<\n");
	   		printf("           /<\n");
	 		printf(" |\\{o}----------------------------------------------------------\n");
	  		printf("[\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\{*}:::<=============================================->\n");
	    	printf(" |/{o}----------------------------------------------------------\n");
	    	printf("           \\<\n");
	    	printf("            \\<\n");
	   		printf("             \\>\n");
	    	printf("\n\n");
	
			printf("Forca do Cavaleiro: %.1f\n\nDestreza do Cavaleiro: %.1f\n\nSaude do Cavaleiro: %.1f\n\n\n", cavaleiro.forca,cavaleiro.agilidade,cavaleiro.hp);
			
			printf("\033[0m"); // Retorna a cor ao normal
			
			printf("Pressione 'P' 2 vezes para ver a proxima pagina ou pressione 'E' para escolher seu personagem.\n");
	        if (getch() == 'o')
			{
				system("cls");
	            printf("1- Mago:\n");
	            printf("\033[0;35m"); // Muda a cor para roxo
	   			printf("           /:\\\n");
	   			printf("          /;:.\\\n");
	   			printf("         //;:. \\\n");
	   			printf("        ///;:.. \\\n");
	  		 	printf("  _--\"////;:... \\\\\\--_\n");
	   			printf("--__   \"--_--\"   __--\n");
	   			printf("    \"\"\"--_--\"\"\"\n\n\n");
	       
	    		printf("Forca do Mago: %.2f\n\nDestreza do Mago: %.1f\n\nhp do Mago: %.1f\n\n\n", mago.forca, mago.agilidade, mago.hp);
	    		printf("\033[0m"); // Retorna a cor ao normal
	            printf("\n2- Cavaleiro:\n");
	            printf("\033[0;33m"); // Muda a cor para amarelo
	   			printf("             />\n");
	   			printf("            /<\n");
	   			printf("           /<\n");
	 			printf(" |\\{o}----------------------------------------------------------\n");
	  		  	printf("[\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\{*}:::<=============================================->\n");
	    		printf(" |/{o}----------------------------------------------------------\n");
	    		printf("           \\<\n");
	    	  	printf("            \\<\n");
	   			printf("             \\>\n");
	    		printf("\n\n");
	
				printf("Forca do Cavaleiro: %.1f\n\nDestreza do Cavaleiro: %.1f\n\nSaude do Cavaleiro: %.1f\n\n\n", cavaleiro.forca,cavaleiro.agilidade,cavaleiro.hp);
	
	     		printf("\033[0m"); // Retorna a cor ao normal
	     		
	     		printf("Pressione 'P' 2 vezes para ver a proxima pagina ou pressione 'E' 3 vezes para escolher seu personagem.\n");
	        } 
			else if (getch() == 'p')
			{
				system("cls");
	            printf("\n3- Arqueiro:\n\n");
	   			printf("\033[0;32m"); // muda a cor para verde
	
	    		printf("          4$$-.                                          \n");
	    		printf("           4   \".                                        \n");
	    		printf("           4    ^\\                                        \n");
	    		printf("           4     $                                        \n");
	   		    printf("           4     'b                                       \n");
	    		printf("           4      \"b.                                     \n");
	    		printf("           4        $                                     \n");
	    		printf("           4        $r                                    \n");
	    		printf("           4        $F                                    \n");
	    		printf("-$b========4========$b====*P=-                           \n");
	    		printf("           4       *$$F                                   \n");
	    		printf("           4        $$\"                                   \n");
	    		printf("           4       .$F                                    \n");
	    		printf("           4       dP                                     \n");
	    		printf("           4      F                                       \n");
	    		printf("           4     @                                        \n");
	    		printf("           4    .                                         \n");
	    		printf("           J.                                             \n");
	    		printf("          '$$                                             \n");
	
	
	    		printf("Forca do Arqueiro: %.1f\n\nAgilidade do Arqueiro: %.1f\n\nSaude do Arqueiro: %.1f\n\n", arqueiro.forca, arqueiro.agilidade, arqueiro.hp);
	
	    		printf("\033[0m"); // Retorna a cor ao normal
	    		
	    		printf("Pressione 'O' 1 vez para voltar a pagina anterior ou pressione 'E' uma vez para escolher seu personagem.\n");
	        }
	    } while(getch() != 'e');
	    puts("Escolha sua caracteristica:");
	    scanf("%d", &esc);
	    printf("\n\n");
	    fflush(stdin);
	    if(esc != 1 && esc != 2 && esc != 3)
	    {
	    	printf("Escolha um dos personagens, bobao! (Dica: 1, 2 ou 3)");
	    	delay(2);
		}
	    system("cls");
	} while(esc != 1 && esc != 2 && esc != 3);
	
	float balanceamento1, balanceamento2, balanceamento3;
	
    switch(esc)
	{
        case 1:
        	balanceamento1 = 25;
        	balanceamento2 = 15;
        	balanceamento3 = 10;
    		jogador.forca = mago.forca;
    		jogador.agilidade = mago.agilidade;
    		jogador.hp = mago.hp;
        	system("cls");	
        	printf("Seja bem vindo(a) Mago(a) %s", nome);
        	system("pause");
        	system("cls");	
        break;

        case 2:
        	balanceamento1 = 9;
        	balanceamento2 = 5;
        	balanceamento3 = 3;
    		jogador.forca = cavaleiro.forca;
    		jogador.agilidade = cavaleiro.agilidade;
    		jogador.hp = cavaleiro.hp;
        	system("cls");
        	printf("Seja bem vindo(a) Cavaleiro(a) %s", nome);
        	system("pause");
        	system("cls");
        break;

        case 3:
        	balanceamento1 = 10;
        	balanceamento2 = 5;
        	balanceamento3 = 2;
    		jogador.forca = arqueiro.forca;
    		jogador.agilidade = arqueiro.agilidade;
    		jogador.hp = arqueiro.hp;
        	system("cls");
       		printf("\nSeja bem vindo(a) Arqueiro(a) %s", nome);
        	system("pause");
        	system("cls");
        break;

    }

    printf("\033[1;36m"); // introduzir cor

    //Introdução
    char texto[] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  * 8888888888            d8888          .d8888b.          8888888888                  d888 *\n"
                   "\t\t\t\t\t\t\t\t  * 888                  d88888         d88P  Y88b         888                        d8888 *\n"
                   "\t\t\t\t\t\t\t\t  * 888                 d88P888         Y88b.              888                          888 *\n"
                   "\t\t\t\t\t\t\t\t  * 8888888            d88P 888          \"Y888b.           8888888                      888 *\n"
                   "\t\t\t\t\t\t\t\t  * 888               d88P  888             \"Y88b.         888                          888 *\n"
                   "\t\t\t\t\t\t\t\t  * 888              d88P   888               \"888         888                          888 *\n"
                   "\t\t\t\t\t\t\t\t  * 888             d8888888888         Y88b  d88P         888                          888 *\n"
                   "\t\t\t\t\t\t\t\t  * 888            d88P     888          \"Y8888P\"          8888888888                 8888888 *\n\n";
   
    for (int i = 0; texto[i] != '\0'; i++)
	{
		putchar(texto[i]);
        fflush(stdout);    
        Sleep(1);        
        if (kbhit())
		{
        	system("cls");
        	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  * 8888888888            d8888          .d8888b.          8888888888                  d888 *\n"
                   "\t\t\t\t\t\t\t\t  * 888                  d88888         d88P  Y88b         888                        d8888 *\n"
                   "\t\t\t\t\t\t\t\t  * 888                 d88P888         Y88b.              888                          888 *\n"
                   "\t\t\t\t\t\t\t\t  * 8888888            d88P 888          \"Y888b.           8888888                      888 *\n"
                   "\t\t\t\t\t\t\t\t  * 888               d88P  888             \"Y88b.         888                          888 *\n"
                   "\t\t\t\t\t\t\t\t  * 888              d88P   888               \"888         888                          888 *\n"
                   "\t\t\t\t\t\t\t\t  * 888             d8888888888         Y88b  d88P         888                          888 *\n"
                   "\t\t\t\t\t\t\t\t  * 888            d88P     888          \"Y8888P\"          8888888888                 8888888 *\n\n");
			break;
		}
    }
	printf("\n\t\t\t\t\t\t\t\t\t\t\t");
	printf("\033[0m");
	system("pause");
	
    system("cls");

    printf("Ola %sme chamo Girotto, irei ser seu treinador durante seu processo de aprendizagem...\n\n", nome);
    printf("Prologo:\n\n");
    printf("Neste prologo sera apresentado uma estrutura basica de um programa em C...\n\n");

    printf("\033[35m#include <stdio.h>\n\n");
    printf("\033[0m\n");
    printf("\033[34mint \033[0m main(){\n\n");
    printf("\033[33m\033[34mreturn\033[0m \033[33m\033[1m0\033[0m;\n}\n");
    printf("\n\n\033[31mObservacao: vamos usar a biblioteca stdio.h pois ela apresenta as funcoes basicas para o que iremos aprender no capitulo 1...");
    printf("\033[0m\n\n");

    system("pause");
    system("cls");

    printf("Capitulo 1:\n");
    printf("Imprimindo dados na Tela:\n\n");
    printf("Para imprimir algo do seu desejo na tela iremos usar uma funcao chamada (printf), sua estrutura segue abaixo:\n\n");
    printf("\033[35m#include <stdio.h>\n\n");
    printf("\033[0m\n");
    printf("\033[34mint \033[0m main(){\n\n");
    printf("\033[0mprintf\033[0;33m('');");
    printf("\033[0m\n\n");
    printf("\033[33m\033[34mreturn\033[0m \033[33m\033[1m0\033[0m;\n}\n");
    printf("\033[31mObservacao: Dentro dos parenteses do printf devera ser acompanhado com aspas duplas, e dentro dos parenteses com as aspas voce pode digitar oq quiser...\n");
    printf("\033[31mNUNCA ESQUECA DE BOTAR (;), no final\n\n");
    printf("\033[0m\n\n");

    system("pause");
    system("cls");

   
    //construção jogo c;

    printf("Agora vamos comecar:\n\n");
    
	int opc, resposta, escolha_ataque, numeroAleatorio, debug;
	float ataque_fraco = jogador.forca * balanceamento3;
    float ataque_medio = jogador.forca * balanceamento2;
	float ataque_forte = jogador.forca * balanceamento1;
	float ataque = jogador.hp;
	
	do
	{
		opc = 0;
    	printf("Um inimigo quer enfrentar voce:\n\n");
        printf("Voce aceita o desafio:\n1- SIM.\n2- NAO.\n");
        scanf("%d", &opc);
        printf("\n\n");
        fflush(stdin);

        system("cls");

        if (opc == 1)
		{
            printf("Batalha aceita...\n\n");
            printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
                   "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
                   "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
                   "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
                   nome, natasha.forca,  
                   jogador.forca, natasha.agilidade, 
                   jogador.agilidade, natasha.hp, 
                   ataque);
                   
            printf("\033[0m");
            system("pause");
		}
		else if (opc == 2) 
		{
           printf("Continuando...\n\n");
           break;
        }
		else if(opc != 1 && opc!= 2)
		{
	    	printf("\nNao quer jogar eh? Entao tome. Receba\n\n");
	        GameOver();
	        debug = 1;
	        break;
	    }
	
		do
		{
			if(natasha.hp > 0 && ataque > 0)
			{
				escolha_ataque = 0;
				system("cls");
				printf("\nSua vez. Ataque:\n");
        		printf("\n\nEscolha seu ataque:\n\033[31m1- Ataque forte\n2- Ataque medio\n3- Ataque fraco\n.");
        		printf("\033[0m\n\n");
        		scanf("%d",&escolha_ataque);
        		fflush(stdin);

        		system("pause");
            	system("cls");
			}
			else if(ataque < 0)
			{
			    GameOver();
			    break;
			}
			if (escolha_ataque != 1 && escolha_ataque != 2 && escolha_ataque != 3)
			{
				printf("\nAh, nao quer atacar eh?\nRelaxa que o teu adversario quer...\n\nReceba");
				delay(3);
				system("cls");
				GameOver();
				debug = 1;
				break;
			}
	
	        if(escolha_ataque == 1)
			{
	            printf("Voce escolheu o ataque forte..\n\n");
	
	            printf("\nEscolha a opcao correta onde o codigo imprima um hello world na tela:\n\n");
	            printf("\033[35m"); // Muda a cor para roxo
	            printf("\033[35m1- #include <stdio.h>\n\nint main(){\n\nprintf('hello world');\n\nreturn 0;\n\n}\n\n\n");
	            printf("\033[34m2- int main(){\n\nprintf('hello world);;\n\nreturn 0;\n\n}\n\n\n");
	            printf("\033[32m3- #include <stdio.h>\n\nint main(){\n\nprintf('hello world')\n\nreturn 0;\n\n}\n\n\n");
	
	            printf("\033[0m"); // Retorna a cor ao normal
	
		        printf("Responda: ");
		        scanf("%d", &resposta);
		        fflush(stdin);
	
		        if(resposta != 1)
				{
		            printf("Resposta errada,..... nem uma ataque efetivo\n");
		            printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
		                    "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
		                   	"\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
		                   	"\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
		                  	nome, natasha.forca,
		                  	jogador.forca, natasha.agilidade,
		                 	jogador.agilidade, natasha.hp,
		                  	ataque);
		            system("pause");
		                   
		            srand(time(NULL));
		            if(natasha.hp > 0)   
					{    
			            printf("Vez de Natasha.exe:\n");
			            printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
			            printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
			            srand(time(NULL));
			            numeroAleatorio = rand() % 100;
			            printf("Numero sorteado: %d\n", numeroAleatorio);
			                        	
			            if(numeroAleatorio < 77)
						{
			                ataque = ataque - natasha.forca;
			                        		
			                printf("Que pena, NATASHA.exe te atacou...\n\n");
			                        		
			                printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
			                        nome, natasha.forca,  
			                        jogador.forca, natasha.agilidade, 
			                        jogador.agilidade, natasha.hp, 
			                        ataque);
							system("pause");
							system("cls"); 
							continue;                      	
			            }
			                       	 
			            else if(numeroAleatorio > 77)
						{			
			                printf("UAU, que sorte... ataque novamente\n\n");
			                        			
			                printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                        nome, natasha.forca,  
			                        jogador.forca, natasha.agilidade, 
			                        jogador.agilidade, natasha.hp, 
			                        ataque);
			                        			
			                system("pause");
			                system("cls");
			                continue;
			            		/*se o jogador acertar entao na barra de dados dos persoangens da luta 
			            		ira desaperecer a vida anterior da inimida e ira aparecer aos poucos a nova vida dela apos o dano */ 
			            }
			        }
			        else
			        {
			        	break;
					}
		        }
		
		        else if(resposta == 1)
				{
		            natasha.hp = natasha.hp - ataque_forte;
						 
		            printf("Resposta certa.\n");
		            printf("Ataque efetivo.\n\n");
		            printf("Voce deu: %.1f de dano!\n", ataque_forte);
		            printf("HP Restante de NATASHA.exe: %.1f\n", natasha.hp);
		            system("pause");
		            printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
		                	"\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
		                    "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
		                    "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
		                	nome, natasha.forca,  
		                    jogador.forca, natasha.agilidade, 
		                    jogador.agilidade, natasha.hp,
		                    ataque);
				
					system("pause");
					system("cls");
		            srand(time(NULL));
		            if(natasha.hp > 0)   
					{    
			            printf("Vez de Natasha.exe:\n");
			            printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
			            printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
			            srand(time(NULL));
			            numeroAleatorio = rand() % 100;
			            printf("Numero sorteado: %d\n", numeroAleatorio);
			                        	
			            if(numeroAleatorio < 77)
						{
			                ataque = ataque - natasha.forca;
			                        		
			                printf("Que pena, NATASHA.exe te atacou...\n\n");
			                        		
			                printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
			                        nome, natasha.forca,  
			                        jogador.forca, natasha.agilidade, 
			                        jogador.agilidade, natasha.hp, 
			                        ataque);
							system("pause");
							system("cls"); 
							continue;                      	
			            }
			                       	 
			            else if(numeroAleatorio > 77)
						{			
			                printf("UAU, que sorte... ataque novamente\n\n");
			                        			
			                printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                        nome, natasha.forca,  
			                        jogador.forca, natasha.agilidade, 
			                        jogador.agilidade, natasha.hp, 
			                        ataque);
			                        			
			                system("pause");
			                system("cls");
			                continue;
			            		/*se o jogador acertar entao na barra de dados dos persoangens da luta 
			            		ira desaperecer a vida anterior da inimida e ira aparecer aos poucos a nova vida dela apos o dano */ 
			            }
			        }
			        else
			        {
			        	break;
					}
		        }
		    }
		
		    else if(escolha_ataque == 2)
			{
		        printf("Voce escolheu o ataque medio...\n\n");
		        printf("\nEscolha a opcao correta sobre estrututa basica em C:\n\n");
		        printf("\033[35m"); // Muda a cor para roxo
		        printf("\033[35m1- #include <stdio.h>\n\nint main(){\n\n\n\nreturn 0;\n\n}\n\n\n");
		        printf("\033[34m2- #include <studio.h>\n\nint main(){\n\n\n\nreturn 0;\n\n}\n\n\n");
		        printf("\033[32m3- #include <stdio.h\n\nint main(){\n\n\n\nreturn 0\n\n}\n\n\n");
		
		        printf("\033[0m"); // Retorna a cor ao normal
		
		        printf("Responda: ");
		        scanf("%d", &resposta);
		        fflush(stdin);           	
		                     	
		        if(resposta == 1)
				{   
		            natasha.hp = natasha.hp - ataque_medio;
						 
		            printf("Resposta certa, ataque medio efetuado");
		            printf("Voce deu: %.1f de dano!\n", ataque_medio);
		            printf("HP Restante de NATASHA.exe: %.1f\n", natasha.hp);
		
		                        
		            printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
		                    "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
		                    "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
		                    "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
		                    nome, natasha.forca,  
		                    jogador.forca, natasha.agilidade, 
		                    jogador.agilidade, natasha.hp, 
		                    ataque);
		            system("pause");
		            system("cls");
		            
		            if(natasha.hp > 0)   
					{    
			            printf("Vez de Natasha.exe:\n");
			            printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
			            printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
			            srand(time(NULL));
			            numeroAleatorio = rand() % 100;
			            printf("Numero sorteado: %d\n", numeroAleatorio);
			                        	
			            if(numeroAleatorio < 77)
						{
			                ataque = ataque - natasha.forca;
			                        		
			                printf("Que pena, NATASHA.exe te atacou...\n\n");
			                        		
			                printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
			                        nome, natasha.forca,  
			                        jogador.forca, natasha.agilidade, 
			                        jogador.agilidade, natasha.hp, 
			                        ataque);
							system("pause");
							system("cls"); 
							continue;                      	
			            }
			                       	 
			            else if(numeroAleatorio > 77)
						{			
			                printf("UAU, que sorte... ataque novamente\n\n");
			                        			
			                printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                        nome, natasha.forca,  
			                        jogador.forca, natasha.agilidade, 
			                        jogador.agilidade, natasha.hp, 
			                        ataque);
			                        			
			                system("pause");
			                system("cls");
			                continue;
			            		/*se o jogador acertar entao na barra de dados dos persoangens da luta 
			            		ira desaperecer a vida anterior da inimida e ira aparecer aos poucos a nova vida dela apos o dano */ 
			            }
			        }
			        else
			        {
			        	break;
					}
		        }
										                    		
		        if(resposta != 1)
				{
		            printf("Resposta errada... Seu ataque falhou!\n");
		            printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
		                    "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
		                    "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
		                    "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
		                    nome, natasha.forca,  
		                    jogador.forca, natasha.agilidade, 
		                    jogador.agilidade, natasha.hp, 
		                    ataque);
		            system("pause");
		            system("cls");
		            if(natasha.hp > 0)   
					{    
			            printf("Vez de Natasha.exe:\n");
			            printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
			            printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
			            srand(time(NULL));
			            numeroAleatorio = rand() % 100;
			            printf("Numero sorteado: %d\n", numeroAleatorio);
			                        	
			            if(numeroAleatorio < 77)
						{
			                ataque = ataque - natasha.forca;
			                        		
			                printf("Que pena, NATASHA.exe te atacou...\n\n");
			                        		
			                printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
			                        nome, natasha.forca,  
			                        jogador.forca, natasha.agilidade, 
			                        jogador.agilidade, natasha.hp, 
			                        ataque);
							system("pause");
							system("cls"); 
							continue;                      	
			            }
			                       	 
			            else if(numeroAleatorio > 77)
						{			
			                printf("UAU, que sorte... ataque novamente\n\n");
			                        			
			                printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                        nome, natasha.forca,  
			                        jogador.forca, natasha.agilidade, 
			                        jogador.agilidade, natasha.hp, 
			                        ataque);
			                        			
			                system("pause");
			                system("cls");
			                continue;
			            		/*se o jogador acertar entao na barra de dados dos persoangens da luta 
			            		ira desaperecer a vida anterior da inimida e ira aparecer aos poucos a nova vida dela apos o dano */ 
			            }
			        }
			        else
			        {
			        	break;
					}
		        }
		    }
		                    
			else if(escolha_ataque == 3)
			{ 
				printf("Voce escolheu o ataque fraco...\n\n");
		        printf("Responda uma pergunta basica sobre a funcao de printar na tela =>\n");
	            printf("complete a escrita dessa funcao: \n\n");
	            printf("prin__\n\n");
	            printf("\033[1;31m1- print();\n\n\033[34m2- printf('');\n\n\033[38;5;208m3- print''\n\n\033[0m");
	            scanf("%d", &resposta);
		        printf("\033[0m"); // Retorna a cor ao normal
		        fflush(stdin);
		                     	
		                     	
		
		        if(resposta == 2)
				{   
		            natasha.hp = natasha.hp - ataque_fraco;
						 
		            printf("Resposta certa, ataque fraco efetuado");
		            printf("Voce deu: %.1f de dano!\n", ataque_fraco);
		            printf("HP Restante de NATASHA.exe: %.1f\n", natasha.hp);
		
		                        
		            printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
		                        "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
		                        "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
		                        "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
		                        nome, natasha.forca,  
		                        jogador.forca, natasha.agilidade, 
		                        jogador.agilidade, natasha.hp, 
		                        ataque);
		            system("pause");
		            system("cls");
		                
		            if(natasha.hp > 0)   
					{    
			            printf("Vez de Natasha.exe:\n");
			            printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
			            printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
			            srand(time(NULL));
			            numeroAleatorio = rand() % 100;
			            printf("Numero sorteado: %d\n", numeroAleatorio);
			                        	
			            if(numeroAleatorio < 77)
						{
			                ataque = ataque - natasha.forca;
			                        		
			                printf("Que pena, NATASHA.exe te atacou...\n\n");
			                        		
			                printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
			                        nome, natasha.forca,  
			                        jogador.forca, natasha.agilidade, 
			                        jogador.agilidade, natasha.hp, 
			                        ataque);
							system("pause");
							system("cls"); 
							continue;                      	
			            }
			                       	 
			            else if(numeroAleatorio > 77)
						{			
			                printf("UAU, que sorte... ataque novamente\n\n");
			                        			
			                printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                        nome, natasha.forca,  
			                        jogador.forca, natasha.agilidade, 
			                        jogador.agilidade, natasha.hp, 
			                        ataque);
			                        			
			                system("pause");
			                system("cls");
			                continue;
			            		/*se o jogador acertar entao na barra de dados dos persoangens da luta 
			            		ira desaperecer a vida anterior da inimida e ira aparecer aos poucos a nova vida dela apos o dano */ 
			            }
			        }
			        else
			        {
			        	break;
					}
		        }
										                    		
		        if(resposta != 2)
				{
		            printf("Resposta errada... Seu ataque falhou!\n");
		            printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
		                    "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
		                    "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
		                    "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
		                    nome, natasha.forca,  
		                    jogador.forca, natasha.agilidade, 
		                    jogador.agilidade, natasha.hp, 
		                    ataque);
		            system("pause");
		            system("cls");
		                   
		            if(natasha.hp > 0)   
					{    
			            printf("Vez de Natasha.exe:\n");
			            printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
			            printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
			            srand(time(NULL));
			            numeroAleatorio = rand() % 100;
			            printf("Numero sorteado: %d\n", numeroAleatorio);
			                        	
			            if(numeroAleatorio < 77)
						{
			                ataque = ataque - natasha.forca;
			                        		
			                printf("Que pena, NATASHA.exe te atacou...\n\n");
			                        		
			                printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
			                        nome, natasha.forca,  
			                        jogador.forca, natasha.agilidade, 
			                        jogador.agilidade, natasha.hp, 
			                        ataque);
							system("pause");
							system("cls"); 
							continue;                      	
			            }
			                       	 
			            else if(numeroAleatorio > 77)
						{			
			                printf("UAU, que sorte... ataque novamente\n\n");
			                        			
			                printf("\033[0;33mNome do inimigo: NATASHA.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        "\033[0;33mForca da Natasha: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        "\033[0;33mDestreza da Natasha: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        "\033[0;33mSaude da Natasha: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                        nome, natasha.forca,  
			                        jogador.forca, natasha.agilidade, 
			                        jogador.agilidade, natasha.hp, 
			                        ataque);
			                        			
			                system("pause");
			                system("cls");
			                continue;
			            		/*se o jogador acertar entao na barra de dados dos persoangens da luta 
			            		ira desaperecer a vida anterior da inimida e ira aparecer aos poucos a nova vida dela apos o dano */ 
			            }
			        }
			        else
			        {
			        	break;
					}
		        }
		    }
		} while (natasha.hp > 0);
	} while(opc != 1 && opc !=2);
	
    resposta = 0;
	
	if(ataque > 0 && debug != 1)
	{
		opc = 0;
		ataque = jogador.hp;
		
	    char texto1[] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t   _____      _         ____       _____        ____  \n"
					    "\t\t\t\t\t\t\t\t\t\t  |  ___|    / \\       / ___|     | ____|      |___ \\ \n"
		  			    "\t\t\t\t\t\t\t\t\t\t  | |_      / _ \\      \\___ \\     |  _|          __) |\n"
					    "\t\t\t\t\t\t\t\t\t\t  |  _|    / ___ \\      ___) |    | |___        / __/ \n"
					    "\t\t\t\t\t\t\t\t\t\t  |_|     /_/   \\_\\    |____/     |_____|      |_____| \n\n";
		
		for (int i = 0; texto1[i] != '\0'; i++)
		{
			putchar(texto1[i]);
	        fflush(stdout);    
	        Sleep(1);        
	        if (kbhit())
			{
	        	system("cls");
	        	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t   _____      _         ____       _____        ____  \n"
					    "\t\t\t\t\t\t\t\t\t\t  |  ___|    / \\       / ___|     | ____|      |___ \\ \n"
		  			    "\t\t\t\t\t\t\t\t\t\t  | |_      / _ \\      \\___ \\     |  _|          __) |\n"
					    "\t\t\t\t\t\t\t\t\t\t  |  _|    / ___ \\      ___) |    | |___        / __/ \n"
					    "\t\t\t\t\t\t\t\t\t\t  |_|     /_/   \\_\\    |____/     |_____|      |_____| \n\n");
				break;
			}
	    }
	    
	    printf("\t\t\t\t\t\t\t\t\t\t\t");
		system("pause");
		system("cls");
		
	    printf("Ola, %s\n\n", nome);
	    printf("Vejo que voce superou a fase 1, agora iremos nos preparar mais...\n\n");
	            
	    system("pause");
	    system("cls");
	            
	    printf("capitulo 2:\n\n");
	    printf("Neste capitulo iremos aprender como receber informacoes do usuario e como criar variaveis\n\n");
	    printf("Porem, antes de voce ver como funciona precisamos entender como funciona as variavies e constantes e como armazenar elas na memoria\n\n");
	    printf("Tipos de variaveis...\n\n");
	    printf("\033[0;35m");
	    printf("1- int (%%d) = valores inteiros\n\n");
	    printf("2- float (%%f) = valores com casas decimais\n\n");
	    printf("3- double (%%lf) = valores com casas decimais com dupla precisao\n\n");
	    printf("4- char (%%c) ou (%%s)= caracteres\n\n");
	    printf("\033[0m");
	            
	    printf("\033[0;31m");
	    printf("Observacao: para cada variavel criada voce deve atribuir um nome e uma valor a ela...\n");
	    printf("E dentro no seu scanf voce deve adicionar um & + nome da sua variavel");
	    printf("\033[0m\n");
	            
	    system("pause");
	    system("cls");
	    printf("\033[35m#include <stdio.h>\n\n");
	    printf("\033[0m\n");
	    printf("\033[34mint \033[0m main(){\n\n");
	    printf("\033[0;34mint \033[0m\033[0;37midade \033[0m= \033[0;33m0;\n\n");
	    printf("\033[0mprintf\033[38;5;208m('Digite sua idade:\\n')\033[0m;\n\n");
		printf("scanf(\033[38;5;208m'%%d'\033[0m, &idade);\n\n");
	    printf("\033[33m\033[34mreturn\033[0m \033[33m\033[1m0\033[0m;\n}\n");
	    printf("\033[31mObservacao: note que usei %%d, pois a idade de uma pesso se trata de um numero inteiro...\n");
	    printf("\033[31mNUNCA ESQUECA de usar o & + (nome da sua variavel) depois de usar o %% correspondente a sua variavel\n\n");
	    printf("\033[0m\n\n");
	
	    system("pause");
	    system("cls");
	            
	    printf("Agora iremos ver uma constante...\n");
	    printf("Uma constante eh nada mais nada menos do que voce adicionar um valor predefinido a uma variavel\n\n");
	    printf("Agora vejamos como funciona isso...\n\n");
	    printf("\033[35m#include <stdio.h>\n\n");
	    printf("\033[0m\n");
	    printf("\033[34mint \033[0m main(){\n\n");
	    printf("\033[0;34mint \033[0m\033[0;37midade \033[0m= \033[0;33m18\033[0m;\n\n");
	    printf("printf\033[38;5;208m('%%d'\033[0m, idade);\n\n");
	    printf("\033[33m\033[34mreturn\033[0m \033[33m\033[1m0\033[0m;\n}\n");
	            
	    printf("\033[31mObservacao: note que nao utilizei o & no meu printf, pois eu ja aloquei um valor constante, e eu so quero mostrar na minha tela essa quantidade\n");
	    printf("porem voce sempre que quiser printar a sua variavel na tela, sempre tem que por o especificador de formato correspondente a sua variavel");
	    printf("\033[0m\n\n\n");
	            
	    printf("Com isso vamos a luta\n");
	    system("pause");
	    system("cls");
	    
		do
		{
			opc = 0;
		    printf("Um inimigo quer enfrentar voce:\n\n");
		    printf("Voce aceita o desafio:\n1- SIM.\n2- NAO.\n");
		    scanf("%d", &opc);
		    printf("\n\n");
		    fflush(stdin);
		
		    system("cls");
	
	        if (opc == 1)
			{
	            printf("Batalha aceita...\n\n");
	            printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
	                   "\033[0;33mForca da POLY.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
	                   "\033[0;33mDestreza da POLY.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
	                   "\033[0;33mSaude da POLY.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
	                   nome, poly.forca,  
	                   jogador.forca, poly.agilidade, 
	                   jogador.agilidade, poly.hp, 
	                   ataque);
	                   
	            printf("\033[0m");
	            system("pause");
			}
			else if (opc == 2) 
			{
	           printf("Continuando...\n\n");
	           break;
	        }
			else if(opc != 1 && opc!= 2)
			{
	            printf("\nNao quer jogar eh? Entao tome. Receba\n\n");
	            GameOver();
	            debug = 1;
	            break;
	        }
			
			do
			{
	        	if(poly.hp > 0 && ataque > 0)
				{
					escolha_ataque = 0;
					system("cls");
					printf("\nSua vez. Ataque:\n");
	        		printf("\n\nEscolha seu ataque:\n\033[31m1- Ataque forte\n2- Ataque medio\n3- Ataque fraco\n.");
	        		printf("\033[0m\n\n");
	        		scanf("%d",&escolha_ataque);
	        		fflush(stdin);
	
	        		system("pause");
	            	system("cls");
				}
				else if(ataque < 0)
				{
			        GameOver();
			        break;
				}
				if (escolha_ataque != 1 && escolha_ataque != 2 && escolha_ataque != 3)
				{
					printf("\nAh, nao quer atacar nao eh?\nRelaxa que o teu adversario quer...\n\nReceba");
					delay(3);
					system("cls");
					GameOver();
					break;
				}
	
	        	if(escolha_ataque == 1)
				{
					ataque_forte = jogador.forca * balanceamento1;
				
	            	printf("Voce escolheu o ataque forte..\n\n");
	
	            	printf("Qual dessas alternativas pergunta e armazena os dados de Idade e peso do meu usuario...\n\n");
	            	printf("\033[35m1- #include <studio.h>\n\n");
	            	printf("\033[0m\n");
	            	printf("\033[34mint \033[0m main(){\n\n");
	            	printf("\033[0;34mfloat \033[0m\033[0;37midade \033[0m= \033[0;33m18\033[0m;\n\n");
	            	printf("scanf(\033[38;5;208m'%%d'\033[0m, &idade);\n\n");
	            	printf("\033[33m\033[34mreturn\033[0m \033[33m\033[1m0\033[0m;\n}\n\n\n");
	            	
	            	printf("\033[35m2- #include <stdio.h>\n\n");
	            	printf("\033[0m\n");
	            	printf("\033[34mint \033[0m main(){\n\n");
	            	printf("\033[0;34mint \033[0m\033[0;37midade \033[0m= \033[0;33m0\033[0m;\n\n");
	            	printf("\033[0;34mfloat \033[0m\033[0;37mpeso \033[0m= \033[0;33m0.0\033[0m;\n\n");
	            	printf("\033[0mprintf\033[38;5;208m('Digite sua idade:\\n')\033[0m;\n\n");
	            	printf("scanf(\033[38;5;208m'%%d'\033[0m, &idade);\n\n");
	            	printf("\033[0mprintf\033[38;5;208m('Digite seu peso:\\n')\033[0m;\n\n");
	            	printf("scanf(\033[38;5;208m'%%f'\033[0m, &peso);\n\n");
	            	printf("\033[33m\033[34mreturn\033[0m \033[33m\033[1m0\033[0m;\n}\n\n\n");
	            	
	            	printf("\033[35m3- #include <stdio.h>\n\n");
	            	printf("\033[0m\n");
	            	printf("\033[34mint \033[0m main(){\n\n");
	            	printf("\033[0;34mint \033[0m\033[0;37midade \033[0m= \033[0;33m0\033[0m;\n\n");
	            	printf("\033[0mprintf\033[38;5;208m('Digite sua idade:\\n')\033[0m;\n\n");
	            	printf("scanf(\033[38;5;208m'%%d'\033[0m, &idade);\n\n");
	            	printf("\033[33m\033[34mreturn\033[0m \033[33m\033[1m0\033[0m;\n}\n\n\n");
	
	            	printf("\033[0m"); // Retorna a cor ao normal
	
		            printf("Responda: ");
		            scanf("%d", &resposta);
		            fflush(stdin);
	
		            if(resposta != 2)
					{
		                printf("Resposta errada,..... nem uma ataque efetivo\n");
		                printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
		                   	   "\033[0;33mForca da POLY.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
		                   	   "\033[0;33mDestreza da POLY.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
		                   	   "\033[0;33mSaude da POLY.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
		                  		nome, poly.forca,
		                  		jogador.forca, poly.agilidade,
		                 		jogador.agilidade, poly.hp,
		                  		ataque);
		                system("pause");
		                   
		
		                if(poly.hp > 0)
		                {
			                printf("Vez de Poly.exe:\n");
			                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
			                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
			                srand(time(NULL));
			                        	
			                system("pause");
			                system("cls");
			                        	
			                numeroAleatorio = rand() % 100;
			                printf("Numero sorteado: %d\n", numeroAleatorio);
			                        	
			                if(numeroAleatorio < 77)
							{
			                    ataque = ataque - poly.forca;
			                        		
			                    printf("Que pena, POLY.EXE te atacou...\n\n");
			                        		
			                    printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        	"\033[0;33mForca da Poly: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        	"\033[0;33mDestreza da Poly: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        	"\033[0;33mSaude da Poly: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
			                        	nome, poly.forca,  
			                        	jogador.forca, poly.agilidade, 
			                        	jogador.agilidade, poly.hp, 
			                        	ataque);
								system("pause");
								system("cls"); 
								
								printf("Sua vez novamente...\n\n");
								printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                           "\033[0;33mForca da POLY: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                           "\033[0;33mDestreza da POLY: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                           "\033[0;33mSaude da POLY: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                           nome, poly.forca,  
			                           jogador.forca, poly.agilidade, 
			                           jogador.agilidade, poly.hp, 
			                           ataque);	                     	
			                           system("pause");
			                }
			                       	 
			                else if(numeroAleatorio > 77)
							{			
			                    printf("UAU! que sorte... Sua vez:\n\n");
			                        			
			                    printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        	"\033[0;33mForca da Poly: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        	"\033[0;33mDestreza da Poly: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        	"\033[0;33mSaude da Poly: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                        	nome, poly.forca,  
			                        	jogador.forca, poly.agilidade, 
			                        	jogador.agilidade, poly.hp, 
			                        	ataque);
			                        			
			                    system("pause");
			                    system("cls");      	
							}
						}
						else
						{
							break;
						}
		            }
		
		        	else if(resposta == 2)
					{
		                poly.hp = poly.hp - ataque_forte;
						 
		                printf("Resposta certa.\n");
		                printf("Ataque efetivo.\n\n");
		                printf("Voce deu: %.1f de dano!\n", ataque_forte);
		                printf("HP Restante de POLY.EXE: %.1f\n", poly.hp);
		                system("pause");
		                printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
		                	"\033[0;33mForca da Poly: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
		                    "\033[0;33mDestreza da Poly: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
		                    "\033[0;33mSaude da Poly: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
		                    nome, poly.forca,  
		                    jogador.forca, poly.agilidade, 
		                    jogador.agilidade, poly.hp,
		                    ataque);
				
						system("pause");
						system("cls");
						if(poly.hp > 0)
		                {
			                printf("Vez de Poly.exe:\n");
			                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
			                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
			                srand(time(NULL));
			                        	
			                system("pause");
			                system("cls");
			                        	
			                numeroAleatorio = rand() % 100;
			                printf("Numero sorteado: %d\n", numeroAleatorio);
			                        	
			                if(numeroAleatorio < 77)
							{
			                    ataque = ataque - poly.forca;
			                        		
			                    printf("Que pena, POLY.EXE te atacou...\n\n");
			                        		
			                    printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        	"\033[0;33mForca da Poly: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        	"\033[0;33mDestreza da Poly: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        	"\033[0;33mSaude da Poly: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
			                        	nome, poly.forca,  
			                        	jogador.forca, poly.agilidade, 
			                        	jogador.agilidade, poly.hp, 
			                        	ataque);
								system("pause");
								system("cls"); 
								
								printf("Sua vez novamente...\n\n");
								printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                           "\033[0;33mForca da POLY: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                           "\033[0;33mDestreza da POLY: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                           "\033[0;33mSaude da POLY: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                           nome, poly.forca,  
			                           jogador.forca, poly.agilidade, 
			                           jogador.agilidade, poly.hp, 
			                           ataque);	      
							    system("pause");               	
			                }
			                       	 
			                else if(numeroAleatorio > 77)
							{			
			                    printf("UAU! que sorte... Sua vez:\n\n");
			                        			
			                    printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        	"\033[0;33mForca da Poly: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        	"\033[0;33mDestreza da Poly: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        	"\033[0;33mSaude da Poly: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                        	nome, poly.forca,  
			                        	jogador.forca, poly.agilidade, 
			                        	jogador.agilidade, poly.hp, 
			                        	ataque);
			                        			
			                    system("pause");
			                    system("cls");      	
							}
						}
						else
						{
							break;
						}
		            }
		        }
		
		        else if(escolha_ataque == 2)
				{
		            printf("Voce escolheu o ataque medio...\n\n");
		            printf("\nEscolha a opcao onde imprima na tela uma constante:\n\n");
		            printf("\033[35m"); // Muda a cor para roxo
		            printf("\033[35m1- #include <stdio.h>\n\n\n");
		            printf("int main(){\n\n");
		            printf("int idade = 18;\n\n");
		            printf("printf('%%d');\n\n");
		            
		            
		            printf("\033[35m2- #include <stdio.h>\n\n\n");
		            printf("int main(){\n\n");
		            printf("int idade = 18;\n\n");
		            printf("printf('%%d', &idade);\n\n");
		            
		            printf("\033[35m3- #include <stdio.h>\n\n\n");
		            printf("int main(){\n\n");
		            printf("int idade = 18;\n\n");
		            printf("printf('%%d', idade);");
		
		            printf("\033[0m"); // Retorna a cor ao normal
		
		            printf("Responda: ");
		            scanf("%d", &resposta);
		            fflush(stdin);
		                     	
		                     	
		
		            if(resposta == 3)
					{   
		                poly.hp = poly.hp - ataque_medio;
						 
		                printf("Resposta certa, ataque medio efetuado");
		                printf("Voce deu: %.1f de dano!\n", ataque_medio);
		                printf("HP Restante de POLY.EXE: %.1f\n", poly.hp);
		
		                        
		                printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
		                           "\033[0;33mForca da POLY: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
		                           "\033[0;33mDestreza da POLY: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
		                           "\033[0;33mSaude da POLY: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
		                           nome, poly.forca,  
		                           jogador.forca, poly.agilidade, 
		                           jogador.agilidade, poly.hp, 
		                           ataque);
		                system("pause");
		                system("cls");
		                
		                printf("Voce esta quase vencendo....\n");
		                printf("Vez de Poly.exe:\n");
		                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
		                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
		                srand(time(NULL));
		                        	
		                system("pause");
		                system("cls");
		                        	
		                numeroAleatorio = rand() % 100;
		                printf("Numero sorteado: %d\n", numeroAleatorio);
		                        	
		                if(numeroAleatorio < 77)
						{
		                    ataque = ataque - poly.forca;
		                        		
		                    printf("Que pena, POLY.EXE te atacou...\n\n");
		                        		
		                    printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
		                        	"\033[0;33mForca da Poly: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
		                        	"\033[0;33mDestreza da Poly: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
		                        	"\033[0;33mSaude da Poly: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
		                        	nome, poly.forca,  
		                        	jogador.forca, poly.agilidade, 
		                        	jogador.agilidade, poly.hp, 
		                        	ataque);
							system("pause");
							system("cls"); 
							
							printf("Sua vez novamente...\n\n");
							printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
		                           "\033[0;33mForca da POLY: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
		                           "\033[0;33mDestreza da POLY: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
		                           "\033[0;33mSaude da POLY: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
		                           nome, poly.forca,  
		                           jogador.forca, poly.agilidade, 
		                           jogador.agilidade, poly.hp, 
		                           ataque);	       
							system("pause");              	
		                }
		                       	 
		                else if(numeroAleatorio > 77)
						{			
		                    printf("UAU! que sorte... Sua vez:\n\n");
		                        			
		                    printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
		                        	"\033[0;33mForca da Poly: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
		                        	"\033[0;33mDestreza da Poly: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
		                        	"\033[0;33mSaude da Poly: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
		                        	nome, poly.forca,  
		                        	jogador.forca, poly.agilidade, 
		                        	jogador.agilidade, poly.hp, 
		                        	ataque);
		                        			
		                    system("pause");
		                    system("cls");      	
						}
		            }
										                    		
		            if(resposta != 3)
					{
		                printf("Resposta errada... Seu ataque falhou!\n");
		                printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
		                     	"\033[0;33mForca da Poly: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
		                     	"\033[0;33mDestreza da Poly: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
		                     	"\033[0;33mSaude da Poly: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
		                     	nome, poly.forca,  
		                     	jogador.forca, poly.agilidade, 
		                     	jogador.agilidade, poly.hp, 
		                     	ataque);
		                system("pause");
		                system("cls");
		                   
		                if(poly.hp > 0)
		                {
			                printf("Vez de Poly.exe:\n");
			                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
			                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
			                srand(time(NULL));
			                        	
			                system("pause");
			                system("cls");
			                        	
			                numeroAleatorio = rand() % 100;
			                printf("Numero sorteado: %d\n", numeroAleatorio);
			                        	
			                if(numeroAleatorio < 77)
							{
			                    ataque = ataque - poly.forca;
			                        		
			                    printf("Que pena, POLY.EXE te atacou...\n\n");
			                        		
			                    printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        	"\033[0;33mForca da Poly: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        	"\033[0;33mDestreza da Poly: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        	"\033[0;33mSaude da Poly: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
			                        	nome, poly.forca,  
			                        	jogador.forca, poly.agilidade, 
			                        	jogador.agilidade, poly.hp, 
			                        	ataque);
								system("pause");
								system("cls"); 
								
								printf("Sua vez novamente...\n\n");
								printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                           "\033[0;33mForca da POLY: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                           "\033[0;33mDestreza da POLY: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                           "\033[0;33mSaude da POLY: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                           nome, poly.forca,  
			                           jogador.forca, poly.agilidade, 
			                           jogador.agilidade, poly.hp, 
			                           ataque);	
								system("pause");                     	
			                }
			                       	 
			                else if(numeroAleatorio > 77)
							{			
			                    printf("UAU! que sorte... Sua vez:\n\n");
			                        			
			                    printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        	"\033[0;33mForca da Poly: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        	"\033[0;33mDestreza da Poly: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        	"\033[0;33mSaude da Poly: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                        	nome, poly.forca,  
			                        	jogador.forca, poly.agilidade, 
			                        	jogador.agilidade, poly.hp, 
			                        	ataque);
			                        			
			                    system("pause");
			                    system("cls");      	
							}
						}
						else
						{
							break;
						}
		            }
		        }
		                    
				else if(escolha_ataque == 3)
				{
		            printf("Voce selecionou a opcao de ataque fraco...\n\n");
		            printf("O que eh uma variavel?\n\n");
		            printf("1- Um tipo de dado primitivo\n\n2- Uma funcao pre definida\n\n");
		            printf(" 3-Um local na memoria para armazenar um valor durante a execucao de um programa\n\n");
		            printf("Responda: ");
		            scanf("%d", &resposta);
		            fflush(stdin);
		            
		            if(resposta == 3)
					{   
			            poly.hp = poly.hp - ataque_fraco;
							 
			            printf("Resposta certa, ataque fraco efetuado");
			            printf("Voce deu: %.1f de dano!\n", ataque_fraco);
			            printf("HP Restante de poly.exe: %.1f\n", poly.hp);
			
			                        
			            printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        "\033[0;33mForca da POLY: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        "\033[0;33mDestreza da POLY: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        "\033[0;33mSaude da POLY: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                        nome, poly.forca,  
			                        jogador.forca, poly.agilidade, 
			                        jogador.agilidade, poly.hp, 
			                        ataque);
			            system("pause");
			            system("cls");
			                
			            if(poly.hp > 0)
		                {
			                printf("Vez de Poly.exe:\n");
			                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
			                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
			                srand(time(NULL));
			                        	
			                system("pause");
			                system("cls");
			                        	
			                numeroAleatorio = rand() % 100;
			                printf("Numero sorteado: %d\n", numeroAleatorio);
			                        	
			                if(numeroAleatorio < 77)
							{
			                    ataque = ataque - poly.forca;
			                        		
			                    printf("Que pena, POLY.EXE te atacou...\n\n");
			                        		
			                    printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        	"\033[0;33mForca da Poly: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        	"\033[0;33mDestreza da Poly: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        	"\033[0;33mSaude da Poly: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
			                        	nome, poly.forca,  
			                        	jogador.forca, poly.agilidade, 
			                        	jogador.agilidade, poly.hp, 
			                        	ataque);
								system("pause");
								system("cls"); 
								
								printf("Sua vez novamente...\n\n");
								printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                           "\033[0;33mForca da POLY: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                           "\033[0;33mDestreza da POLY: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                           "\033[0;33mSaude da POLY: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                           nome, poly.forca,  
			                           jogador.forca, poly.agilidade, 
			                           jogador.agilidade, poly.hp, 
			                           ataque);	      
							system("pause");               	
			                }
			                       	 
			                else if(numeroAleatorio > 77)
							{			
			                    printf("UAU! que sorte... Sua vez:\n\n");
			                        			
			                    printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        	"\033[0;33mForca da Poly: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        	"\033[0;33mDestreza da Poly: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        	"\033[0;33mSaude da Poly: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                        	nome, poly.forca,  
			                        	jogador.forca, poly.agilidade, 
			                        	jogador.agilidade, poly.hp, 
			                        	ataque);
			                        			
			                    system("pause");
			                    system("cls");      	
							}
						}
						else
						{
							break;
						}
			        }
											                    		
			        if(resposta != 3)
					{
			            printf("Resposta errada... Seu ataque falhou!\n");
			            printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                    "\033[0;33mForca da POLY: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                    "\033[0;33mDestreza da POLY: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                    "\033[0;33mSaude da POLY: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                    nome, poly.forca,  
			                    jogador.forca, poly.agilidade, 
			                    jogador.agilidade, poly.hp, 
			                    ataque);
			            system("pause");
			            system("cls");
			                   
			            if(poly.hp > 0)
		                {
			                printf("Vez de Poly.exe:\n");
			                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
			                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
			                srand(time(NULL));
			                        	
			                system("pause");
			                system("cls");
			                        	
			                numeroAleatorio = rand() % 100;
			                printf("Numero sorteado: %d\n", numeroAleatorio);
			                        	
			                if(numeroAleatorio < 77)
							{
			                    ataque = ataque - poly.forca;
			                        		
			                    printf("Que pena, POLY.EXE te atacou...\n\n");
			                        		
			                    printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        	"\033[0;33mForca da Poly: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        	"\033[0;33mDestreza da Poly: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        	"\033[0;33mSaude da Poly: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
			                        	nome, poly.forca,  
			                        	jogador.forca, poly.agilidade, 
			                        	jogador.agilidade, poly.hp, 
			                        	ataque);
								system("pause");
								system("cls"); 
								
								printf("Sua vez novamente...\n\n");
								printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                           "\033[0;33mForca da POLY: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                           "\033[0;33mDestreza da POLY: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                           "\033[0;33mSaude da POLY: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                           nome, poly.forca,  
			                           jogador.forca, poly.agilidade, 
			                           jogador.agilidade, poly.hp, 
			                           ataque);	               
								system("pause");      	
			                }
			                       	 
			                else if(numeroAleatorio > 77)
							{			
			                    printf("UAU! que sorte... Sua vez:\n\n");
			                        			
			                    printf("\033[0;33mNome do inimigo: POLY.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        	"\033[0;33mForca da Poly: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        	"\033[0;33mDestreza da Poly: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        	"\033[0;33mSaude da Poly: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                        	nome, poly.forca,  
			                        	jogador.forca, poly.agilidade, 
			                        	jogador.agilidade, poly.hp, 
			                        	ataque);
			                        			
			                    system("pause");
			                    system("cls");      	
							}
						}
						else
						{
							break;
						}
					}
				}
		    } while (poly.hp > 0);
		} while(opc != 1 && opc !=2);
	}
 
    escolha_ataque = 0;
    resposta = 0;

	if(ataque > 0 && debug != 1)
	{
		ataque = jogador.hp;
		
	    char texto3[] = 
						" _____      _      ____    _____      _____ \n"
						"|  ___|    / \\    / ___|  | ____|    |___ / \n"
						"| |_      / _ \\   \\___ \\  |  _|        |_ \\ \n"
						"|  _|    / ___ \\   ___) | | |___      ___) |\n"
						"|_|     /_/   \\_\\ |____/  |_____|    |____/ \n";
						
						for (int i = 0; texto3[i] != '\0'; i++)
						{
						putchar(texto3[i]);
	        			fflush(stdout);    
	       				 Sleep(1);        
	       				 if (kbhit())
						{
	        			system("cls");
	        			printf(" _____      _      ____    _____      _____ \n"
								"|  ___|    / \\    / ___|  | ____|    |___ / \n"
								"| |_      / _ \\   \\___ \\  |  _|        |_ \\ \n"
								"|  _|    / ___ \\   ___) | | |___      ___) |\n"
								"|_|     /_/   \\_\\ |____/  |_____|    |____/ \n");
						
						break;
			}
	    }
	    
	    
	    printf("\t\t\t\t\t\t\t\t\t\t\t");
		system("pause");
		system("cls");
		
	    printf("Girotto: Ola, %s\n\n", nome);
	    printf("Vejo que voce superou a fase 2, agora iremos nos preparar mais...\n\n");
	    system("pause");
	    system("cls");
	    
	    printf("Nesta fase iremos aprender, sobre Operadores Aritmeticos, logicos e relacionais, e fluxo condicionais...\n\n");
	  	
	  	
	  	
	    printf("\033[1;34m"); // Azul para operadores aritméticos
	    printf("Operadores aritmeticos...\n\n");
	    printf("+ : Adicao: soma dois operandos.\n");
	    printf("- : Subtracao: subtrai o operando da direita do operando da esquerda.\n");
	    printf("* : Multiplicacao: multiplica dois operandos.\n");
	    printf("/ : Divisao: divide o operando da esquerda pelo operando da direita.\n");
	    printf("%% : Modulo: retorna o resto da divisão do operando da esquerda pelo operando da direita.\n\n");
	    
	    
	    printf("\033[1;33m"); // Bege para operadores lógicos
		printf("Operadores logicos...\n\n");
	    printf("\n&& : E logico: retorna verdadeiro se ambos os operandos forem verdadeiros.\n");
	    printf("|| : OU logico: retorna verdadeiro se pelo menos um dos operandos for verdadeiro.\n");
	    printf("! : NAO logico: inverte o valor do operando booleano.\n\n");
	
	    printf("\033[1;35m"); // Rosa para operadores relacionais
	    printf("Operadores relacionais...\n\n");
	    printf("\n== : Igual a: verifica se os operandos sao iguais.\n");
	    printf("!= : Diferente de: verifica se os operandos sao diferentes.\n");
	    printf("> : Maior que: verifica se o operando da esquerda eh maior que o operando da direita.\n");
	    printf("< : Menor que: verifica se o operando da esquerda eh menor que o operando da direita.\n");
	    printf(">= : Maior ou igual a: verifica se o operando da esquerda eh maior ou igual ao operando da direita.\n");
	    printf("<= : Menor ou igual a: verifica se o operando da esquerda eh menor ou igual ao operando da direita.\n\n");
	    
	    printf("\033[1;36m"); // Azul claro
	    printf("fluxo condicionais...\n\n");
	    printf("if: O 'if' eh uma estrutura de controle de fluxo que permite executar um bloco de codigo se uma condicao especificada for verdadeira.\n");
	    printf("O 'else if' eh uma extensão do 'if' que permite verificar uma condição adicional se a condição do 'if' for falsa.\n");
	    printf("else: O 'else' eh uma estrutura de controle de fluxo que permite executar um bloco de codigo alternativo se a condicao do 'if' for falsa.\n\n");
	    printf("\033[0m"); // Reseta a cor para a padrão
	    
	    
	    system("pause");
	    system("cls");
	    
	    printf("Agora com base em tudo que voce aprendeu vou lhe mostrar como usalos calculando a media de um usuario...\n\n");
	    
	    //mostrando media
	    printf("\033[1;36m#include <stdio.h>\n\n");
	    printf("\033[1;34mint \033[0m main(){\n\n");
	    printf("\033[1;34mfloat \033[0m n1 = \033[1;33m0.0\033[0m;\n\n");
	    printf("\033[1;34mfloat \033[0m n2 = \033[1;33m0.0\033[0m;\n\n");
	    printf("\033[1;32mprintf\033[0m(\033[38;5;208m'Digite sua primeira nota: '\033[0m);\n");
	    printf("\033[1;32mscanf\033[0m(\033[38;5;208m'%%f'\033[0m, &n1)\n\n");
	    printf("\033[1;32mprintf\033[0m(\033[38;5;208m'Digite sua segunda nota: '\033[0m);\n\n");
	    printf("\033[1;32mscanf\033[0m(\033[38;5;208m'%%f'\033[0m, &n2);\n\n");
	    printf("\033[1;34mfloat \033[0m media = (n1 + n2)/2;\n\n");
	    printf("\033[1;32mprintf\033[0m(\033[38;5;208m'Sua media corresponde a %%f'\033[0m, media);\n\n");
	    printf("\033[1;34mif\033[0m(media >= \033[1;33m7 \033[0m&& media <= \033[1;33m10\033[0m){\n");
	    printf("   \033[1;32mprintf\033[0m(\033[38;5;208m'Aprovado...\\n'\033[0m);\n}\n\n");
	    printf("\033[1;34melse \033[1;34mif\033[0m(media >= \033[1;33m0 \033[0m&& media <= \033[1;33m6\033[0m){\n");
	    printf("\033[1;32mprintf\033[0m(\033[38;5;208m'Reprovado...\\n'\033[0m);\n}\n\n");
	    printf("\033[1;34melse{\n\033[1;32mprintf\033[0m(\033[38;5;208m'Media invalida'\033[0m);\n}\n");
	    printf("\033[33m\033[34mreturn\033[0m \033[33m\033[1m0\033[0m;\n}\n\n\n");
	    
	    system("pause");
	    system("cls");
	
	    // Reseta a cor para a padrão
	    printf("\033[0m");
	
	    do
		{
			opc = 0;
	    	printf("Um inimigo quer enfrentar voce:\n\n");
	        printf("Voce aceita o desafio:\n1- SIM.\n2- NAO.\n");
	        scanf("%d", &opc);
	        printf("\n\n");
	        fflush(stdin);
	
	        system("cls");
	
	        if (opc == 1)
			{
	            printf("Batalha aceita...\n\n");
	            printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
	                   "\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
	                   "\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
	                   "\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
	                   nome, victor.forca,  
	                   jogador.forca, victor.agilidade, 
	                   jogador.agilidade, victor.hp, 
	                   ataque);
	                   
	            printf("\033[0m");
	            system("pause");
			
				do
				{
		        	if(victor.hp > 0 && ataque > 0)
					{
						escolha_ataque = 0;
						system("cls");
						printf("\nSua vez. Ataque:\n");
		        		printf("\n\nEscolha seu ataque:\n\033[31m1- Ataque forte\n2- Ataque medio\n3- Ataque fraco\n.");
		        		printf("\033[0m\n\n");
		        		scanf("%d",&escolha_ataque);
		        		fflush(stdin);
		
		        		system("pause");
		            	system("cls");
					}
					else if(ataque < 0)
					{
				        GameOver();
				        break;
					}
					if (escolha_ataque != 1 && escolha_ataque != 2 && escolha_ataque != 3)
					{
						printf("\nAh, nao quer atacar eh?\nRelaxa que o teu adversario quer...\n\nReceba");
						delay(3);
						system("cls");
						GameOver();
						break;
					}
		
		        	else if(escolha_ataque == 1)
					{
						ataque_forte = jogador.forca * balanceamento1;
					
		            	printf("Voce escolheu o ataque forte..\n\n");
					
		            	printf("Escolha a opcao que nao contem nenhum erro:\n\n");
		            	
		            	// Opção 1 - Verde
		    			printf("\033[1;32m1- ");
		    			printf("#include <stdio.h>\n\n");
		    			printf("int main(){\n\n");
		    			printf("float n1 = 0.0;\n\n");
		    			printf("float n2 = 0.0;\n\n");
		    			printf("printf('Digite sua primeira nota: ');\n");
		    			printf("scanf('%%f', &n1)\n\n");
		    			printf("printf('Digite sua segunda nota: ');\n\n");
		    			printf("scanf('%%f', &n2);\n\n");
		    			printf("float media = (n1 + n2)/2;\n\n");
		    			printf("printf('Sua media corresponde a %%f', media);\n\n");
		   				printf("if(media >= 7 && media <= 10)\n");
		    			printf("   printf('Aprovado...\\n');\n\n");
		    			printf("else if(media >= 0 && media <= 6)\n");
		    			printf("printf('Reprovado...\\n');\n\n");
		    			printf("else{\nprintf('Media invalida');\n}\n");
		    			printf("return 0;\n\n\n");
		
		    // Opção 2 - Vermelho
		    			printf("\033[1;31m2- ");
		    			printf("#include <stdio.h>\n\n");
		    			printf("int main(){\n\n");
		    			printf("float n1 = 0.0;\n\n");
		    			printf("float n2 = 0.0;\n\n");
		    			printf("printf('Digite sua primeira nota: ');\n");
		    			printf("scanf('%%f', &n1);\n\n"); // Erro sutil: falta ponto e vírgula
		    			printf("printf('Digite sua segunda nota: ');\n\n");
		    			printf("scanf('%%f', &n2);\n\n");
		    			printf("float media = (n1 + n2)/2;\n\n");
		    			printf("printf('Sua media corresponde a %%f', media);\n\n"); // Erro sutil: falta \n no final
		    			printf("if(media >= 7 && media <= 10){\n");
		    			printf("   printf('Aprovado...\\n');\n\n");
		    			printf("else if(media >= 0 && media <= 6)\n"); // Erro sutil: falta \n no final
		    			printf("printf('Reprovado...\\n');\n\n");
		    			printf("else{\nprintf('Media invalida');\n}\n");
		    			printf("return 0;\n\n");
		
		    // Opção 3 - Laranja
		    			printf("\033[1;33m3- ");
		    			printf("#include <stdio.h>\n\n");
		    			printf("int main(){\n\n");
		    			printf("float n1 = 0.0;\n\n");
		    			printf("float n2 = 0.0;\n\n");
		    			printf("printf('Digite sua primeira nota: ');\n");
		    			printf("scanf('%%f', &n1);\n\n"); // Correto: ponto e vírgula no final
		    			printf("printf('Digite sua segunda nota: ');\n\n");
		    			printf("scanf('%%f', &n2);\n\n");
		    			printf("float media = (n1 + n2)/2;\n\n");
		    			printf("printf('Sua media corresponde a %%f\\n', media);\n\n"); // Correto: \n no final
		    			printf("if(media >= 7 && media <= 10){\n");
		    			printf("   printf('Aprovado...\\n');\n}\n\n");
		    			printf("else if(media >= 0 && media <= 6){\n");
		    			printf("   printf('Reprovado...\\n');\n}\n\n");
		    			printf("else{\nprintf('Media invalida');\n}\n\n");
		    			printf("return 0;\n}\n\n");
		
		    			printf("\033[0m"); // Reseta a cor para a padrão
		            	
		
			            printf("Responda: ");
			            scanf("%d", &resposta);
			            fflush(stdin);
						
						system("pause");
						system("cls");
						
						if(resposta != 3)
						{
			                printf("Resposta errada,..... nem uma ataque efetivo\n");
			                printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                   	   "\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                   	   "\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                   	   "\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                  		nome, victor.forca,
			                  		jogador.forca, victor.agilidade,
			                 		jogador.agilidade, victor.hp,
			                  		ataque);
			                system("pause");
			                   
			
			                if(victor.hp > 0)
			                {
				                printf("Vez de VICTOR_HUGO.exe:\n");
				                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
				                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
				                srand(time(NULL));
				                        	
				                system("pause");
				                system("cls");
				                        	
				                numeroAleatorio = rand() % 100;
				                printf("Numero sorteado: %d\n", numeroAleatorio);
				                        	
				                if(numeroAleatorio < 77)
								{
				                    ataque = ataque - poly.forca;
				                        		
				                    printf("Que pena, VICTOR_HUGO.EXE te atacou...\n\n");
				                        		
				                    printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
				                        	nome, victor.forca,  
				                        	jogador.forca, victor.agilidade, 
				                        	jogador.agilidade, victor.hp, 
				                        	ataque);
									system("pause");
									system("cls"); 
									
									printf("Sua vez novamente...\n\n");
									printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                           "\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                           "\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                           "\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                           nome, victor.forca,  
				                           jogador.forca, victor.agilidade, 
				                           jogador.agilidade, victor.hp, 
				                           ataque);	      
									system("pause");              	
				                }
				                       	 
				                else if(numeroAleatorio > 77)
								{			
				                    printf("UAU! que sorte... Sua vez:\n\n");
				                        			
				                    printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                        	nome, victor.forca,  
				                        	jogador.forca, victor.agilidade, 
				                        	jogador.agilidade, victor.hp, 
				                        	ataque);
				                        			
				                    system("pause");
				                    system("cls");      	
								}
							}
							else
							{
								break;
							}
			            }
			
			        	else if(resposta == 3)
						{
			                victor.hp = victor.hp - ataque_forte;
							 
			                printf("Resposta certa.\n");
			                printf("Ataque efetivo.\n\n");
			                printf("Voce deu: %.1f de dano!\n", ataque_forte);
			                printf("HP Restante de VICTOR_HUGO.EXE: %.1f\n", victor.hp);
			                system("pause");
			                printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                	"\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                    "\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                    "\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                    nome, victor.forca,  
			                    jogador.forca, victor.agilidade, 
			                    jogador.agilidade, victor.hp,
			                    ataque);
					
							system("pause");
							system("cls");
							if(victor.hp > 0)
			                {
				                printf("Vez de VICTOR_HUGO.EXE:\n");
				                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
				                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
				                srand(time(NULL));
				                        	
				                system("pause");
				                system("cls");
				                        	
				                numeroAleatorio = rand() % 100;
				                printf("Numero sorteado: %d\n", numeroAleatorio);
				                        	
				                if(numeroAleatorio < 77)
								{
				                    ataque = ataque - victor.forca;
				                        		
				                    printf("Que pena, de VICTOR_HUGO.EXE te atacou...\n\n");
				                        		
				                    printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
				                        	nome, victor.forca,  
				                        	jogador.forca, victor.agilidade, 
				                        	jogador.agilidade, victor.hp, 
				                        	ataque);
									system("pause");
									system("cls"); 
									
									printf("Sua vez novamente...\n\n");
									printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                           "\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                           "\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                           "\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                           nome, victor.forca,  
				                           jogador.forca, victor.agilidade, 
				                           jogador.agilidade, victor.hp, 
				                           ataque);	 
								    system("pause");                   	
				                }
				                       	 
				                else if(numeroAleatorio > 77)
								{			
				                    printf("UAU! que sorte... Sua vez:\n\n");
				                        			
				                    printf("\033[0;33mNome do inimigo: de VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                        	nome, victor.forca,  
				                        	jogador.forca, victor.agilidade, 
				                        	jogador.agilidade, victor.hp, 
				                        	ataque);
				                        			
				                    system("pause");
				                    system("cls");      	
								}
							}
							else
							{
								break;
							}
			            }
			        }
			
			        else if(escolha_ataque == 2)
					{
			            printf("Voce escolheu o ataque medio...\n\n");
			            printf("\nEscolha a opcao correta, onde usam os operadores e a logica correta:\n\n");
			            // Opção 1 - Correta (Verde)
	    				printf("\033[1;32m1- ");
	    				printf("#include <stdio.h>\n\n");
	    				printf("int main() {\n");
	    				printf("    int numero = 15;\n");
	    				printf("    if (numero > 10 && numero < 20) {\n");
	    				printf("        printf(\"O numero esta entre 10 e 20.\\n\");\n");
	    				printf("    }\n");
	    				printf("    return 0;\n");
	    				printf("}\n\n");
	
	    				// Opção 2 - Errada (Vermelho)
	   					printf("\033[1;31m2- ");
	    				printf("#include <stdio.h>\n\n");
	    				printf("int main() {\n");
	    				printf("    int numero = 5;\n");
	    				printf("    if (numero >= 10 && numero <= 20) {\n");
	    				printf("        printf(\"O numero esta entre 10 e 20.\\n\");\n");
	    				printf("    }\n");
	    				printf("    return 0;\n");
	    				printf("}\n\n");
	
	    				// Opção 3 - Errada (Azul)
	    				printf("\033[1;34m3- ");
	    				printf("#include <stdio.h>\n\n");
	    				printf("int main() {\n");
	    				printf("    int numero = 25;\n");
	    				printf("    if (numero >= 10 && numero <= 20) {\n");
	    				printf("        printf(\"O numero esta entre 10 e 20.\\n\");\n");
	    				printf("    }\n");
	    				printf("    return 0;\n");
	    				printf("}\n\n");
	
	    				printf("\033[0m"); // Reseta a cor para a padrão
	
			
			            printf("Responda: ");
			            scanf("%d", &resposta);
			            fflush(stdin);
			                     	
			                     	
			
			            if(resposta == 1)
						{   
			                victor.hp = victor.hp - ataque_medio;
							 
			                printf("Resposta certa, ataque medio efetuado");
			                printf("Voce deu: %.1f de dano!\n", ataque_medio);
			                printf("HP Restante de POLY.EXE: %.1f\n", victor.hp);
			
			                        
			                printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                           "\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                           "\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                           "\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                           nome, victor.forca,  
			                           jogador.forca, victor.agilidade, 
			                           jogador.agilidade, victor.hp, 
			                           ataque);
			                system("pause");
			                system("cls");
			                
			                printf("Voce esta quase vencendo....\n");
			                printf("Vez de VICTOR_HUGO.EXE.exe:\n");
			                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
			                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
			                srand(time(NULL));
			                        	
			                system("pause");
			                system("cls");
			                        	
			                numeroAleatorio = rand() % 100;
			                printf("Numero sorteado: %d\n", numeroAleatorio);
			                        	
			                if(numeroAleatorio < 77)
							{
			                    ataque = ataque - victor.forca;
			                        		
			                    printf("Que pena, VICTOR_HUGO.EXE te atacou...\n\n");
			                        		
			                    printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        	"\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        	"\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        	"\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
			                        	nome, victor.forca,  
			                        	jogador.forca, victor.agilidade, 
			                        	jogador.agilidade, victor.hp, 
			                        	ataque);
								system("pause");
								system("cls"); 
								
								printf("Sua vez novamente...\n\n");
								printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                           "\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                           "\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                           "\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                           nome, victor.forca,  
			                           jogador.forca, victor.agilidade, 
			                           jogador.agilidade, victor.hp, 
			                           ataque);	                     	
			                    system("pause");
			                }
			                       	 
			                else if(numeroAleatorio > 77)
							{			
			                    printf("UAU! que sorte... Sua vez:\n\n");
			                        			
			                    printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        	"\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        	"\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        	"\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                        	nome, victor.forca,  
			                        	jogador.forca, victor.agilidade, 
			                        	jogador.agilidade, victor.hp, 
			                        	ataque);
			                        			
			                    system("pause");
			                    system("cls");      	
							}
			            }
											                    		
			            if(resposta != 1)
						{
			                printf("Resposta errada... Seu ataque falhou!\n");
			                printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                     	"\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                     	"\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                     	"\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                     	nome, victor.forca,  
			                     	jogador.forca, victor.agilidade, 
			                     	jogador.agilidade, victor.hp, 
			                     	ataque);
			                system("pause");
			                system("cls");
			                   
			                if(victor.hp > 0)
			                {
				                printf("Vez de VICTOR_HUGO.EXE:\n");
				                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
				                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
				                srand(time(NULL));
				                        	
				                system("pause");
				                system("cls");
				                        	
				                numeroAleatorio = rand() % 100;
				                printf("Numero sorteado: %d\n", numeroAleatorio);
				                        	
				                if(numeroAleatorio < 77)
								{
				                    ataque = ataque - victor.forca;
				                        		
				                    printf("Que pena, VICTOR_HUGO.EXE te atacou...\n\n");
				                        		
				                    printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
				                        	nome, victor.forca,  
				                        	jogador.forca, victor.agilidade, 
				                        	jogador.agilidade, victor.hp, 
				                        	ataque);
									system("pause");
									system("cls"); 
									
									printf("Sua vez novamente...\n\n");
									printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                           "\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                           "\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                           "\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                           nome, victor.forca,  
				                           jogador.forca, victor.agilidade, 
				                           jogador.agilidade, victor.hp, 
				                           ataque);	            
								    system("pause");         	
				                }
				                       	 
				                else if(numeroAleatorio > 77)
								{			
				                    printf("UAU! que sorte... Sua vez:\n\n");
				                        			
				                    printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                        	nome, victor.forca,  
				                        	jogador.forca, victor.agilidade, 
				                        	jogador.agilidade, victor.hp, 
				                        	ataque);
				                        			
				                    system("pause");
				                    system("cls");      	
								}
							}
							else
							{
								break;
							}
			            }
			        }
			                    
					else if(escolha_ataque == 3)
					{
						printf("Selecione a opcao correta:\n\n");
						
			            // Opção 1 - Errada
	    				printf("\033[1;31m1- ");
	    				printf("Operadores logicos sao utilizados para realizar operacoes matematicas em um programa.\n\n");
	
	    				// Opção 2 - Errada
	    				printf("\033[1;31m2- ");
	    				printf("Operadores aritmeticos sao utilizados para comparar valores e tomar decisoes em um programa.\n\n");
	
	    				// Opção 3 - Correta (Verde)
	    				printf("\033[1;32m3- ");
	    				printf("Operadores relacionais sao utilizados para realizar operacoes de comparacao entre valores, retornando um resultado verdadeiro ou falso.\n\n");
	
	    				printf("\033[0m\nResponda:"); // Reseta a cor para a padrão
	    				scanf("%d", &resposta);
			            
			            if(resposta == 3)
						{   
				            victor.hp = victor.hp - ataque_fraco;
								 
				            printf("Resposta certa, ataque fraco efetuado");
				            printf("Voce deu: %.1f de dano!\n", ataque_fraco);
				            printf("HP Restante de VICTOR_HUGO.exe: %.1f\n", victor.hp);
				
				                        
				            printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        "\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        "\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        "\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                        nome, victor.forca,  
				                        jogador.forca, victor.agilidade, 
				                        jogador.agilidade, victor.hp, 
				                        ataque);
				            system("pause");
				            system("cls");
				                
				            if(victor.hp > 0)
			                {
				                printf("Vez de VICTOR_HUGO.EXE:\n");
				                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
				                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
				                srand(time(NULL));
				                        	
				                system("pause");
				                system("cls");
				                        	
				                numeroAleatorio = rand() % 100;
				                printf("Numero sorteado: %d\n", numeroAleatorio);
				                        	
				                if(numeroAleatorio < 77)
								{
				                    ataque = ataque - victor.forca;
				                        		
				                    printf("Que pena, VICTOR_HUGO.EXE te atacou...\n\n");
				                        		
				                    printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
				                        	nome, victor.forca,  
				                        	jogador.forca, victor.agilidade, 
				                        	jogador.agilidade, victor.hp, 
				                        	ataque);
									system("pause");
									system("cls"); 
									
									printf("Sua vez novamente...\n\n");
									printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                           "\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                           "\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                           "\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                           nome, victor.forca,  
				                           jogador.forca, victor.agilidade, 
				                           jogador.agilidade, victor.hp, 
				                           ataque);	    
									system("pause");                 	
				                }
				                       	 
				                else if(numeroAleatorio > 77)
								{			
				                    printf("UAU! que sorte... Sua vez:\n\n");
				                        			
				                    printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                        	nome, victor.forca,  
				                        	jogador.forca, victor.agilidade, 
				                        	jogador.agilidade, victor.hp, 
				                        	ataque);
				                        			
				                    system("pause");
				                    system("cls");      	
								}
							}
							else
							{
								break;
							}
				        }
												                    		
				        if(resposta != 3)
						{
				            printf("Resposta errada... Seu ataque falhou!\n");
				            printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                    "\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                    "\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                    "\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                    nome, victor.forca,  
				                    jogador.forca, victor.agilidade, 
				                    jogador.agilidade, victor.hp, 
				                    ataque);
				            system("pause");
				            system("cls");
				                   
				            if(poly.hp > 0)
			                {
				                printf("Vez de VICTOR_HUGO.EXE:\n");
				                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
				                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
				                srand(time(NULL));
				                        	
				                system("pause");
				                system("cls");
				                        	
				                numeroAleatorio = rand() % 100;
				                printf("Numero sorteado: %d\n", numeroAleatorio);
				                        	
				                if(numeroAleatorio < 77)
								{
				                    ataque = ataque - victor.forca;
				                        		
				                    printf("Que pena, VICTOR_HUGO.EXE te atacou...\n\n");
				                        		
				                    printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
				                        	nome, victor.forca,  
				                        	jogador.forca, victor.agilidade, 
				                        	jogador.agilidade, victor.hp, 
				                        	ataque);
									system("pause");
									system("cls"); 
									
									printf("Sua vez novamente...\n\n");
									printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                           "\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                           "\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                           "\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                           nome, victor.forca,  
				                           jogador.forca, victor.agilidade, 
				                           jogador.agilidade, victor.hp, 
				                           ataque);	         
									system("pause");            	
				                }
				                       	 
				                else if(numeroAleatorio > 77)
								{			
				                    printf("UAU! que sorte... Sua vez:\n\n");
				                        			
				                    printf("\033[0;33mNome do inimigo: VICTOR_HUGO.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de VICTOR_HUGO.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de VICTOR_HUGO.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                        	nome, victor.forca,  
				                        	jogador.forca, victor.agilidade, 
				                        	jogador.agilidade, victor.hp, 
				                        	ataque);
				                        			
				                    system("pause");
				                    system("cls");      	
								}
							}
							else
							{
								break;
							}
						}
					}
				} while (victor.hp > 0);
			}
			else if (opc == 2) 
			{
	           printf("Continuando...\n\n");
	           break;
	        }
			else if(opc != 1 && opc!= 2)
			{
	            printf("\nNao quer jogar eh? Entao tome. Receba\n\n");
	            GameOver();
	            debug = 1;
	            break;
	        }
		} while(opc != 1 && opc !=2);
	}
    resposta = 0;
    
    if(ataque > 0 && debug != 1)
    {
    	opc = 0;
    	ataque = jogador.hp;
    	
    	
		char texto4[] = " _   _   _   _____   ___   __  __      _    \n"
    					"| | | | | | |_   _| |_ _| |  \\/  |    / \\   \n"
    					"| | | | | |   | |    | |  | |\\/| |   / _ \\  \n"
    					"| |_| | | |___| |    | |  | |  | |  / ___ \\ \n"
    					" \\___/ _|_____|_| _ |___|_|_|  |_|_/_/   \\_\\ \n\n"
    					"      |  ___|    / \\    / ___|  | ____|     \n"
    					"      | |_      / _ \\   \\___ \\  |  _|       \n"
    					"      |  _|    / ___ \\   ___) | | |___      \n"
    					"      |_|     /_/   \\_\\ |____/  |_____|     \n";
    					
    					for (int i = 0; texto4[i] != '\0'; i++)
						{
							putchar(texto4[i]);
	        				fflush(stdout);    
							Sleep(1);        
							if (kbhit())
							{
	        					system("cls");
	        			    	printf(" _   _   _   _____   ___   __  __      _    \n"
    									"| | | | | | |_   _| |_ _| |  \\/  |    / \\   \n"
    									"| | | | | |   | |    | |  | |\\/| |   / _ \\  \n"
    									"| |_| | | |___| |    | |  | |  | |  / ___ \\ \n"
    									" \\___/ _|_____|_| _ |___|_|_|  |_|_/_/   \\_\\ \n\n"
    									"      |  ___|    / \\    / ___|  | ____|     \n"
    									"      | |_      / _ \\   \\___ \\  |  _|       \n"
    									"      |  _|    / ___ \\   ___) | | |___      \n"
    									"      |_|     /_/   \\_\\ |____/  |_____|     \n");
								break;
							}
	    				}
	    
	    
	    printf("\t\t\t\t\t\t\t\t\t\t\t");
		system("pause");
		system("cls");
		
	    printf("Girotto: Ola, %s\n\n", nome);
	    printf("Vejo que voce superou a fase 3, agora iremos para sua ultima fase...\n");
	    printf("Parabens Garoto voce esta indo muito bem muahah... quer dizer muito bem\n\n");
	    system("pause");
	    system("cls");
	    
	    printf("Nesta fase iremos aprender, sobre lacos de repiticao(do, do while, for)...\n\n");
	    printf("\033[1;31mPRESTE BASTANTE ATENCAO NESSE ASSUNTO\033[0m\n\n");

	    
	  	// Laço FOR
		printf("\033[1;36mLaco FOR:\n\033[0m");
		printf("\033[1;37mO laco FOR eh usado quando voce sabe exatamente quantas vezes deseja repetir uma acao.\n\033[0m");
		printf("\033[1;37mSintaxe:\n");
		printf("\033[1;37mfor (inicializacao; condicao; incremento/decremento) {\n");
		printf("    // corpo do laco\n");
		printf("}\n\n\033[0m");
		
		printf("\033[1;37mExemplo:\n");
		printf("\033[1;32mfor (int i = 0; i < 5; i++) {\n");
		printf("    printf(\"Contagem: %%d\\n\", i);\n");
		printf("}\n\n\033[0m");
		
		// Laço WHILE
		printf("\033[1;36mLaço WHILE:\n\033[0m");
		printf("\033[1;37mO laco WHILE eh usado quando voce nao sabe quantas vezes deseja repetir uma acao, mas sabe a condicao para parar.\n\033[0m");
		printf("\033[1;37mSintaxe:\n");
		printf("\033[1;37mwhile (condicao) {\n");
		printf("    // corpo do laco\n");
		printf("}\n\n\033[0m");
		
		printf("\033[1;37mExemplo:\n");
		printf("\033[1;32mint j = 0;\n");
		printf("while (j < 5) {\n");
		printf("    printf(\"Contagem: %%d\\n\", j);\n");
		printf("    j++;\n");
		printf("}\n\n\033[0m");
		
		// Laço DO-WHILE
		printf("\033[1;36mLaco DO-WHILE:\n\033[0m");
		printf("\033[1;37mO laco DO-WHILE eh semelhante ao WHILE, mas a condicao eh verificada apos a execucao do bloco de codigo, garantindo que o bloco seja executado pelo menos uma vez.\n\033[0m");
		printf("\033[1;37mSintaxe:\n");
		printf("\033[1;37mdo {\n");
		printf("    // corpo do laco\n");
		printf("} while (condicao);\n\n\033[0m");
		
		printf("\033[1;37mExemplo:\n");
		printf("\033[1;32mint k = 0;\n");
		printf("do {\n");
		printf("    printf(\"Contagem: %%d\\n\", k);\n");
		printf("    k++;\n");
		printf("} while (k < 5);\n\n\033[0m\n\n");
		
		
		system("pause");
		system("cls");
		
		printf("voce ja esta pronto...\n\n");
		
		
		
		
	    do
		{
			opc = 0;
	    	printf("Um inimigo quer enfrentar voce:\n\n");
	        printf("Voce aceita o desafio:\n1- SIM.\n2- NAO.\n");
	        scanf("%d", &opc);
	        printf("\n\n");
	        fflush(stdin);
	
	        system("cls");
	
	        if (opc == 1)
			{
	            printf("Batalha aceita...\n\n");
	            printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
	                   "\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
	                   "\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
	                   "\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
	                   nome, eliane.forca,  
	                   jogador.forca, eliane.agilidade, 
	                   jogador.agilidade, eliane.hp, 
	                   ataque);
	                   
	            printf("\033[0m");
	            system("pause");
	            system("cls");
			
				do
				{
		        	if(eliane.hp > 0 && ataque > 0)
					{
						escolha_ataque = 0;
						system("cls");
						printf("\nSua vez. Ataque:\n");
		        		printf("\n\nEscolha seu ataque:\n\033[31m1- Ataque forte\n2- Ataque medio\n3- Ataque fraco\n.");
		        		printf("\033[0m\n\n");
		        		scanf("%d",&escolha_ataque);
		        		fflush(stdin);
		
		        		system("pause");
		            	system("cls");
					}
					else if(ataque < 0)
					{
				        GameOver();
				        break;
					}
					if (escolha_ataque != 1 && escolha_ataque != 2 && escolha_ataque != 3)
					{
						printf("\nAh, nao quer atacar eh?\nRelaxa que o teu adversario quer...\n\nReceba");
						delay(3);
						system("cls");
						GameOver();
						break;
					}
		
		        	else if(escolha_ataque == 1)
					{
						ataque_forte = jogador.forca * balanceamento1;
					
		            	printf("Voce escolheu o ataque forte..\n\n");
					
		            	printf("Escolha a opcao que esta INcorreta:\n\n");
		            	

					    printf("\033[1;31mLoop A:\n");
					    printf("#include <stdio.h>\n");
					    printf("int main() {\n");
					    printf("    for (int i = 0; i < 5; i++) {\n");
					    printf("        printf(\"%%d \", i);\n");
					    printf("    }\n");
					    printf("    return 0;\n");
				        printf("}\n\n");
						
						printf("\033[1;32mLoop B:\n");
					    printf("#include <stdio.h>\n");
						printf("int main() {\n");
						printf("    for (int j = 1; j <= 5; j++) {\n");
						printf("        printf(\"%%d \", j);\n");
						printf("        j++;\n");
						printf("    }\n");
						printf("    return 0;\n");
						printf("}\n\n");
						
						printf("\033[1;33mLoop C:\n");
						printf("#include <stdio.h>\n");
						printf("int main() {\n");
						printf("    for (int k = 0; k <= 5; k++) {\n");
						printf("        printf(\"%%d \", k);\n");
						printf("    }\n");
						printf("    return 0;\n");
						printf("}\n\n");

							            	
		
			            printf("Responda: ");
			            scanf("%d", &resposta);
			            fflush(stdin);
						
						system("pause");
						system("cls");
						
						if(resposta != 2)
						{
			                printf("Resposta errada,..... nem uma ataque efetivo\n");
			                printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                   	   "\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                   	   "\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                   	   "\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                  		nome, eliane.forca,
			                  		jogador.forca, eliane.agilidade,
			                 		jogador.agilidade, eliane.hp,
			                  		ataque);
			                system("pause");
			                   
			
			                if(eliane.hp > 0)
			                {
				                printf("Vez de ELIANE.EXE:\n");
				                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
				                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
				                srand(time(NULL));
				                        	
				                system("pause");
				                system("cls");
				                        	
				                numeroAleatorio = rand() % 100;
				                printf("Numero sorteado: %d\n", numeroAleatorio);
				                        	
				                if(numeroAleatorio < 77)
								{
				                    ataque = ataque - eliane.forca;
				                        		
				                    printf("Que pena, ELIANE.EXE te atacou...\n\n");
				                        		
				                    printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
				                        	nome, eliane.forca,  
				                        	jogador.forca, eliane.agilidade, 
				                        	jogador.agilidade, eliane.hp, 
				                        	ataque);
									system("pause");
									system("cls"); 
									
									printf("Sua vez novamente...\n\n");
									printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                           "\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                           "\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                           "\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                           nome, eliane.forca,  
				                           jogador.forca, eliane.agilidade, 
				                           jogador.agilidade, eliane.hp, 
				                           ataque);	      
									system("pause");              	
				                }
				                       	 
				                else if(numeroAleatorio > 77)
								{			
				                    printf("UAU! que sorte... Sua vez:\n\n");
				                        			
				                    printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                        	nome, eliane.forca,  
				                        	jogador.forca, eliane.agilidade, 
				                        	jogador.agilidade, eliane.hp, 
				                        	ataque);
				                        			
				                    system("pause");
				                    system("cls");      	
								}
							}
							else
							{
								break;
							}
			            }
			
			        	else if(resposta == 2)
						{
			                eliane.hp = eliane.hp - ataque_forte;
							 
			                printf("Resposta certa.\n");
			                printf("Ataque efetivo.\n\n");
			                printf("Voce deu: %.1f de dano!\n", ataque_forte);
			                printf("HP Restante de ELIANE.EXE.EXE: %.1f\n", eliane.hp);
			                system("pause");
			                printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                	"\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                    "\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                    "\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                    nome, eliane.forca,  
			                    jogador.forca, eliane.agilidade, 
			                    jogador.agilidade, eliane.hp,
			                    ataque);
					
							system("pause");
							system("cls");
							if(eliane.hp > 0)
			                {
				                printf("Vez de ELIANE.EXE:\n");
				                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
				                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
				                srand(time(NULL));
				                        	
				                system("pause");
				                system("cls");
				                        	
				                numeroAleatorio = rand() % 100;
				                printf("Numero sorteado: %d\n", numeroAleatorio);
				                        	
				                if(numeroAleatorio < 77)
								{
				                    ataque = ataque - victor.forca;
				                        		
				                    printf("Que pena, de ELIANE.EXE te atacou...\n\n");
				                        		
				                    printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
				                        	nome, eliane.forca,  
				                        	jogador.forca, eliane.agilidade, 
				                        	jogador.agilidade, eliane.hp, 
				                        	ataque);
									system("pause");
									system("cls"); 
									
									printf("Sua vez novamente...\n\n");
									printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                           "\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                           "\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                           "\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                           nome, eliane.forca,  
				                           jogador.forca, eliane.agilidade, 
				                           jogador.agilidade, eliane.hp, 
				                           ataque);	 
								    system("pause");                   	
				                }
				                       	 
				                else if(numeroAleatorio > 77)
								{			
				                    printf("UAU! que sorte... Sua vez:\n\n");
				                        			
				                    printf("\033[0;33mNome do inimigo: de ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                        	nome, eliane.forca,  
				                        	jogador.forca, eliane.agilidade, 
				                        	jogador.agilidade, eliane.hp, 
				                        	ataque);
				                        			
				                    system("pause");
				                    system("cls");      	
								}
							}
							else
							{
								break;
							}
			            }
			        }
			
			        else if(escolha_ataque == 2)
					{
						printf("Voce escolheu o ataque medio...\n");
						printf("Responda corretamente:\n\n");
						
			            printf("\033[1;31m1- \n");
					    printf("#include <stdio.h>\n");
					    printf("int main() {\n");
					    printf("    int i = 0;\n");
					    printf("    while (i < 5) {\n");
					    printf("        printf(\"%%d \", i);\n");
					    printf("        i++;\n");
					    printf("    }\n");
					    printf("    return 0;\n");
					    printf("}\n\n");
					
					    printf("\033[1;32m2- \n");
					    printf("#include <stdio.h>\n");
					    printf("int main() {\n");
					    printf("    int j = 1;\n");
					    printf("    while (j <= 5) {\n");
					    printf("        printf(\"%%d \", j);\n");
					    printf("        j+;\n");
					    printf("    }\n");
					    printf("    return 0;\n");
					    printf("}\n\n");
					
					    printf("\033[1;33m3- \n");
					    printf("#include <stdio.h>\n");
					    printf("int main() {\n");
					    printf("    int k = 0;\n");
					    printf("    while (1) {\n"); // Loop infinito
					    printf("        printf(\"%%d \", k);\n");
					    printf("    }\n");
					    printf("    return 0;\n");
					    printf("}\n\n");
	
			
			            printf("Responda: ");
			            scanf("%d", &resposta);
			            fflush(stdin);
			                     	
			                     	
			
			            if(resposta == 1)
						{   
			                eliane.hp = eliane.hp - ataque_medio;
							 
			                printf("Resposta certa, ataque medio efetuado");
			                printf("Voce deu: %.1f de dano!\n", ataque_medio);
			                printf("HP Restante de ELIANE.EXE: %.1f\n", eliane.hp);
			
			                        
			                printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                           "\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                           "\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                           "\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                           nome, eliane.forca,  
			                           jogador.forca, eliane.agilidade, 
			                           jogador.agilidade, eliane.hp, 
			                           ataque);
			                system("pause");
			                system("cls");
			                
			                printf("Voce esta quase vencendo....\n");
			                printf("Vez de ELIANE.EXE:\n");
			                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
			                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
			                srand(time(NULL));
			                        	
			                system("pause");
			                system("cls");
			                        	
			                numeroAleatorio = rand() % 100;
			                printf("Numero sorteado: %d\n", numeroAleatorio);
			                        	
			                if(numeroAleatorio < 77)
							{
			                    ataque = ataque - eliane.forca;
			                        		
			                    printf("Que pena, ELIANE.EXE te atacou...\n\n");
			                        		
			                    printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        	"\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        	"\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        	"\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
			                        	nome, eliane.forca,  
			                        	jogador.forca, eliane.agilidade, 
			                        	jogador.agilidade, eliane.hp, 
			                        	ataque);
								system("pause");
								system("cls"); 
								
								printf("Sua vez novamente...\n\n");
								printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                           "\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                           "\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                           "\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                           nome, eliane.forca,  
			                           jogador.forca, eliane.agilidade, 
			                           jogador.agilidade, eliane.hp, 
			                           ataque);	                     	
			                    system("pause");
			                }
			                       	 
			                else if(numeroAleatorio > 77)
							{			
			                    printf("UAU! que sorte... Sua vez:\n\n");
			                        			
			                    printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                        	"\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                        	"\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                        	"\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                        	nome, eliane.forca,  
			                        	jogador.forca, eliane.agilidade, 
			                        	jogador.agilidade, eliane.hp, 
			                        	ataque);
			                        			
			                    system("pause");
			                    system("cls");      	
							}
			            }
											                    		
			            if(resposta != 1)
						{
			                printf("Resposta errada... Seu ataque falhou!\n");
			                printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
			                     	"\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
			                     	"\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
			                     	"\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
			                     	nome, eliane.forca,  
			                     	jogador.forca, eliane.agilidade, 
			                     	jogador.agilidade, eliane.hp, 
			                     	ataque);
			                system("pause");
			                system("cls");
			                   
			                if(eliane.hp > 0)
			                {
				                printf("Vez de ELIANE.EXE:\n");
				                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
				                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
				                srand(time(NULL));
				                        	
				                system("pause");
				                system("cls");
				                        	
				                numeroAleatorio = rand() % 100;
				                printf("Numero sorteado: %d\n", numeroAleatorio);
				                        	
				                if(numeroAleatorio < 77)
								{
				                    ataque = ataque - eliane.forca;
				                        		
				                    printf("Que pena, ELIANE.EXE te atacou...\n\n");
				                        		
				                    printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
				                        	nome, eliane.forca,  
				                        	jogador.forca, eliane.agilidade, 
				                        	jogador.agilidade, eliane.hp, 
				                        	ataque);
									system("pause");
									system("cls"); 
									
									printf("Sua vez novamente...\n\n");
									printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                           "\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                           "\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                           "\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                           nome, eliane.forca,  
				                           jogador.forca, eliane.agilidade, 
				                           jogador.agilidade, eliane.hp, 
				                           ataque);	            
								    system("pause");         	
				                }
				                       	 
				                else if(numeroAleatorio > 77)
								{			
				                    printf("UAU! que sorte... Sua vez:\n\n");
				                        			
				                    printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                        	nome, eliane.forca,  
				                        	jogador.forca, eliane.agilidade, 
				                        	jogador.agilidade, eliane.hp, 
				                        	ataque);
				                        			
				                    system("pause");
				                    system("cls");      	
								}
							}
							else
							{
								break;
							}
			            }
			        }
			                    
					else if(escolha_ataque == 3)
					{
			            // Opção 1 - Errada
	    				printf("Qual a diferenca entre 'while' e 'do-while' em C?\n");
					    printf("\033[1;31m1- 'while' executa o bloco de codigo antes de verificar a condicao, enquanto o 'do-while' verifica a condicao antes de executar o bloco de codigo.\n");
					    printf("\033[1;32m2- 'while' e o 'do-while' sao exatamente iguais em funcionamento.\n");
					    printf("\033[1;33m3- 'do-while' pode ser usado apenas para loops infinitos.\n");
					    
					    scanf("%d", &resposta);
					    fflush(stdin);
					    
					    system("pause");
					    system("cls");
   
			            
			            if(resposta == 1)
						{   
				            eliane.hp = eliane.hp - ataque_fraco;
								 
				            printf("Resposta certa, ataque fraco efetuado");
				            printf("Voce deu: %.1f de dano!\n", ataque_fraco);
				            printf("HP Restante de ELIANE.EXE: %.1f\n", eliane.hp);
				
				                        
				            printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        "\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        "\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        "\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                        nome, eliane.forca,  
				                        jogador.forca, eliane.agilidade, 
				                        jogador.agilidade, eliane.hp, 
				                        ataque);
				            system("pause");
				            system("cls");
				                
				            if(eliane.hp > 0)
			                {
				                printf("Vez de ELIANE.EXE:\n");
				                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
				                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
				                srand(time(NULL));
				                        	
				                system("pause");
				                system("cls");
				                        	
				                numeroAleatorio = rand() % 100;
				                printf("Numero sorteado: %d\n", numeroAleatorio);
				                        	
				                if(numeroAleatorio < 77)
								{
				                    ataque = ataque - eliane.forca;
				                        		
				                    printf("Que pena, ELIANE.EXE te atacou...\n\n");
				                        		
				                    printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
				                        	nome, eliane.forca,  
				                        	jogador.forca, eliane.agilidade, 
				                        	jogador.agilidade, eliane.hp, 
				                        	ataque);
									system("pause");
									system("cls"); 
									
									printf("Sua vez novamente...\n\n");
									printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                           "\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                           "\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                           "\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                           nome, eliane.forca,  
				                           jogador.forca, eliane.agilidade, 
				                           jogador.agilidade, eliane.hp, 
				                           ataque);	    
									system("pause");                 	
				                }
				                       	 
				                else if(numeroAleatorio > 77)
								{			
				                    printf("UAU! que sorte... Sua vez:\n\n");
				                        			
				                    printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                        	nome, eliane.forca,  
				                        	jogador.forca, eliane.agilidade, 
				                        	jogador.agilidade, eliane.hp, 
				                        	ataque);
				                        			
				                    system("pause");
				                    system("cls");      	
								}
							}
							else
							{
								break;
							}
				        }
												                    		
				        if(resposta != 1)
						{
				            printf("Resposta errada... Seu ataque falhou!\n");
				            printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                    "\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                    "\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                    "\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                    nome, eliane.forca,  
				                    jogador.forca, eliane.agilidade, 
				                    jogador.agilidade, eliane.hp, 
				                    ataque);
				            system("pause");
				            system("cls");
				                   
				            if(eliane.hp > 0)
			                {
				                printf("Vez de ELIANE.EXE:\n");
				                printf("Voce esta prestes a receber um ataque, se prepare para desviar...\n");//colocar para aparecer aos poucos/
				                printf("Para voce conseguir desviar, voce precisa sortear um valor acima de 77!\n\n");
				                srand(time(NULL));
				                        	
				                system("pause");
				                system("cls");
				                        	
				                numeroAleatorio = rand() % 100;
				                printf("Numero sorteado: %d\n", numeroAleatorio);
				                        	
				                if(numeroAleatorio < 77)
								{
				                    ataque = ataque - eliane.forca;
				                        		
				                    printf("Que pena, ELIANE.EXE te atacou...\n\n");
				                        		
				                    printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n\n",
				                        	nome, eliane.forca,  
				                        	jogador.forca, eliane.agilidade, 
				                        	jogador.agilidade, eliane.hp, 
				                        	ataque);
									system("pause");
									system("cls"); 
									
									printf("Sua vez novamente...\n\n");
									printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                           "\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                           "\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                           "\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                           nome, eliane.forca,  
				                           jogador.forca, eliane.agilidade, 
				                           jogador.agilidade, eliane.hp, 
				                           ataque);	         
									system("pause");            	
				                }
				                       	 
				                else if(numeroAleatorio > 77)
								{			
				                    printf("UAU! que sorte... Sua vez:\n\n");
				                        			
				                    printf("\033[0;33mNome do inimigo: ELIANE.EXE\t\t\t\033[0;32mNome de seu personagem: %s\n"
				                        	"\033[0;33mForca de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mForca de Seu personagem: %.1f\n"
				                        	"\033[0;33mDestreza de ELIANE.EXE: %.1f\t\t\t\033[0;32mDestreza de seu personagem: %.1f\n"
				                        	"\033[0;33mSaude de ELIANE.EXE: %.1f\t\t\t\t\033[0;32mSaude de seu personagem: %.1f\n",
				                        	nome, eliane.forca,  
				                        	jogador.forca, eliane.agilidade, 
				                        	jogador.agilidade, eliane.hp, 
				                        	ataque);
				                        			
				                    system("pause");
				                    system("cls");      	
								}
							}
							else
							{
								break;
							}
						}
					}
				} while (eliane.hp > 0);
			}
			else if (opc == 2) 
			{
	           printf("Continuando...\n\n");
	           break;
	        }
			else if(opc != 1 && opc!= 2)
			{
	            printf("\nNao quer jogar eh? Entao tome. Receba\n\n");
	            GameOver();
	            debug = 1;
	            break;
	        }
		} while(opc != 1 && opc !=2);
	}
	if (eliane.hp <= 0 && poly.hp <= 0 && victor.hp <= 0 && natasha.hp <=0)
	{
		Tela_De_Vitoria();
	}
	else
	{
		printf("\nSo pular as batalhas ou morrer, nao vai contar como vitoria ne?!\n");
	}
}	
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Antes disso, as fases ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// Restante do código

int main()
{
    Tela_de_inicio();

    system("cls");

    int opc;
    char lista[5][40]={"Jogar", "Tutorial", "Historia", "Desenvolvedores", "exit"};
    while(true)
	{
        opc = menu(10,10,5,lista);
        if (opc==0)
		{
            break;
        }
        switch(opc)
		{

           


            case 1:

            	iniciarJogo();
				
            	system("pause");
            	system("cls");
            break;

            case 2:
                system("cls");
                // Variáveis e Constantes
    			printf("\033[1;33mVariaveis e Constantes:\033[0m\n");
    			printf("- \033[1mVariaveis:\033[0m Sao como caixas onde voce pode guardar valores. Elas podem ser alteradas durante o jogo.\n");
    			printf("- \033[1mConstantes:\033[0m Sao valores que nao mudam durante o jogo, como uma regra fixa.\n\n");

    			// Operadores Aritméticos
   				printf("\033[1;33mOperadores Aritmeticos:\033[0m\n");
    			printf("- Os operadores aritmeticos sao como ferramentas matematicas.\n");
    			printf("  - \033[1mAdicao (+):\033[0m Para somar valores.\n");
    			printf("  - \033[1mSubtracao (-):\033[0m Para subtrair um valor de outro.\n");
    			printf("  - \033[1mMultiplicacao (*):\033[0m Para multiplicar valores.\n");
    			printf("  - \033[1mDivisao (/):\033[0m Para dividir um valor pelo outro.\n");
    			printf("  - \033[1mModulo (%%):\033[0m Para obter o resto da divisao entre dois valores.\n\n");

    			// Operadores Lógicos
			    printf("\033[1;33mOperadores Logicos:\033[0m\n");
			    printf("- Os operadores logicos ajudam a tomar decisoes no jogo.\n");
			    printf("  - \033[1mAND (&&):\033[0m Retorna verdadeiro apenas se ambas as expressoes forem verdadeiras.\n");
			    printf("  - \033[1mOR (||):\033[0m Retorna verdadeiro se pelo menos uma das expressoes for verdadeira.\n");
			    printf("  - \033[1mNOT (!):\033[0m Inverte o valor de verdade de uma expressao.\n\n");
			
			    // Operadores Relacionais
			    printf("\033[1;33mOperadores Relacionais:\033[0m\n");
			    printf("- Os operadores relacionais sao usados para comparar valores.\n");
			    printf("  - \033[1mIgual a (==):\033[0m Verifica se dois valores sao iguais.\n");
			    printf("  - \033[1mDiferente de (!=):\033[0m Verifica se dois valores sao diferentes.\n");
			    printf("  - \033[1mMaior que (>):\033[0m Verifica se um valor e maior que o outro.\n");
			    printf("  - \033[1mMenor que (<):\033[0m Verifica se um valor e menor que o outro.\n");
			    printf("  - \033[1mMaior ou igual a (>=):\033[0m Verifica se um valor e maior ou igual a outro.\n");
			    printf("  - \033[1mMenor ou igual a (<=):\033[0m Verifica se um valor e menor ou igual a outro.\n\n");
			
			    // Laços de Seleção e Repetição
			    printf("\033[1;33mLacos de Selecao e Repeticao:\033[0m\n");
			    printf("- \033[1mif e else:\033[0m Sao usados para fazer escolhas no jogo. Se uma condicao for verdadeira, uma acao acontece, senao, outra acao ocorre.\n");
			    printf("- \033[1mLacos de Repeticao (for, while, do while):\033[0m Sao usados para repetir acoes no jogo.\n");
			    printf("  - \033[1mfor:\033[0m E usado quando voce sabe exatamente quantas vezes deseja repetir uma acao.\n");
			    printf("  - \033[1mwhile:\033[0m E usado quando voce nao sabe quantas vezes deseja repetir uma acao, mas sabe a condicao para parar.\n");
			    printf("  - \033[1mdo while:\033[0m Semelhante ao while, mas a condicao e verificada apos a execucao do bloco de codigo, garantindo que o bloco seja executado pelo menos uma vez.\n\n");
			
			    // Exemplo de Uso do do while
			    printf("\033[1;33mExemplo de Uso do do while:\033[0m\n");
			    printf("#include <stdio.h>\n\n");
			    printf("int main() {\n");
			    printf("    int contador = 0;\n\n");
			    printf("    do {\n");
			    printf("        printf(\"Contador: %%d\\n\", contador);\n");
			    printf("        contador++;\n");
			    printf("    } while (contador < 5);\n\n");
			    printf("    return 0;\n");
			    printf("}\n\n");
			
			    printf("\033[1;33mExemplo de Uso do for:\033[0m\n");
			    printf("#include <stdio.h>\n\n");
			    printf("int main() {\n");
			    printf("    for (int i = 0; i < 5; i++) {\n");
			    printf("        printf(\"Contador: %%d\\n\", i);\n");
			    printf("    }\n\n");
			    printf("    return 0;\n");
			    printf("}\n\n");
			
			    // Exemplo de Uso do while
			    printf("\033[1;33mExemplo de Uso do while:\033[0m\n");
			    printf("#include <stdio.h>\n\n");
			    printf("int main() {\n");
			    printf("    int contador = 0;\n\n");
			    printf("    while (contador < 5) {\n");
			    printf("        printf(\"Contador: %%d\\n\", contador);\n");
			    printf("        contador++;\n");
			    printf("    }\n\n");
			    printf("    return 0;\n");
			    printf("}\n\n");
			
			    printf("\033[1;32mAgora voce esta pronto para comecar a criar seus proprios jogos em C!\033[0m\n");
			    
			system("pause");    
			system("cls");
            break;

            case 3:
                system("cls");
                printf("Voce e um Engenheiro da computacao, e esta em um mundo de cheio hackers e misterios.\n");
                printf("Sua jornada comeca em uma pequena vila chamada Villageburg.\n");
                printf("Voce e um heroi destinado a salvar o mundo das trevas que o ameacam.\n\n");

                printf("Ao explorar Villageburg, voce descobre que a vila esta sofrendo com um terrivel malwere.\n");
                printf("Os habitantes estao desaparecendo misteriosamente durante a noite, e uma aura de medo paira sobre o lugar.\n");
                printf("Determinado a ajudar, voce decide investigar a origem desse malwere e encontrar uma maneira de quebra-lo.\n\n");

                printf("Enquanto investiga, voce encontra pistas que levam a uma antiga masmorra nas proximidades, conhecida como a Caverna dos Espiritos.\n");
                printf("Diz a lenda que a caverna eh habitada por hackers malignos que sao responsaveis pelo malwere que assola Villageburg.\n");
                printf("Determinado a enfrentar esse desafio, voce se prepara para entrar na caverna e enfrentar os perigos que a aguardam.\n\n");

                printf("Dentro da caverna, voce enfrenta hackers sombrios e virus.exe mortais, mas sua coragem e determinacao o mantem firme.\n");
                printf("Finalmente, voce chega a camara central, onde encontra o lider dos hackers, um ser poderoso e sinistro.\n");
                printf("Uma batalha epica se inicia, e voce luta com todas as suas forcas para derrotar o mal que ameaca Villageburg.\n\n");

            	printf("Com um golpe final, voce derrota o lider dos hackers e quebra o malwere que assolava a vila.\n");
            	printf("Os habitantes de Villageburg estao livres do medo e da escuridao, e eles o aclamam como seu salvador e heroi.\n");
            	printf("Sua jornada esta apenas comecando, e muitas aventuras e desafios ainda aguardam voce neste mundo magico e cheio de misterios.\n");

                system("pause");
                system("cls");
            break;

            case 4:
               system("cls");
               printf("Desenvolvedores: \n\n");
               printf("\n\n\n\n\n\n\n\n\n\n\n\n");
               printf("\t\t\t\t\t\t\t\t\t================================\n");
               printf("\t\t\t\t\t\t\t\t\t=     Ramon Silva de souza     =\n");
               printf("\t\t\t\t\t\t\t\t\t=             and              =\n");
               printf("\t\t\t\t\t\t\t\t\t=       Joao Pedro Silva       =\n");
               printf("\t\t\t\t\t\t\t\t\t=             and              =\n");
               printf("\t\t\t\t\t\t\t\t\t=       Joao Pedro Maues       =\n");
               printf("\t\t\t\t\t\t\t\t\t================================\n");

               system("pause");
               system("cls");
            break;
               
            case 5:
                system("cls");
                printf("\nSaindo...");
            return 0;
            default:
                printf("\nSaindo...");
        }
    }
    textColor(WHITE, _BLACK);
    linhaCol(24,1);
    printf("");
    return 0;
}
