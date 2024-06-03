// Author: Juanmi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char base = 2; // 2: binary, 16: hex

unsigned char c_operando1[10], c_operando2[10];
long int operando1, operando2;
long int resultado;

void operar(int op);
void shifting(int op);
void bitOps(int op);
void convertResult(long int);

int main() 
{   
    printf("\nCALCULADORA BINARIA\n");
    printf("-------------------\n");
    printf("1. OR\n");
    printf("2. AND\n");
    printf("3. XOR\n");
    printf("4. <<\n");
    printf("5. >>\n");
    printf("6. Get a certain bit.\n");
    printf("7. Change a certain bit.\n");
    printf("8. Base change (0 -> binary) (1 -> hexadecimal)\n");
    printf("0. Exit.\n");

    unsigned char c_opcode[3];
    long int opcode;

    unsigned char c_op8[3];
    long int op8;

    do {
        printf("\nChoose op: ");
        fgets(c_opcode, 10, stdin);
        opcode = strtol(c_opcode, NULL, 10);
        switch(opcode)
        { 
            case 0:
                printf("EXIT\n");
                return 0;
            case 1:
                printf("-> [OR]\n");
                operar(1);
                break; 
            case 2:
                printf("-> [AND]\n");
                operar(2);
                break;
            case 3:
                printf("-> [XOR]\n");
                operar(3);
                break;
            case 4:
                printf("-> [<<] (leftwards shift) how many times?: ");
                shifting(4);
                break; 
            case 5:
                printf("-> [>>] (rightwards shift) how many times?: ");
                shifting(5);
                break;
            case 6:
                printf("-> Get bit at position: ");
                bitOps(6);
                break;
            case 7:
                printf("-> Change bit at position: ");
                bitOps(7);
                break;
            case 8:
                printf("-> Base change (0 -> binary) (1 -> hexadecimal): ");
                fgets(c_op8, 10, stdin);
                op8 = strtol(c_op8, NULL, 10);
                if (op8 == 0)
                    base = 2;
                else
                    base = 16;
                break;
            default:
                printf("ERROR: Wrong op code\n");
        }
    } while (opcode != 0);

}

void getOperandos();

void operar(int op)
{
    getOperandos();
    switch(op)
    { 
        case 1:
            resultado = operando1 | operando2;
            break; 
        case 2:
            resultado = operando1 & operando2;
            break;
        case 3:
            resultado = operando1 ^ operando2;
            break;
    }
    convertResult(resultado);
}

void getOperandos()
{
    printf("op1: ");
    fgets(c_operando1, 20, stdin);
    operando1 = strtol(c_operando1, NULL, base);
    printf("op2: ");
    fgets(c_operando2, 20, stdin);
    operando2 = strtol(c_operando2, NULL, base);
}

void shifting(int op)
{
    fgets(c_operando1, 20, stdin);
    operando1 = strtol(c_operando1, NULL, 10);
    printf("number: ");
    fgets(c_operando2, 20, stdin);
    operando2 = strtol(c_operando2, NULL, base);
    if (op ==4)
        resultado = operando2 << operando1;
    else
        resultado = operando2 >> operando1;
    convertResult(resultado);
}

void bitOps(int op)
{   
    fgets(c_operando1, 20, stdin);
    operando1 = strtol(c_operando1, NULL, 10);
    printf("number: ");
    fgets(c_operando2, 20, stdin);
    operando2 = strtol(c_operando2, NULL, base);
    if (op == 6) {
        resultado = (operando2 & (1 << operando1)) >> operando1;
        printf("--------------\nres: %d\n", resultado);
    } else {
        resultado = operando2 ^ (1 << operando1);
        convertResult(resultado);
    }
}

void convertResult(long int result)
{   
    printf("--------------\n");
    printf("res: ");
    char converted[20];
    int i = 0;
    if (base == 2) {
        while (result > 0) {
            converted[i] = result % 2;
            result = result / 2;
            i++;
        }
        for (int j = i - 1; j >= 0; j--) {
            printf("%d", converted[j]);
            if (j % 4 == 0)
                printf(" ");
        }
    } else {
        while (result > 0) {
            int remainder = result % 16;
            if (remainder < 10)
                converted[i] = remainder + '0';
            else
                converted[i] = remainder - 10 + 'A';
            result = result / 16;
            i++;
        }
        for (int j = i - 1; j >= 0; j--) {
            printf("%c", converted[j]);
            if (j % 4 == 0)
                printf(" ");
        }
    }
    printf("\n");
}
