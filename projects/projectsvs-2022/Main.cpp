
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                                                             *
 *  Este código es de dominio público.                                         *
 *  angel.rodriguez@esne.edu                                                   *
 *  2015.04                                                                    *
 *                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <SDL.h>
#include <ciso646>

int main(int, char**)
{
    // Se hace inicializa SDL:

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Log("No se ha podido inicializar SDL2.");
    }
    else
    {
        // Se crea una ventana:

        SDL_Window* window = SDL_CreateWindow("SDL2 Window Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

        if (not window)
        {
            SDL_Log("No se ha podido crear una ventana.");
        }
        else
        {
            // Se toma el buffer de la ventana para dibujar en él:

            SDL_Surface* surface = SDL_GetWindowSurface(window);

            if (not surface)
            {
                SDL_Log("No se ha podido acceder al buffer de la ventana.");
            }
            else
            {
                bool exit = false;

                do
                {
                    // Se procesan los eventos acumulados:

                    SDL_Event event;

                    while (SDL_PollEvent(&event) > 0)
                    {
                        if (event.type == SDL_QUIT)
                        {
                            exit = true;
                        }
                    }

                    // Se rellena el fondo de la ventana de color gris:

                    SDL_FillRect(surface, 0, SDL_MapRGB(surface->format, 225, 225, 225));

                    SDL_UpdateWindowSurface(window);
                } while (!exit);
            }

            SDL_DestroyWindow(window);
        }

        SDL_Quit();
    }

    return 0;
}
