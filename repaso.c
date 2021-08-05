// Clase práctica 4/8. Repaso para examen. (ppt Clase 10)
#include <stdio.h>
int main(){
     
    struct datosMesa{
        char nombre[20];
        char apellido[30];
        int dni;
        int comensales;
        int subtotal;
        int total;
    };
    
    struct datosMesa mesas[49];

    int cubierto;
    int op;

    printf("\nIngrese el valor de cubierto");
    scanf("%d", &cubierto);

    do{
        do{
            printf("\nOcupar una mesa ..........1");
            printf("\nActualizar una mesa.......2");
            printf("\nCobrar una mesa...........3");
            printf("\nFinalizar día.............4");
            scanf("%d", &op);
        }while (op != 1 || op!= 2 || op!=3 || op!=4);
        
        switch (op){
        case 1: //Si se desea ocupar una mesa...

            int mesaDisp;
            int valorPedido;
            //Recorro todas las mesas buscando alguna sin comensales. Si existe alguna almaceno el número de esa mesa, y si no hay disponibles lo indico con -1
            for (int i = 0; i < 49; i++){
                if(mesas[i].comensales == 0){
                    mesaDisp = -1;
                } else {
                    mesaDisp = i;
                    break;
                }
            }

            if (mesaDisp == -1){
                printf("\nTodas las mesas están ocupadas");
            } else {
                printf("\nSe asignó la mesa %d", mesaDisp);
                printf("\nIngrese la cantidad de comensales ");
                scanf("%d", &mesas[mesaDisp].comensales);
                printf("\nIngrese el nombre de uno de los comensales ");
                scanf("%s", &mesas[mesaDisp].nombre);
                printf("\nIngrese el apellido de %s ", mesas[mesaDisp].nombre);
                scanf("%d", &mesas[mesaDisp].apellido);
                printf("\nIngrese el DNI de %s %s", mesas[mesaDisp].nombre, mesas[mesaDisp].apellido);
                scanf("%d", &mesas[mesaDisp].dni);
                //Pedido
                printf("Ingese el valor del pedido");
                scanf("%d", &valorPedido);
                mesas[mesaDisp].subtotal += valorPedido;
                mesas[mesaDisp].subtotal += mesas[mesaDisp].comensales * cubierto;
            }

            break;
        case 2: //Actualizar una mesa
            int mesa;
            printf("\nIngrese el número de la mesa a actualizar");
            scanf("%d", &mesa);

            if (mesas[mesa].comensales == 0){
                printf("La mesa %d está desocupada. Ingrese otra mesa o seleccione la opción 1 del menú (ocupar mesa)", mesa);
            } else {
                printf("Ingese el valor del nuevo pedido");
                scanf("%d", &valorPedido);
                mesas[mesa].subtotal += valorPedido;
            }

            break;
        case 3: //Cobrar mesa
            int mesa;
            printf("\nIngrese el número de la mesa a cobrar");
            scanf("%d", &mesa);

            //Valido que esa mesa tenga comensales
            if (mesas[mesa].comensales == 0){
                printf("\nLa mesa %d está desocupada, por lo que no puede cobrarse");
            } else {
                printf("\nLa mesa %d debe abonar $%d", mesa, mesas[mesa].subtotal);
                //Reseteo los campos del registro, a exepción del total que acumula el subtotal
                mesas[mesa].total += subtotal;
                mesas[mesa].apellido = null;
                mesas[mesa].nombre = null;
                mesas[mesa].comensales = null;
                mesas[mesa].dni = null;
                mesas[mesa].subtotal = 0;
            }

            break;
        case 4: //Finalizar dia
            printf("\nDía finalizado");
            int totDia = 0; //Acumulador del total de cada mesa

            //Recorro cada mesa y acumulo el total
            for (int i = 0; i < 49; i++){
                totDia += mesas[i].total;
            }

            //Recorro cada mesa e informo el total de c/u y lo que representa en el total de ganancias
            for (int i = 0; i < 49; i++){
                printf("\nLa mesa %d obtuvo una ganancia de $%d, que representa un %d del total", i, mesas[i].total, mesas[i].total * 100 / totDia);
            }

            printf("\nEl total de ganancias del día es de $%d", totDia);
            break;
        default:
            printf("\nDEFAULT");
            break;
        }
    } while (op =! 4);
return 0;
}