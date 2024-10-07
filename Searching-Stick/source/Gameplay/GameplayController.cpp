#include "Gameplay/GameplayController.h"
#include "Gameplay/GameplayView.h"

void Gameplay::GameplayController::destroy()
{
	delete(gameplay_view);
}

Gameplay::GameplayController::GameplayController()
{
	gameplay_view = new GameplayView();
}

Gameplay::GameplayController::~GameplayController()
{
	destroy();
}

void Gameplay::GameplayController::initialize()
{
	gameplay_view->initialize(this);
}

void Gameplay::GameplayController::update()
{
	gameplay_view->update();
}

void Gameplay::GameplayController::render()
{
	gameplay_view->render();
}

void Gameplay::GameplayController::reset()
{
}
