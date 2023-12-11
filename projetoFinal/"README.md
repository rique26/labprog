Para iniciar o programa, informe o nível de quantização, os nomes dos arquivos e o tamanho da janela.

Informações do código:

O programa contém os seguintes 6 procedimentos:

    readPGMImage: Lê a imagem original.
    filtro: Aplica o filtro na imagem original.
    writePGMImage: Escreve a imagem filtrada em um arquivo.
    quantizacao: Quantiza a imagem original e a filtrada.
    matrizSCM: Cria a matriz SCM entre as duas imagens.

Variáveis importantes:

    char nome[]: Nome do arquivo da imagem original.
    char nome2[]: Nome do arquivo para armazenar a imagem suavizada.
    char nome3[]: Nome do arquivo texto para armazenar a matriz SCM.
    int tamJanela: Tamanho da janela do filtro.
    int nivel: Nível de quantização.
