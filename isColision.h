
//By Caio
// A estrutura Rectangle define um retângulo com quatro atributos: x e y representam as coordenadas do centro do retângulo, e width e height representam a largura e altura do retângulo
typedef struct{
    float x, y;
    float width, height;
    }Rectangle;


int isColision(Rectangle rect1, Rectangle rect2){
	//esse array é criado e preenchido com as coordenadas x e y dos dois retângulos
   float axes[] = { rect1.x, rect1.y, rect2.x, rect2.y };
	//o array dimensions é criado e preenchido com as larguras e alturas dos dois retângulos.
   float dimensions[] = {rect1.width, rect1.height, rect2.width, rect2.height};
	//os arrays "proj1" e 'proj2' armazenarão as projeções dos retângulos nos eixos x e y.
   float proj1[4], proj2[4];
//End By Caio

//By Jamile
//o loop for percorre as dimensões x e y dos retângulos.
//em cada iteração, as projeções máximas e mínimas dos retângulos são calculadas e armazenadas nos arrays proj1 e proj2, levando em consideração as coordenadas e dimensões dos retângulos.
   for (int i = 0; i < 2; i++) {
        proj1[i] = axes[i] + (dimensions[i]/ 2.0f); // Projeções máximas
        proj1[i+2] = axes[i] - (dimensions[i]/ 2.0f);
        proj2[i] = axes[i+2] + (dimensions[i+2]/ 2.0f);
        proj2[i+2] = axes[i+2] - (dimensions[i+2]/ 2.0f);
    }
//a função verifica se há sobreposição entre os retângulos comparando as projeções nos eixos x e y
    if ((proj1[0] < proj2[2]|| proj2[0] < proj1[2]) || (proj1[1] < proj2[3] || proj2[1] < proj1[3]))
//se houver sobreposição em qualquer um dos eixos, a função retorna 1
	return 1;
//caso contrário, retorna 0
	return 0;

};
//End By Jamile
