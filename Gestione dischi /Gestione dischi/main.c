#include "mio_header.h"
int main ()
{
    int dischi_rimanenti;
    int i;
    char scelta;
    int codice;
    int procedi;
    int numero;
    char elimina;
    float min;
    char indice_min;

    printf("* Benvenuto nell'archivio dischi *\n");
    
            
    categoria array_categoria[3]={{0,"Rock"},
                                  {1,"Pop"},
                                  {2,"Tech House"}};
                          
    disco array_dischi[5];
    

    procedi=1;
    while(procedi==1)
    {
        printf("Scegli che operazioni vuoi eseguire: ");
        printf("\n1. Inserisci un nuovo disco");
        printf("\n2. Elimina prodotto");
        printf("\n3. Visualizza titolo del disco con prezzo minore\n");
        scanf ("\n\n%s", &scelta);

    switch (scelta)
    {
        case '1':
            printf ("\n\n** INSERIMENTO DISCO **\n");
            
            for (i=0; i< 3; i++)
            {
                printf("Genere n.%d: %s\n", array_categoria[i].codice, array_categoria[i].genere);
            }
           
            printf("\n\nScegli numero genere: ");
            scanf("%d", &codice);
            printf("Hai selezionato il genere %s\n", array_categoria[codice].genere);
            
            int n;
            printf("Quanti dischi vuoi inserire? ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
               printf("Titolo:");
               scanf("%s", &array_dischi[codice].titolo);
                
               printf("Autore:");
               scanf("%s", &array_dischi[codice].autore);
            
               printf("Prezzo:");
               scanf("%f", &array_dischi[codice].prezzo);
                    
               array_categoria[codice].n_dischi++;
               numero=array_categoria[codice].n_dischi;
               dischi_rimanenti= 5 - array_categoria[codice].n_dischi;
                       
            printf("\nPuoi inserire ancora %d dischi\n", dischi_rimanenti);
                                        
            if(array_categoria[codice].n_dischi++ >= 5)
            {
                printf("*CATEGORIA PIENA*");
                exit;
            }
            }
            break;
            
                        
        case '2':
            printf ("\n\n** ELIMINA PRODOTTO **\n");
            
            for(i=0;i<numero+1;i++)
            {
                printf("%s\n",array_dischi[i].titolo);
            }
            
            printf("\nInserisci titolo disco che vuoi eliminare: ");
            scanf("%s", &elimina);
            while(i < 5)
            {
                if (strcmp(array_dischi[i].titolo,elimina)==0)
                {
                    array_dischi[i].titolo == array_dischi[i+1].titolo;
                }
            }
            break;
            
              case '3':
                        printf("\n\n*Visualizza titolo del disco con prezzo minore*");

                        printf("\n\nGeneri inseriti\n");
                        for (i = 0; i < 3; i++)
                        {
                            printf("Genere n.%d: %s\n", array_categoria[i].codice, array_categoria[i].genere);
                        }

                        int sel;
                        printf("\n\nScegli numero genere: ");
                        scanf("%d", &sel);

                        printf("\nIl titolo del disco con prezzo minore=>: %s\n", fun(array_categoria[sel].array_dischi, 0, 5));
                        break;

                    case '0':
                        return 0;

                    default:
                        printf("la scelta selezionata non esiste\n");
                    }
                }
                return 0;
            }

            int fun(disco array[], int a, int b)
            {

                if (a == b)
                {
                    return array[a].titolo;
                }

                if (array[a].prezzo < fun(array, a + 1, b))
                {
                    return array[a].titolo;
                }
                else
                {
                    return fun(array, a + 1, b);
                }
            }
