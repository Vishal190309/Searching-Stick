
#include "../include/Gameplay/GameplayService.h"
#include "../include/Gameplay/GameplayController.h"
#include "../include/Gameplay/StickCollection/StickCollectionContoller.h"`
namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
		collection_controller = new StickCollectionContoller();
	}

	GameplayService::~GameplayService()
	{
		delete(gameplay_controller);
		delete(collection_controller);
	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
		collection_controller->initialize();
	}

	void GameplayService::update()
	{
		gameplay_controller->update();
		collection_controller->update();
	}

	void GameplayService::render()
	{
		gameplay_controller->render();
		collection_controller->render();
	}

	void GameplayService::reset()
	{
	}
	void GameplayService::searchElement(Collection::SearchType search_type)
	{
	}
	Collection::SearchType GameplayService::getCurrentSearchType()
	{
		return Collection::SearchType();
	}
	int GameplayService::getNumberOfSticks()
	{
		return 0;
	}
}