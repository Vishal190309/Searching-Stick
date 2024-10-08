#pragma once
#include <SFML/System/String.hpp>
#include "Gameplay/StickCollection/StickCollectionModel.h"
#include "Gameplay/StickCollection/StickCollectionContoller.h"

namespace Gameplay
{
	using namespace Collection;
	class GameplayController;
	enum class SearchType;

	class GameplayService
	{
	private:
		GameplayController* gameplay_controller;
		StickCollectionContoller* collection_controller;


	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();

		void reset();
		void searchElement(Collection::SearchType search_type);

		Collection::SearchType getCurrentSearchType();

		int getNumberOfSticks();

		void initializeRandomSeed();

	};
}