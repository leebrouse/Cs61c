/************************************************************************
**
** NAME:        gameoflife.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-23
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "imageloader.h"

//Determines what color the cell at the given row/col should be. This function allocates space for a new Color.
//Note that you will need to read the eight neighbors of the cell in question. The grid "wraps", so we treat the top row as adjacent to the bottom row
//and the left column as adjacent to the right column.
Color *evaluateOneCell(Image *image, int row, int col, uint32_t rule)
{
	//YOUR CODE HERE
	 Color *new_color = malloc(sizeof(Color));
    if (new_color == NULL)
    {
        return NULL;
    }

	//Change the judgment:
	//Need to design a Algorithm to judge the cell with its neighbors
    if ((image->image[row][col].B & 1) == 1)
    {
        new_color->R = new_color->G = new_color->B = 255;
    }
    else
    {
        new_color->R = new_color->G = new_color->B = 0;
    }

    return new_color;
	
}

//The main body of Life; given an image and a rule, computes one iteration of the Game of Life.
//You should be able to copy most of this from steganography.c
Image *life(Image *image, uint32_t rule)
{
	//YOUR CODE HERE
	    Image *new_image = malloc(sizeof(Image));
    if (new_image == NULL)
    {
        return NULL;
    }

    new_image->rows = image->rows;
    new_image->cols = image->cols;

    new_image->image = malloc(sizeof(Color *) * new_image->rows);
    if (new_image->image == NULL)
    {
        free(new_image);
        return NULL;
    }

    for (int i = 0; i < new_image->rows; i++)
    {
        new_image->image[i] = malloc(sizeof(Color) * new_image->cols);
        if (new_image->image[i] == NULL)
        {
            for (int k = 0; k < i; k++)
            {
                free(new_image->image[k]);
            }
            free(new_image->image);
            free(new_image);
            return NULL;
        }

        for (int j = 0; j < new_image->cols; j++)
        {	//The code should be changed
            Color *new_color = evaluateOneCell(image, i, j,rule);

            if (new_color == NULL)
            {
                for (int k = 0; k < i; k++)
                {
                    free(new_image->image[k]);
                }
                free(new_image->image);
                free(new_image);
                return NULL;
            }
            else
            {
                new_image->image[i][j] = *new_color;
                free(new_color);
            }
        }
    }

    return new_image;
}

/*
Loads a .ppm from a file, computes the next iteration of the game of life, then prints to stdout the new image.

argc stores the number of arguments.
argv stores a list of arguments. Here is the expected input:
argv[0] will store the name of the program (this happens automatically).
argv[1] should contain a filename, containing a .ppm.
argv[2] should contain a hexadecimal number (such as 0x1808). Note that this will be a string.
You may find the function strtol useful for this conversion.
If the input is not correct, a malloc fails, or any other error occurs, you should exit with code -1.
Otherwise, you should return from main with code 0.
Make sure to free all memory before returning!

You may find it useful to copy the code from steganography.c, to start.
*/
int main(int argc, char **argv)
{
	//YOUR CODE HERE
	 if (argc != 3)
    {
        printf("./gameOfLife filename rule");
        printf("filename is an ASCII PPM file (type P3) with maximum value 255.\n");
		printf("rule is a hex number beginning with 0x; Life is 0x1808.");
        exit(-1);
    }

	char *filename = argv[1];
	Image *originalimage=readData(filename);
	if (originalimage==NULL)
	{
		exit(1);
	}

	uint32_t rule=argv[2];
	Image *new_image=life(originalimage,rule);
	if (new_image==NULL)
	{
		exit(1);
	}

	writeData(new_image);
	// Free originalImage after creating newImage.
	freeImage(originalimage);
	// Free newImage before returning.
    freeImage(new_image); 
	return 0;
}
