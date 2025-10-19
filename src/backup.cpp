#include "backup.hpp"
#include <cassert>
#include <fstream>
#include <cstring>
#include <sys/stat.h>
#include <time.h>


/** 
 * @brief  faz o backup de um arquivo listado em Backup.parm
 * @author Bernardo Pimentel
 * @param  caminho_backup_parm caminho do arquivo Backup.parm
 * @param  caminho_destino caminho do destino onde o arquivo de interesse será copiado
 * 
 * Assertivas de entrada:
 *      caminho_backup_parm != NULL
 *      caminho_destino != NULL
 *      assert(stat_destino.st_mtime > stat_pendrive.st_mtime)
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

    // copia arquivo para o pendrive pt 1:
    const char *nome_arquivo = strrchr(caminho_destino, '/');
    if (nome_arquivo == NULL) {
        nome_arquivo = caminho_destino;
    } else {
        nome_arquivo++; // pula a barra
    }

    char caminho_no_pendrive[512];
    snprintf(caminho_no_pendrive, sizeof(caminho_no_pendrive), "tests/fixtures/pendrive_simulado/%s", nome_arquivo);
    // copiar arquivo para o pendrive pt 1

    // Comparar idade do arquivo no pendrice com no HD:
    FILE* arquivo_no_pendrive = fopen(caminho_no_pendrive, "rb");
    if (!(arquivo_no_pendrive == NULL)) {
        struct stat stat_destino;
        struct stat stat_pendrive;

        // stats do caminho destino
        if (stat(caminho_destino, &stat_destino) != 0) {
            return 1;
        }
        // stats do caminho pendrive
        if (stat(caminho_no_pendrive, &stat_pendrive) != 0) {
            return 1;
        }

        // garantir q hd é mais velho
        if (stat_destino.st_mtime > stat_pendrive.st_mtime) {
            return 1; // erro 
        } else if (stat_destino.st_mtime == stat_pendrive.st_mtime) {
            return 0; // fazer nada
        }
    }


    // copiar arquivo para o pendrive pt 2
    FILE *arquivo_saida = fopen(caminho_no_pendrive, "wb");
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
    // copia arquivo para o pendrive pt 2.
    
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
 *  Assertivas de entrada:
 *      caminho_backup_parm != NULL
 *      caminho_fonte != NULL
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

    // copia arquivo para o HD pt 1:
    const char *nome_arquivo = strrchr(caminho_fonte, '/');
    if (nome_arquivo == NULL) {
        nome_arquivo = caminho_fonte;
    } else {
        nome_arquivo++; // pula a barra
    }

    char caminho_no_HD[512];
    snprintf(caminho_no_HD, sizeof(caminho_no_HD), "tests/fixtures/HD_simulado/%s", nome_arquivo);
    // copiar arquivo para o HD pt 1

    // Comparar idade do arquivo no pendrice com no HD:
    FILE* arquivo_no_HD = fopen(caminho_no_HD, "rb");
    if (!(arquivo_no_HD == NULL)) {
        struct stat stat_fonte;
        struct stat stat_HD;

        // stats do caminho destino
        if (stat(caminho_fonte, &stat_fonte) != 0) {
            return 1;
        }
        // stats do caminho pendrive
        if (stat(caminho_no_HD, &stat_HD) != 0) {
            return 1;
        }

        // garantir q hd é mais velho
        if (stat_fonte.st_mtime < stat_HD.st_mtime) {
            return 1; // erro 
        } else if (stat_fonte.st_mtime == stat_HD.st_mtime) {
            return 0; // fazer nada
        }
    }

    // copiar arquivo para o pendrive pt 2
    FILE *arquivo_saida = fopen(caminho_no_HD, "wb");
    if (arquivo_saida == NULL) {
        fclose(arquivo_fonte);
        fclose(backup_parm);
        return 1; // erro ao criar arquivo de saída
    }

    // Copia o conteúdo de arquivo_destino para arquivo_saida
    char buffer[4096];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), arquivo_fonte)) > 0) {
        fwrite(buffer, 1, bytes, arquivo_saida);
    }
    // copia arquivo para o pendrive pt 2.
    
    fclose(arquivo_saida);
    fclose(arquivo_fonte);
    fclose(backup_parm);
    return 0; // sucesso
}
