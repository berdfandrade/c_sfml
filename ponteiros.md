# Ponteiros em C 

Pense em ponteiros como "endereços" que indicam onde algo está armazenado na memória.

## Conceitos básicos 

Variáveis normais : Amazenam valores diretamente

```c 
int numero = 10;
```

Ponteiros : Armazenam o endereço de memória de outra variável 

```c 
int* ponteiroParaNumero = &numero; 
```
Aqui, `&numero` pega o endereço de memória da variável `numero`. 

Acessando o valor apontado : Para acessar ou modificar o valor da variável que o ponteiro aponta, usamos o operado `*` (desreferenciação).

```c 
*ponteiroParaNumero = 20* 
```

### Entrada e saída 

Imagine que temos uma função que precise modificar uma variável de entrada para produzir uma saída. Vamos usar um ponteiro para isso. 

```c 
#include <stdio.h>

// Criando uma função para dobrar o valor 
void dobrarValor(int* entrada) {
    *entrada = *entrada * 2
}

int main () {
    int numeroEntrada = 5; 
    printf("Antes: %d\n", numeroEntrada); 

    dobrarValor(&numeroEntrada); 
    printf("Depois %d\n", numeroEntrada);

    return 0;
}
```

Explicação 
    - `entrada` é um ponteiro que recebe o endereço de `numeroEntrada`.
    - Dentro da função `dobrarValor`, usamos `*entrada` para acessar e modificar o valor original 


--- 

### Função com múltiplas saídas
Agora, suponha que queremos calcular o dobro e o triplo de um número e retornar ambos. Usaremos ponteiros para "retornar" mais de um valor. 

```c 
#include <stdio.h>

void calcularDobroETriplo(int entrada, int* saidaDobro, int* saidaTriplo) {
    *saidaDobro = entrada * 2;  // Armazena o dobro no endereço apontado por 'saidaDobro'.
    *saidaTriplo = entrada * 3; // Armazena o triplo no endereço apontado por 'saidaTriplo'.
}

int main() {
    int numeroEntrada = 4;
    int dobro, triplo;

    calcularDobroETriplo(numeroEntrada, &dobro, &triplo);  // Passamos os endereços de 'dobro' e 'triplo'.
    printf("Entrada: %d\nDobro: %d\nTriplo: %d\n", numeroEntrada, dobro, triplo);

    return 0;
}
```
