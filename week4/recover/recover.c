#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    BYTE buf[512];
    int cnt = 0;
    FILE *img = NULL;
    char img_name[8];

    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return (1);
    }
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("Error: cannot open %s\n", argv[1]);
        return (1);
    }
    while (fread(&buf, 512, 1, file) == 1)
    {
        if (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && (buf[3] & 0xf0) == 0xe0)
        {
            if (!(cnt == 0))
            {
                fclose(img);
            }
            sprintf(img_name, "%03i.jpg", cnt);
            img = fopen(img_name, "w");
            cnt++;
        }
        if (!(cnt == 0))
        {
            fwrite(&buf, 512, 1, img);
        }
    }
    fclose(file);
    fclose(img);
    return 0;
}