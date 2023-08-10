# BloodEngine
BloodEngine repository
@author Bloodmask
BloodEngine
The BloodEngine is a game engine created using C++ and SDL2 as a college project. It follows the Entity/Components/Systems (ECS) architecture and is designed to be flexible and extensible.
 
C++ version --> ISO C++17 Standard (/std:c++17)

Kernel
The kernel is the core of the engine, responsible for creating and managing the various subsystems, such as the render system, physics system, and input system. It also manages the lifecycle of the engine, including initializing and shutting down the various subsystems.

Scenes
Scenes are the primary container for game objects in the engine. Each scene contains a collection of entities, which are made up of various components such as renderable, physics, and audio components. The kernel is responsible for managing the scenes, including loading and unloading them as needed.

Entities and Components
Entities are the basic building blocks of the engine and represent game objects in the scene. They are composed of various components, such as a renderable component, a physics component, and an audio component. Each component is responsible for a specific aspect of the entity, such as rendering, physics, and audio.

Systems
The systems within the engine are responsible for handling specific functionality, such as rendering, physics, audio, and input. Each system is designed to handle a specific set of tasks and is implemented as a separate class.

    Render_System
    The render system is responsible for rendering the game objects in the scene. It uses SDL2 for rendering and is responsible for creating and managing the window and OpenGL context.

    Physics_System
    The physics system is responsible for simulating physics in the scene. It uses the Box2D physics engine and is responsible for updating the physics simulation and handling collision events.

    Audio_System
    The audio system is responsible for playing audio in the scene. It uses the OpenAL library and is responsible for creating and managing audio sources and buffers.

    Input_System
    The input system is responsible for handling input from the user. It uses SDL2 for input handling and is responsible for processing input events and updating the input state.

    Message_System
    The message system is responsible for handling messages between the different systems, entities and components of the engine. It uses a message queue to store the messages and a map to register the observers that are in charge of handling the messages.


Overall, the BloodEngine is designed to be flexible and easily extensible, allowing developers to add new systems, entities, and components as needed to create their own unique game experiences.