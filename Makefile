all: output.out

output.out: main.c keyboard.c graphics.c player.c
	gcc graphics.c keyboard.c main.c player.c -o output.out