// Created by Rose ((github) AUnicornWithNoLife)

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "font8x8/font8x8.h"
#include "carg-parse/carg-parse.h"

#define SIZE 8

char trueChar = '#';
char falseChar = ' ';

bool verbose = false;

bool isBitTrue(char val, int pos) // check if the bit from val in position pos is a one
{
    return (val) & (1 << pos); // dont touch this caffiene induced wizardry
}

char* getCharFromFont(char input) // get a pointer to the relative char from the font
{
    return &*font8x8_basic[(int)input]; // char can't be used to access array, so has to be cast to an int (ik i hate this too)
}

void stringToFont(char* input, int width, char output[SIZE][width])
{
    int length = strlen(input);

    for (int i = 0; i < length; i++) // loop through characters
    {
        char* fontChar = getCharFromFont(*input); // get font pointer

        for (int x = 0; x < SIZE; x++) // loop from top to bottom
        {
            for (int y = 0; y < SIZE; y++) // loop from left to right
            {
                output[x][(i * SIZE) + y] = isBitTrue(fontChar[x], y) ? trueChar : falseChar;

                if (verbose)
                {
                    printf("i: %d, x: %d, y: %d, out: %c\n", i, x, y, output[x][(i * SIZE) + y]);
                }
            }
        }

        input++; // increment the character from the input (I <3 POINTERS)
    }
}

int main (int argc, char** argv) // argument layout "'./Big Letter' 'INPUT TEXT' -trueC 'OPTIONAL TRUE CHARACTER' -falseC 'OPTIONAL FALSE CHARACTER' -v (optional VERBOSE flag)
{
    carg_parse_data* args = carg_parse(argc, argv);

    for (int i = 0; i < args->lv_len; i++)
    {
        if (!strcmp(args->lv_labels[i], "v"))
        {
            verbose = true;

            printf("VERBOSE ENABLED");
        }

        if (!strcmp(args->lv_labels[i], "trueC"))
        {
            trueChar = args->lv_values[i][0];
        }

        if (!strcmp(args->lv_labels[i], "falseC"))
        {
            falseChar = args->lv_values[i][0];
        }
    }

    char* inputString;

    if (args->values_len > 0)
    {
        inputString = args->values[0];
    }
    else
    {
        printf("\n!!!NOT ENOUGH ARGUMNETS!!!\n\n");

        return -1;
    }

    carg_parse_free(args);

    if (verbose)
    {
        printf("Text: \"%s\"\n\n", inputString);
    }

    int width = SIZE * strlen(inputString); // width of canvas

    if (verbose)
    {
        printf("WIDTH: %d\n", width);
    }

    char final[SIZE][width]; // create canvas

    stringToFont(inputString, width, final); // paint canvas

    if (verbose)
    {
        printf("Generated:\n"); // GENERATED (hopefully no pointer errors)
    }

    printf("\n");

    for (int x = 0; x < SIZE; x++) // output canvas
    {
        for (int y = 0; y < width; y++)
        {
            printf("%c", final[x][y]);
        }

        printf("\n");
    }

    printf("\n");

    return 0;
}