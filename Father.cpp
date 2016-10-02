/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
#include "s3e.h"
#include "IwDebug.h"

#include "Iw2D.h"

#include "engine/Engine.h"
#include "engine/MoveSystem.h"
#include "engine/RenderSystem.h"

class Application
{
private:
	Engine* engine;

public:
	void Init()
	{
		engine = new Engine;
		engine->AddSystem(new RenderSystem);
		engine->AddSystem(new MoveSystem);

		auto entity = new IEntity;

		auto transform = new TransformComponent;
		transform->SetPosition(100, 100);
		transform->SetScale(15);
		entity->AddComponent(transform);

		auto display = new DisplayComponent;
		display->SetTransform(transform);
		display->SetImage(Iw2DCreateImage("PackMan.png"));
		entity->AddComponent(display);

		auto velocity = new VelocityComponent;
		velocity->SetTransform(transform);
		velocity->SetAngle(70);
		entity->AddComponent(velocity);

		engine->AddEntity(entity);
	}

	void Update(float time)
	{
		engine->Update(time);
	}
};
// Main entry point for the application
int main()
{
    //Initialise graphics system(s)
	Iw2DInit();

	Application* app = new Application;
	app->Init();

    // Loop forever, until the user or the OS performs some action to quit the app
    while (!s3eDeviceCheckQuitRequest())
    {       
        // Your rendering/app code goes here.
		Iw2DSurfaceClear(0xff000080);

		app->Update(0.04f);

		Iw2DSurfaceShow();

        // Sleep for 0ms to allow the OS to process events etc.
        s3eDeviceYield(0);
    }

	delete app;

    //Terminate modules being used
	Iw2DTerminate();

    // Return
    return 0;
}
