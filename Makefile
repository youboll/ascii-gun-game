all: output.out

output.out: main.c keyboard.c graphics.c player.c monsters.c
	gcc graphics.c keyboard.c main.c player.c monsters.c -o output.out