#include <SFML/Graphics.h>
#include "collision.h"
#include <stdbool.h>
#include <stdio.h>
#include <sys/resource.h>

// Definir uma constante com o caminho de uma fonte
#define FONT_PATH "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"

// Definindo a framerate
#define FRAMERATE 30

// Para saber quais recursos estão sendo gastos
void print_resource_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    printf("Uso de CPU: %ld.%06ld segundos\n",
           usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    printf("Máximo de memória usada: %ld KB\n", usage.ru_maxrss);
}

int main() {
    // Criação de uma janela
    sfVideoMode mode = {1020, 820, 32}; 
    sfRenderWindow *window = sfRenderWindow_create(mode, "Meu jogo", sfResize | sfClose, NULL);

    print_resource_usage(); 
    

    // bool checkCollision(NULL, NULL, NULL, NULL, NULL, NULL){}

    if (!window) {
        return 1; // Falha ao criar a janela
    }

    // Criando o círculo do jogador
    sfCircleShape* circle_player = sfCircleShape_create();

    // Define o raio do círculo
    sfCircleShape_setRadius(circle_player, 20.0f);

    // Define a cor
    sfCircleShape_setFillColor(circle_player, sfColor_fromRGB(255, 255, 255));

    // Define a posição inicial
    sfCircleShape_setPosition(circle_player, (sfVector2f){375.0f, 275.0f}); 

    // Defindo a velocidade de movimento do círculo
    float SPEED = 0.1; 
    
    // Loop principal
    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        // Processamento de eventos
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }

        // Controle do jogador (teclas de movimento)
        sfVector2f position = sfCircleShape_getPosition(circle_player);
        if (sfKeyboard_isKeyPressed(sfKeyUp)) {
            position.y -= SPEED; // Mover para cima
        }
        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            position.y += SPEED; // Mover para baixo
        }
        if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
            position.x -= SPEED; // Mover para a esquerda
        }
        if (sfKeyboard_isKeyPressed(sfKeyRight)) {
            position.x += SPEED; // Mover para a direita
        }

        // Atualizar a posição do círculo do jogador
        sfCircleShape_setPosition(circle_player, position);

        // Limpar a janela com uma cor
        sfRenderWindow_clear(window, sfBlack);

        // Desenha o círculo do jogador na tela
        sfRenderWindow_drawCircleShape(window, circle_player, NULL);

        // Exibir o conteúdo na janela
        sfRenderWindow_display(window);
    }

    // Liberar recursos
    sfCircleShape_destroy(circle_player);
    sfRenderWindow_destroy(window);

    return 0;
}
