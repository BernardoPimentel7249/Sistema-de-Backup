/**
 * \file testa_backup.cpp
 */

#define CATCH_CONFIG_MAIN
#include "../third_party/catch/catch_amalgamated.hpp"
#include "../src/backup.hpp"
#include <stdio.h>
#include <unistd.h>

TEST_CASE("Coluna 1: arquivo Backup.parm inexistente gera erro", "[backup]") {
    int resultado = Salvar("tests/fixtures/nao_existe.parm", "tests/pendrive_simulado");
    REQUIRE(resultado != 0);
}

TEST_CASE("Coluna 2: backup.parm existe, arquivo está no HD, arquivo não está no pendrive", "[backup]") {
    int resultado = Salvar("tests/fixtures/backup.parm", "tests/pendrive_simulado");
    REQUIRE(resultado == 0);
}