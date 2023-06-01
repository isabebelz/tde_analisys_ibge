#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_principal(char regioes[5][100], int conc_masc[5], int conc_fem[5], char genero[2][15], int qtd_conc_t[2], int qtd_conc_n_t[2], int qtd_n_conc[2]);
void leitura_dados_regioes(char regioes[5][100], int conc_masc[5], int conc_fem[5]);
void leitura_dados_genero(char genero[2][15], int qtd_conc_t[2], int qtd_conc_n_t[2], int qtd_n_conc[2]);
void busca_por_regiao(char regioes[5][100], int conc_masc[5], int conc_fem[5]);
void busca_por_genero(char genero[2][15], int qtd_conc_t[2], int qtd_conc_n_t[2], int qtd_n_conc[2]);
void taxa_masc(char regioes[5][100], int conc_masc[5], char regiao[15]);
void taxa_fem(char regioes[5][100], int conc_fem[5], char regiao[15]);
void n_conc(char genero[2][15],int qtd_n_conc[2]);
void conc_n_t(char genero[2][15],int qtd_conc_n_t[2]);
void conc_t(char genero[2][15], int qtd_conc_t[2]);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // values from dataset:
    char regioes[5][100];
    int conc_masc[5];
    int conc_fem[5];
    char genero[2][15];
    int qtd_conc_t[2];
    int qtd_conc_n_t[2];
    int qtd_n_conc[2];

    printf("Todos os dados aqui apresentados são referentes ao ano de 2014 e foram fornecidos pelo IBGE.\n\n");
    printf("OBSERVAÇÃO: Os dados referentes ao item 1 e ao item 2 não possuem ligação entre si.\n\n");

    printf("Pressione 'Enter' para começar...\n");

    /*Quando o programa chega na chamada getchar(), ele pausa a execução e aguarda até que o usuário pressione a tecla
     "Enter". Isso acontece porque a função getchar() lê um caractere do fluxo de entrada padrão (nesse caso, o teclado)
    e retorna quando um caractere é digitado. Ao pressionar "Enter", é gerado um caractere de nova linha ('\n'), que é o que a função getchar() lê.
    Assim que o caractere é lido, o programa continua sua execução normalmente.*/

    getchar();

    leitura_dados_regioes(regioes, conc_masc, conc_fem);

    leitura_dados_genero(genero, qtd_conc_t, qtd_conc_n_t, qtd_n_conc);

    menu_principal(regioes, conc_masc, conc_fem, genero, qtd_conc_t, qtd_conc_n_t, qtd_n_conc);

    return 0;
}
void leitura_dados_regioes(char regioes[5][100], int conc_masc[5], int conc_fem[5])
{

    FILE *arquivo_regioes;

    arquivo_regioes = fopen("dados_regiao.csv", "r");

    if(arquivo_regioes == NULL)
    {
        printf("ERRO! O arquivo não pode ser lido. Tente novamente.");
    }

    char texto[100];
    char *token;

    fgets(texto, 100, arquivo_regioes);

    int i = 0;
    while(fgets(texto, 100, arquivo_regioes) != NULL)
    {
        token = strtok(texto, ",");
        strcpy(regioes[i], token);
        token = strtok(NULL, ",");
        conc_masc[i] = atoi(token);
        token = strtok(NULL, ",");
        conc_fem[i] = atoi(token);
        i++;

    }

}
void leitura_dados_genero(char genero[2][15], int qtd_conc_t[2], int qtd_conc_n_t[2], int qtd_n_conc[2])
{

    FILE *arquivo_genero;

    arquivo_genero = fopen("dados_genero.csv", "r");

    if(arquivo_genero == NULL)
    {
        printf("ERRO! O arquivo não pode ser lido. Tente novamente.");
    }

    char texto_g[200];
    char *token_g;

    fgets(texto_g, 200, arquivo_genero);

    int i = 0;
    while(fgets(texto_g, 200, arquivo_genero) != NULL)
    {

        token_g = strtok(texto_g, ",");
        strcpy(genero[i], token_g);
        token_g = strtok(NULL, ",");
        qtd_conc_t[i] = atoi(token_g);
        token_g = strtok(NULL, ",");
        qtd_conc_n_t[i] = atoi(token_g);
        token_g = strtok(NULL, ",");
        qtd_n_conc[i] = atoi(token_g);
        i++;

    }

}
void menu_principal(char regioes[5][100], int conc_masc[5], int conc_fem[5], char genero[2][15], int qtd_conc_t[2], int qtd_conc_n_t[2], int qtd_n_conc[2])
{

    leitura_dados_regioes(regioes, conc_masc, conc_fem);

    leitura_dados_genero(genero, qtd_conc_t, qtd_conc_n_t, qtd_n_conc);

    system("cls");

    int escolha = 0;

     /*O valor "1" passado como parâmetro no while é uma expressão booleana que indica uma condição de repetição infinita. No contexto apresentado,
        o while (1) cria um loop que continuará sendo executado indefinidamente, a menos que uma instrução de saída seja encontrada dentro do loop*/
    while (1)
    {

        printf("---------------------------------MENU PRINCIPAL-----------------------------------\n");
        printf("         **ANÁLISE DE DADOS SOBRE FORMAÇÃO SUPERIOR TECNOLÓGICA**\n");
        printf("----------------------------------------------------------------------------------\n\n");

        printf("1 - Busca por região: Quantidade de estudantes que concluíram seus estudos por região, levando em consideração o gênero.\n");
        printf("2 - Busca por gênero: Identificação dos concluintes e não concluintes, além da divisão entre os que já trabalharam na área e os que não possuem experiência profissional na área.\n");
        printf("3 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            busca_por_regiao(regioes, conc_masc, conc_fem);
            break;
        case 2:
            busca_por_genero(genero, qtd_conc_t, qtd_conc_n_t, qtd_n_conc);
            break;
        case 3:
            exit(0);
        default:
            system("cls");
            printf("Valor inválido. Escolha valores entre 1 e 3 \n");
            break;
        }
    }

}
void busca_por_regiao(char regioes[5][100], int conc_masc[5], int conc_fem[5])
{

    char regiao[20];
    int encontrado = 0;

    do
    {
        printf("Digite o nome da região na qual deseja visualizar a número de concluintes: ");
        scanf(" %[^\n]", regiao);

        int i = 0;
        for(i = 0; i < 5; i++)
        {
            if(strncasecmp(regioes[i], regiao, strlen(regiao)) == 0)
            {
                encontrado = 1;
                break;
            }
        }

        system("cls");

        /*o operador ! é usado para negar uma expressão booleana, !encontrado significa "não encontrado" ou "não verdadeiro".
        Se o valor da variável encontrado for zero (falso), !encontrado será avaliado como verdadeiro (diferente de zero), e o loop continuará a ser executado.
        No entanto, se encontrado for diferente de zero (verdadeiro), !encontrado será avaliado como falso (zero), e o loop será interrompido. */
        if(!encontrado)
        {
            printf("Nao foram encontrados dados para a regiao especificada.\nAs regiões conhecidas são:\nNorte\nNordeste\nCentro-Oeste\nSudeste\nSul\n");
        }

    }
    while(!encontrado);

    char genero[2][15];
    int qtd_conc_t[2];
    int qtd_conc_n_t[2];
    int qtd_n_conc[2];

    int escolha;
    while (1)
    {

        printf("------------------------------------------------------------------------------------\n");
        printf("       **ANÁLISE DE DADOS SOBRE FORMAÇÃO SUPERIOR TECNOLÓGICA POR REGIÃO**\n");
        printf("----------------------------------------------------------------------------------\n\n");

        printf("Digite o número desejado\n");
        printf("1 - Número de concluintes do gênero masculino da região %s\n", regiao);
        printf("2 - Número de concluintes do gênero feminino da região %s\n", regiao);
        printf("3 - Escolher uma nova região\n");
        printf("4 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            taxa_masc(regioes, conc_masc, regiao);
            break;
        case 2:
            taxa_fem(regioes, conc_fem, regiao);
            break;
        case 3:
            busca_por_regiao(regioes, conc_masc, conc_fem);
            break;
        case 4:
            menu_principal(regioes, conc_masc, conc_fem, genero, qtd_conc_t, qtd_conc_n_t, qtd_n_conc);
            break;
        default:
            system("cls");
            printf("Valor inválido. Escolha valores entre 1 e 4 \n");
            break;
        }
    }

}
void taxa_masc(char regioes[5][100], int conc_masc[5], char regiao[15])
{
    system("cls");
    int count = 0;
    char escolha_salvar[2];

    int valores_usados[5], aux = 0;

    int i = 0;
    for(i=0; i<5; i++)
    {
        if (strcasecmp(regioes[i], regiao) == 0)
        {
            printf("Número de concluintes do sexo masculino em curso superior de tecnologia no ano de 2014 da região %s:\n%d HOMENS\n", regioes[i], conc_masc[i]);
            aux = i;
            count++;
        }
        if(count == 1)
        {
            break;
        }
    }

    printf("\nDeseja salvar os dados visualizados? [S/N] ");
    scanf("%1s", escolha_salvar);

    while (strcasecmp(escolha_salvar, "S") != 0 && strcasecmp(escolha_salvar, "N") != 0)
    {
        printf("\n O valor digitado é inválido. Digite apenas 'S' ou 'N'.\n");
        printf("\n Deseja salvar os dados visualizados? [S/N]");
        scanf("%s[^\n]", escolha_salvar);
    }

    if(strcasecmp(escolha_salvar, "S") == 0)
    {
        FILE *arquivo_regioes;

        if(strcasecmp(regiao, "Norte") == 0)
        {

            arquivo_regioes = fopen("norte_m.csv", "w");
            fprintf(arquivo_regioes, "Dado referente ao número de concluintes do sexo masculino em curso superior de tecnologia no ano de 2014 na região norte do Brasil:\n");
            fprintf(arquivo_regioes, "REGIÃO %s\n%d HOMENS\n", regioes[aux], conc_masc[aux]);

            system("cls");
            fclose(arquivo_regioes);

        }
        else
        {
            if(strcasecmp(regiao, "Nordeste") == 0)
            {

                arquivo_regioes = fopen("nordeste_m.csv", "w");
                fprintf(arquivo_regioes, "Dado referente ao número de concluintes do sexo masculino em curso superior de tecnologia no ano de 2014 na região nordeste do Brasil:\n");
                fprintf(arquivo_regioes, "REGIÃO %s\n%d HOMENS\n", regioes[aux], conc_masc[aux]);

                system("cls");

                fclose(arquivo_regioes);
            }
            else
            {
                if(strcasecmp(regiao, "Centro-Oeste") == 0)
                {

                    arquivo_regioes = fopen("centro_oeste_m.csv", "w");
                    fprintf(arquivo_regioes, "Dado referente ao número de concluintes do sexo masculino em curso superior de tecnologia no ano de 2014 na região centro-oeste do Brasil:\n");
                    fprintf(arquivo_regioes, "REGIÃO %s\n%d HOMENS\n", regioes[aux], conc_masc[aux]);

                    printf("\nDados salvos com sucesso!\n\n");
                    system("cls");

                    fclose(arquivo_regioes);

                }
                else
                {

                    if(strcasecmp(regiao, "Sudeste") == 0)
                    {

                        arquivo_regioes = fopen("sudeste_m.csv", "w");
                        fprintf(arquivo_regioes, "Dado referente ao número de concluintes do sexo masculino em curso superior de tecnologia no ano de 2014 na região sudeste do Brasil:\n");
                        fprintf(arquivo_regioes, "REGIÃO %s\n%d HOMENS\n", regioes[aux], conc_masc[aux]);

                        system("cls");

                        fclose(arquivo_regioes);

                    }
                    else
                    {

                        if(strcasecmp(regiao, "Sul") == 0)
                        {

                            arquivo_regioes = fopen("sul_m.csv", "w");
                            fprintf(arquivo_regioes, "Dado referente ao número de concluintes do sexo masculino em curso superior de tecnologia no ano de 2014 na região sul do Brasil:\n");
                            fprintf(arquivo_regioes, "REGIÃO %s\n%d HOMENS\n", regioes[aux], conc_masc[aux]);

                            system("cls");

                            fclose(arquivo_regioes);
                        }
                    }
                }

            }
        }
        printf("\nDados salvos com sucesso!\n\n");
        printf("\nRetornando ao menu.. \n\n\n");
    }
    else
    {
        if(strcasecmp(escolha_salvar, "N") == 0)
        {
            system("cls");
            printf("\nRetornando ao menu.. \n\n\n");
        }
    }
}
void taxa_fem(char regioes[5][100], int conc_fem[5], char regiao[15])
{
    system("cls");
    int count = 0;
    char escolha_salvar[2];

    int valores_usados[5], aux = 0;

    int i;
    for(i=0; i<5; i++)
    {
        if (strcasecmp(regioes[i], regiao) == 0)
        {
            printf("Número de concluintes do sexo feminino em curso superior de tecnologia no ano de 2014 da região %s:\n%d MULHERES\n", regioes[i], conc_fem[i]);
            valores_usados[count] = i;
            aux = valores_usados[count];
            count++;
        }
        if(count == 1)
        {
            break;
        }
    }

    printf("\nDeseja salvar os dados visualizados? [S/N] ");
    scanf("%1s", escolha_salvar);

    while (strcasecmp(escolha_salvar, "S") != 0 && strcasecmp(escolha_salvar, "N") != 0)
    {
        printf("\n O valor digitado é inválido. Digite apenas 'S' ou 'N'.\n");
        printf("\n Deseja salvar os dados visualizados? [S/N]");
        scanf("%s[^\n]", escolha_salvar);
    }

    if(strcasecmp(escolha_salvar, "S") == 0)
    {
        FILE *arquivo_regioes;

        if(strcasecmp(regiao, "Norte") == 0)
        {

            arquivo_regioes = fopen("norte_f.csv", "w");
            fprintf(arquivo_regioes, "Dado referente ao número de concluintes do sexo feminino em curso superior de tecnologia no ano de 2014 na região norte do Brasil:\n");
            fprintf(arquivo_regioes, "REGIÃO %s\n%d MULHERES\n", regioes[aux], conc_fem[aux]);

            printf("\nDados salvos com sucesso!\n\n");
            system("cls");

            fclose(arquivo_regioes);

        }
        else
        {
            if(strcasecmp(regiao, "Nordeste") == 0)
            {

                arquivo_regioes = fopen("nordeste_f.csv", "w");
                fprintf(arquivo_regioes, "Dado referente ao número de concluintes do sexo feminino em curso superior de tecnologia no ano de 2014 na região nordeste do Brasil:\n");
                fprintf(arquivo_regioes, "REGIÃO %s\n%d MULHERES\n", regioes[aux], conc_fem[aux]);

                printf("\nDados salvos com sucesso!\n\n");
                system("cls");

                fclose(arquivo_regioes);
            }
            else
            {
                if(strcasecmp(regiao, "Centro-Oeste") == 0)
                {

                    arquivo_regioes = fopen("centro_oeste_f.csv", "w");
                    fprintf(arquivo_regioes, "Dado referente ao número de concluintes do sexo feminino em curso superior de tecnologia no ano de 2014 na região centro-oeste do Brasil:\n");
                    fprintf(arquivo_regioes, "REGIÃO %s\n%d MULHERES\n", regioes[aux], conc_fem[aux]);

                    printf("\nDados salvos com sucesso!\n\n");

                    fclose(arquivo_regioes);

                }
                else
                {

                    if(strcasecmp(regiao, "Sudeste") == 0)
                    {

                        arquivo_regioes = fopen("sudeste_f.csv", "w");
                        fprintf(arquivo_regioes, "Dado referente ao número de concluintes do sexo feminino em curso superior de tecnologia no ano de 2014 na região sudeste do Brasil:\n");
                        fprintf(arquivo_regioes, "REGIÃO %s\n%d MULHERES\n", regioes[aux], conc_fem[aux]);

                        printf("\nDados salvos com sucesso!\n\n");
                        system("cls");

                        fclose(arquivo_regioes);

                    }
                    else
                    {

                        if(strcasecmp(regiao, "Sul") == 0)
                        {

                            arquivo_regioes = fopen("sul_f.csv", "w");
                            fprintf(arquivo_regioes, "Dado referente ao número de concluintes do sexo feminino em curso superior de tecnologia no ano de 2014 na região sul do Brasil:\n");
                            fprintf(arquivo_regioes, "REGIÃO %s\n%d MULHERES\n", regioes[aux], conc_fem[aux]);

                            printf("\nDados salvos com sucesso!\n\n");
                            system("cls");

                            fclose(arquivo_regioes);
                        }
                    }
                }
            }
        }
        printf("\nDados salvos com sucesso!\n\n");
        printf("\nRetornando ao menu.. \n\n\n");
    }
    else
    {
        if(strcasecmp(escolha_salvar, "N") == 0)
        {
            system("cls");
            printf("\nRetornando ao menu.. \n\n\n");
        }
    }

}
void busca_por_genero(char genero[2][15], int qtd_conc_t[2], int qtd_conc_n_t[2], int qtd_n_conc[2])
{

    char regioes[5][100];
    int conc_masc[5];
    int conc_fem[5];

    system("cls");
    int escolha = 0;
    while (1)   // Infinity loop
    {

        printf("-------------------------------------------------------------------------------------------\n");
        printf("    **ANÁLISE DE DADOS SOBRE EMPREGABILIDADE E FORMAÇÃO SUPERIOR TECNOLÓGICA POR GÊNERO**\n");
        printf("-------------------------------------------------------------------------------------------\n\n");

        printf("Digite o número desejado\n");
        printf("1 - Número de concluintes que trabalhavam ou já trabalharam na área\n");
        printf("2 - Número de concluintes que nunca trabalharam na área\n");
        printf("3 - Número de não concluintes\n");
        printf("4 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            conc_t(genero, qtd_conc_t);
            break;
        case 2:
            conc_n_t(genero, qtd_conc_n_t);
            break;
        case 3:
            n_conc(genero, qtd_n_conc);
            break;
        case 4:
            menu_principal(regioes, conc_masc, conc_fem, genero, qtd_conc_t, qtd_conc_n_t, qtd_n_conc);
            break;
        default:
            system("cls");
            printf("Valor inválido. Escolha valores entre 1 e 4.\n");
            break;
        }
    }

}
void conc_t(char genero[2][15], int qtd_conc_t[2])
{
    char genero_escolhido[15];
    int encontrado = 0;

    do
    {
        printf("Digite o gênero desejado para saber o número de concluintes que trabalhavam ou já trabalharam na área: \n");
        scanf(" %[^\n]", &genero_escolhido);

        int i = 0;
        for(i = 0; i < 2; i++)
        {
            if(strcasecmp(genero[i], genero_escolhido) == 0)
            {
                encontrado = 1;
                break;
            }
        }

        system("cls");


        if(!encontrado)
        {
            printf("Desculpe, não entendi. Tente novamente.\n");
        }

    }
    while(!encontrado);

    char escolha_salvar[2];
    int count = 0, aux = 0;

    int i = 0;
    for(i=0; i<2; i++)
    {
        if (strcasecmp(genero[i], genero_escolhido) == 0)
        {
            printf("Número de graduados em curso superior de tecnologia do sexo %s que trabalhavam ou já trabalharam na área: %d\n", genero[i], qtd_conc_t[i]);
            aux = i;
            count++;
        }
        if(count == 1)
        {
            break;
        }
    }

    printf("\nDeseja salvar os dados visualizados? [S/N] ");
    scanf("%1s", escolha_salvar);

    while (strcasecmp(escolha_salvar, "S") != 0 && strcasecmp(escolha_salvar, "N") != 0)
    {
        printf("\n O valor digitado é inválido. Digite apenas 'S' ou 'N'.\n");
        printf("\n Deseja salvar os dados visualizados? [S/N]");
        scanf("%s[^\n]", escolha_salvar);
    }

    if(strcasecmp(escolha_salvar, "S") == 0)
    {
        if(strcasecmp(genero_escolhido, "Feminino") == 0)
        {

        FILE *arquivo_genero;

        arquivo_genero = fopen("conc_trab_f.csv", "w");
        fprintf(arquivo_genero, "Dado referente ao ano de 2014 do número de concluintes do sexo feminino que trabalhavam ou já trabalharam na área: %d\n", qtd_conc_t[aux]);

        fclose(arquivo_genero);

        system("cls");

        printf("\nDados salvos com sucesso!\n\n");
        printf("\nRetornando ao menu.. \n\n\n");

        }
        else if(strcasecmp(genero_escolhido, "Masculino") == 0)
        {
            FILE *arquivo_genero;

            arquivo_genero = fopen("conc_trab_m.csv", "w");
            fprintf(arquivo_genero, "Dado referente ao ano de 2014 do número de concluintes do sexo masculino que trabalhavam ou já trabalharam na área: %d\n", qtd_conc_t[aux]);


            fclose(arquivo_genero);

            system("cls");

            printf("\nDados salvos com sucesso!\n\n");
            printf("\nRetornando ao menu.. \n\n\n");
        }
    }
    else
    {
        system("cls");
        printf("\nRetornando ao menu.. \n\n\n");
    }


}
void conc_n_t(char genero[2][15], int qtd_conc_n_t[2])
{
    char genero_escolhido[15];
    int encontrado = 0;

    do
    {
        printf("Digite o gênero desejado para saber o número de pessoas que não concluiram o curso superior de tecnologia: \n");
        scanf(" %[^\n]", &genero_escolhido);

        int i = 0;
        for(i = 0; i < 2; i++)
        {
            if(strcasecmp(genero[i], genero_escolhido) == 0)
            {
                encontrado = 1;
                break;
            }
        }

        system("cls");


        if(!encontrado)
        {
            printf("Desculpa, não entendi. Tente novamente.\n");
        }

    }
    while(!encontrado);

    char escolha_salvar[2];
    int count = 0, aux = 0;

    int i = 0;
    for(i=0; i<2; i++)
    {
        if (strcasecmp(genero[i], genero_escolhido) == 0)
        {
            printf("Número de graduados em curso superior de tecnologia do sexo %s que nunca trabalharam na área: %d\n", genero[i], qtd_conc_n_t[i]);
            aux = i;
            count++;
        }
        if(count == 1)
        {
            break;
        }
    }

    printf("\nDeseja salvar os dados visualizados? [S/N] ");
    scanf("%1s", escolha_salvar);

    while (strcasecmp(escolha_salvar, "S") != 0 && strcasecmp(escolha_salvar, "N") != 0)
    {
        printf("\n O valor digitado é inválido. Digite apenas 'S' ou 'N'.\n");
        printf("\n Deseja salvar os dados visualizados? [S/N]");
        scanf("%s[^\n]", escolha_salvar);
    }

    if(strcasecmp(escolha_salvar, "S") == 0)
    {
        if(strcasecmp(genero_escolhido, "Feminino") == 0)
        {

        FILE *arquivo_genero;

        arquivo_genero = fopen("conc_n_trab_f.csv", "w");
        fprintf(arquivo_genero, "Número de concluintes do sexo feminino que nunca trabalharam na área: %d\n", qtd_conc_n_t[aux]);

        fclose(arquivo_genero);

        system("cls");

        printf("\nDados salvos com sucesso!\n\n");
        printf("\nRetornando ao menu.. \n\n\n");

        }
        else if(strcasecmp(genero_escolhido, "Masculino") == 0)
        {
            FILE *arquivo_genero;

            arquivo_genero = fopen("conc_n_trab_m.csv", "w");
            fprintf(arquivo_genero, "Dado referente ao ano de 2014 do número de concluintes do sexo masculino que nunca trabalharam na área: %d\n", qtd_conc_n_t[aux]);


            fclose(arquivo_genero);

            system("cls");

            printf("\nDados salvos com sucesso!\n\n");
            printf("\nRetornando ao menu.. \n\n\n");
        }
    }
    else
    {
        system("cls");
        printf("\nRetornando ao menu.. \n\n\n");
    }

}
void n_conc(char genero[2][15], int qtd_n_conc[2])
{
    char genero_escolhido[15];
    int encontrado = 0;

    do
    {
        printf("Digite o gênero desejado para saber o número de pessoas que não concluiram o curso superior de tecnologia: \n");
        scanf(" %[^\n]", &genero_escolhido);

        int i = 0;
        for(i = 0; i < 2; i++)
        {
            if(strcasecmp(genero[i], genero_escolhido) == 0)
            {
                encontrado = 1;
                break;
            }
        }

        system("cls");


        if(!encontrado)
        {
            printf("Desculpa, não entendi. Tente novamente.\n");
        }

    }
    while(!encontrado);

    char escolha_salvar[2];
    int count = 0, aux = 0;

    int i = 0;
    for(i=0; i<2; i++)
    {
        if (strcasecmp(genero[i], genero_escolhido) == 0)
        {
            printf("Número de pessoas do sexo %s que não concluiram o curso: %d\n", genero[i], qtd_n_conc[i]);
            aux = i;
            count++;
        }
        if(count == 1)
        {
            break;
        }
    }

    printf("\nDeseja salvar os dados visualizados? [S/N] ");
    scanf("%1s", escolha_salvar);

    while (strcasecmp(escolha_salvar, "S") != 0 && strcasecmp(escolha_salvar, "N") != 0)
    {
        printf("\n O valor digitado é inválido. Digite apenas 'S' ou 'N'.\n");
        printf("\n Deseja salvar os dados visualizados? [S/N]");
        scanf("%s[^\n]", escolha_salvar);
    }

     if(strcasecmp(escolha_salvar, "S") == 0)
    {
        if(strcasecmp(genero_escolhido, "Feminino") == 0)
        {

        FILE *arquivo_genero;

        arquivo_genero = fopen("n_conc_f.csv", "w");
        fprintf(arquivo_genero, "Dado referente ao ano de 2014 do número de pessoas do sexo feminino que não concluiram curso superior de tecnologia: %d\n", qtd_n_conc[aux]);

        fclose(arquivo_genero);

        system("cls");

        printf("\nDados salvos com sucesso!\n\n");
        printf("\nRetornando ao menu.. \n\n\n");

        }
        else if(strcasecmp(genero_escolhido, "Masculino") == 0)
        {
            FILE *arquivo_genero;

            arquivo_genero = fopen("n_conc_m.csv", "w");
            fprintf(arquivo_genero, "Dado referente ao ano de 2014 do número de pessoas do sexo masculino que não concluiram curso superior de tecnologia: %d\n", qtd_n_conc[aux]);

            fclose(arquivo_genero);

            system("cls");

            printf("\nDados salvos com sucesso!\n\n");
            printf("\nRetornando ao menu.. \n\n\n");
        }
    }
    else
    {
        system("cls");
        printf("\nRetornando ao menu.. \n\n\n");
    }
}
