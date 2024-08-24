
//biblioteca do SDL para lidar com a engine gráfica do jogo
#include <SDL.h>
#include <iostream>


const short SCREEN_WIDTH = 1280;
const short SCREEN_HEIGHT = 720;

int main(int argc, char* args[])
{
	/*
	* Usa a struct SDL_Window para redenizar a tela;
	*/
	SDL_Window* tela = NULL;

	/*
	* Usa a struct SDL_Surface contida pela tela
	*/
	SDL_Surface* superficieTela = NULL;

	//Inicialização do SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL Não conseguiu ser inicializado" << std::endl;
	}

	tela = SDL_CreateWindow("Primeira tela",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);


	if (tela == NULL) {
		std::cout << "Tela nao pode ser criada:" << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	else {
		//Pega uma superfície de tela
		superficieTela = SDL_GetWindowSurface(tela);
		std::cout << "Resolução da superfície: " << superficieTela->w << "x" << superficieTela->h << std::endl;

		//Preenche com uma cor
		SDL_FillRect(superficieTela, NULL, SDL_MapRGB(superficieTela->format, 0xFF, 0xFF, 0xFF));

		//Atualiza a cor
		SDL_UpdateWindowSurface(tela);


		//manter a tela e fecha a tela
		SDL_Event e;
		bool quit = false;
		do {
			while (SDL_PollEvent(&e)) {
				if (e.type == SDL_QUIT) {
					quit = true;
				}
			}

		} while (!quit);

		SDL_DestroyWindow(tela);

		
		return 0;


	}
}


