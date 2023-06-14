### Inicialização:

1. Abre o arquivo selecionado com o leitor
2. Armazena as informações da classe no constant pool. vetor de ponteiros?
3. Carrega classes super até chegar na object
4. Roda blocos estáticos do object até a classe inicial
5. procura main e a coloca na pilha de frames
   Será que a inicialização pode ser um frame? Preciso executar os blocos ou apenas empilhar eles na pilha?

### Loop de execução:

1. PC aponta pro frame sendo executado
2. PC interno ao frame diz qual instrução do code é a próxima a ser executada
3. Identificar opcode e executar a operação correspondente, que pode ser dos tipos:

- load e store
- aritméticas
- conversão de tipos
- Criação e manipulação de objetos
- Invocação de métodos e retorno
- Lançar exceção
- sincronização
