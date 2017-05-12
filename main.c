
/* _____________________________________________________________________________________________________

    Exercice : créer un Pong en C avec la SDL, à rendre le 12/05/2017

    Ludus Académie - F2A - Maxime Dorffer

    ** Le jeu ne fonctionne pas, ce n'est encore qu'un brouillon, malheureusement.

_________________________________________________________________________________________________________*/


/********************************************************************************************************
BUT : Créer un jeu de pong a
ENTREES : Librairie SDL, inputs Haut et Bas de deux joueurs
SORTIE : le jeu fonctionnel, les raquettes se déplacent verticalement

*********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>                   // on utilise la librairie SDL2
#include <time.h>                       // un timer pour le jeu

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 780


typedef struct game{                    // structures SDL


     SDL_Window *g_pWindow;
     SDL_Renderer *g_pRenderer;
     SDL_Texture *g_ptexture;
     SDL_Surface *g_psurface;

}game;

typedef struct gameState{               // renvoie l'état du jeu

    int g_bRunning;


}gameState;

typedef struct coordonnees {            // met en place les coordonnées

    double x;
    double y;

} coordonnees;



//-----------------------------------------------------------------------------------------------PROTOTYPES


int init(char *title, int xpos,int ypos,int width,int height,int flags,game *myGame);
void destroy(game *myGame);
void handleEvents(gameState *state,coordonnees *dep,coordonnees *dep2);                 // gère les événements. utilisateurs...
void delay(unsigned int frameLimit);                                                    // gérer les FPS

void render(game *myGame);
void drawInRenderer(game *myGame);
void drawInSurface(game *myGame);
void renderTexture(game *myGame,coordonnees *dep,coordonnees *dep2);



//-------------------------------------------------------------------------------------------------PROGRAMME PRINCIPAL

int main(int argc, char *argv[])
{
     game myGame;
     gameState state;
    //Pour les 60 fps
    unsigned int frameLimit = SDL_GetTicks() + 16;
     coordonnees dep;
     coordonnees dep2;
     int choix=0;
     state.g_bRunning=1;
        //Create texture for drawing in texture or load picture
        myGame.g_ptexture=SDL_CreateTexture(myGame.g_pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,SCREEN_WIDTH,SCREEN_HEIGHT);
        while(state.g_bRunning){
                if(choix==0){
                    printf("1:Joueur au pong\n");
                    scanf("%i",&choix);
                }
                switch (choix){
                        case 1:
                                init("Pong",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&myGame);
                                render(&myGame);choix=0;
                                break;
                                {
                                    handleEvents(&state,&dep,&dep2);
                                    renderTexture(&myGame,&dep,&dep2);
                                }
                        default:break;
                }
                 system ("cls");
             // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
            delay(frameLimit);
            frameLimit = SDL_GetTicks() + 16;
        }
        destroy(&myGame);

        SDL_Quit();

    return 0;
}

//-------------------------------------------------------------------------------------------FONCTIONS ET PROCEDURES

/********************************************************************
BUT : INIT de SDL
ENTREES : titre, position fenetre, hauteur, largeur,flags gameObject
SORTIE : SDL init

*********************************************************************/


int init(char *title, int xpos,int ypos,int width, int height,int flags,game *myGame){

    myGame->g_pWindow=NULL;
    myGame->g_pRenderer=NULL;
    myGame->g_psurface=NULL;
    myGame->g_ptexture=NULL;

    //initialize SDL

    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
    {
            //if succeeded create our window
            myGame->g_pWindow=SDL_CreateWindow(title,xpos,ypos,width,height,flags);
            //if succeeded create window, create our render
            if(myGame->g_pWindow!=NULL){
                myGame->g_pRenderer=SDL_CreateRenderer(myGame->g_pWindow,-1,SDL_RENDERER_PRESENTVSYNC);
            }
    }else{
        return 0;
    }
    return 1;
}

/********************************************************************
BUT : GESTION des events (input=>clavier)
ENTREES : gameStateObject
SORTIE : state
*********************************************************************/


void handleEvents(gameState *state){
Joueur 1 direction haut

    SDL_Event event; //gestion evenements

    if(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT: //ex clic croix
              state->g_bRunning=0;break;

        case SDL_KEYDOWN://pression sur touche clavier
                        switch (event.key.keysym.sym)
                            {
                                case SDLK_Z:  ; break; //Joueur 1 direction haut
                                case SDLK_S: ; break; // Joueur 1 direction bas
                                case SDLK_UP:    ; break; //Joueur 2 direction haut
                                case SDLK_DOWN:  ; break; //Joueur 2 direction bas
                            }
                            break;

        case SDL_KEYUP://pression sur touche clavier
                        switch (event.key.keysym.sym)
                            {
                                case SDLK_Z:  ; break; //Joueur 1 direction haut
                                case SDLK_S: ; break; // Joueur 1 direction bas
                                case SDLK_UP:    ; break; //Joueur 2 direction haut
                                case SDLK_DOWN:  ; break; //Joueur 2 direction bas
                            }
                            break;
        default:break;
        }
    }
}

/********************************************************************
BUT : GESTION FrameRate 60fps(1 images/16ms => (1/60fps)*1000 =16.67ms)
ENTREES : FrameLimit
SORTIE : Delay=>frameLimit
*********************************************************************/

void render(game *myGame){

        SDL_RenderPresent(myGame->g_pRenderer);

         SDL_Rect terrain1;
         SDL_Rect terrain2;
         SDL_Rect terrain3;
         SDL_Rect terrain4;
         SDL_Rect terrain5;
         SDL_Rect terrain6;
         SDL_Rect terrain7;
         SDL_Rect terrain8;


         //Affichage du terrain

        SDL_SetRenderDrawColor(myGame->g_pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(myGame->g_pRenderer);

        SDL_SetRenderDrawColor(myGame->g_pRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

        terrain1.x=512;     // X commence
        terrain1.y=5;       // Y commence
        terrain1.w=10;      //Largeur
        terrain1.h=50;      //Hauteur


        //Affichage dans fenêtre
        SDL_RenderPresent(myGame->g_pRenderer);

        terrain2.x=512;     // X commence
        terrain2.y=100;      // Y commence
        terrain2.w=10;      // Largeur
        terrain2.h=50;      // Hauteur


        //rectangle plein
        SDL_RenderFillRect(myGame->g_pRenderer,&terrain2);


        terrain3.x=512;     // X commence
        terrain3.y=200;      // Y commence
        terrain3.w=10;      //Largeur
        terrain3.h=50;      //Hauteur


        //rectangle plein
        SDL_RenderFillRect(myGame->g_pRenderer,&terrain3);

        terrain4.x=512;     // X commence
        terrain4.y=300;      // Y commence
        terrain4.w=10;      //Largeur
        terrain4.h=50;      //Hauteur


        //rectangle plein
        SDL_RenderFillRect(myGame->g_pRenderer,&terrain4);


        terrain5.x=512;     // X commence
        terrain5.y=400;       // Y commence
        terrain5.w=10;      //Largeur
        terrain5.h=50;       //Hauteur


        //rectangle plein
        SDL_RenderFillRect(myGame->g_pRenderer,&terrain5);


        terrain6.x=512;     // X commence
        terrain6.y=500;       // Y commence
        terrain6.w=10;      //Largeur
        terrain6.h=50;      //Hauteur

        //rectangle plein
        SDL_RenderFillRect(myGame->g_pRenderer,&terrain6);


        terrain7.x=512;     // X commence
        terrain7.y=600;       // Y commence
        terrain7.w=10;       //Largeur
        terrain7.h=50;       //Hauteur


        //rectangle plein
        SDL_RenderFillRect(myGame->g_pRenderer,&terrain7);


        terrain8.x=512;     // X commence
        terrain8.y=700;       // Y commence
        terrain8.w=10;      //Largeur
        terrain8.h=50;       //Hauteur

        //rectangle plein
        SDL_RenderFillRect(myGame->g_pRenderer,&terrain8);

    SDL_Delay(4000);

    destroy(myGame);

}

void drawInSurface(game *myGame){

    myGame->g_psurface = SDL_CreateRGBSurface(100, 100, 400, 32 , 0, 0, 0, 0); //on crée la surface

    SDL_FillRect(myGame->g_psurface, NULL, SDL_MapRGB(mygame->g_psurface->format, 255, 0, 0)); // on remplit en rouge

    SDL_Texture *texture_tampon = SDL_CreateTextureFromSurface(myGame->g_pRenderer, myGame->g_psurface); // on crée une texture

    SDL_SetRenderTarget(myGame->g_pRenderer, texture_tampon);

    SDL_Rect position;
    position.x = 0;
    position.y = 0;
    SQL_QueryTexture(texture_tampon, NULL, NULL, &position.w, &position.h); //la ou je passe ma texture avec ses positions x et y
    SQL_RenderCopy(myGame->g_pRenderer,texture_tampon,NULL,&position);

    SDL_RenderPresent(myGame->g_pRenderer); //à mettre une seule fois

    SDL_Delay(4000); // 4 sec

    destroy (myGame);

}

void drawInRenderer(game *myGame){          //dessiner dans le renderer

    //Definition du rectangle à dessiner
    SDL_Rect rectangle;

    SDL_SetRenderDrawColor(myGame->g_pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(myGame->g_pRenderer);

    SDL_SetRenderDrawColor(myGame->g_pRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    //Triangle
    SDL_RenderDrawLines(myGame->g_pRenderer, 320, 200, 300, 240);
    SDL_RenderDrawLines(myGame->g_pRenderer, 320, 200, 300, 240);
    SDL_RenderDrawLines(myGame->g_pRenderer, 320, 200, 300, 240);

    rectangle.x=100;    //debut x
    rectangle.y=100;    //debut y
    rectangle.w=10;    //Largeur
    rectangle.h=100;    //Hauteur

    //rectangle vide
    SDL_RenderDrawRect(myGame->g_pRenderer,&rectangle);

    rectangle.x=0;      //debut x
    rectangle.y=0;      //debut y
    rectangle.w=0;      //Largeur
    rectangle.h=0;      //Hauteur

    //rectangle plein
    SDL_RenderFillRect(myGame->g_pRenderer,&rectangle);

    SDL_Delay(4000);

    destroy(myGame);


}

void renderTexture(game *myGame,coordonnees *dep,coordonnees *dep2 ) {

       //Définition du rectangle 1 a dessiner
        SDL_Rect rectangle;
        rectangle.x=0;//debut x
        rectangle.y=dep->y;//debut y
        rectangle.w=10; //Largeur
        rectangle.h=100; //Hauteur


        //Définition du rectangle 2 a dessiner
        SDL_Rect rectangle2;
        rectangle2.x=SCREEN_WIDTH-10;//debut x
        rectangle2.y=dep2->y;//debut y
        rectangle2.w=10; //Largeur
        rectangle2.h=100; //Hauteur


        //Draw in texture
        SDL_SetRenderDrawColor(myGame->g_pRenderer,255,0,0,255);
        SDL_SetRenderTarget(myGame->g_pRenderer, myGame->g_ptexture); //on modifie la texture

        SDL_RenderFillRect(myGame->g_pRenderer, &rectangle);
        SDL_RenderFillRect(myGame->g_pRenderer, &rectangle2);

        SDL_SetRenderTarget(myGame->g_pRenderer, NULL);// Dorénavent, on modifie à nouveau le renderer

        SDL_Rect position;//position de la texture dans screen
        position.x = 0;
        position.y = 0;
        SDL_QueryTexture(myGame->g_ptexture, NULL, NULL, &position.w, &position.h);
        SDL_RenderCopy(myGame->g_pRenderer,myGame->g_ptexture,NULL,&position);


         SDL_RenderPresent(myGame->g_pRenderer);

         SDL_SetRenderDrawColor(myGame->g_pRenderer,0,0,0,255);
         SDL_DestroyTexture(myGame->g_ptexture);
         SDL_RenderClear(myGame->g_pRenderer);

}


void delay(unsigned int frameLimit){

    // Gestion des 60 fps (images/seconde)
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {Joueur 1 direction haut
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}


/********************************************************************
BUT : Destruction de la SDL
ENTREES : GameObject
SORTIE : SDL Destroy
*********************************************************************/

void destroy(game *myGame){


    //Destruction texture
    if(myGame->g_ptexture!=NULL)
            SDL_DestroyTexture(myGame->g_ptexture);


    //Destuction du rendu
    if(myGame->g_pRenderer!=NULL)
           SDL_DestroyRenderer(myGame->g_pRenderer);


    //Destruction fenetre
    if(myGame->g_pWindow!=NULL)
        SDL_DestroyWindow(myGame->g_pWindow);

}
