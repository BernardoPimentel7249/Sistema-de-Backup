/** 
 * @brief  faz o backup de um arquivo listado em Backup.parm
 * @author Bernardo Pimentel
 * @param  caminho_backup_parm caminho do arquivo Backup.parm
 * @param  caminho_destino caminho do destino onde o arquivo de interesse será copiado
 * 
 * Assertivas de entrada:
 *      caminho_backup_parm != NULL
 *      caminho_destino != NULL
 */ 
int Salvar(const char *caminho_backup_parm, const char *caminho_destino);


/** 
 * @brief  restaura um arquivo listado em Backup.parm
 * @author Bernardo Pimentel
 * @param  caminho_backup_parm caminho do arquivo Backup.parm
 * @param  caminho_fonte caminho do destino onde o arquivo de interesse será restaurado
 * 
 *  Descrever o que a funcao faz
 */ 
int Restaurar(const char *caminho_backup_parm, const char *caminho_fonte);

