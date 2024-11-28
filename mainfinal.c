#include <stdio.h>
#define ZONAS 5
#define DIAS_HISTORICOS 7
#include "funciones.h"


int main() {
    float datosHistoricos[ZONAS][4][DIAS_HISTORICOS]; 
    float actuales[ZONAS][4]; 
    float predicciones[ZONAS][4]; 
    int opcion;

    
    for (int zona = 0; zona < ZONAS; zona++) {
        printf("\n--- Ingreso datos para la zona %d ---\n", zona + 1);
        for (int contaminante = 0; contaminante < 4; contaminante++) {
            printf("Contaminante: %s\n", CONTAMINANTES[contaminante]);
            printf("Datos históricos (últimos %d días):\n", DIAS_HISTORICOS);
            for (int dia = 0; dia < DIAS_HISTORICOS; dia++) {
                printf("Día %d: ", dia + 1);
                scanf("%f", &datosHistoricos[zona][contaminante][dia]);
            }
            printf("Nivel actual de %s: ", CONTAMINANTES[contaminante]);
            scanf("%f", &actuales[zona][contaminante]);
        }
    }

  
    do {
        printf("\n--- Menú Principal ---\n");
        printf("1. Calcular predicciones y mostrar recomendaciones\n");
        printf("2. Modificar datos\n");
        printf("3. Salir\n");
        printf("Por favor igrese el numero de la opción que quiere realizar: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            for (int zona = 0; zona < ZONAS; zona++) {
                printf("\n--- Predicciones y recomendaciones para la zona %d ---\n", zona + 1);
                for (int contaminante = 0; contaminante < 4; contaminante++) {
                    predicciones[zona][contaminante] = calcularPromedio(&datosHistoricos[zona][contaminante][0]);
                }
                generarRecomendaciones(actuales[zona][0], predicciones[zona][0], CONTAMINANTES[0]);
            }
        } else if (opcion == 2) {
            modificarDatos(datosHistoricos, actuales);
        } else if (opcion != 3) {
            printf("Opción no válida.\n");
        }
    } while (opcion != 3);

    return 0;
}
