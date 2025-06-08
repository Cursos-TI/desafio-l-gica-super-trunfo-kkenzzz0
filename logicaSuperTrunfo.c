#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 3 - Nível Mestre: Comparação com dois atributos escolhidos pelo usuário

// Variáveis globais
int numerodhabitantesC1, numerodhabitantesC2;
float pibC1, pibC2;
float areatotalC1, areatotalC2;
int pontosturisticosC1, pontosturisticosC2;
float densidadePopulC1, densidadePopulC2;
float pibpercapitaC1, pibpercapitaC2;

int main() {
    char sigladestadoC1[3], sigladestadoC2[3];
    char cidadeC1[60], cidadeC2[60];
    char codCartaC1[10], codCartaC2[10];
    int opcao;

    printf("###Escolha uma opção a seguir### \n");
    printf("1 - Iniciar jogo \n");
    printf("2 - Regras \n");
    printf("3 - Sair \n");
    printf("Digite sua escolha: \n");
    scanf("%d", &opcao);

    getchar(); // Limpa buffer do scanf

    switch (opcao) {
    case 1:
        // Cadastro carta 1
        printf("\n--- Cadastro da Carta 1 ---\n");
        printf("Sigla do estado: "); scanf("%s", sigladestadoC1); getchar();
        printf("Cidade: "); fgets(cidadeC1, sizeof(cidadeC1), stdin); cidadeC1[strcspn(cidadeC1, "\n")] = '\0';
        printf("Código da carta: "); scanf("%s", codCartaC1);
        printf("Habitantes: "); scanf("%d", &numerodhabitantesC1);
        printf("PIB: "); scanf("%f", &pibC1);
        printf("Área (km2): "); scanf("%f", &areatotalC1);
        printf("Pontos turísticos: "); scanf("%d", &pontosturisticosC1);

        getchar();

        // Cadastro carta 2
        printf("\n--- Cadastro da Carta 2 ---\n");
        printf("Sigla do estado: "); scanf("%s", sigladestadoC2); getchar();
        printf("Cidade: "); fgets(cidadeC2, sizeof(cidadeC2), stdin); cidadeC2[strcspn(cidadeC2, "\n")] = '\0';
        printf("Código da carta: "); scanf("%s", codCartaC2);
        printf("Habitantes: "); scanf("%d", &numerodhabitantesC2);
        printf("PIB: "); scanf("%f", &pibC2);
        printf("Área (km2): "); scanf("%f", &areatotalC2);
        printf("Pontos turísticos: "); scanf("%d", &pontosturisticosC2);

        // Cálculos
        densidadePopulC1 = numerodhabitantesC1 / areatotalC1;
        densidadePopulC2 = numerodhabitantesC2 / areatotalC2;
        pibpercapitaC1 = pibC1 / numerodhabitantesC1;
        pibpercapitaC2 = pibC2 / numerodhabitantesC2;

        // Menu de atributos
        printf("\nEscolha dois atributos para comparar:\n");
        printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per capita\n");

        int attr1, attr2;
        do {
            printf("Primeiro atributo (1-6): ");
            scanf("%d", &attr1);
            printf("Segundo atributo (diferente do primeiro): ");
            scanf("%d", &attr2);
        } while(attr1 < 1 || attr1 > 6 || attr2 < 1 || attr2 > 6 || attr1 == attr2);

        // Obtenção dos valores diretamente
        float v1_a1 = (attr1 == 1) ? numerodhabitantesC1 :
                      (attr1 == 2) ? areatotalC1 :
                      (attr1 == 3) ? pibC1 :
                      (attr1 == 4) ? pontosturisticosC1 :
                      (attr1 == 5) ? densidadePopulC1 : pibpercapitaC1;

        float v2_a1 = (attr1 == 1) ? numerodhabitantesC2 :
                      (attr1 == 2) ? areatotalC2 :
                      (attr1 == 3) ? pibC2 :
                      (attr1 == 4) ? pontosturisticosC2 :
                      (attr1 == 5) ? densidadePopulC2 : pibpercapitaC2;

        float v1_a2 = (attr2 == 1) ? numerodhabitantesC1 :
                      (attr2 == 2) ? areatotalC1 :
                      (attr2 == 3) ? pibC1 :
                      (attr2 == 4) ? pontosturisticosC1 :
                      (attr2 == 5) ? densidadePopulC1 : pibpercapitaC1;

        float v2_a2 = (attr2 == 1) ? numerodhabitantesC2 :
                      (attr2 == 2) ? areatotalC2 :
                      (attr2 == 3) ? pibC2 :
                      (attr2 == 4) ? pontosturisticosC2 :
                      (attr2 == 5) ? densidadePopulC2 : pibpercapitaC2;

        // Comparação
        float soma1 = ((attr1 == 5 ? 1/v1_a1 : v1_a1) + (attr2 == 5 ? 1/v1_a2 : v1_a2));
        float soma2 = ((attr1 == 5 ? 1/v2_a1 : v2_a1) + (attr2 == 5 ? 1/v2_a2 : v2_a2));

        printf("\nResultado:\nCarta 1 (%s): %.2f\nCarta 2 (%s): %.2f\n",
               cidadeC1, soma1, cidadeC2, soma2);

        if (soma1 > soma2)
            printf("Vencedor: %s\n", cidadeC1);
        else if (soma2 > soma1)
            printf("Vencedor: %s\n", cidadeC2);
        else
            printf("Empate!\n");

        break;

    case 2:
        printf("Regras:\nEscolha dois atributos distintos das cartas cadastradas. Quem tiver a maior soma vence, exceto se um dos atributos for densidade (onde menor valor vence).\n");
        break;

    case 3:
        printf("Saindo...\n");
        break;

    default:
        printf("erro\n");
        break;
    }

    return 0;
}
