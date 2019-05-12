#include <iostream>
#include <fstream>
#include <time.h>
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <cstdlib>
#include <vector>

#include "Player.h"
//#include "Bullet.h"
//#include "Enemy.h"
#include "Boss.h"

//using namespace sf;
using namespace std;

int main()
{
	int n;
	char ch;

	//string playlist[] = { "thunder.wav", "Sad.wav", "Cartoon.wav", "Believer.wav" };


	cout << "\n\n\n\n\t\t\t\t \xB2\xB2\xB2\xB1\xB1\xB0 WELCOME TO SPACE ASSAILANT \xB0\xB1\xB1\xB2\xB2\xB2";
	cout << "\n\t\t\t\t A Space Invader Spin Off Made By: ";
	cout << "\n\t\t\t\t   (i) ZEERAK TAHIR";
	cout << "\n\t\t\t\t  (ii) SYED MUHAMMAD NASIR";
	cout << "\n\t\t\t\t (iii) MUHAMMAD USMAN";
	cout << "\n\n\t Choose The Avatar & Background: ";
	cout << "\n\n\t 1 - Spaceship And Space-TIME";
	cout << "\n\n\t 2 - Dog and Grass Field";
	cout << "\n\n\t 3 - ";
	cin >> n;

	RenderWindow window(VideoMode(1024, 768), "SPACE ASSAILANT!", Style::Fullscreen);
	window.setFramerateLimit(60);

	//Init text
	Font font;
	font.loadFromFile("Fonts/Amatic-Bold.ttf");

	//Init textures
	Texture bossTex;
	bossTex.loadFromFile("Textures/enemy.png");
	Texture playerTex;
	switch (n)
	{
	case 1:
		playerTex.loadFromFile("Textures/ship.png");
		break;
	case 2:
		playerTex.loadFromFile("Textures/Doge.png");
		break;
	case 3:
		playerTex.loadFromFile("Textures/.png");
		break;

	default:
		break;
	}



	Texture enemyTex;

	switch (n)
	{
	case 1:
		enemyTex.loadFromFile("Textures/enemy.png");
		break;
	case 2:
		enemyTex.loadFromFile("Textures/dogeney.png");
		break;
	case 3:
		enemyTex.loadFromFile("Textures/.png");
		break;

	default:
		break;
	}



	Texture bulletTex;
	switch (n)
	{
	case 1:
		bulletTex.loadFromFile("Textures/missileTex01.png");
		break;
	case 2:
		bulletTex.loadFromFile("Textures/bone_PNG54.png");
		break;
	case 3:
		bulletTex.loadFromFile("Textures/.png");
		break;


	default:
		break;
	}


	Texture backgroundtex;
	switch (n)
	{
	case 1:
		backgroundtex.loadFromFile("Textures/Space123.jpg");
		break;
	case 2:
		backgroundtex.loadFromFile("Textures/Grass_01.jpg");
		break;
	case 3:
		backgroundtex.loadFromFile("Textures/.jpg");
		break;
	default:
		break;
	}
	Sprite background(backgroundtex);
	background.setPosition(0, 0);
	background.setScale(1.f, 1.f);
	//UI init
	Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(30);
	scoreText.setFillColor(Color::Yellow);
	scoreText.setPosition(8.f, 5.f);
		Text gameOverText;
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(90);
	gameOverText.setFillColor(Color::White);
	gameOverText.setPosition(10.0f, 300.2f);  //window.getSize().y / 2
	gameOverText.setString("GAME OVER! Even My Dog Plays better Than you!!");

X:
	//Player init
	int x;
	int score = 0;
	Player player(&playerTex);
	int shootTimer = 20;
	Text hpText;
	hpText.setFont(font);
	hpText.setCharacterSize(30);
	hpText.setFillColor(Color::White);

	//Enemy init
	int enemySpawnTimer = 0;
	std::vector<Enemy> enemies;
	
	// Boss Init
	int BossTimer = 0;
	std::vector<Boss> boss;
	int BossShootTimer = 0;

	Text eHpText;
	eHpText.setFont(font);
	eHpText.setCharacterSize(30);
	eHpText.setFillColor(Color::White);
	
	Text RetryText; /////////////////////////////////////
	RetryText.setFont(font);
	RetryText.setCharacterSize(60);
	RetryText.setFillColor(Color::Yellow);
	RetryText.setString(" TRY AGAIN??? Y / N ");
	RetryText.setPosition(395.2f, 500.2f);
	

	sf::Sound music;
	sf::Music ending;
	sf::SoundBuffer songBuffer;
	if (!songBuffer.loadFromFile("thunder.wav"))

	{
		std::cout << "Sorry, we are having some techinal difficults and cannot play your music." << std::endl;
	}
	if (!ending.openFromFile("Sad.wav"))

	{
		std::cout << "Sorry, we are having some techinal difficults and cannot play your music." << std::endl;
	}
	music.setBuffer(songBuffer);

	music.play();

	////////////////
	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{ 
				music.stop();
				ending.play();
				window.close();
			}
		}
		if (player.getHP() > 0)
		{
			//Player
			if (Keyboard::isKeyPressed(Keyboard::Up))
				player.PlayerMove(0.f, -9.f);
			if (Keyboard::isKeyPressed(Keyboard::Left))
				player.PlayerMove(-9.f, 0.f);
			if (Keyboard::isKeyPressed(Keyboard::Down))
				player.PlayerMove(0.f, 9.f);
			if (Keyboard::isKeyPressed(Keyboard::Right))
				player.PlayerMove(9.f, 0.f);
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
			hpText.setPosition(player.getshape().getPosition().x, player.getshape().getPosition().y - hpText.getGlobalBounds().height);
			hpText.setString(std::to_string(player.getHP()) + "/" + std::to_string(player.getHPMax()));
			hpText.setColor(Color::Red);
			//Collision with window
			if (player.getshape().getPosition().x <= 0) //Left
				player.SetPositionLeft(window);
			if (player.getshape().getPosition().x >= window.getSize().x - player.getshape().getGlobalBounds().width) //Right
				player.SetPositionRight(window);
			if (player.getshape().getPosition().y <= 0) //Top
				player.SetPositionTop(window);
			if (player.getshape().getPosition().y >= window.getSize().y - player.getshape().getGlobalBounds().height) //Bottom
				player.SetPositionBottom(window);

			//Update Controls
			
			// Update Shoot Timer for both Enemy and Boss
			if (shootTimer < 25)
				shootTimer++;
			if (BossShootTimer < 10)
				BossShootTimer++;

			 
			if ((Keyboard::isKeyPressed(Keyboard::Space)) && shootTimer >= 25) //Shooting
			{
				player.bullets.push_back(Bullet(&bulletTex, player.getshape().getPosition()));
				shootTimer = 0; //reset timer
			}
			if (BossShootTimer >= 10)
			{
				boss[0].Bbullets.push_back(Bullet(&bulletTex, boss[0].getshape().getPosition()));
				BossShootTimer = 0;
			}
			//Bullets
			for (size_t i = 0; i < player.bullets.size(); i++)
			{
				//Move
				player.bullets[i].Bulletmove(20.f, 0.f);
				// boss[0].Bbullets[i].Bulletmove(-15.f, 0.f);
				//Out of window bounds for player bullets
				if (player.bullets[i].getshape().getPosition().x > window.getSize().x -10)
				{
					player.bullets.erase(player.bullets.begin() + i);
					break;
				}
				// Out of window bounds for enemy bullets
				if (boss[0].Bbullets[i].getshape().getPosition().x < 10)
				{
					boss[0].Bbullets.erase(player.bullets.begin() + i);
					break;
				}
				//Enemy collision
				for (size_t k = 0; k < enemies.size(); k++)
				{
					if (player.bullets[i].getshape().getGlobalBounds().intersects(enemies[k].getshape().getGlobalBounds()))
					{
						if (enemies[k].getHP() <= 1)
						{
							score += enemies[k].getHPMax();
							x = score;

							enemies.erase(enemies.begin() + k);
						}
						else
							enemies[k].HPh(); //ENEMY TAKE DAMAGE

						player.bullets.erase(player.bullets.begin() + i);
						break;
					}
				}
			// Boss Collistion 
				{
					if (player.bullets[i].getshape().getGlobalBounds().intersects(boss[0].getshape().getGlobalBounds()))
					{
						if (boss[0].getHP() <= 1)
						{
							score += boss[0].getHPMax();
							x = score;
							boss.erase(boss.begin());
							BossTimer = 0;
						}
						else
							boss[0].HPh(); //ENEMY TAKE DAMAGE

						player.bullets.erase(player.bullets.begin() + i);
						break;
					}
				}
			{
					if (player.bullets[i].getshape().getGlobalBounds().intersects(boss[0].getshape().getGlobalBounds()))
					{
						if (boss[0].getHP() <= 1)
						{
							score += boss[0].getHPMax();
							x = score;
							boss.erase(boss.begin());
							BossTimer = 0;
						}
						else
							boss[0].HPh(); //ENEMY TAKE DAMAGE

						player.bullets.erase(player.bullets.begin() + i);
						break;
					}
				}
				//  Player Collision with Boss Bullet
				/**/{
					if (boss[0].Bbullets[i].getshape().getGlobalBounds().intersects(player.getshape().getGlobalBounds()))
					{
						
							player.HPh(); // Player TAKE DAMAGE

						boss[0].Bbullets.erase(boss[0].Bbullets.begin() + i);
						break;
					}
				}/**/
			}
			//Enemy
			if (enemySpawnTimer < 15)
				enemySpawnTimer++;

			//enemy spawn
			if (enemySpawnTimer >= 15)
			{
				enemies.push_back(Enemy(&enemyTex, window.getSize()));
				enemySpawnTimer = 0; //reset timer

			}
			// Boss spawn Timer 
			BossTimer++;
			boss.push_back(Boss(&bossTex, window.getSize()));
			boss[0].Enemymove(0, 1 * sin(BossTimer/100) );
			if (boss[0].getshape().getPosition().x <= 0 - boss[0].getshape().getGlobalBounds().width)
			{
				boss.erase(boss.begin());
				break;
					

				if (boss[0].getshape().getGlobalBounds().intersects(player.getshape().getGlobalBounds()))
				{
					boss.erase(boss.begin());

					player.HPh(); // PLAYER TAKE DAMAGE
					break;
				}
			}


			for (size_t i = 0; i < enemies.size(); i++)
			{

				enemies[i].Enemymove(-6, 0.f);

				if (enemies[i].getshape().getPosition().x <= 0 - enemies[i].getshape().getGlobalBounds().width)
				{
					enemies.erase(enemies.begin() + i);
					break;
				}


				if (enemies[i].getshape().getGlobalBounds().intersects(player.getshape().getGlobalBounds()))
				{
					enemies.erase(enemies.begin() + i);

					player.HPh(); // PLAYER TAKE DAMAGE
					break;
				}
			}
			//UI Update
			scoreText.setString("Score: " + std::to_string(score));
		}
		//Draw ===================================================================== DRAW
		window.clear();
		//player
		window.draw(background);
		window.draw(player.getshape());
		//Player Bullets
		for (size_t i = 0; i < player.bullets.size(); i++)
		{
			window.draw(player.bullets[i].getshape());
		}
		//enemy
		if (BossTimer < 1000)
		{
			for (size_t i = 0; i < enemies.size(); i++)
			{
				eHpText.setString(std::to_string(enemies[i].getHP()) + "/" + std::to_string(enemies[i].getHPMax()));
				eHpText.setPosition(enemies[i].getshape().getPosition().x, enemies[i].getshape().getPosition().y - eHpText.getGlobalBounds().height);
				window.draw(eHpText);
				window.draw(enemies[i].getshape());
			}
		}
		else
			for (size_t i = 0; i < enemies.size(); i++)
				enemies.erase(enemies.begin() + i);
		// Boss 
		if (BossTimer >= 1000)
		{
			window.draw(boss[0].getshape());
			for (size_t i = 0; i < boss[0].Bbullets.size(); i++)
			{
				//window.draw(boss[0].Bbullets[i].getshape());
			}
		}
			//UI
			window.draw(scoreText);
		window.draw(hpText);
		if (player.getHP() <= 0) {
			music.stop();
			ending.play();
			window.draw(gameOverText);
			window.draw(RetryText);
		}
		
		window.display();
		x = score;
		if (Keyboard::isKeyPressed(Keyboard::N)) {
			window.close();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Y)) {
			goto X;
		}
	}
	system("pause");
	return 0;
}
