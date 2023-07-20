
# JVM para a disciplina Software básico com o professor Ladeira
### Alunos:
* Marcelo Piano - 200049496
* Marcelo Junqueira - 200023624
* Gabriel Borges - 202006401
* Maycon Fabio - 200059742
* Edson Sales - 190105399


# Como configurar o projeto
Rodar o comando `make` para compilar o projeto

# Como rodar o projeto
## Modo leitor-exibidor
```./jvmSB arquivo.class -leitor```
## Modo execução
```./jvmSB arquivo.class``` (sem flags)
## Modo execução com debug
```./jvmSB arquivo.class -debug```


# Organização do projeto
![Diagrama](./diagram.png)
## Módulos:
### JVM
Se comunica com os outros módulos e gerencia a execução do programa.
### Common
Contém as estruturas de dados e funções comuns a quase todos os módulos.

### Leitor
Contém funções e estruturas de dados que permitem a leitura de arquivos .class e salvamento de suas informações.

### FrameStack
Contém funções e estruturas de dados que permitem executar os métodos na ordem correta, gerenciando a pilha de frames.

### Heap
Armazena os objetos e arrays instanciados da JVM, gerenciando o acesso e a alteração dos mesmos.

### MethodArea
Armazena e permite interação com as classes e interfaces carregadas na JVM.

### Exibidor
Contém as funções e estruturas de dados que permitem a exibição das informações contidas no .class.

### Instructions
Contêm a implementação das instruções da JVM.

