#include "hash.h"
#include <cstdio>

// Funcao hash. Retorna o indice de uma chave na tabela. Nao alterar!
int hash(char chave[STR_SIZE], int tamanho, int tentativa) {
    int h = chave[0];
    for (int i = 1; chave[i] != '\0'; i++)
        h = (h * 251 * chave[i]) % tamanho;
    return (h + tentativa) % tamanho;
}

tipoHash criar(modoHash m, int t) {
    tipoHash h;
    h.tamanho = t;
    switch (h.modo = m) {
    case semColisao:
        h.tabela.aberto = (hashAberto*) malloc(sizeof(hashAberto) * t);
        for (int i = 0; i < t; i++) 
            h.tabela.aberto[i].chave[0] = h.tabela.aberto[i].valor[0] = '\0';
        break;

    case encadeamento:
        h.tabela.encadeada = (hashEncadeada*) malloc(sizeof(hashEncadeada) * t);
        for (int i = 0; i < t; i++)
            h.tabela.encadeada[i].primeiro = NULL;
        break;

    case aberto:
        h.tabela.aberto = (hashAberto*) malloc(sizeof(hashAberto) * t);
        for (int i = 0; i < t; i++) {
            h.tabela.aberto[i].excluido = false;
            h.tabela.aberto[i].chave[0] = h.tabela.aberto[i].valor[0] = '\0';
        }
        break;
    }
    return h;
}

void destruirRecursivo(listaEncadeada * p) {
    if(p != NULL) 
        destruirRecursivo(p->proximo);
    free(p);
    p = NULL;
}

void destruir(tipoHash h) {
    switch (h.modo) {
        case semColisao:
            free(h.tabela.aberto);
            h.tabela.aberto = NULL;
            break;

        case encadeamento:
            for (int i = 0; i < h.tamanho; i++) {
                if(h.tabela.encadeada[i].primeiro != NULL)
                    destruirRecursivo(h.tabela.encadeada[i].primeiro);
            }
            free(h.tabela.encadeada);
            h.tabela.encadeada = NULL;

            break;

        case aberto:
            free(h.tabela.aberto);
            h.tabela.aberto = NULL;
            break;
    }
}


listaEncadeada * novo(char c[STR_SIZE], char v[STR_SIZE]) {
    listaEncadeada *novoItem;
    novoItem = (listaEncadeada*) malloc(sizeof(listaEncadeada));
    strcpy(novoItem->chave, c);  
    strcpy(novoItem->valor, v);
    novoItem->proximo = NULL;
    return novoItem;
}

hashAberto * novoHash(char c[STR_SIZE], char v[STR_SIZE]) {
    hashAberto *novoItem;
    novoItem = (hashAberto*) malloc(sizeof(hashAberto));
    strcpy(novoItem->chave, c);  
    strcpy(novoItem->valor, v);
    novoItem->excluido = false;
    return novoItem;
}

void inserir(tipoHash h, char c[STR_SIZE], char v[STR_SIZE]) {
    int idx = hash(c, h.tamanho);
    switch (h.modo) {
    case semColisao:
        strcpy(h.tabela.aberto[idx].chave, c);
        strcpy(h.tabela.aberto[idx].valor, v);
        break;

    case encadeamento:
        // IMPLEMENTAR!!!
        // Eh preciso alocar a estrutura listaEncadeada para cada elemento inserido.
        // Sugiro incluir no final da lista, mas pode ser inserido em qualquer ponto.
        if(h.tabela.encadeada[idx].primeiro == NULL) {
            listaEncadeada *novoItem = novo(c, v);
            h.tabela.encadeada[idx].primeiro = novoItem;
        } else {
            listaEncadeada *l = h.tabela.encadeada[idx].primeiro;
            while (l->proximo != NULL) 
                l = l->proximo;
            l->proximo = novo(c, v);
        }
        
        break;

    case aberto:
        // IMPLEMENTAR!!!
        // DICA: Eh utilizado encadeamento aberto linear. Utilize as tentativas conforme mostrado abaixo.
        for (int tentativa = 0; tentativa < h.tamanho; tentativa++) {
            idx = hash(c, h.tamanho, tentativa);
            if(h.tabela.aberto[idx].chave[0] == '\0') {
                strcpy(h.tabela.aberto[idx].chave, c);
                strcpy(h.tabela.aberto[idx].valor, v);
                h.tabela.aberto[idx].excluido = false;
                break;
                // DICA: Use uma verificacao como h.tabela.aberto[idx].chave[0] == '\0' para saber se a celula esta vazia
                // DICA: Nao esquecer de atualizar o atributo excluido
            }
        }
        break;
    }
}


char *buscarRecursivo(listaEncadeada *p, char c[STR_SIZE]) {
    if(p == NULL) return NULL;
    if(strcmp(p->chave, c) == 0) {
        return p->valor;
    }
    
    return buscarRecursivo(p->proximo, c);
}

char *buscar(tipoHash h, char c[STR_SIZE]) {
    int idx = hash(c, h.tamanho);
    switch (h.modo) {
    case semColisao:
        return strcmp(h.tabela.aberto[idx].chave, c) == 0 ? h.tabela.aberto[idx].valor : NULL;

    case encadeamento:
        return buscarRecursivo(h.tabela.encadeada->primeiro, c);

    case aberto:
        // IMPLEMENTAR!!!
        // Retornar nulo se a chave nao for encontrada!
        for(int i = 0; i < h.tamanho; i++) {
            if(strcmp(h.tabela.aberto[i].chave, c) == 0)
                return h.tabela.aberto[i].valor;
        }
        
        return NULL;
    }
}

void apagar(tipoHash h, char c[STR_SIZE]) {
    int idx = hash(c, h.tamanho);
    switch (h.modo) {
        case semColisao:
            if (strcmp(h.tabela.aberto[idx].chave, c) == 0)
                h.tabela.aberto[idx].chave[0] = h.tabela.aberto[idx].valor[0] = '\0';
            break;

        case encadeamento: {

            for (int i = 0; i < h.tamanho; i++) {
                idx = hash(c, h.tamanho);
                listaEncadeada *l = h.tabela.encadeada[idx].primeiro; 
                if(l == NULL) return;
                if(strcmp(l->chave, c) == 0) {
                    h.tabela.encadeada[idx].primeiro = l->proximo;
                    break;
                }
                
                while(l->proximo != NULL) {
                    if(strcmp(l->proximo->chave, c) == 0) {
                        l->proximo = l->proximo->proximo;
                        break;
                    }
                    l = l->proximo;
                }
                
                break;
            }
        }

        case aberto:
            for (int tentativa = 0; tentativa < h.tamanho; tentativa++) {
                idx = hash(c, h.tamanho, tentativa);
                if(strcmp(h.tabela.aberto[idx].chave, c) == 0) {
                    h.tabela.aberto[idx].excluido = true;
                    h.tabela.aberto[idx].chave[0] = '\0';
                    h.tabela.aberto[idx].valor[0] = '\0';
                    break;
                    // DICA: Use uma verificacao como h.tabela.aberto[idx].chave[0] == '\0' para saber se a celula esta vazia
                    // DICA: Nao esquecer de atualizar o atributo excluido
                }
            }
            break;
    }
}

int quantidade(tipoHash h) {
    int qtd = 0;
    switch (h.modo) {
    case semColisao:
    case aberto: // Igual ao semColisao, portanto, jah implementado!!!
        for (int i = 0; i < h.tamanho; i++)
            if (h.tabela.aberto[i].chave[0] != '\0')
                qtd++;
        break;

    case encadeamento:
        for (int i = 0; i < h.tamanho; i++){
            listaEncadeada *lista = h.tabela.encadeada[i].primeiro;
            while(lista != NULL) {
                qtd++;
                lista = lista->proximo;
            }
        }
        break;
    }
    return qtd;
}

int main(int argc, char *argv[]) {
    tipoHash h;
    modoHash m;
   
    char comando[64];
    while(true) {
        scanf("%s", comando);

        if (strcmp(comando, "CRIAR") == 0) {
            scanf("%s", comando);
            if     (strcmp(comando, "SEM_COLISAO") == 0)  m = semColisao;
            else if(strcmp(comando, "ENCADEAMENTO") == 0) m = encadeamento;
            else if(strcmp(comando, "ABERTO") == 0)       m = aberto;


            int tamanho;
            scanf("%d", &tamanho);
            h = criar(m, tamanho);
        }
        else if (strcmp(comando, "INSERIR") == 0) {
            char chave[STR_SIZE]; char valor[STR_SIZE];
            scanf("%s %s", chave, valor);
            inserir(h, chave, valor);
        }
        else if (strcmp(comando, "BUSCAR") == 0) {
            char chave[STR_SIZE];
            scanf("%s", chave);
            char *valor = buscar(h, chave);
            if (valor != NULL)
                printf("%s\n", valor);
            else
                printf("---Nao existe---\n");
        }
        else if (strcmp(comando, "APAGAR") == 0) {
            char chave[STR_SIZE];
            scanf("%s", chave);
            apagar(h, chave);
        }
        else if (strcmp(comando, "QUANTIDADE") == 0) {
            int qtd = quantidade(h);
            printf("Existem %d elementos (FC=%.3f)\n", qtd, qtd / (float) h.tamanho);
        }
        else if (strcmp(comando, "FIM") == 0) {
            int qtd = 0;
            switch (m) {
            case semColisao:
            case aberto:
                for (int i = 0; i < h.tamanho; i++)
                    if (h.tabela.aberto[i].chave[0] != '\0')
                        qtd++;
                break;
            case encadeamento:
                for (int i = 0; i < h.tamanho; i++) {
                    listaEncadeada *l = h.tabela.encadeada[i].primeiro;
                    while (l != NULL) {
                        qtd++;
                        l = l->proximo;
                    }
                }
                break;
            }
            if (qtd != quantidade(h)) {
                printf("ERRO: Tabela hash inconsistente!!!\n");
            }
            destruir(h);
            break;
        } else {
            printf("ERRO INTERNO!!!\n");
            break;
        }
    }

    return 0;
}