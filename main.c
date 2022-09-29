#include <stdio.h>

int cpfD1(const char cpf[11]);
int cpfD2(const char cpf[11]);

int main() {
    //Inicializa as variaveis necessárias
    char cpf[11];
    int dt1;
    int dt2;

    //Recebe do usuário somente os numeros do cpf
    printf("Digite somente os numeros do seu cpf:");
    gets(cpf);

    //Calcula os dois digitos verificadores
    dt1 = cpfD1(cpf);
    dt2 = cpfD2(cpf);

    //Verifica se o CPF é valido ou não
    if(dt1 == ((int)cpf[9])-48 && dt2 == ((int) cpf[10])-48){
        printf("CPF valido");
        return 0;
    } else{
        printf("CPF invalido");
        return 1;
    }
}

int cpfD1(const char cpf[11]){
    int soma = 0;
    int digito;
    for (int i = 10, j = 0; i >= 2 && j<10; --i, ++j) {
        int c = ((int) cpf[j])-48;
        soma += (c)*i;
    }
    digito = 11 - soma % 11;
    if (digito >= 10) digito = 0;
    return digito;
}
int cpfD2(const char cpf[11]){
    int soma = 0;
    int digito;
    for (int i = 11, j = 0; i >= 2 && j<11; --i, ++j) {
        int c = ((int) cpf[j])-48;
        soma += (c)*i;
    }
    digito = 11 - soma % 11;
    if (digito >= 10) digito = 0;
    return digito;
}