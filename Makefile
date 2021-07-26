all : mini-sql.o entrada.o arquivos.o saida.o 
	gcc -o mini-sql.o -c mini-sql.c
	gcc -o entrada.o -c entrada.c
	gcc -o arquivos.o -c arquivos.c
	gcc -o saida.o -c saida.c
	gcc -o executavel mini-sql.o entrada.o arquivos.o saida.o

run :
	./executavel