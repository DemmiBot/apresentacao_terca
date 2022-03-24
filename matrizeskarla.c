#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct passageiro
{
    char nome[60],rg[11],dest2[20],hs1[5],hc1[5];
    int id,lugar;
    float pass1;
};

struct onibus
{
    int no;
};

struct bus
{
    char dest[20],hs[5],hc[5];
    float pass;
};

int main()
{
    int  l, c, menu, qtd, qa,i,qtd1,p,pr;
    float t,soma;
    char dest1[20],rg1[10];
    struct onibus a[4][4];
    struct passageiro b[2];
    struct bus bus[2];
    pr=0;
    qtd = 0;
    soma = 0;
    qa = 0;
    menu = 0;
    t = 0;
    for (l=0; l<4; l++)
    {
        for (c=0; c<4; c++)
        {
            qtd++;
            a[l][c].no = qtd;
        }
    }
    do
    {
        printf("*****MATRIZ ONIBUS*****\n");
        printf("1-CADASTRAR ONIBUS MANAUS\n");
        printf("2-EXIBIR LUGARES DISPONIVEIS\n");
        printf("3-REALIZAR VENDA DE PASSAGEM\n");
        printf("4-EMITIR PASSAGEM\n");
        printf("5-GERAR RELATORIO DE VENDAS: ONIBUS MANAUS\n");
        printf("0-SAIR\n");
        printf("*********************");
        printf("\n\nOp\207\706o:");
        scanf("%i",&menu);
        system("cls");
        switch (menu)
        {
        case 1:
            if(pr < 2)
            {
                for (i=0; i<2; i++)
                {
                    printf("Destino:");
                    scanf("%s",&bus[i].dest);
                    strupr(bus[i].dest);
                    printf("hora de saida:");
                    scanf("%s",&bus[i].hs);
                    fflush(stdin);
                    printf("hora de chegada:");
                    scanf("%s",&bus[i].hc);
                    fflush(stdin);
                    printf("valor da passagem:");
                    scanf("%f",&bus[i].pass);
                    pr++;
                }
            }
            else
            {
                printf("Numero de onibus preenchido\n");
            }
            break;
        case 2:
            printf("Destino do Onibus:");
            scanf("%s",&dest1);
            strupr(dest1);
            if(strcmp(bus[0].dest,dest1)==0)
            {
                for (l=0; l<4; l++)
                {
                    for (c=0; c<4; c++)
                    {
                        if (a[l][c].no==0)
                        {
                            printf("[ x] ");
                        }
                        else
                        {
                            printf("[ %d] ", a[l][c]);
                        }
                        if(qtd%2==0 && qtd<15)
                        {
                            printf("\t");
                        }
                    }
                    printf("\n");
                }
            }
            else if(strcmp(bus[1].dest,dest1)==0)
            {
                qtd1 = 0;
                for (l=0; l<4; l++)
                {
                    for (c=0; c<4; c++)
                    {
                        qtd1++;
                        a[l][c].no = qtd1;
                        if (a[l][c].no==100)
                        {

                            printf("[ x] ");
                        }
                        else
                        {
                            printf("[ %d] ", a[l][c]);
                        }
                    }
                    printf("\n");
                }
            }
            else
            {
                printf("lugar nao cadastrado");
            }
            break;

        case 3:
            printf("Quantas Passagens:");
            scanf("%i",&p);
            fflush(stdin);
            for(i=0; i<p; i++)
            {
                printf("Destino desejado:");
                scanf("%s",&dest1);
                strupr(dest1);
                fflush(stdin);
                if(strcmp(bus[0].dest,dest1)==0)
                {
                    strcpy(b[i].dest2,bus[0].dest);
                    strcpy(b[i].hc1, bus[0].hc);
                    strcpy(b[i].hs1,bus[0].hs);
                    bus[0].pass = b[1].pass1;
                    printf("Nome do passageiro:");
                    scanf("%s",&b[i].nome);
                    printf("Numero Rg:");
                    scanf("%s",&b[i].rg);
                    printf("idade:");
                    scanf("%i",&b[i].id);
volta:
                    printf("\ndigite o lugar: ");
                    scanf("%d", &b[i].lugar);
                    if (b[i].lugar>=1 && b[i].lugar<=16)
                    {
                        soma++;
                        qa++;
                        for (l=0; l<4; l++)
                        {
                            for(c=0; c<4; c++)
                            {
                                if (a[l][c].no==b[i].lugar)
                                {
                                    a[l][c].no=0;
                                }
                            }
                        }
                    }
                }
                else if(strcmp(bus[1].dest,dest1)==0)
                {
                    strcpy(b[i].dest2,bus[1].dest);
                    strcpy(b[i].hc1,bus[1].hc);
                    strcpy(b[i].hs1,bus[1].hs);
                    bus[1].pass = b[i].pass1;
                    printf("Nome do passageiro:");
                    scanf("%s",&b[i].nome);
                    printf("Numero Rg:");
                    scanf("%s",&b[i].rg);
                    printf("idade:");
                    scanf("%i",&b[i].id);
volta1:
                    printf("\ndigite o lugar: ");
                    scanf("%d", &b[i].lugar);
                    if (b[i].lugar>=1 && b[i].lugar<=16)
                    {
                        soma++;
                        qa++;
                        for (l=0; l<4; l++)
                        {
                            for(c=0; c<4; c++)
                            {
                                if (a[l][c].no==b[i].lugar)
                                {
                                    a[l][c].no=100;
                                }
                            }
                        }
                    }
                    else
                    {
                        printf("\nlugares de 1 a 16\n");
                        goto volta1;
                    }
                }
                else
                {
                    printf("lugar nao encontrado");
                }
            }
            break;
        case 4:
            printf("RG para identificacao\n");
            scanf("%s",&rg1);
            for(i=0; i<p; i++)
            {
                if(strcmp(b[i].rg,rg1)==0)
                {
                    fflush(stdin);
                    printf("Nome:%s\t",b[i].nome);
                    printf("RG:%s\t",b[i].rg);
                    printf("Idade:%i\n",b[i].id);
                    fflush(stdin);
                    printf("hora de embarque:%s\t",b[i].hs1);
                    printf("Hora da chegada:%s\n",b[i].hc1);
                    printf("Destino:%s\t",b[i].dest2);
                    printf("Poltrona:%i\n",b[i].lugar);
                    system("pause");
                }
            }
            system("cls");
            break;
        case 5:
            for(i=0; i<p; i++)
            {
                fflush(stdin);
                for (l=0; l<12; l++)
                {
                    for (c=0; c<4; c++)
                    {
                        if (a[l][c].no==0)
                        {
                            t = soma * b[i].pass1;
                        }
                    }
                }
            }
            printf("\npassagens vendidas %d", qa);
            printf("\ntotal %fR$\n", t);
            break;

        case 0:
            exit(0);
        default :
            printf("\ndigite uma opcao valida\n");
            break;
        }
    }
    while(menu!=0);
    system("pause");
}
