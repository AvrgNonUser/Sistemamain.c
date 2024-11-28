#include <stdio.h>
#define ZONAS 5
#define DIAS_HISTORICOS 7

const char *CONTAMINANTES[4] = {"CO2", "SO2", "NO2", "PM2.5"};
const float LIMITES[4] = {3000.0, 1000.0, 2000.0, 250.0}; 


float calcularPromedio(float *datos) {
    float suma = 0, pesos = 0;
    for (int i = 0; i < DIAS_HISTORICOS; i++) {
        suma += *(datos + i) * (DIAS_HISTORICOS - i);
        pesos += (DIAS_HISTORICOS - i);
    }
    return suma / pesos;
}

// Función para generar recomendaciones
void generarRecomendaciones(float actual, float prediccion, const char *contaminante) {
    printf("Recomendaciones para %s:\n", contaminante);
    if (actual > LIMITES[3] || prediccion > LIMITES[3]) {
        printf("- Suspender actividades al aire libre.\n");
        printf("- Aumentar campañas de reducción de emisiones.\n");
    } else if (actual > LIMITES[0] || prediccion > LIMITES[0]) {
        printf("- Implementar restricciones vehiculares.\n");
        printf("- Promover el uso de transporte público y bicicletas.\n");
    } else if (actual > LIMITES[1] || prediccion > LIMITES[1]) {
        printf("- Regular emisiones industriales.\n");
        printf("- Vigilar fuentes industriales.\n");
    } else if (actual > LIMITES[2] || prediccion > LIMITES[2]) {
        printf("- Restringir actividades de construcción.\n");
        printf("- Promover combustibles más limpios.\n");
    } else {
        printf("- Mantener medidas actuales para preservar la calidad del aire.\n");
    }
}

// Función para modificar datos
void modificarDatos(float datosHistoricos[ZONAS][4][DIAS_HISTORICOS], float actuales[ZONAS][4]) {
    int zona, contaminante, opcion;
    printf("\n--- Modificar Datos ---\n");
    printf("Seleccione la zona (1 a %d): ", ZONAS);
    scanf("%d", &zona);
    zona -= 1; // Ajustar índice

    printf("Seleccione el contaminante:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, CONTAMINANTES[i]);
    }
    scanf("%d", &contaminante);
    contaminante -= 1; // Ajustar índice

    printf("¿Qué desea modificar?\n");
    printf("1. Datos históricos\n");
    printf("2. Datos actuales\n");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Datos históricos actuales para %s en la zona %d:\n", CONTAMINANTES[contaminante], zona + 1);
        for (int i = 0; i < DIAS_HISTORICOS; i++) {
            printf("Día %d: %.2f\n", i + 1, datosHistoricos[zona][contaminante][i]);
        }
        int dia;
        printf("Seleccione el día a modificar (1 a %d): ", DIAS_HISTORICOS);
        scanf("%d", &dia);
        dia -= 1; // Ajustar índice
        printf("Ingrese el nuevo valor: ");
        scanf("%f", &datosHistoricos[zona][contaminante][dia]);
    } else if (opcion == 2) {
        printf("Valor actual para %s en la zona %d: %.2f\n", CONTAMINANTES[contaminante], zona + 1, actuales[zona][contaminante]);
        printf("Ingrese el nuevo valor: ");
        scanf("%f", &actuales[zona][contaminante]);
    } else {
        printf("Opción no válida.\n");
    }
}
