/**
 * \file testa_velha.cpp
 */

#define CATCH_CONFIG_MAIN
#include "../third_party/catch/catch_amalgamated.hpp"
#include "../src/backup.hpp"


TEST_CASE("Coluna 1: arquivo Backup.parm inexistente gera erro", "[backup]") {
    int resultado = Salvar("tests/fixtures/nao_existe.parm", "tests/pendrive_sim");
    REQUIRE(resultado != 0);
}