all : mini-sql.o entrada.o arquivos.o saida.o comparacao.o memoria.o
	gcc -o mini-sql.o -c mini-sql.c
	gcc -o entrada.o -c entrada.c
	gcc -o arquivos.o -c arquivos.c
	gcc -o saida.o -c saida.c
	gcc -o comparacao.o -c comparacao.c
	gcc -o memoria.o -c memoria.c
	gcc -o executavel mini-sql.o entrada.o arquivos.o saida.o comparacao.o memoria.o

run :
	./executavel 

zip : 
	zip ProjetoMiniSQL.zip *.h *.c *.tsv Makefile

debug : 
	valgrind ./executavel 

clean :
	rm *.o