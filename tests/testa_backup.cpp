/**
 * \file testa_backup.cpp
 */

#define CATCH_CONFIG_MAIN
#include "../third_party/catch/catch_amalgamated.hpp"
#include "../src/backup.hpp"
#include <stdio.h>
#include <unistd.h>

TEST_CASE("Coluna 1: arquivo Backup.parm inexistente gera erro", "[backup]") {
    int resultado = Salvar("tests/fixtures/nao_existe.parm", "tests/fixtures/pendrive_simulado");
    REQUIRE(resultado != 0);
}

TEST_CASE("Coluna 2: backup.parm existe, arquivo está no HD, arquivo não está no pendrive", "[backup]") {
    // Arquivo não está no pendrive:
    int resultado2 = Restaurar("tests/fixtures/backup.parm", "tests/fixtures/pendrive_simulado/backup_parm_teste4.txt");
    REQUIRE(resultado2 != 0); // nenhuma ação feita

    // Backup.parm existe e o arquivo está no HD:
    int resultado1 = Salvar("tests/fixtures/backup.parm", "tests/fixtures/HD_simulado/backup_parm_teste4.txt");
    REQUIRE(resultado1 == 0);
}

TEST_CASE("Coluna 3", "[backup]") {
    // Arquivo está no HD e no pendrive, mas o do HD é mais antigo.
    int resultado = Salvar("tests/fixtures/backup.parm", "tests/fixtures/HD_simulado/backup_parm_teste5.txt");
    REQUIRE(resultado == 0);
}

TEST_CASE("Coluna 4", "[backup]") {
    // arquivo no HD e no Pendrive com a mesma idade.
    int resultado = Salvar("tests/fixtures/backup.parm", "tests/fixtures/HD_simulado/backup_parm_teste8.txt");
    REQUIRE(resultado == 0); // nenhuma ação feita
}

TEST_CASE("Coluna 5", "[backup]") {
    // arquivo no HD é menos antigo que o do pendrive.
    int resultado = Salvar("tests/fixtures/backup.parm", "tests/fixtures/HD_simulado/backup_parm_teste10.txt");
    REQUIRE(resultado != 0); // nenhuma ação feita
}

TEST_CASE("Coluna 6", "[backup]") {
    // Restaura, mas arquivo ta no pendrive e não no HD
    int resultado = Restaurar("tests/fixtures/backup.parm", "tests/fixtures/pendrive_simulado/backup_parm_teste11.txt");
    REQUIRE(resultado != 0); // erro
}

TEST_CASE("Coluna 7", "[backup]") {
    // Restaura, arquivo nos dois mas o do pen é mais velho
    int resultado = Restaurar("tests/fixtures/backup.parm", "tests/fixtures/pendrive_simulado/backup_parm_teste13.txt");
    REQUIRE(resultado != 0); // erro
}