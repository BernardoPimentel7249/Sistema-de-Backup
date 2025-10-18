#include "backup.hpp"
#include <cassert>
#include <fstream>
#include <cstring>

/** 
 * @brief  faz o backup de um arquivo listado em Backup.parm
 * @author Bernardo Pimentel
 * @param  caminho_backup_parm caminho do arquivo Backup.parm
 * @param  caminho_destino caminho do destino onde o arquivo de interesse será copiado
 * 
 * Assertivas de entrada:
 *      caminho_backup_parm != NULL
 *      caminho_destino != NULL
 * 
 */ 

int Salvar(const char *caminho_backup_parm, const char *caminho_destino) {
    assert(caminho_backup_parm != nullptr);
    assert(caminho_destino != nullptr);

    FILE *backup_parm = fopen(caminho_backup_parm, "r");
    if (backup_parm == NULL) {
        return 1; // arquivo inexistente
    }

    FILE * arquivo_destino = fopen(caminho_destino, "r");
    if (arquivo_destino == NULL) {
        return 1; // arquivo inexistente
    }

    // copia arquivo para o pendrive inicio:
    const char *nome_arquivo = strrchr(caminho_destino, '/');
    if (nome_arquivo == NULL) {
        nome_arquivo = caminho_destino;
    } else {
        nome_arquivo++; // pula a barra
    }

    char caminho_saida[512];
    snprintf(caminho_saida, sizeof(caminho_saida), "tests/fixtures/pendrive_simulado/%s", nome_arquivo);

    FILE *arquivo_saida = fopen(caminho_saida, "wb");
    if (arquivo_saida == NULL) {
        fclose(arquivo_destino);
        fclose(backup_parm);
        return 1; // erro ao criar arquivo de saída
    }

    // Copia o conteúdo de arquivo_destino para arquivo_saida
    char buffer[4096];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), arquivo_destino)) > 0) {
        fwrite(buffer, 1, bytes, arquivo_saida);
    }
    // copia arquivo para o pendrive fim.
    
    fclose(arquivo_saida);
    fclose(arquivo_destino);
    fclose(backup_parm);

    // Aqui você pode fazer o que for necessário com o arquivo aberto.
    // Exemplo: copiar para outro local (caminho_destino), etc.
    return 0; // sucesso
}

/** 
 * @brief  restaura um arquivo listado em Backup.parm
 * @author Bernardo Pimentel
 * @param  caminho_backup_parm caminho do arquivo Backup.parm
 * @param  caminho_fonte caminho do destino onde o arquivo de interesse será restaurado
 * 
 *  Descrever o que a funcao faz
 */ 

int Restaurar(const char *caminho_backup_parm, const char *caminho_fonte) {
    assert(caminho_backup_parm != nullptr);
    assert(caminho_fonte != nullptr);

    FILE *backup_parm = fopen(caminho_backup_parm, "r");
    if (backup_parm == NULL) {
        return 1; // erro: arquivo não existe
    }

    FILE * arquivo_fonte = fopen(caminho_fonte, "r");
    if (arquivo_fonte == NULL) {
        return 1;
    }

    // Aqui você pode fazer o que for necessário com o arquivo aberto.
    // Exemplo: copiar para outro local (caminho_destino), etc.

    fclose(arquivo_fonte);
    fclose(backup_parm);
    return 0; // sucesso
}
