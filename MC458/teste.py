def alterar_lista_recursivamente(lista, indice):
    if indice < len(lista):
        # Altera o valor na posição atual
        lista[indice] = lista[indice] * 2
        # Chama recursivamente para o próximo índice
        alterar_lista_recursivamente(lista, indice + 1)

# Exemplo de uso
minha_lista = [1, 2, 3, 4, 5]
alterar_lista_recursivamente(minha_lista, 0)
print(minha_lista)