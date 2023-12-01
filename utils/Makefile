all: build

build: entry_point.o intern.o info.o draw.o analyze.o obstacles.o planes.o
	gcc entry_point.o intern.o info.o draw.o analyze.o obstacles.o planes.o -o entry_point -lm -Wall

entry_point.o: ../start/entry_point.c
	gcc -c ../start/entry_point.c

intern.o: ./intern.c
	gcc -c ./intern.c

info.o: ../action/info.c
	gcc -c ../action/info.c

draw.o: ../action/draw.c
	gcc -c ../action/draw.c

analyze.o: ../action/analyze.c
	gcc -c ../action/analyze.c

obstacles.o: ../action/obstacles.c
	gcc -c ../action/obstacles.c


planes.o: ./planes.c
	gcc -c ./planes.c

clean:
	rm *.o entry_point
