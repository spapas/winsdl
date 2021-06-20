#include <stdio.h>
#include <SDL.h>

int main(int argc, char** args) {
	SDL_Surface* winSurface = NULL;
	SDL_Window* window = NULL;
    //Main loop flag
    int quit = 0;

    //Event handler
    SDL_Event e;

	if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
		printf("Error initializing SDL: %s\n", SDL_GetError());
		return 1;
	} 

	window = SDL_CreateWindow( "Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN );
	if ( !window ) {
		printf("Error creating window: %s\n", SDL_GetError());
		return 1;
	}

	winSurface = SDL_GetWindowSurface( window );
	if ( !winSurface ) {
		printf( "Error getting surface: %s\n", SDL_GetError());
		return 1;
	}

	SDL_FillRect( winSurface, NULL, SDL_MapRGB( winSurface->format, 111, 222, 255 ) );
	SDL_UpdateWindowSurface( window );

	while( !quit )
            {
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = 1;
                    }
                    else if( e.type == SDL_KEYDOWN )
                    {
                        //Select surfaces based on key press
                        switch( e.key.keysym.sym )
                        {
                            case SDLK_q:
                            quit = 1;
                            break;
                        }
                    }
                }
            }

	SDL_DestroyWindow( window );
	SDL_Quit();
	
	return 0;
}