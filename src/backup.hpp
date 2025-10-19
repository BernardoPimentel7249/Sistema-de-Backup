/** 
 * @brief  restaura um arquivo listado em Backup.parm
 * @author Bernardo Pimentel
 * @param  caminho_backup_parm caminho do arquivo Backup.parm
 * @param  caminho_fonte caminho do destino onde o arquivo de interesse será restaurado
 * @return int Código de status:
 *      - `0` → sucesso ou nenhuma ação necessária (arquivos iguais);
 *      - `1` → erro (arquivo inexistente, falha ao abrir/criar, ou timestamps inconsistentes).
 * 
 *@assert
        -assertivas de entrada:
        caminho_backup_parm != nullptr
        caminho_destino != nullptr
        -assertiva de saída:
        arquivo realmente criado no destino
 */ 
int Salvar(const char *caminho_backup_parm, const char *caminho_destino);


/** 
 * @brief  restaura um arquivo listado em Backup.parm
 * @author Bernardo Pimentel
 * @param  caminho_backup_parm caminho do arquivo Backup.parm
 * @param  caminho_fonte caminho do destino onde o arquivo de interesse será restaurado
 * @return int Código de status:
 *      - `0` → sucesso ou nenhuma ação necessária (arquivos iguais);
 *      - `1` → erro (arquivo inexistente, falha ao abrir/criar, ou timestamps inconsistentes).
 * 
 *@assert
        -assertivas de entrada:
        caminho_backup_parm != nullptr
        caminho_fonte != nullptr
        -assertiva de saída:
        arquivo realmente criado no destino
 */ 
int Restaurar(const char *caminho_backup_parm, const char *caminho_fonte);

