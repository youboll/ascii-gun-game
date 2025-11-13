all: output.out

output.out: main.c keyboard.c graphics.c
	gcc graphics.c keyboard.c main.c -o output.out