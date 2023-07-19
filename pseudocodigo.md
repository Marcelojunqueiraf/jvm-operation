# Pseudocódigo

## Inicialização:

1. Abre o arquivo selecionado com o leitor
2. Armazena as informações da classe no method area
3. procura main e a coloca na pilha de frames
4. Carrega classes super até chegar na object
5. Roda blocos estáticos (clinit) do object até a classe inicial (Coloca eles na pilha de frames)
6. Inicia loop de execução

## Loop de execução:

1. Pega o frame no topo da pilha
2. PC interno ao frame diz qual instrução do code é a próxima a ser executada
3. Identificar opcode e executar a operação correspondente
