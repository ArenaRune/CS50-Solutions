//Recovers lost data
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //Ensures proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image");
        return 1;
    }
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "File cannot be opened for reading");
        return 2;
    }

    const int BLOCK_SIZE = 512;
    unsigned char buffer[BLOCK_SIZE];

    FILE *outptr = NULL;

    char image[7];

    int n = 0;

    // search until jpg is found
    while(fread(buffer, BLOCK_SIZE, 1, inptr) == 1)
    {
        // find the beginning of an jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            // close image file if one has been created
            if (n > 0)
            {
                fclose(outptr);
            }
            // make name for nth image
            sprintf(image, "%03d.jpg", n);

            // open nth image file
            outptr = fopen(image, "w");
            if (outptr == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", image);
                return 3;
            }

            // increment number of image files created
            n++;
        }

        // write to image file only if one exists
        if (outptr != NULL)
        {
            // write to image file
            fwrite(buffer, BLOCK_SIZE, 1, outptr);
        }
    }

    // close last image file
    fclose(outptr);

    // close card.raw
    fclose(inptr);

    return 0;

}

