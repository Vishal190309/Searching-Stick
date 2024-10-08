#include "Global/ServiceLocator.h"
#include "Main/GameService.h"

namespace Global
{
	using namespace Graphics;
	using namespace Event;
	using namespace Sound;
	using namespace Gameplay;
	using namespace UI;
	using namespace Main;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		gameplay_service = nullptr;
		event_service = nullptr;
		sound_service = nullptr;
		ui_service = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator() { clearAllServices(); }

	void ServiceLocator::createServices()
	{
		event_service = new EventService();
		graphic_service = new GraphicService();
		gameplay_service = new GameplayService();
		sound_service = new SoundService();
		ui_service = new UIService();
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		gameplay_service->initialize();
		sound_service->initialize();
		event_service->initialize();
		ui_service->initialize();
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();
		switch (GameService::getGameState())
		{
		case GameState::GAMEPLAY:
			gameplay_service->update();
		default:
			break;
		}
		ui_service->update();
	}

	void ServiceLocator::render()
	{
		ui_service->render();
		graphic_service->render();
		switch (GameService::getGameState())
		{
		case GameState::GAMEPLAY:
			gameplay_service->render();
		default:
			break;
		}
	}

	void ServiceLocator::clearAllServices()
	{
		delete(ui_service);
		delete(graphic_service);
		delete(gameplay_service);
		delete(sound_service);
		delete(event_service);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	EventService* ServiceLocator::getEventService() { return event_service; }

	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

	Gameplay::GameplayService* ServiceLocator::getGameplayService()
	{
		return gameplay_service;
	}

	SoundService* ServiceLocator::getSoundService() { return sound_service; }

	UIService* ServiceLocator::getUIService() { return ui_service; }

	
}