# ascii-gun-game
A simple ASCII gun game made as a final project for the CC2AED2

## Como Criar Mapas

Para criar novos níveis, consulte o arquivo `levels/Como criar níveis.txt` para instruções detalhadas.

### Regras Básicas:
- `@` - Posição inicial do jogador
- ` ` (espaço) - Área andável
- Qualquer outro caractere - Obstáculo (não andável)

### Estrutura do Mapa:
1. Use `+` para cantos, `-` para bordas horizontais, `|` para bordas verticais
2. Todas as bordas devem estar fechadas
3. Não deixe linhas vazias extras no final do arquivo
4. Todas as linhas devem ter o mesmo comprimento

Exemplo `level1.txt` atual:
```
+-----------------------------------------+
|                                         |
|          ##       #         #        #  |
|          ##                 #           |
|          ##                 #           |
|          ##                             |
|                  ##      ##             |
|       @    ##    ##      ##             |
|                  #        #             |
|       ##         #        #             |
|       # #        ##      ##        ##   |
|       # #                           #   |
|       # #      ##        ##        #    |
|       ###      #          #        #    |
|               #            #        #   |
|      ###      #            #            |
|                       ## ##             |
|         # #                       #     |
|         # #                       #     |
|         # #      ########         #     |
|         # #      #      #         #     |
|         # #      #      #         #     |
|                ##        ##             |
|                                         |
|                                         |
+-----------------------------------------+
```
