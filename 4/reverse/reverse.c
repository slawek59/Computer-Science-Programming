#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Proper usage: filename input_name output_name \n");
        return 1;
    }

    //remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // Open input file for reading
    FILE *inptr = fopen(infile, "r");

    if (inptr == NULL)
    {
        printf("Couldn't open a file\n");

        return 2;
    }

    // Read header
    WAVHEADER wh;
    fread(&wh, sizeof(WAVHEADER), 1, inptr);

    int wh_end = ftell(inptr);



    // Use check_format to ensure WAV format
    check_format(wh);

    // Open output file for writing
    FILE *outptr = fopen(outfile, "w");

    if (outptr == NULL)
    {
        return 3;
    }

    // Write header to file
    fwrite(&wh, sizeof(wh), 1, outptr);

    int audio_start = wh_end + 1;

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(wh);

    // Write reversed audio to file

    //find end of the file
    fseek(inptr, 0, SEEK_END);
    int end = ftell(inptr);

    //calculate number of blocks
    int blocks = (end - wh_end) / block_size;

    //set one block outside the file --> loop will go block_size * (-2)
    if (fseek(inptr, block_size, SEEK_END))
    {
        return 4;
    }

    //rewrite
    for (int i = 0; i < blocks; i++)
    {
        fseek(inptr, block_size * (-2), SEEK_CUR);
        BYTE *arr[i];
        fread(&arr[i], block_size, 1, inptr);

        fwrite(&arr[i], block_size, 1, outptr);
    }

    fclose(inptr);
    fclose(outptr);
}

int check_format(WAVHEADER header)
{
    char *format[4] = {"W", "A", "V", "E"};

    for (int i = 0; i < sizeof(header.format); i++)
    {
        if (header.format[i] != *format[i])
        {
            return 1;
        }
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    //convert bits into bytes
    int bytes = header.bitsPerSample / 8;

    //calculate block size
    int block_size = header.numChannels * bytes;

    return block_size;
}
//Sławek