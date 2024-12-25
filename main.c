#include <SFML/Graphics.h>
#include <stdio.h>

// Definir uma constante com o caminho de uma fonte
#define FONT_PATH "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"

int main() {
    // Criação de uma janela
    sfVideoMode mode = {800, 600, 32}; // Largura, Altura, Profundidade de cor
    sfRenderWindow *window = sfRenderWindow_create(mode, "Janela SFML em C", sfResize | sfClose, NULL);

    if (!window) {
        return 1; // Falha ao criar a janela
    }


    // Carregar uma fonte 
    sfFont *font = sfFont_createFromFile(FONT_PATH);

    // Caso a fonte não carregue entramos nesse fallback aqui
    if(!font) {
      printf("Erro ao carregar a fonte/n");
      return 1;
    }

    // Carregar a textura 
    sfTexture* texture = sfTexture_createFromFile("./4ur3tny7ka3e1.png", NULL);

    if(!texture){
        return 1; 
    }

    // Criar um sprite para exibir a textura
    sfSprite* player = sfSprite_create();
    sfSprite_setTexture(player, texture, sfTrue);
    sfSprite_setPosition(player, (sfVector2f){400.0f, 300.0f});

    // Cria o círculo
    sfCircleShape* circle = sfCircleShape_create();
    sfCircleShape_setRadius(circle, 50.0f); // Define o raio do círculo
    sfCircleShape_setFillColor(circle, sfColor_fromRGB(255, 255, 255)); // Define a cor (verde)
    sfCircleShape_setPosition(circle, (sfVector2f){375.0f, 275.0f}); // Define a posição


    // Criar o texto 
    sfText *text = sfText_create();

    // Qual é o texto em si
    sfText_setString(text, "Bem-vindo, Bernardo!");

    // Colocando a fonte no texto 
    sfText_setFont(text, font);

    // Qual é o tamanho do texto
    sfText_setCharacterSize(text, 30);
    
    // Qual é a cor do texto 
    sfText_setColor(text, sfWhite);

    // Posição do texto
    sfText_setPosition(text, (sfVector2f){200, 300});


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
        sfVector2f position = sfSprite_getPosition(player);
        if (sfKeyboard_isKeyPressed(sfKeyUp)) {
            position.y -= 5.0f;
        }
        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            position.y += 5.0f;
        }
        if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
            position.x -= 5.0f;
        }
        if (sfKeyboard_isKeyPressed(sfKeyRight)) {
            position.x += 5.0f;
        }

        // Limpar a janela com uma cor
        sfRenderWindow_clear(window, sfBlack);

        // Desenhar o texto na janela 
        sfRenderWindow_drawText(window, text, NULL);

        // Carrega jogador na tela 
        sfRenderWindow_drawSprite(window, player, NULL);

        // Desenha o círculo na tela
        sfRenderWindow_drawCircleShape(window, circle, NULL);

        // Exibir o conteúdo na janela
        sfRenderWindow_display(window);
    }

    // Liberar recursos
    sfRenderWindow_destroy(window);
    sfSprite_destroy(player);
    sfFont_destroy(font);
    sfRenderWindow_destroy(window);

    return 0;
}

