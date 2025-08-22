# Calculadora

Calculadora em C utilizando a Notação Polonesa Inversa.

> [!warning]
> O programa funciona apenas em OS Linux.

### Utilização

Para efetuar o cálculo, basta entrar com a operação seguindo a **RPN**, como apresentado no exemplo:

```
    10 20 + 5 /
```

O resultado será dado em seguida:

```
    10 20 + 5 /
    = 6.00
```

As operações atualmente suportadas são:

| Operação      | Sinal | Exemplo         | Operação         |
|---------------|-------|-----------------|------------------|
| Soma          | +     | `a b +`         | $$ a + b $$      |
| Subtração     | -     | `a b -`         | $$ a - b $$      |
| Multiplicação | *     | `a b *`         | $$ a . b $$      |
| Divisão       | /     | `a b /`         | $$ a \over b $$  |
| Raiz          | root  | `a b root`      | $$ \sqrt[b]{a} $$|
| Potência      | ^     | `a b ^`         | $$ a^b $$        |

Para **encerrar a calculadora**, basta entrar com a letra **q**.

### Compilação
Para a compilação, basta utilizar o comando **make** enquanto na raiz do projeto.

### Configuração
Para alterar o número de casas decimais, utiliza-se o comando:

```
    decimal n
```

Onde *n* é o número de casas decimais. Por padrão, ele é configurado para duas casas decimais.

### Notação Polonesa Inversa

Calculadora na **N**otação **P**olonesa **I**nversa (**RPN**), também conhecida como **notação pós-fixada**. Uma operação matemática será apresentada como:

| **Operação**           | **Notação Convencional** | **RPN**      |
|------------------------|-------------------------|--------------|
| $$ {a + b} \over c $$  | (a+b)/c                 | a b + c /    |

Para efetuar as operações em **RPN**, em linguagens de programação, utilizamos uma estrutura de pilha. Como exemplo, tomemos a operação:

$$ 5 + ((1 + 2) * 4) - 3 $$

Pode ser representada em **RPN** como:

$$ 5 \space 1 \space 2 \space + \space 4 \space * \space + \space 3 \space - $$

Quando formos ler a equação, devemos seguir os seguintes passos, começando a ler pela esquerda:

1. Leia um caractere da notação.
2. Se for um operando, empilhe-o, isto é, coloque-o no topo da pilha.
3. Mas se ele for um operador, retire o penúltimo e o último operando da pilha. Faça a operação que se pede entre eles e coloque o resultado de volta na pilha.
4. Repita todos os passos acima até que toda a notação seja lida.
5. O resultado será o que sobrou na pilha.

Representando graficamente, teremos:

| Elemento Lido | Operação         | Pilha     |
|---------------|------------------|-----------|
| 5             | Armazenar 5      | [5]       |
| 1             | Armazenar 1      | [5 1]     |
| 2             | Armazenar 2      | [5 1 2]   |
| +             | Soma             | [5 3]     |
| 4             | Armazenar 4      | [5 3 4]   |
| *             | Multiplicação    | [5 12]    |
| +             | Soma             | [17]      |
| 3             | Armazenar 3      | [17 3]    |
| -             | Subtração        | [14]      |
| FIM           | Resultado        | [14]      |