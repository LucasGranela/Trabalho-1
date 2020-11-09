all: 
	gcc -o main main.c funcoesUtilizadas.c arqIndicePessoa.c funcoes-fornecidas/fornecido.c -lm
run:
	./main