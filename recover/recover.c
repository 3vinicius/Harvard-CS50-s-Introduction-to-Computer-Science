#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        return 1;
    }


    FILE *file = fopen(argv[1], "r");
    BYTE buffer[512];
    int jpeg = 0;
    char fileName[8] = {0};
    FILE *outptr = NULL;

    if (file != NULL)
    {
        while (fread(buffer, sizeof(BYTE) * 512, 1, file))
        {
            if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xF0) == 0xE0)
            {
                if (outptr != NULL)
                {
                    fclose(outptr);
                }

                sprintf(fileName, "%03d.jpg", jpeg++);
                outptr = fopen(fileName, "w");
            }

            if (outptr != NULL)
            {
                fwrite(buffer, sizeof(BYTE) * 512, 1, outptr);
            }
        }
        fclose(file);
    }

    return 0;
}
