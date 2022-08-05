#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <direct.h>
#include "model/sine.h"

void get_data_from_txt(float data[1000])
{

    char path[] = "..\\txt_data\\x_values.txt";

    FILE *fpt;
    fpt = fopen(path, "r");

    if (fpt==NULL)
    {
        printf("Something failed opening the file %s", path);
    }
    else
    {
        char str[1024];
        int index = 0;

        while (fgets(str, 1024, fpt) != NULL)
        {
            sscanf(str, "%f", &data[index]);
            index ++;
        }
        fclose(fpt);
    }
}

void make_predictions(float data[1000], float predictions[1000])
{
    float input[1]; 
    float prediction[1][1]; 

    for (int n=0; n<1000; n++)
    {
        input[0] = data[n]; 
        entry(input, prediction);
        predictions[n] = prediction[0][0]; 
    }
}

int main()
{
    float data[1000];
    get_data_from_txt(data);
    
    float predictions[1000];
    make_predictions(data, predictions);

    for (int j = 0; j<1000; j++)
    {
        printf("Input: %f\n", data[j]);
        printf("Output: %f\n", predictions[j]);
        printf("\n");
    }

    getchar();
    return 0;
}
