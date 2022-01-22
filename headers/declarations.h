#pragma once
#include <pplwin.h>



///////////////////////////////////////// THREAD POOL

typedef class thread_pool thread_pool;
typedef std::uint_fast32_t ui32;
typedef std::uint_fast64_t ui64;
ui64 get_tasks_queued() ;

////////////////////////////////////////////////////// SDL///////////////
typedef struct SDL_Window SDL_Window;
typedef void* SDL_GLContext;

/////////////////////////// OPENGL Toolkit
namespace glt {
	class Render_Node;
}