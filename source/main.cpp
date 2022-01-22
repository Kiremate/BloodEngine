
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                                                             *
 *  Este código es de dominio público.                                         *
 *  angel.rodriguez@esne.edu                                                   *
 *  2015.04                                                                    *
 *                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <SDL.h>
#include <ciso646>
#include <SDL_opengl.h>

int main (int , char ** )
{
    const int window_width  = 800;
    const int window_height = 600;

    // Se hace inicializa SDL:

    if (SDL_Init (SDL_INIT_VIDEO) < 0)
    {
        SDL_Log ("No se ha podido inicializar SDL2.");
    }
    else
    {
        // Se preconfigura la versión de OpenGL deseada:

        SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 1);

        // Se crea una ventana:

        SDL_Window * window = SDL_CreateWindow
        (
           "SDL2 OpenGL Window Example",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            window_width,
            window_height,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
        );

        if (not window)
        {
            SDL_Log ("No se ha podido crear una ventana.");
        }
        else
        {
            // Se toma el buffer de la ventana para dibujar en él:

            SDL_GLContext gl_context = SDL_GL_CreateContext (window);

            if (not gl_context)
            {
                SDL_Log ("No se ha podido crear un contexto de OpenGL asociado a la ventana.");
            }
            else
            {
                // Se activa la sincronización vertical:

                SDL_GL_SetSwapInterval (1);

                // Se configura la matriz de proyección y el viewport:

                glMatrixMode   (GL_PROJECTION);
                glLoadIdentity ();
                glOrtho        (0, GLdouble(window_width), 0, GLdouble(window_height), +1, -1);
                glViewport     (0, 0, window_width, window_height);
                glMatrixMode   (GL_MODELVIEW);

                bool exit = false;

                do
                {
                    // Se procesan los eventos acumulados:

                    SDL_Event event;

                    while (SDL_PollEvent (&event) > 0)
                    {
                        if (event.type == SDL_QUIT)
                        {
                            exit = true;
                        }
                    }

                    // Se dibuja un triángulo:

                    glClear (GL_COLOR_BUFFER_BIT);

                    glLoadIdentity ();
                    glTranslatef   (400.f, 300.f, 0.f);

                    glBegin (GL_TRIANGLES);
                    {
                        glColor3f  (   1.f,    0.f, 0.f);
                        glVertex3f (-200.f, -200.f, 0.f);
                        glColor3f  (   0.f,    1.f, 0.f);
                        glVertex3f (+200.f, -200.f, 0.f);
                        glColor3f  (   0.f,    0.f, 1.f);
                        glVertex3f (   0.f,  200.f, 0.f);
                    }
                    glEnd ();

                    // Se actualiza el contenido de la ventana:

                    SDL_GL_SwapWindow (window);
                }
                while (!exit);

                SDL_GL_DeleteContext (gl_context);
            }

            SDL_DestroyWindow (window);
        }

        SDL_Quit ();
    }

    return 0;
}
