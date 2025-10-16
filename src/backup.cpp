#include "backup.hpp"
#include <cassert>
#include <fstream>

/** 
 * @brief  faz o backup de um arquivo listado em Backup.parm
 * @author Bernardo Pimentel
 * @param  caminho_backup_parm caminho do arquivo Backup.parm
 * @param  caminho_destino caminho do destino onde o arquivo de interesse será copiado
 * 
 * Assertivas de entrada:
 *      caminho_backup_parm != NULL
 */ 

int Salvar(const char *caminho_backup_parm, const char *caminho_destino) {
    assert(caminho_backup_parm != nullptr);
    assert(caminho_destino != nullptr);

    FILE *arquivo = fopen(caminho_backup_parm, "r");
    if (arquivo == NULL) {
        return 1; // erro: arquivo não existe
    }

    // Aqui você pode fazer o que for necessário com o arquivo aberto.
    // Exemplo: copiar para outro local (caminho_destino), etc.

    fclose(arquivo);
    return 0; // sucesso
}

/** 
 * @brief  restaura um arquivo listado em Backup.parm
 * @author Bernardo Pimentel
 * @param  caminho_backup_parm caminho do arquivo Backup.parm
 * @param  caminho_destino caminho do destino onde o arquivo de interesse será restaurado
 * 
 *  Descrever o que a funcao faz
 */ 

int Restaurar(char *caminho_backup_parm, char *caminho_fonte) {
	return 0; /*!< retorna zero para teste */ 
}