#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE * input_file;
    FILE * output_file;
    input_file = fopen(argv[argc-3], "rb");
    output_file = fopen(argv[argc-1], "wb");
    if (input_file == 0)
    {
        printf("Не удалось открыть входной файл\n");
        exit(0);
    }
    
    unsigned char symbol;
    unsigned char utf8_symbol[2];

    while (fread(&symbol, 1, 1, input_file) > 0)
    {
        if (strcmp(argv[argc-2], "WINDOWS-1251") == 0)
        {
            if (symbol >= 192 && symbol <= 239 && (symbol != 168 || symbol != 184))
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = symbol - 0x30;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol >= 240)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = symbol - 0x70;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 168)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x81;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 184)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x91;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else
            {
                fwrite(&symbol, sizeof(symbol), 1, output_file);
            }
        }
        else if (strcmp(argv[argc-2], "KOI-8") == 0)
        {
            if (symbol == 163)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x91;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 179)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x81;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 192)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x8E;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 193)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xB0;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 194)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xB1;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 195)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x86;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 196)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xB4;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 197)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xB5;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 198)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x84;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 199)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xB3;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 200)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x85;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 201)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xB8;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 202)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xB9;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 203)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xBA;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 204)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xBB;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 205)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xBC;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 206)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xBD;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 207)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xBE;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 208)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xBF;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 209)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x8F;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 210)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x80;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 211)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x81;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 212)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x82;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 213)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x83;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 214)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xB6;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 215)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xB2;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 216)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x8C;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 217)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x8B;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 218)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xB7;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 219)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x88;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 220)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x8D;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 221)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x89;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 222)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x87;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 223)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x8A;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 224)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xAE;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 225)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x90;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 226)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x91;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 227)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xA6;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 228)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x94;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 229)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x95;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 230)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xA4;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 231)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x93;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 232)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xA5;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 233)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x98;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 234)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x99;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 235)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x9A;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 236)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x9B;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 237)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x9C;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 238)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x9D;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 239)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x9E;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 240)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x9F;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 241)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xAF;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 242)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xA0;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 243)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xA1;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 244)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xA2;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 245)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xA3;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 246)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x96;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 247)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x92;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 248)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xAC;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 249)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xAB;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 250)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x97;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 251)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xA8;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 252)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xAD;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 253)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xA9;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 254)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xA7;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 255)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0xAA;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }

            else
            {
                fwrite(&symbol, sizeof(symbol), 1, output_file);
            }
        }
        else if (strcmp(argv[argc-2], "ISO-8859-5") == 0)
        {
            if (symbol >= 176 && symbol <= 223)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = symbol - 0x20;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol >= 224 && symbol <= 239)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = symbol - 0x60;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 161)
            {
                utf8_symbol[0] = 0xD0;
                utf8_symbol[1] = 0x81;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else if (symbol == 241)
            {
                utf8_symbol[0] = 0xD1;
                utf8_symbol[1] = 0x91;
                fwrite(utf8_symbol, sizeof(utf8_symbol), 1, output_file);
            }
            else
            {
                fwrite(&symbol, sizeof(symbol), 1, output_file);
            }
        }
        else
        {
            printf("Кодировка %s не поддерживается\n", argv[argc-2]);
            exit(0);
        }
    }

    printf("Файл перекодирован\n");

    fclose(input_file);
    fclose(output_file);

    return 0;
}
