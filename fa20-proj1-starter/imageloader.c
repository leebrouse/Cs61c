/************************************************************************
**
** NAME:        imageloader.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Dan Garcia  -  University of California at Berkeley
**              Copyright (C) Dan Garcia, 2020. All rights reserved.
**              Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-15
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "imageloader.h"

// Opens a .ppm P3 image file, and constructs an Image object.
// You may find the function fscanf useful.
// Make sure that you close the file with fclose before returning.
Image *readData(char *filename)
{
	// YOUR CODE HERE
	Image *image = malloc(sizeof(Image));
	if (image == NULL)
	{
		return NULL;
	}

	FILE *image_file = fopen(filename, "r");
	if (image_file == NULL)
	{
		free(image);
		return NULL;
	}

	char format[3];
	if (fscanf(image_file, "%2s", format) != 1 || strcmp(format, "P3") != 0)
	{
		free(image);
		fclose(image_file);
		return NULL;
	}

	if (fscanf(image_file, "%d %d", &image->cols, &image->rows) != 2)
	{
		free(image);
		fclose(image_file);
		return NULL;
	}

	int max_num;
	if (fscanf(image_file, "%d", &max_num) != 1 || max_num != 255)
	{
		free(image);
		fclose(image_file);
		return NULL;
	}

	image->image = malloc(sizeof(Color *) * image->rows);
	if (image->image == NULL)
	{
		free(image);
		fclose(image_file);
		return NULL;
	}

	for (int i = 0; i < image->rows; i++)
	{
		image->image[i] = malloc(sizeof(Color) * image->cols);
		if (image->image[i] == NULL)
		{
			for (int k = 0; k < i; k++)
			{
				free(image->image[k]);
			}
			free(image->image);
			free(image);
			fclose(image_file);
			return NULL;
		}

		for (int j = 0; j < image->cols; j++)
		{
			Color *color = &image->image[i][j];
			if (fscanf(image_file, "%hhu %hhu %hhu", &color->R, &color->G, &color->B) != 3)
			{
				for (int k = 0; k <= i; k++)
				{
					free(image->image[k]);
				}
				free(image->image);
				free(image);
				fclose(image_file);
				return NULL;
			}
		}
	}

	fclose(image_file);
	return image;
}


// Given an image, prints to stdout (e.g. with printf) a .ppm P3 file with the image's data.
void writeData(Image *image)
{
	// YOUR CODE HERE
	printf("P3\n");
	printf("%d %d\n",image->cols,image->rows);
	printf("255\n");
	Color **colors = image->image;
	for (int i = 0; i < image->rows; i++)
	{
		for (int j = 0; j < image->cols; j++)
		{
			Color color = colors[i][j];
			printf("%3hhu %3hhu %3hhu", color.R, color.G, color.B);
			if (j != image->cols - 1)
			{
				printf("   ");
			}
		}
		printf("\n");
	}

	
}

// Frees an image
void freeImage(Image *image)
{
	// YOUR CODE HERE
	
	
		//按行释放
		for (int i = 0; i < image->rows; i++)
		{
			free(image->image[i]);
		}	
	
	
	free(image->image);
	free(image);
}

