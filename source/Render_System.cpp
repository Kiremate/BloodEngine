#include "..\headers\Render_System.h"
#include <Render_Node.hpp>

bool blood_engine::Render_System::CreateRenderComponent()
{
	return false;
}

void blood_engine::Render_System::Render()
{
	for (;;) {
        // Se ajusta el viewport por si el tamaño de la ventana ha cambiado:

       // GLsizei width = GLsizei(window->get_width());
       // GLsizei height = GLsizei(window->get_height());

        renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

        glViewport(0, 0, width, height);

        // Se rota el objeto:

        auto cube = renderer->get("cube");

        cube->rotate_around_x(0.01f);
        cube->rotate_around_y(0.02f);
        cube->rotate_around_z(0.03f);

        // Se renderiza la escena y se intercambian los buffers de la ventana para
        // hacer visible lo que se ha renderizado:

        window->clear();

        renderer->render();

        window->swap_buffers();
	}

}
