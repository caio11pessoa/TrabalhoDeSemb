/*
* Copyright (c) 2023 Caio de Almeida Pessoa e Jamile Sousa Bezerra Loureiro
* Instituto Federal de Educa��o, Ci�ncia e Tecnologia do Cear� - IFCE
 * Todos os direitos reservados.
 *
 * Este c�digo est� protegido por leis de direitos autorais.
*/

/*--------------------------------------------------------------
--  #1.
--  Date: Jun, 07, 2023
--  Author: Caio de Almeida Pessoa
--  Motivo: colabora��o com o algoritmo
-------------------------------------------------------------
--  #2.
--  Date: Jun, 07, 2023
--  Author: Jamile Sousa Bezerra Loureiro
--  Motivo: colabora��o com o algoritmo
-------------------------------------------------------------
*/

//By Caio
//Essa biblioteca � necess�ria para poder adicionar dados diretamente na mem�ria flash
#include <avr/pgmspace.h>
//End by Caio

// By Jamile
//Arquivo que est� escrito o algoritmo de colis�o (SAF)
#include "isColision.h"
// End by Jamile

//By Caio
// Array que armazena os valores das dimens�es e posi��es dos ret�ngulos
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
//Essas duas estruturas ser�o preenchidas e ser�o a entrada das fun��es do algoritmo SAF
Rectangle rec1;
Rectangle rec2;
// End by Jamile


// Fun��o padr�o do ardu�no
// Vamos utiliz�-la para a execu��o do algoritmo, j� que n�o precisamos do loop
void setup() {

// In�cio do serial
Serial.begin(9600);

    // looping que retira da mem�ria os valores do array principal
      for(int i = 0 ; i < 68 ; i++){
          if(i %4 == 0 ){
              Serial.println();
         }

    // A colis�o � verificada a cada 2 ret�ngulos
    // Dois ret�ngulos precisam de 8 valores do array principal
    // ent�o a cada 8 itera��es � retirado os valores da mem�ria flash e testado se h� colis�o
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
