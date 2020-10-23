all: 
	gcc -o main trabalho1.c arquivos.c funcoes-fornecidas/fornecido.c -lm
run:
	./main

clean:
	rm -r main