so_long/
├── includes/
│ ├── so_long.h # Header principal com includes e structs globais
│ ├── game.h # Funções relacionadas à lógica do jogo
│ ├── map.h # Parsing, validação e verificação do mapa
│ ├── render.h # Renderização e manipulação gráfica com MiniLibX
│ ├── input.h # Eventos do teclado e interações do jogador
│ ├── entity.h # Estruturas e funções relacionadas a personagens
│ ├── utils.h # Funções auxiliares gerais
├── lib/ # Bibliotecas externas (como libft, se utilizada)
├── maps/ # Arquivos de mapas do jogo (.ber)
│ ├── level1.ber
│ ├── level2.ber
├── src/ # Código-fonte principal
│ ├── main.c # Ponto de entrada do programa
│ ├── init_game.c # Inicialização do jogo (janela, assets, variáveis)
│ ├── game_loop.c # Lógica principal do jogo (movimentação, regras)
│ ├── handle_input.c # Processamento de entrada do teclado
│ ├── map_parser.c # Leitura, verificação e armazenamento do mapa
│ ├── map_validation.c # Regras e validações do mapa (paredes, caminhos)
│ ├── render.c # Desenho de sprites e atualização da tela
│ ├── player.c # Movimentação e ações do jogador
│ ├── cleanup.c # Liberação de memória e encerramento seguro
│ ├── utils.c # Funções auxiliares (exemplo: ft_strerror, logging)
├── textures/ # Sprites e imagens utilizadas no jogo
│ ├── player.xpm
│ ├── wall.xpm
│ ├── collectible.xpm
│ ├── exit.xpm
├── bonus/ # Implementações adicionais
│ ├── enemy_ai.c # Movimentação dos inimigos no mapa
│ ├── animations.c # Efeitos visuais e animações
│ ├── hud_display.c # Contador de movimentos e informações na tela
├── Makefile # Script de compilação do projeto
└── README.md # Documentação do projeto


TODO:

[ ] ao invés da gambiarra usar o instance da MLX ==> mlx_instance_t *inst = &collectible_image->instances[i] ==> inst->enabled = false;
[ ] deletar as texturas:
    mlx_delete_texture(game->textures.wall);
    mlx_delete_texture(game->textures.floor);
    mlx_delete_texture(game->textures.player);
    mlx_delete_texture(game->textures.collectible);
    mlx_delete_texture(game->textures.exit);
