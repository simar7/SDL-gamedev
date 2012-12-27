#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

// Screen attributes, now in 16:9 aspect ratio
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define SCREEN_BPP 32

SDL_Surface *image = NULL;
SDL_Surface *screen = NULL;

// Event struct
SDL_Event event;

SDL_Surface *load_image( std::string filename )
{
    SDL_Surface *loadedImage = NULL;
    SDL_Surface *optimizedImage = NULL;

    loadedImage = IMG_Load( filename.c_str() );
    
    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        SDL_FreeSurface( loadedImage );
    }
    else
    {
        return NULL;
    }
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface *source, SDL_Surface *destination )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, NULL, destination, &offset );
}

bool init()
{
    if( SDL_Init(SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    
    if( screen == NULL )
    {
        return false;
    }

    SDL_WM_SetCaption( "Event handler application", NULL );
    
    return true;
}

bool load_files()
{
    image = load_image( "psy.png" );

    if( image == NULL )
    {
        return false;
    }
    
    return true;
}

void cleanup()
{
    SDL_FreeSurface( image );
    SDL_Quit();
}

int main( int argc, char *argv[] ) 
{
    bool quit = false;

    if( !init() )
    {
        return 1;
    }

    if( !load_files() )
    {
        return 1;
    }

    apply_surface( 0, 0, image, screen );
    
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }
        
    while(!quit)
    {
      while( SDL_PollEvent( &event )
      {
        if( event.type == SDL_QUIT )  // if the user decides to exit out..
        {
            quit = true;
        }
        cleanup();
        return 0;
     }
    }
return 0;
}  
