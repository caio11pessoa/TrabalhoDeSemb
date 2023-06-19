
//By Caio
// A estrutura Rectangle define um ret�ngulo com quatro atributos: x e y representam as coordenadas do centro do ret�ngulo, e width e height representam a largura e altura do ret�ngulo
typedef struct{
    float x, y;
    float width, height;
    }Rectangle;


int isColision(Rectangle rect1, Rectangle rect2){
	//esse array � criado e preenchido com as coordenadas x e y dos dois ret�ngulos
   float axes[] = { rect1.x, rect1.y, rect2.x, rect2.y };
	//o array dimensions � criado e preenchido com as larguras e alturas dos dois ret�ngulos.
   float dimensions[] = {rect1.width, rect1.height, rect2.width, rect2.height};
	//os arrays "proj1" e 'proj2' armazenar�o as proje��es dos ret�ngulos nos eixos x e y.
   float proj1[4], proj2[4];
//End By Caio

//By Jamile
//o loop for percorre as dimens�es x e y dos ret�ngulos.
//em cada itera��o, as proje��es m�ximas e m�nimas dos ret�ngulos s�o calculadas e armazenadas nos arrays proj1 e proj2, levando em considera��o as coordenadas e dimens�es dos ret�ngulos.
   for (int i = 0; i < 2; i++) {
        proj1[i] = axes[i] + (dimensions[i]/ 2.0f); // Proje��es m�ximas
        proj1[i+2] = axes[i] - (dimensions[i]/ 2.0f);
        proj2[i] = axes[i+2] + (dimensions[i+2]/ 2.0f);
        proj2[i+2] = axes[i+2] - (dimensions[i+2]/ 2.0f);
    }
//a fun��o verifica se h� sobreposi��o entre os ret�ngulos comparando as proje��es nos eixos x e y
    if ((proj1[0] < proj2[2]|| proj2[0] < proj1[2]) || (proj1[1] < proj2[3] || proj2[1] < proj1[3]))
//se houver sobreposi��o em qualquer um dos eixos, a fun��o retorna 1
	return 1;
//caso contr�rio, retorna 0
	return 0;

};
//End By Jamile
