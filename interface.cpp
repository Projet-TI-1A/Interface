#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
void SDL_ExitWithError(const char *message);


int main(int argc, char** argv)
{
	SDL_Window *window = NULL ;
	SDL_Renderer *renderer = NULL ;
	int d, y, x,rayon=100, rayon2=50;
	int cx=120,cy=120,cx2=120,cy2=120;
	
	/* LANCEMENT*/
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_ExitWithError("Initialisation SDL");
	}
	
	/* CREATION FENETRE */
	window = SDL_CreateWindow("Simulation ventre",
					SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600, SDL_WINDOW_FULLSCREEN); /* le dernier peut être changé c'est mode affichage*/
					/* titre, position x, y, largeur, hauteur, mode d'affichage*/
	
	if (window==NULL)
	{
		SDL_ExitWithError("Creation fenetre echouée");
	}
	/*CREATION RENDU POUR TRACER*/
	renderer= SDL_CreateRenderer(window, -1,SDL_RENDERER_SOFTWARE); /* fenetre du rendu, gerer driver affichage,ensemble de valeurs possibles*/
	if (renderer==NULL)
	{
		SDL_ExitWithError("creation rendu echouée");
	}
	
	
	/* POSE--------------------------------------------------------*/
	if (SDL_SetRenderDrawColor(renderer,112,168,237,SDL_ALPHA_OPAQUE) !=0)/*changer couleur pour tracer, paramètre : rendu,taux R G B, gerer transparence et alpha */
	{
		SDL_ExitWithError("impossible changer la couleur pour le rendu");
	}
	if (SDL_RenderDrawPoint(renderer,100,450) !=0) /*dessiner un point , parametre : rendu, coordonnées x et y*/
	{
		SDL_ExitWithError("impossible dessiner le point");
	}
	d = 3 - (2 * rayon);
	x = 0;
	y = rayon;
	while (y >= x) 
	{
  	if (SDL_RenderDrawPoint(renderer,cx+x,cy+y) !=0)
  	{
		SDL_ExitWithError("impossible dessiner le point");
	}
  	if (SDL_RenderDrawPoint(renderer,cx+y,cy+x)!=0)
  	{
		SDL_ExitWithError("impossible dessiner le point");
	}
  	if (SDL_RenderDrawPoint(renderer,cx-x,cy+y)!=0)
  	{
		SDL_ExitWithError("impossible dessiner le point");
	} 
  	if (SDL_RenderDrawPoint(renderer,cx-y,cy+x)!=0) 
  	{
		SDL_ExitWithError("impossible dessiner le point");
	}
  	if (SDL_RenderDrawPoint(renderer,cx+x,cy-y)!=0) 
  	{
		SDL_ExitWithError("impossible dessiner le point");
	}
  	if (SDL_RenderDrawPoint(renderer,cx+y,cy-x)!=0) 
  	{
		SDL_ExitWithError("impossible dessiner le point");
	}
  	if (SDL_RenderDrawPoint(renderer,cx-x,cy-y)!=0) 
  	{
		SDL_ExitWithError("impossible dessiner le point");
	}
  	if (SDL_RenderDrawPoint(renderer,cx-y,cy-x)!=0) 
  	{
		SDL_ExitWithError("impossible dessiner le point");
	}
	if (d < 0)
		{d = d + (4 * x) + 6;}
	else
		{d = d + 4 * (x - y) + 10;
		y--;}
	x++;
	}
	d = 3 - (2 * rayon2);
	x = 0;
	y = rayon2;
	while (y >= x) 
	{
  	if (SDL_RenderDrawPoint(renderer,cx2+x,cy2+y) !=0)
  	{
		SDL_ExitWithError("impossible dessiner le point");
	}
  	if (SDL_RenderDrawPoint(renderer,cx2+y,cy2+x)!=0)
  	{
		SDL_ExitWithError("impossible dessiner le point");
	}
  	if (SDL_RenderDrawPoint(renderer,cx2-x,cy2+y)!=0)
  	{
		SDL_ExitWithError("impossible dessiner le point");
	} 
  	if (SDL_RenderDrawPoint(renderer,cx2-y,cy2+x)!=0) 
  	{
		SDL_ExitWithError("impossible dessiner le point");
	}
  	if (SDL_RenderDrawPoint(renderer,cx2+x,cy2-y)!=0) 
  	{
		SDL_ExitWithError("impossible dessiner le point");
	}
  	if (SDL_RenderDrawPoint(renderer,cx2+y,cy2-x)!=0) 
  	{
		SDL_ExitWithError("impossible dessiner le point");
	}
  	if (SDL_RenderDrawPoint(renderer,cx2-x,cy2-y)!=0) 
  	{
		SDL_ExitWithError("impossible dessiner le point");
	}
  	if (SDL_RenderDrawPoint(renderer,cx2-y,cy2-x)!=0) 
  	{
		SDL_ExitWithError("impossible dessiner le point");
	}
	if (d < 0)
		{d = d + (4 * x) + 6;}
	else
		{d = d + 4 * (x - y) + 10;
		y--;}
	x++;
	}
	
	SDL_RenderPresent(renderer); /* mettre ecran noir*/
	
	SDL_Delay(5000); /* 5secondes d'attente avant de se fermer, PLUS TARD BOUCLE INFINI */
	
	/*POSE----------------------------------------------------------*/
	
	
	
 
	
	
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return EXIT_SUCCESS;
}


/*void cercle(SDL_Renderer *renderer,int cx, int cy, int rayon)
{
  int d, y, x;
 
  d = 3 - (2 * rayon);
  x = 0;
  y = rayon;
 
  while (y >= x) {
  	SDL_RenderDrawPoint(renderer,cx+x,cy+y) ;/*dessiner un point , parametre : rendu, coordonnées x et y
  	SDL_RenderDrawPoint(renderer,cx+y,cy+x) ;/*dessiner un point , parametre : rendu, coordonnées x et y  
  	SDL_RenderDrawPoint(renderer,cx-x,cy+y) ;/*dessiner un point , parametre : rendu, coordonnées x et y  
  	SDL_RenderDrawPoint(renderer,cx-y,cy+x) ;/*dessiner un point , parametre : rendu, coordonnées x et y  
  	SDL_RenderDrawPoint(renderer,cx+x,cy-y) ;/*dessiner un point , parametre : rendu, coordonnées x et y
  	SDL_RenderDrawPoint(renderer,cx+y,cy-x) ;/*dessiner un point , parametre : rendu, coordonnées x et y
  	SDL_RenderDrawPoint(renderer,cx-x,cy-y) ;/*dessiner un point , parametre : rendu, coordonnées x et y
  	SDL_RenderDrawPoint(renderer,cx-y,cy-x) ;/*dessiner un point , parametre : rendu, coordonnées x et y
	if (d < 0)
      {d = d + (4 * x) + 6;};
	if (d>=0)
      {d = d + 4 * (x - y) + 10;
      y--;
    }
 
    x++;
  }
}

/* ne pas compiler avec makefile mais ecrire [ gcc exo2.c $(sdl2-config --cflags --libs) -o prog ] puis compiler ./prog */

void SDL_ExitWithError(const char *message)
{
	SDL_Log("ERREUR : %s > %s\n",message,SDL_GetError());
	SDL_Quit();
		exit(EXIT_FAILURE);
}

