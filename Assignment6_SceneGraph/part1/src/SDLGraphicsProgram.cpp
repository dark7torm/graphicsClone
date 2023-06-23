#include "SDLGraphicsProgram.hpp"
#include "Camera.hpp"
#include "Terrain.hpp"
#include "Sphere.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

// Initialization function
// Returns a true or false value based on successful completion of setup.
// Takes in dimensions of window.
SDLGraphicsProgram::SDLGraphicsProgram(int w, int h){
	// Initialization flag
	bool success = true;
	// String to hold any errors that occur.
	std::stringstream errorStream;
	// The window we'll be rendering to
	m_window = NULL;

	// Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO)< 0){
		errorStream << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
		success = false;
	}
	else{
		//Use OpenGL 3.3 core
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
		// We want to request a double buffer for smooth updating.
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		//Create window
		m_window = SDL_CreateWindow( "Lab",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                w,
                                h,
                                SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );

		// Check if Window did not create.
		if( m_window == NULL ){
			errorStream << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
			success = false;
		}

		//Create an OpenGL Graphics Context
		m_openGLContext = SDL_GL_CreateContext( m_window );
		if( m_openGLContext == NULL){
			errorStream << "OpenGL context could not be created! SDL Error: " << SDL_GetError() << "\n";
			success = false;
		}

		// Initialize GLAD Library
		if(!gladLoadGLLoader(SDL_GL_GetProcAddress)){
			errorStream << "Failed to iniitalize GLAD\n";
			success = false;
		}

		//Initialize OpenGL
		if(!InitGL()){
			errorStream << "Unable to initialize OpenGL!\n";
			success = false;
		}
  	}

    // If initialization did not work, then print out a list of errors in the constructor.
    if(!success){
        errorStream << "SDLGraphicsProgram::SDLGraphicsProgram - Failed to initialize!\n";
        std::string errors=errorStream.str();
        SDL_Log("%s\n",errors.c_str());
    }else{
        SDL_Log("SDLGraphicsProgram::SDLGraphicsProgram - No SDL, GLAD, or OpenGL, errors detected during initialization\n\n");
    }

	// SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN); // Uncomment to enable extra debug support!
	GetOpenGLVersionInfo();


    // Setup our Renderer
    m_renderer = new Renderer(w,h);    
}


// Proper shutdown of SDL and destroy initialized objects
SDLGraphicsProgram::~SDLGraphicsProgram(){
    if(m_renderer!=nullptr){
        delete m_renderer;
    }


    //Destroy window
	SDL_DestroyWindow( m_window );
	// Point m_window to NULL to ensure it points to nothing.
	m_window = nullptr;
	//Quit SDL subsystems
	SDL_Quit();
}


// Initialize OpenGL
// Setup any of our shaders here.
bool SDLGraphicsProgram::InitGL(){
	//Success flag
	bool success = true;

	return success;
}

// ====================== Create the planets =============
// NOTE: I will admit it is a little lazy to have these as globals,
//       we could build on our ObjectManager structure to manage the
//       each object that is inserted and automatically create a 'SceneNode'
//       for it for example. Or otherwise, build a 'SceneTree' class that
//       manages creating nodes and setting their type.
//       (e.g. A good use of the Factory Design Pattern if you'd like to
//             invetigate further--but it is beyond the scope of this assignment).

// Create the Moon
Object* sphere3;
SceneNode* Moon;
// Create the Earth
Object* sphere2;
SceneNode* Earth;
// Create the Sun
Object* sphere;
SceneNode* Sun;

Object* sphere4;
SceneNode* Moon2;

Object* sphere5;
SceneNode* Moon3;

Object* sphere6;
SceneNode* Moon4;

Object* sphere7;
SceneNode* Moon5;

Object* sphere8;
SceneNode* Moon6;

Object* sphere9;
Object* sphere10;

SceneNode* Venus;

SceneNode* Mars;


// ====================== Create the planets =============

//Loops forever!
void SDLGraphicsProgram::Loop(){

    // ================== Initialize the planets ===============
    static float rotate = 0.0f;


    // Create the Sun
    sphere = new Sphere();
    sphere->LoadTexture("./../../common/textures/sun.ppm");
    Sun = new SceneNode(sphere);

    // Create the Earth
    sphere2 = new Sphere();
    sphere2->LoadTexture("./../../common/textures/earth.ppm");
    Earth = new SceneNode(sphere2);


    sphere3 = new Sphere();
    sphere3->LoadTexture("./../../common/textures/rock.ppm");
    Moon = new SceneNode(sphere3);

    sphere4 = new Sphere();
    sphere4->LoadTexture("./../../common/textures/mercury.ppm");
    Mars = new SceneNode(sphere4);

    sphere5 = new Sphere();
    sphere5->LoadTexture("./../../common/textures/planet.ppm");
    Venus = new SceneNode(sphere5);

    sphere6 = new Sphere();
    sphere6->LoadTexture("./../../common/textures/rock.ppm");
    Moon2 = new SceneNode(sphere6);

    sphere7 = new Sphere();
    sphere7->LoadTexture("./../../common/textures/rock.ppm");
    Moon3 = new SceneNode(sphere7);

    sphere8 = new Sphere();
    sphere8->LoadTexture("./../../common/textures/rock.ppm");
    Moon4 = new SceneNode(sphere8);

    sphere9 = new Sphere();
    sphere9->LoadTexture("./../../common/textures/rock.ppm");
    Moon5 = new SceneNode(sphere9);

    sphere10 = new Sphere();
    sphere10->LoadTexture("./../../common/textures/rock.ppm");
    Moon6 = new SceneNode(sphere10);

    sphere3 = new Sphere();
    sphere3->LoadTexture("./../../common/textures/rock.ppm");

    Moon = new SceneNode(sphere3);

    
    

    

    
    

    // Render our scene starting from the sun.
    m_renderer->setRoot(Sun);
    // Make the Earth a child of the Sun
    Sun->AddChild(Earth);
    Sun->AddChild(Venus);
    Sun->AddChild(Mars);
    // Make the Moon a child of the Earth
    Earth->AddChild(Moon);
    Earth->AddChild(Moon2);
    Venus->AddChild(Moon3);
    Venus->AddChild(Moon4);
    Mars->AddChild(Moon5);
    Mars->AddChild(Moon6);

    
    // Set a default position for our camera
    m_renderer->GetCamera(0)->SetCameraEyePosition(0.0f,0.0f,20.0f);

    // Main loop flag
    // If this is quit = 'true' then the program terminates.
    bool quit = false;
    // Event handler that handles various events in SDL
    // that are related to input and output
    SDL_Event e;
    // Enable text input
    SDL_StartTextInput();

    // Set the camera speed for how fast we move.
    float cameraSpeed = 5.0f;

    // While application is running
    while(!quit){

        //Handle events on queue
        while(SDL_PollEvent( &e ) != 0){
            // User posts an event to quit
            // An example is hitting the "x" in the corner of the window.
            if(e.type == SDL_QUIT){
                quit = true;
            }
            // Handle keyboard input for the camera class
            if(e.type==SDL_MOUSEMOTION){
                // Handle mouse movements
                int mouseX = e.motion.x;
                int mouseY = e.motion.y;
//              m_renderer->GetCamera(0)->MouseLook(mouseX, mouseY);
            }
            switch(e.type){
                // Handle keyboard presses
                case SDL_KEYDOWN:
                    switch(e.key.keysym.sym){
                        case SDLK_LEFT:
                            m_renderer->GetCamera(0)->MoveLeft(cameraSpeed);
                            break;
                        case SDLK_RIGHT:
                            m_renderer->GetCamera(0)->MoveRight(cameraSpeed);
                            break;
                        case SDLK_UP:
                            m_renderer->GetCamera(0)->MoveForward(cameraSpeed);
                            break;
                        case SDLK_DOWN:
                            m_renderer->GetCamera(0)->MoveBackward(cameraSpeed);
                            break;
                        case SDLK_RSHIFT:
                            m_renderer->GetCamera(0)->MoveUp(cameraSpeed);
                            break;
                        case SDLK_RCTRL:
                            m_renderer->GetCamera(0)->MoveDown(cameraSpeed);
                            break;
                    }
                break;
            }
        } // End SDL_PollEvent loop.
        // ================== Use the planets ===============
        // TODO:
        //      After the planets have been created, and the hierarchy
        //      has been made, you can transform them.
        //      Note, you'll need to setup the scene graph world/local
        //      transformation correctly first before the planets are shown.
        //      
        //      The 'Sun' for example will be the only object shown initially
        //      since the rest of the planets are children (or grandchildren)
        //      of the Sun.
        static float orbitEarth = 0.001f;
        orbitEarth += 0.004;

        static float orbitEAxis = 0.001f;
        orbitEAxis += 0.001;

        static float orbitMoon = 0.0005f;
        orbitMoon += 0.005;

        static float orbitMars = 0.001f;
        orbitMars += 0.002;

        static float orbitMAxis = 0.001f;
        orbitMAxis += 0.001;

        static float orbitVenus = 0.001f;
        orbitVenus += 0.006;

        static float orbitVAxis = 0.001f;
        orbitVAxis += 0.001;

        
    






        Sun->GetLocalTransform().LoadIdentity();	
        Sun->GetLocalTransform().Rotate(0.5 * orbitEAxis, 0, 1, 0);
        Sun->GetLocalTransform().Scale(3, 3, 3);

	
    
        // ... transform the Sun

        


        // ... transform the Moon

        Earth->GetLocalTransform().LoadIdentity();	
        Earth->GetLocalTransform().Rotate(0.5 * orbitEarth, 0, 1, 0);
        Earth->GetLocalTransform().Translate(5, 0, 0);
        Earth->GetLocalTransform().Rotate(orbitEAxis, 0, 1, 0);
        Earth->GetLocalTransform().Scale(0.3, 0.3, 0.3);

        Mars->GetLocalTransform().LoadIdentity();	
        Mars->GetLocalTransform().Rotate(0.5 * orbitMars, 0, 1, 0);
        Mars->GetLocalTransform().Translate(7, 0, 0);
        Mars->GetLocalTransform().Rotate(orbitMAxis, 0, 1, 0);
        Mars->GetLocalTransform().Scale(0.4, 0.4, 0.4);

        Venus->GetLocalTransform().LoadIdentity();	
        Venus->GetLocalTransform().Rotate(0.5 * orbitVenus, 0, 1, 0);
        Venus->GetLocalTransform().Translate(3, 0, 0);
        Venus->GetLocalTransform().Rotate(orbitVAxis, 0, 1, 0);
        Venus->GetLocalTransform().Scale(0.2, 0.2, 0.2);

        Moon->GetLocalTransform().LoadIdentity();	
        Moon->GetLocalTransform().Rotate(0.5 * orbitMoon, 0, 1, 0);
        Moon->GetLocalTransform().Translate(2, 0, 0);
        Moon->GetLocalTransform().Rotate(orbitEAxis, 0, 1, 0);
        Moon->GetLocalTransform().Scale(0.5, 0.5, 0.5);

        Moon2->GetLocalTransform().LoadIdentity();	
        Moon2->GetLocalTransform().Rotate(0.75 * orbitMoon, 0, 1, 0);
        Moon2->GetLocalTransform().Translate(3, 0, 0);
        Moon2->GetLocalTransform().Rotate(orbitEAxis, 0, 1, 0);
        Moon2->GetLocalTransform().Scale(0.4, 0.4, 0.4);

        Moon3->GetLocalTransform().LoadIdentity();	
        Moon3->GetLocalTransform().Rotate(0.5 * orbitMoon, 0, 1, 0);
        Moon3->GetLocalTransform().Translate(2, 0, 0);
        Moon3->GetLocalTransform().Rotate(orbitVAxis, 0, 1, 0);
        Moon3->GetLocalTransform().Scale(0.5, 0.5, 0.5);

        Moon4->GetLocalTransform().LoadIdentity();	
        Moon4->GetLocalTransform().Rotate(0.8 * orbitMoon, 0, 1, 0);
        Moon4->GetLocalTransform().Translate(4, 0, 0);
        Moon4->GetLocalTransform().Rotate(orbitVAxis, 0, 1, 0);
        Moon4->GetLocalTransform().Scale(0.3, 0.3, 0.3);

        Moon5->GetLocalTransform().LoadIdentity();	
        Moon5->GetLocalTransform().Rotate(0.5 * orbitMoon, 0, 1, 0);
        Moon5->GetLocalTransform().Translate(2, 0, 0);
        Moon5->GetLocalTransform().Rotate(orbitMAxis, 0, 1, 0);
        Moon5->GetLocalTransform().Scale(0.5, 0.5, 0.5);

        Moon6->GetLocalTransform().LoadIdentity();	
        Moon6->GetLocalTransform().Rotate(0.6 * orbitMoon, 0, 1, 0);
        Moon6->GetLocalTransform().Translate(1, 0, 0);
        Moon6->GetLocalTransform().Rotate(orbitMAxis, 0, 1, 0);
        Moon6->GetLocalTransform().Scale(0.25, 0.25, 0.25);
        // ... transform the Earth        

        // Update our scene through our renderer
        m_renderer->Update();
        // Render our scene using our selected renderer
        m_renderer->Render();
        // Delay to slow things down just a bit!
        SDL_Delay(25);  // TODO: You can change this or implement a frame
                        // independent movement method if you like.
      	//Update screen of our specified window
      	SDL_GL_SwapWindow(GetSDLWindow());
	}
    //Disable text input
    SDL_StopTextInput();
}


// Get Pointer to Window
SDL_Window* SDLGraphicsProgram::GetSDLWindow(){
  return m_window;
}

// Helper Function to get OpenGL Version Information
void SDLGraphicsProgram::GetOpenGLVersionInfo(){
	SDL_Log("(Note: If you have two GPU's, make sure the correct one is selected)");
	SDL_Log("Vendor: %s",(const char*)glGetString(GL_VENDOR));
	SDL_Log("Renderer: %s",(const char*)glGetString(GL_RENDERER));
	SDL_Log("Version: %s",(const char*)glGetString(GL_VERSION));
	SDL_Log("Shading language: %s",(const char*)glGetString(GL_SHADING_LANGUAGE_VERSION));
}
