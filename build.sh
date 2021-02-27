cc main.c -g -c -I /opt/raylib/src -o main.o
cc main.o -s -Wall -I/opt/raylib/src -L/opt/raylib/release/libs/linux -lraylib -lGL -lm -lpthread -ldl -lrt -lX11