#include <stdio.h>

#include "weather-utils.h"

int lower_temperature (WeatherTable a){

    int temp = a[0][0][0]._min_temp;

    for (unsigned int i=0; i<YEARS; i++){
        for (unsigned int j=0; j<MONTHS; j++){
            for (unsigned int k=0; k<DAYS; k++){
                if (a[i][j][k]._min_temp < temp){
                    temp = a[i][j][k]._min_temp ;
                }
            }
        }
    }

    return temp;
}

void highest_temperature_peryear (WeatherTable a, int outputs[YEARS]){

    int temp_max_peryear;
    for (unsigned int i=0; i<YEARS; i++){
        
        temp_max_peryear = a[i][0][0]._max_temp;
        for (unsigned int j=0; j<MONTHS;j++){
            
            for (unsigned int k=0; k<DAYS; k++){
               
                if (temp_max_peryear < a[i][j][k]._max_temp){
                    temp_max_peryear = a[i][j][k]._max_temp;
                }

            }
        }
        outputs[i] = temp_max_peryear;
    }
    
    printf("[");
    for (unsigned int year=0; year < YEARS-1; year++){
        printf("%d, ",outputs[year]);
    }
    printf("%d]\n", outputs[YEARS-1]);

}

void highest_rainfall_month_peryear (WeatherTable a, int outputs[YEARS]){

    unsigned int rainfall_month[YEARS][MONTHS];
    
    for (unsigned int i=0; i<YEARS; i++){
        for (unsigned int j=0; j<MONTHS; j++){

            int sum_month_rainfall = 0;
            for (unsigned int k=0; k<DAYS; k++){
                sum_month_rainfall = sum_month_rainfall + a[i][j][k]._rainfall;
            }
            rainfall_month[i][j] = sum_month_rainfall;

        }
    }

    unsigned int precipitacion_mensual;
    for (unsigned int year = 0; year<YEARS; year++){
        
        unsigned int mes_maxima_precipitacion = 0;
        precipitacion_mensual = rainfall_month[year][0];
        for (unsigned int month = 0; month < MONTHS; month++){ //0=enero hasta 11=diciembre
                
            if (precipitacion_mensual < rainfall_month[year][month])
            mes_maxima_precipitacion = month;

        }
        outputs[year] = mes_maxima_precipitacion;
    }

    printf("[");
    for (unsigned int year=0; year < YEARS-1; year++){
        printf("%d, ", outputs[year]);
    }
    printf("%d]\n", outputs[YEARS-1]);

}