
//#include <cstdlib>
//
//#include "Game.h"
//
//
//Game::Game(RenderWindow window)
//{
//		window.setFramerateLimit(60);
//		GameState = Start;
//
//}
//void Game::GameInit(RenderWindow window,int choice)
//{
//	Font font;
//	font.loadFromFile("Fonts/Amatic-Bold.ttf");
//
//	//Init textures
//	Texture playerTex;
//	playerTex.loadFromFile("Textures/ship.png");
//
//	Texture enemyTex;
//	enemyTex.loadFromFile("Textures/enemy.png");
//
//	Texture bulletTex;
//	bulletTex.loadFromFile("Textures/missile.png");
//	Texture backgroundtex;
//	backgroundtex.loadFromFile("Textures/space.png");
//	Sprite background(backgroundtex);
//	background.setPosition(0, 0);
//	background.setScale(3.f, 3.f);
//	//UI init
//	Text scoreText;
//	scoreText.setFont(font);
//	scoreText.setCharacterSize(20);
//	scoreText.setFillColor(Color::White);
//	scoreText.setPosition(5.f, 5.f);
//
//	Text gameOverText;
//	gameOverText.setFont(font);
//	gameOverText.setCharacterSize(50);
//	gameOverText.setFillColor(Color::Red);
//	gameOverText.setPosition(window.getSize().x / 2, window.getSize().y / 2);
//	gameOverText.setString("Try Again");
//
//	//Player init
//	int x;
//	int score = 0;
//	Player player(&playerTex);
//	int shootTimer = 20;
//	Text hpText;
//	hpText.setFont(font);
//	hpText.setCharacterSize(12);
//	hpText.setFillColor(Color::White);
//
//	//Enemy init
//	int enemySpawnTimer = 0;
//	std::vector<Enemy> enemies;
//
//	Text eHpText;
//	eHpText.setFont(font);
//	eHpText.setCharacterSize(16);
//	eHpText.setFillColor(Color::White);
//
//	// Audio
//	// Song
//	sf::Sound music;
//	sf::Music ending;
//	sf::SoundBuffer songBuffer;
//	if (!songBuffer.loadFromFile("thunder.wav"))
//	printf("Sorry, we are having some techinal difficults and cannot play your music\n.");
//	if (!ending.openFromFile("Sad.wav"))
//		printf("Sorry, we are having some techinal difficults and cannot play your music.\n");
//
//	music.setBuffer(songBuffer);
//
//}
//void Game::Render(sf::RenderWindow window,GState GS,int choice)
//{
//	switch (GS)
//	{
//	case Start:
//		GameInit(window,choice);
//		StartScreen(window);
//		break;
//	case Running:
//
//		break;
//	case Stop:
//		break;
//	}
//}
//void Game::Draw(sf::RenderWindow window)
//{
//
//}
//void Game::Run(sf::RenderWindow window)
//{
//	Draw(window);
//	Update();
//
//}
//void Game::Update(){}
//void Game::StartScreen(sf::RenderWindow window) {
//	while (!sf::Keyboard::Enter)
//	{
//		sf::Texture ScreenTex;
//		ScreenTex.loadFromFile("Texture/FrontScreen.png");
//		sf::Sprite Screen(ScreenTex);
//			window.draw(Screen);
//	
//	}
//	GameState = Running;
//
//	window.clear();
//}
//Game::~Game()
//{
//	
//}
