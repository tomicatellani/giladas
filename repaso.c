// Clase práctica 4/8. Repaso para examen. (ppt Clase 10)
#include <stdio.h>
int main(){
    
    struct datosMesa{
        char nombre[20];
        char apellido[30];
        int dni;
        int comensales;
        int ganancia;
    };
    
    struct datosMesa mesas[49];

    int cubierto;
    int op;

    printf("\nIngrese el valor de cubierto");
    scanf("%d", &cubierto);

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
            printf("\nIngrese la cantidad de comensales ");
            scanf("%d", &mesas[mesaDisp].comensales);
            printf("\nIngrese el nombre de uno de los comensales ");
            scanf("%s", &mesas[mesaDisp].nombre);
            printf("\nIngrese el apellido de %s ", mesas[mesaDisp].nombre);
            scanf("%d", &mesas[mesaDisp].apellido);
            printf("\nIngrese el DNI de %s %s", mesas[mesaDisp].nombre, mesas[mesaDisp].apellido);
            scanf("%d", &mesas[mesaDisp].dni);
            //Pedido
            printf("Ingese el valor del nuevo pedido");
            scanf("%d", &valorPedido);
            mesas[mesaDisp].ganancia += valorPedido; 
        }

        break;
    case 2:
        int mesa;
        printf("\nIngrese el número de la mesa a actualizar");
        scanf("%d", &mesa);

        if (mesas[mesa].comensales == 0){
            printf("La mesa %d está ocupada. Ingrese otra mesa o seleccione la opción 1 del menú (ocupar mesa)", mesa);
        } else {
            printf("Ingese el valor del nuevo pedido");
            scanf("%d", &valorPedido);
            mesas[mesa].ganancia += valorPedido; 
        }
        
        
        break;
    
    case 3:
        int mesa;
        printf("\nIngrese el número de la mesa a cobrar");
        scanf("%d", &mesa);

        break;
    default:
        break;
    }
    


return 0;
}
