/**
 * \file testa_velha.cpp
 */

#define CATCH_CONFIG_MAIN
#include "../third_party/catch/catch_amalgamated.hpp"
#include "../src/backup.hpp"


TEST_CASE( "Testa backup", "[single-file]" ) {
    char teste1[100] = "caminho";
    REQUIRE( Backup(teste1) == 1 );
} 
 
