default:
	gcc main.c scenes/title.c scenes/char.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o game
