/*
* Copyright (c) 2023 Caio de Almeida Pessoa e Jamile Sousa Bezerra Loureiro
* Instituto Federal de Educação, Ciência e Tecnologia do Ceará - IFCE
 * Todos os direitos reservados.
 *
 * Este código está protegido por leis de direitos autorais.
*/

/*--------------------------------------------------------------
--  #1.
--  Date: Jun, 07, 2023
--  Author: Caio de Almeida Pessoa
--  Motivo: colaboração com o algoritmo
-------------------------------------------------------------
--  #2.
--  Date: Jun, 07, 2023
--  Author: Jamile Sousa Bezerra Loureiro
--  Motivo: colaboração com o algoritmo
-------------------------------------------------------------
*/

//By Caio
//Essa biblioteca é necessária para poder adicionar dados diretamente na memória flash
#include <avr/pgmspace.h>
//End by Caio

// By Jamile
//Arquivo que está escrito o algoritmo de colisão (SAF)
#include "isColision.h"
// End by Jamile

//By Caio
// Array que armazena os valores das dimensões e posições dos retângulos
const PROGMEM int16_t valores[] = {
1,1,2,4,
4,6,2,4,

1,1,2,4,
2,5,2,4,

1,1,2,4,
2,4,2,4,

1,1,2,4,
-1,-3,2,4,

1,1,2,4,
-2,-4,2,4,

1,1,2,4,
-2,-3,2,4,

1,1,2,4,
-2,-2,2,4,

1,1,2,4,
-1,-2,2,4,

1,1,2,4,
-2,1,2,4,

1,1,2,4,
-1,1,2,4,

1,1,2,4,
0,1,2,4,

1,1,2,4,
-2,3,2,4,

1,1,2,4,
-1,3,2,4,

1,1,2,4,
0,3,2,4,

1,1,2,4,
-2,5,2,4,

1,1,2,4,
-1,5,2,4,

1,1,2,4,
0,4,2,4,

1,1,2,4,
0,6,2,4,

1,1,2,4,
0,5,2,4,

1,1,2,4,
5,3,2,4,

1,1,2,4,
4,4,2,4,

1,1,2,4,
4,3,2,4,

1,1,2,4,
4,1,2,4,

1,1,2,4,
3,1,2,4,

1,1,2,4,
4,0,2,4,

1,1,2,4,
3,0,2,4,

1,1,2,4,
3,-3,2,4,

1,1,2,4,
4,-4,2,4,

1,1,2,4,
2,-2,2,4,

1,1,2,4,
2,-4,2,4,

1,1,2,4,
1,-4,2,4,

1,1,2,4,
1,-3,2,4,

1,1,2,4,
1,-2,2,4,

1,1,2,4,
0,-4,2,4,

1,1,2,4,
0,-3,2,4,

1,1,2,4,
0,-2,2,4,

1,1,2,4,
6,3,2,4,

1,1,2,4,
5,4,2,4,

1,1,2,4,
5,1,2,5,

1,1,2,4,
5,0,2,4,

1,1,2,4,
5,-4,2,4,

1,1,2,4,
3,-4,2,4,

4,4,3,3,
5,5,6,6,

6,2,7,7,
7,3,4,4,

0,2,3,4,
0,2,3,4,

0,2,3,4,
0,3,4,5,

0,2,3,4,
0,4,5,6,

0,2,3,4,
0,5,6,7,

0,2,3,4,
0,6,7,8,

0,0,2,2,
5,0,2,2,

0,0,2,2,
5,1,2,2,

0,0,2,2,
5,2,2,2,

0,0,2,2,
5,3,2,2,

0,0,2,2,
5,4,2,2,

0,0,2,2,
6,4,2,2,

0,0,2,2,
7,4,2,2,

3,2,4,4,
4,2,4,4,

3,2,4,4,
2,2,4,4,

3,2,4,4,
3,1,4,4,

3,2,4,4,
3,3,4,4,

5,5,3,3,
-2,-10,3,3,

5,5,3,3,
-15,-3,3,3,

5,5,3,3,
-5,-5,3,3,

5,5,3,3,
-5,-15,3,3,

5,5,3,3,
2,-35,3,3,

5,5,3,3,
-5,5,3,3,

5,5,3,3,
-25,5,3,3,

5,5,3,3,
-2,5,3,3
};
// End by Caio

// By Jamile
//Essas duas estruturas serão preenchidas e serão a entrada das funções do algoritmo SAF
Rectangle rec1;
Rectangle rec2;
// End by Jamile


// Função padrão do arduíno
// Vamos utilizá-la para a execução do algoritmo, já que não precisamos do loop
void setup() {

// Início do serial
Serial.begin(9600);

    // looping que retira da memória os valores do array principal
      for(int i = 0 ; i < 68 ; i++){
          if(i %4 == 0 ){
              Serial.println();
         }

    // A colisão é verificada a cada 2 retângulos
    // Dois retângulos precisam de 8 valores do array principal
    // então a cada 8 iterações é retirado os valores da memória flash e testado se há colisão
        for(long int k = i * 8; k < (i*8) +8 ; k++){

          int newIndice = k%8;
          int displayInt = pgm_read_word_near(valores + k);
          if(newIndice == 0){
            rec1.x = displayInt;
          }
          if(newIndice == 1){
            rec1.y = displayInt;
          }
          if(newIndice == 2){
            rec1.width = displayInt;
          }
          if(newIndice == 3){
            rec1.height = displayInt;
          }
          if(newIndice == 4){
            rec2.x = displayInt;
          }
          if(newIndice == 5){
            rec2.y = displayInt;
          }
          if(newIndice == 6){
            rec2.width = displayInt;
          }
          if(newIndice == 7){
            rec2.height = displayInt;
            int collision = isCollision(rec1, rec2);
            Serial.print(collision);
            Serial.print(", ");
          }
        }

    }
}

void loop() {

}
