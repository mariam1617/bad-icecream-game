#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Play.h"

using namespace std;
using namespace sf;
struct player {
	int score = 0;
	Texture txplayer;
	Sprite player;
	Font font;
	Text text;
	Vector2f velocity;
	int touch = 0;

}player1, player2;

struct enemies {
	Texture txenemy;
	Sprite enemy;


}greenenemy, cowenemy1, cowenemy2;


struct fruits {
	Texture txfruit;
	Sprite fruit;
}banana1[15], banana2[15], watermelon1[10], watermelon2[10], grape1[10], grape2[10];

struct pos
{
	int x;
	int y;
};
struct MyStruct
{
	SoundBuffer soundbuffer;
	Sound sound;

}fruit, winso, gameover, jumpSound, dieSound, pointSound;

int pagenum = 100;
int cnt = 0;
Clock gameclock;
float deltatime = 0;

float speed = 100.0f;
float timer = 0, delay = 0.15f;
int i = 0, e = 0;
const int scale_b3 = 33;//lenth of block
const int width_of_block = 118;
const int scale_b4 = 59;//the horizontal distanse between the middle and border fruit
int scale_b5 = 297;//the virtical distance between center fruit

bool pass_level1 = true;
bool pass_level2 = false;


string oneflav = "null";
string twoflav[2] = { "null","null" };
Music music;
Texture txblock2;
Sprite blockface1[7 * 2 + 3 * 2 + 2 * 2];
Texture blockintx;
Sprite blockin[12];
Texture txicecastle;
Sprite icecastle;
Texture mainbackground_txx;
Sprite mainbackground2;
Texture winner_tx;
Sprite winnermenu;
Texture txmiddleBlock;
Sprite middleBlock;
Texture fruit1;
float timer2 = 0, delay2 = 2.0f;
bool poslevel1 = true;
bool poslevel2 = true;
int level = 0;
bool h = false;
bool win = true;
const int scale1_fruit = 129;//the virtical distance between border fruits
const int scale2_fruit = 119;//the virtical distance between middle fruits
const int scale = 59;//the horizontal distance between the top right fruits
int xx = 599;//first fruit
int y = 140;//first fruit
void setthings(Sprite& s, Texture& tx, int posx, int posy) {
	s.setTexture(tx);
	s.setPosition(posx, posy);
}
void setplayer(player& p) {
	p.player.setTexture(p.txplayer);
	p.player.setTextureRect(IntRect(0, 0, 51, 79));
	p.player.setScale(0.75, 0.75);
	p.player.setOrigin(p.player.getTextureRect().width / 2, p.player.getTextureRect().height / 2);
	p.font.loadFromFile("KnightWarrior-w16n8.otf");
	p.text.setFont(p.font);
	p.text.setString("Score  :  " + to_string(player1.score));
	p.text.setFillColor(Color::Black);
	p.text.setCharacterSize(50);

}
void setenemy(enemies& enm, int scale, Texture& tx, int posx, int posy, int in1, int in2, int in3, int in4) {
	enm.enemy.setTexture(tx);
	enm.enemy.setScale(scale, scale);
	enm.enemy.setPosition(posx, posy);
	enm.enemy.setTextureRect(IntRect(in1, in2, in3, in4));

}
void drawboarder(int scale, int window_w, RenderWindow& window)
{
	Texture txblock1;
	Sprite block1[20 * 4];
	txblock1.loadFromFile("block1.png");
	for (int i = 0; i < 20 * 4; i++) {
		block1[i].setScale(scale, scale);
		block1[i].setTexture(txblock1);
	}

	for (int i = 0; i < 20; i++)
	{
		block1[i].setPosition(0, i * 18 * scale);
	}
	for (int i = 20; i < 20 * 2; i++)
	{
		block1[i].setPosition(i % 20 * scale * 18, window_w - (scale * 18));
	}
	for (int i = 20 * 2; i < 20 * 3; i++)
	{
		block1[i].setPosition(i % 20 * scale * 18, 0);
	}
	for (int i = 20 * 3; i < 20 * 4; i++)
	{
		block1[i].setPosition(window_w - (scale * 18), i % 20 * 18 * scale);
	}
	for (int print = 0; print < 20 * 4; print++) {
		window.draw(block1[print]);
	}

}//level 1
void drawboarder2(int scale, int window_w, RenderWindow& window)
{

	Texture txblock2;
	txblock2.loadFromFile("blocklevel2.png");
	Sprite block2[20 * 4];

	for (int i = 0; i < 20; i++)
	{
		block2[i].setScale(scale, scale);
		block2[i].setTexture(txblock2);
		block2[i].setPosition(0, i * 16 * scale);

	}
	for (int i = 20; i < 20 * 2; i++)
	{
		block2[i].setScale(scale, scale);
		block2[i].setTexture(txblock2);
		block2[i].setPosition(i % 20 * scale * 16, window_w - (scale * 16));

	}
	for (int i = 20 * 2; i < 20 * 3; i++)
	{

		block2[i].setScale(scale, scale);
		block2[i].setTexture(txblock2);

		block2[i].setPosition(i % 20 * scale * 16, 0);

	}
	for (int i = 20 * 3; i < 20 * 4; i++)
	{
		block2[i].setScale(scale, scale);
		block2[i].setTexture(txblock2);

		block2[i].setPosition(window_w - (scale * 16), i % 20 * 16 * scale);

	}
	for (int print = 0; print < 20 * 4; print++) {
		window.draw(block2[print]);
	}


}//level2
void drawinnerboarder(int scale, int window_w, RenderWindow& window)
{


	//////////////////////////////ice man////////////////////
	Texture icemantx;
	icemantx.loadFromFile("iceman.png");
	Sprite iceman[4];
	for (int i = 0; i < 4; i++) {
		iceman[i].setTexture(icemantx);
		iceman[i].setScale(1.5, 1.5);
	}
	iceman[0].setPosition(-30, -20);
	iceman[1].setPosition(-30, 560);
	iceman[2].setPosition(560, 560);
	iceman[3].setPosition(560, -20);
	//////////////////////////////////////////////////////////////////////
	Texture txblock3;
	txblock3.loadFromFile("block1.png");


	Sprite block3[10 * 4];


	for (int i = 0; i < 10; i++)
	{
		block3[i].setScale(scale, scale);
		block3[i].setTexture(txblock3);
		block3[i].setPosition(16 * 3, 16 * 3 + 18 * 3 + (i * 18 * scale));

	}
	for (int i = 10; i < 10 * 2; i++)
	{
		block3[i].setScale(scale, scale);
		block3[i].setTexture(txblock3);
		block3[i].setPosition(16 * 3 + 18 * 3 + i % 10 * scale * 18, window_w - (scale * 18 + 16 * 3));

	}
	for (int i = 10 * 2; i < 10 * 3; i++)
	{
		block3[i].setScale(scale, scale);
		block3[i].setTexture(txblock3);
		block3[i].setPosition(16 * 3 + 18 * 3 + i % 10 * scale * 18, 16 * 3);

	}
	for (int i = 10 * 3; i < 10 * 4; i++)
	{
		block3[i].setScale(scale, scale);
		block3[i].setTexture(txblock3);
		block3[i].setPosition(window_w - (scale * 18 + 16 * 3), 16 * 3 + 18 * 3 + i % 10 * 18 * scale);

	}
	for (int print = 0; print < 10 * 4; print++) {
		window.draw(block3[print]);
	}
	for (int i = 0; i < 4; i++) {
		window.draw(iceman[i]);
	}
}
void innerblock(int scale) {


	txblock2.loadFromFile("block2.png");
	for (int i = 0; i < 7; i++)
	{
		blockface1[i].setScale(scale, scale);
		blockface1[i].setTexture(txblock2);
		blockface1[i].setPosition(160, 180 - 54 + (i * 18 * scale));


	}
	for (int i = 7; i < 7 * 2; i++)
	{
		blockface1[i].setScale(scale, scale);
		blockface1[i].setTexture(txblock2);
		blockface1[i].setPosition(750 - 160 - (3 * 18), 180 - 54 + (i % 7 * 18 * scale));

	}
	for (int i = 7 * 2; i < 7 * 2 + 3; i++)
	{
		blockface1[i].setScale(scale, scale);
		blockface1[i].setTexture(txblock2);
		blockface1[i].setPosition(160 + (i % 3 * 18 * 3), 7 * 18 * 3 + 180 - 18 * scale);

	}
	for (int i = 7 * 2 + 3; i < 7 * 2 + 3 * 2; i++)
	{
		blockface1[i].setScale(scale, scale);
		blockface1[i].setTexture(txblock2);
		blockface1[i].setPosition(750 - 160 - (3 * 18) - (i % 3 * 18 * 3), 7 * 18 * scale + 180 - 18 * 3);

	}
	for (int i = 7 * 2 + 3 * 2; i < 7 * 2 + 3 * 2 + 2; i++)
	{
		blockface1[i].setScale(scale, scale);
		blockface1[i].setTexture(txblock2);
		blockface1[i].setPosition(160 + (18 * 3) + (i % 2 * 18 * scale), 180 - 54);

	}
	for (int i = 7 * 2 + 3 * 2 + 2; i < 7 * 2 + 3 * 2 + 2 * 2; i++)
	{
		blockface1[i].setScale(scale, scale);
		blockface1[i].setTexture(txblock2);
		blockface1[i].setPosition(750 - 160 - (3 * 18) - (i % 2 * 18 * scale) - (3 * 18), 180 - 54);

	}

}
void innerblocks2(int scale, RenderWindow& window) {
	blockintx.loadFromFile("block2.png");
	for (int i = 0; i < 4; i++) {
		blockin[i].setScale(scale, scale);
		blockin[i].setTexture(blockintx);
		blockin[i].setPosition(18 * 6 + 16 * 4, 18 * 6 + 16 * 3 + i * 25 * 5);
	}
	for (int i = 4; i < 6; i++) {
		blockin[i].setScale(scale, scale);
		blockin[i].setTexture(blockintx);
		blockin[i].setPosition(18 * 12 + 16 * 4 + i % 4 * 18 * 7, 18 * 8 + 16 * 3 + 3 * 25 * 4);
	}
	for (int i = 6; i < 10; i++) {
		blockin[i].setScale(scale, scale);
		blockin[i].setTexture(blockintx);
		blockin[i].setPosition(750 - (18 * 8 + 16 * 4), 18 * 6 + 16 * 3 + i % 4 * 25 * 5);
	}
	for (int i = 10; i < 12; i++) {
		blockin[i].setScale(scale, scale);
		blockin[i].setTexture(blockintx);
		blockin[i].setPosition(18 * 12 + 16 * 4 + i % 10 * 18 * 7, 18 * 8 + 16 * 3);
	}

	for (int i = 0; i < 12; i++) {
		window.draw(blockin[i]);
	}
}
void icetowercolision(player& player) {

	RectangleShape recice(Vector2f(150, 150));
	recice.setPosition(300, 250);
	//leftside
	if (player.player.getGlobalBounds().intersects(recice.getGlobalBounds()) && player.player.getPosition().y > 265 && player.player.getPosition().y < 380 && player.player.getPosition().x < 400 && player.player.getPosition().x >300) {
		player.player.setPosition(Vector2f(recice.getPosition().x, player.player.getPosition().y));

	}
	//topside
	if (player.player.getGlobalBounds().intersects(recice.getGlobalBounds()) && player.player.getPosition().y > 260 && player.player.getPosition().y < 265) {
		player.player.setPosition(Vector2f(player.player.getPosition().x, recice.getPosition().y));
	}
	//rightside
	if (player.player.getGlobalBounds().intersects(recice.getGlobalBounds()) && player.player.getPosition().x > 450 && player.player.getPosition().x < 460 && player.player.getPosition().y < 400) {
		player.player.setPosition(Vector2f(recice.getPosition().x + recice.getGlobalBounds().width + 10, player.player.getPosition().y));


	}
	//bottomside
	if (player.player.getGlobalBounds().intersects(recice.getGlobalBounds()) && player.player.getPosition().y > 400 && player.player.getPosition().y < 412 && player.player.getPosition().x < 450 && player.player.getPosition().x >260) {
		player.player.setPosition(Vector2f(player.player.getPosition().x, recice.getPosition().y + recice.getGlobalBounds().height + 10));


	}

}
void innerblockcolision(player& playeer) {
	// left 
	for (int i = 0; i < 4; i++) {
		// left lefe
		if (playeer.player.getGlobalBounds().intersects(blockin[i].getGlobalBounds()) &&
			playeer.player.getPosition().x < 173 && playeer.player.getPosition().x > 150) {
			playeer.player.setPosition(blockin[i].getPosition().x - 20, playeer.player.getPosition().y);
		}

		// left right 
		else if (playeer.player.getGlobalBounds().intersects(blockin[i].getGlobalBounds()) &&
			playeer.player.getPosition().x < 225 && playeer.player.getPosition().x > 205) {
			playeer.player.setPosition(blockin[i].getPosition().x + 20 + 18 * 2, playeer.player.getPosition().y);
		}

		// left top
		else if (playeer.player.getGlobalBounds().intersects(blockin[i].getGlobalBounds()) &&
			playeer.player.getPosition().x < 230 && playeer.player.getPosition().x > 150 &&
			playeer.player.getPosition().y < blockin[i].getPosition().y) {
			playeer.player.setPosition(playeer.player.getPosition().x, blockin[i].getPosition().y - 20);
		}

		// left bottom
		else if (playeer.player.getGlobalBounds().intersects(blockin[i].getGlobalBounds()) &&
			playeer.player.getPosition().x < 230 && playeer.player.getPosition().x > 150 &&
			playeer.player.getPosition().y > blockin[i].getPosition().y) {
			playeer.player.setPosition(playeer.player.getPosition().x, blockin[i].getPosition().y + 30 + 18 * 2);
		}



	}

	// right

	for (int i = 6; i < 10; i++) {
		// right lefe
		if (playeer.player.getGlobalBounds().intersects(blockin[i].getGlobalBounds()) &&
			playeer.player.getPosition().x < 545 && playeer.player.getPosition().x > 515) {
			playeer.player.setPosition(blockin[i].getPosition().x - 20, playeer.player.getPosition().y);
		}

		// right right 
		else if (playeer.player.getGlobalBounds().intersects(blockin[i].getGlobalBounds()) &&
			playeer.player.getPosition().x < 605 && playeer.player.getPosition().x > 577) {
			playeer.player.setPosition(blockin[i].getPosition().x + 20 + 18 * 2, playeer.player.getPosition().y);
		}

		// right top
		else if (playeer.player.getGlobalBounds().intersects(blockin[i].getGlobalBounds()) &&
			playeer.player.getPosition().x < 595 && player1.player.getPosition().x > 525 &&
			playeer.player.getPosition().y < blockin[i].getPosition().y) {
			playeer.player.setPosition(player1.player.getPosition().x, blockin[i].getPosition().y - 20);
		}

		// right bottom
		else if (playeer.player.getGlobalBounds().intersects(blockin[i].getGlobalBounds()) &&
			playeer.player.getPosition().x < 595 && playeer.player.getPosition().x > 525 &&
			playeer.player.getPosition().y > blockin[i].getPosition().y) {
			playeer.player.setPosition(playeer.player.getPosition().x, blockin[i].getPosition().y + 30 + 18 * 2);
		}



	}

	// bottom 
	for (int i = 4; i < 6; i++) {
		// bottom left 
		if (playeer.player.getGlobalBounds().intersects(blockin[i].getGlobalBounds()) &&
			playeer.player.getPosition().y < 555 && playeer.player.getPosition().y > 475 &&
			playeer.player.getPosition().x < blockin[i].getPosition().x) {
			playeer.player.setPosition(blockin[i].getPosition().x - 20, playeer.player.getPosition().y);
		}

		// bottom right
		else if (playeer.player.getGlobalBounds().intersects(blockin[i].getGlobalBounds()) &&
			playeer.player.getPosition().y < 555 && playeer.player.getPosition().y > 475 &&
			playeer.player.getPosition().x > blockin[i].getPosition().x) {
			playeer.player.setPosition(blockin[i].getPosition().x + 20 + 18 * 2, playeer.player.getPosition().y);
		}


		// bottom top
		else if (playeer.player.getGlobalBounds().intersects(blockin[i].getGlobalBounds()) &&
			playeer.player.getPosition().y < 490 && playeer.player.getPosition().y > 470) {
			playeer.player.setPosition(playeer.player.getPosition().x, blockin[i].getPosition().y - 20);
		}

		// bottom bottom
		else if (playeer.player.getGlobalBounds().intersects(blockin[i].getGlobalBounds()) &&
			playeer.player.getPosition().y < 555 && playeer.player.getPosition().y > 540) {
			playeer.player.setPosition(playeer.player.getPosition().x, blockin[i].getPosition().y + 30 + 18 * 2);
		}

	}


	// top

	for (int i = 10; i < 12; i++) {
		// top left 
		if (playeer.player.getGlobalBounds().intersects(blockin[i].getGlobalBounds()) &&
			playeer.player.getPosition().y < 255 && playeer.player.getPosition().y > 175 &&
			playeer.player.getPosition().x < blockin[i].getPosition().x) {
			playeer.player.setPosition(blockin[i].getPosition().x - 20, playeer.player.getPosition().y);
		}

		// bottom right
		else if (playeer.player.getGlobalBounds().intersects(blockin[i].getGlobalBounds()) &&
			playeer.player.getPosition().y < 255 && playeer.player.getPosition().y > 175 &&
			playeer.player.getPosition().x > blockin[i].getPosition().x) {
			playeer.player.setPosition(blockin[i].getPosition().x + 20 + 18 * 2, playeer.player.getPosition().y);
		}


		// bottom top
		else if (playeer.player.getGlobalBounds().intersects(blockin[i].getGlobalBounds()) &&
			playeer.player.getPosition().y < 170 && playeer.player.getPosition().y > 190) {
			playeer.player.setPosition(playeer.player.getPosition().x, blockin[i].getPosition().y - 30);
		}

		// bottom bottom
		else if (playeer.player.getGlobalBounds().intersects(blockin[i].getGlobalBounds()) &&
			playeer.player.getPosition().y < 260 && playeer.player.getPosition().y > 240) {
			playeer.player.setPosition(playeer.player.getPosition().x, blockin[i].getPosition().y + 30 + 18 * 2);
		}

	}

}
void draw_fruits(int scale1, fruits fruitt[15], int scale2, int y, int x)
{
	Texture fruit1;
	fruit1.loadFromFile("banana.png");
	for (int i = 0; i < 15; i++)
	{
		fruitt[i].fruit.setScale(1, 1);
		//fruitt[i].fruit.setTexture(fruit1);

		if (i >= 0 && i < 4)
		{

			fruitt[i].fruit.setPosition(x, (scale1 * (i % 4)) + y);
		}
		else if (i >= 4 && i < 8)
		{
			fruitt[i].fruit.setPosition(x - width_of_block, (scale1 * (i % 4)) + y);
		}
		else if (i >= 8 && i < 12)
		{
			fruitt[i].fruit.setPosition(x - scale_b4, (scale2 * (i % 4)) + y - scale_b3);//midle fruits
		}
		else if (i == 12)
		{
			fruitt[i].fruit.setPosition(x - scale_b4, (scale2 * 4) + y - scale_b3);
		}
		else if (i >= 13 && i < 15)
		{
			fruitt[i].fruit.setPosition(333, (scale_b5 * ((i - 1) % 4)) + 195);
		}
	}
}
void draw_fruits(fruits fruit[10], int x1, int x2, int x3, int x4, int y, int scale1)
{
	Texture fruit1;
	fruit1.loadFromFile("fruit1.png");
	for (int i = 0; i < 10; i++)
	{
		fruit[i].fruit.setScale(scale1, scale1);
		fruit[i].fruit.setTexture(fruit1);
		//from right to left
		if (i >= 0 && i < 2)
		{
			fruit[i].fruit.setPosition(x1, y + (scale * i));
		}
		else if (i >= 2 && i < 4)
		{

			fruit[i].fruit.setPosition(x1, y + (7.5 * scale) + (scale * (i % 2)));
		}
		else if (i >= 4 && i < 6)
		{
			fruit[i].fruit.setPosition(x2, y + ((scale * 8.5) * (i % 4)));
		}
		else if (i >= 6 && i < 8)
		{
			fruit[i].fruit.setPosition(x3, y + (3.5 * scale) + (scale * (i % 6)));
		}
		else if (i >= 8 && i < 10)
		{
			fruit[i].fruit.setPosition(x4, y + (2.2 * scale) + ((4 * scale) * (i % 8)));
		}
	}

}
void score(player& playerr) {
	playerr.score++;
	playerr.text.setString("Score  :  " + to_string(playerr.score));
}
void fruitcolision(fruits arr[], player& p, int lim) {

	for (int i = 0; i < lim; i++) {

		if (p.player.getGlobalBounds().intersects(arr[i].fruit.getGlobalBounds()))
		{
			arr[i].fruit.setScale(0, 0);
			score(p);
			fruit.sound.play();// the play part in the while loop
		}
	}

}
void playermove1(Sprite& p, RenderWindow& window, float scale, int limright, int limleft, int limtop, int limbot) {

	if (Keyboard::isKeyPressed(Keyboard::Right) && p.getPosition().x < limright) {
		player1.velocity.x = speed * deltatime;
		p.setScale(scale, scale);
		if (timer < 0) {
			p.setScale(scale, scale);
			i++;
			i = i % 8;
			p.setTextureRect(IntRect((i * 51), 158, 51, 79));
			timer = delay;

		}
		else {
			timer -= deltatime;
		}


	}
	if (Keyboard::isKeyPressed(Keyboard::Left) && p.getPosition().x > limleft) {
		player1.velocity.x = -speed * deltatime;
		p.setScale(-scale, scale);
		if (timer < 0) {
			p.setScale(-scale, scale);
			i++;
			i = i % 8;
			p.setTextureRect(IntRect((i * 51), 158, 51, 79));
			timer = delay;
		}
		else {
			timer -= deltatime;
		}

	}
	if (Keyboard::isKeyPressed(Keyboard::Up) && p.getPosition().y > limtop) {
		player1.velocity.y = -speed * deltatime;
		p.setScale(-scale, scale);
		if (timer < 0) {
			p.setScale(-scale, scale);
			i++;
			i = i % 8;
			p.setTextureRect(IntRect((i * 54), 79, 54, 79));
			timer = delay;
		}
		else {
			timer -= deltatime;
		}

	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && p.getPosition().y < limbot) {
		player1.velocity.y = speed * deltatime;
		p.setScale(-scale, scale);
		if (timer < 0) {
			p.setScale(-scale, scale);
			i++;
			i = i % 8;
			p.setTextureRect(IntRect((i * 55), 0, 55, 70));
			timer = delay;
		}
		else {
			timer -= deltatime;
		}

	}
}
void playermove2(Sprite& p, RenderWindow& window, float scale, int limright, int limleft, int limtop, int limbot) {

	if (Keyboard::isKeyPressed(Keyboard::D) && p.getPosition().x < limright) {
		player2.velocity.x = speed * deltatime;
		p.setScale(scale, scale);
		if (timer < 0) {
			p.setScale(scale, scale);
			i++;
			i = i % 8;
			p.setTextureRect(IntRect((i * 51), 158, 51, 79));
			timer = delay;

		}
		else {
			timer -= deltatime;
		}


	}
	if (Keyboard::isKeyPressed(Keyboard::A) && p.getPosition().x > limleft) {
		player2.velocity.x = -speed * deltatime;
		p.setScale(-scale, scale);
		if (timer < 0) {
			p.setScale(-scale, scale);
			i++;
			i = i % 8;
			p.setTextureRect(IntRect((i * 51), 158, 51, 79));
			timer = delay;
		}
		else {
			timer -= deltatime;
		}

	}
	if (Keyboard::isKeyPressed(Keyboard::W) && p.getPosition().y > limtop) {
		player2.velocity.y = -speed * deltatime;
		p.setScale(-scale, scale);
		if (timer < 0) {
			p.setScale(-scale, scale);
			i++;
			i = i % 8;
			p.setTextureRect(IntRect((i * 54), 79, 54, 79));
			timer = delay;
		}
		else {
			timer -= deltatime;
		}

	}
	if (Keyboard::isKeyPressed(Keyboard::S) && p.getPosition().y < limbot) {
		player2.velocity.y = speed * deltatime;
		p.setScale(-scale, scale);
		if (timer < 0) {
			p.setScale(-scale, scale);
			i++;
			i = i % 8;
			p.setTextureRect(IntRect((i * 55), 0, 55, 70));
			timer = delay;
		}
		else {
			timer -= deltatime;
		}

	}
}
void enemyanimation(enemies& enemy) {
	for (int i = 0; i < 9; i++) {

		if (enemy.enemy.getPosition().y < 630 && enemy.enemy.getPosition().x < 90) {

			enemy.enemy.move(0, 5 * deltatime);
			if (timer2 < 0) {

				e++;
				e = e % 8;
				enemy.enemy.setTextureRect(IntRect(e * 32, 79, 32, 26));
				timer2 = delay2;

			}
			else {
				timer2 -= deltatime;
			}




		}

		else if (enemy.enemy.getPosition().y >= 630 && enemy.enemy.getPosition().x < 630) {

			enemy.enemy.move(5 * deltatime, 0);
			if (timer2 < 0) {

				e++;
				e = e % 8;
				enemy.enemy.setTextureRect(IntRect(e * 24, 0, 24, 26));
				timer2 = delay2;

			}
			else {
				timer2 -= deltatime;
			}



		}

		else if (enemy.enemy.getPosition().x > 630 && enemy.enemy.getPosition().y > 30) {

			enemy.enemy.move(0, -5 * deltatime);
			if (timer2 < 0) {

				e++;
				e = e % 8;
				enemy.enemy.setTextureRect(IntRect(e * 32, 53, 32, 26));
				timer2 = delay2;

			}
			else {
				timer2 -= deltatime;
			}


		}

		else if (enemy.enemy.getPosition().x <= 635 && enemy.enemy.getPosition().x >= 30 && enemy.enemy.getPosition().y <= 30) {

			enemy.enemy.move(-5 * deltatime, 0);
			if (timer2 < 0) {

				e++;
				e = e % 8;
				enemy.enemy.setTextureRect(IntRect(e * 24, 27, 24, 26));
				timer2 = delay2;

			}
			else {
				timer2 -= deltatime;
			}


		}


	}
}
void enemyanimationlevel2(enemies& enemy) {
	for (int i = 0; i < 9; i++) {

		if (enemy.enemy.getPosition().y < 580 && enemy.enemy.getPosition().x <= 110) {

			enemy.enemy.move(0, 10 * deltatime);
			enemy.enemy.setScale(1.5, 1.5);
			enemy.enemy.setTextureRect(IntRect(0, 71, 18, 35));

		}

		else if (enemy.enemy.getPosition().y >= 580 && enemy.enemy.getPosition().x < 600) {
			enemy.enemy.move(10 * deltatime, 0);
			enemy.enemy.setScale(1.5, 1.5);
			enemy.enemy.setTextureRect(IntRect(0, 0, 20, 35));
		}

		else if (enemy.enemy.getPosition().x > 600 && enemy.enemy.getPosition().y > 100) {
			enemy.enemy.move(0, -10 * deltatime);
			enemy.enemy.setScale(1.5, 1.5);
			enemy.enemy.setTextureRect(IntRect(0, 37, 18, 35));
		}

		else if (enemy.enemy.getPosition().x <= 600 + 5 && enemy.enemy.getPosition().x >= 100 && enemy.enemy.getPosition().y <= 100) {
			enemy.enemy.move(-10 * deltatime, 0);
			enemy.enemy.setScale(-1.5, 1.5);
			enemy.enemy.setTextureRect(IntRect(0, 0, 20, 36));
		}


	}
}
void winmenue(RenderWindow& window, int maxn,bool& pass_level) {
	//win sound 
	winso.soundbuffer.loadFromFile("jump.wav");
	winso.sound.setBuffer(winso.soundbuffer);
	if (cnt == 5) {
		if ((player1.score + player2.score) == maxn) {
			h = true;
			poslevel1 = true;
			pass_level = true;
			if (player1.score > player2.score) {
				winner_tx.loadFromFile("the winner 1.png");
				winnermenu.setTexture(winner_tx);
				winnermenu.setPosition(150, 280);
				window.draw(winnermenu);
			}
			else if (player1.score < player2.score) {
				winner_tx.loadFromFile("the winner 2.png");
				winnermenu.setTexture(winner_tx);
				winnermenu.setPosition(150, 280);
				window.draw(winnermenu);
			}
			else if (player1.score == player2.score && player1.score != 0 && player2.score != 0) {
				winner_tx.loadFromFile("tie.png");
				winnermenu.setTexture(winner_tx);
				winnermenu.setPosition(150, 280);
				window.draw(winnermenu);
			}

			winso.sound.play();// the play part in the while loop
			
		}
	}
	else if (cnt == 4) {

		if (player1.score == maxn) {
			h = true;
			pass_level = true;
			winner_tx.loadFromFile("winnerp1.png");
			winnermenu.setTexture(winner_tx);
			winnermenu.setPosition(150, 280);
			window.draw(winnermenu);
			winso.sound.play();// the play part in the while loop

		}

	}
	// winner menue
	Vector2i mosPos = Mouse::getPosition(window);
	if (Mouse::isButtonPressed(Mouse::Left)) {
		if (h && mosPos.x > 300 && mosPos.x < 380 && mosPos.y>380 && mosPos.y < 450) {
			h == false;
			poslevel1 = true;
			poslevel2 = true;
			cnt = 1;

		}
	}

}

void blockcoliision(player& playerr) {

	RectangleShape recblock(Vector2f(50, 460));
	RectangleShape recblockright(Vector2f(50, 460));
	RectangleShape recblockbottom1(Vector2f(18 * 3 * 3, 25 * 3));
	RectangleShape recblockbottom2(Vector2f(18 * 3 * 3, 25 * 3));
	recblock.setPosition(150, 120);
	recblockright.setPosition(535, 120);
	recblockbottom1.setPosition(160, 504);
	recblockbottom2.setPosition(430, 504);
	RectangleShape recblocktop1(Vector2f(18 * 3 * 3, 25 * 3));
	RectangleShape recblocktop2(Vector2f(18 * 3 * 3, 25 * 3));
	recblocktop1.setPosition(160, 125);
	recblocktop2.setPosition(430, 125);
	// left side out
	if (playerr.player.getGlobalBounds().intersects(recblock.getGlobalBounds()) &&
		playerr.player.getPosition().x > 159 && playerr.player.getPosition().x < 170
		&& playerr.player.getPosition().y> 104 && playerr.player.getPosition().y < 575)
	{
		playerr.player.setPosition(recblock.getPosition().x, playerr.player.getPosition().y);

	}

	//left side in 
	if (player1.player.getGlobalBounds().intersects(recblock.getGlobalBounds()) &&
		playerr.player.getPosition().x > 205 && playerr.player.getPosition().x < 225
		&& playerr.player.getPosition().y> 104 && playerr.player.getPosition().y < 555)
	{
		playerr.player.setPosition(recblock.getPosition().x + 70, playerr.player.getPosition().y);


	}
	// right side in
	if (playerr.player.getGlobalBounds().intersects(recblockright.getGlobalBounds()) &&
		playerr.player.getPosition().x > 505 && playerr.player.getPosition().x < 535
		&& playerr.player.getPosition().y> 104 && playerr.player.getPosition().y < 555)
	{
		playerr.player.setPosition(recblockright.getPosition().x - 20, playerr.player.getPosition().y);

	}
	// right side out
	if (playerr.player.getGlobalBounds().intersects(recblockright.getGlobalBounds()) &&
		playerr.player.getPosition().x > 585 && playerr.player.getPosition().x < 610
		&& playerr.player.getPosition().y> 104 && playerr.player.getPosition().y < 575)
	{
		playerr.player.setPosition(recblockright.getPosition().x + 70, playerr.player.getPosition().y);

	}
	//bottom1 bottom
	if (playerr.player.getGlobalBounds().intersects(recblockbottom1.getGlobalBounds()) &&
		playerr.player.getPosition().x > 150 && playerr.player.getPosition().x < 328
		&& playerr.player.getPosition().y> 577 && playerr.player.getPosition().y < 602)
	{
		playerr.player.setPosition(playerr.player.getPosition().x, recblockbottom1.getPosition().y + 100);


	}
	//bottom1 top
	if (playerr.player.getGlobalBounds().intersects(recblockbottom1.getGlobalBounds()) &&
		playerr.player.getPosition().x > 150 && playerr.player.getPosition().x < 328
		&& playerr.player.getPosition().y> 470 && playerr.player.getPosition().y < 500)
	{
		playerr.player.setPosition(playerr.player.getPosition().x, recblockbottom1.getPosition().y - 30);


	}
	//bottom1 right
	if (playerr.player.getGlobalBounds().intersects(recblockbottom1.getGlobalBounds()) &&
		playerr.player.getPosition().x > 320 && player1.player.getPosition().x < 340
		&& playerr.player.getPosition().y> 477 && player1.player.getPosition().y < 595)
	{
		playerr.player.setPosition(recblockbottom1.getPosition().x + 180, playerr.player.getPosition().y);

	}
	//bottom2 bottom
	if (playerr.player.getGlobalBounds().intersects(recblockbottom2.getGlobalBounds()) &&
		playerr.player.getPosition().x > 405 && playerr.player.getPosition().x < 615
		&& playerr.player.getPosition().y> 577 && playerr.player.getPosition().y < 602)
	{
		playerr.player.setPosition(playerr.player.getPosition().x, recblockbottom2.getPosition().y + 100);


	}


	//bottom1 top
	if (playerr.player.getGlobalBounds().intersects(recblockbottom2.getGlobalBounds()) &&
		playerr.player.getPosition().x > 405 && playerr.player.getPosition().x < 615
		&& playerr.player.getPosition().y> 470 && playerr.player.getPosition().y < 500)
	{
		playerr.player.setPosition(playerr.player.getPosition().x, recblockbottom2.getPosition().y - 30);


	}

	//bottom2 left
	if (playerr.player.getGlobalBounds().intersects(recblockbottom2.getGlobalBounds()) &&
		playerr.player.getPosition().x > 405 && playerr.player.getPosition().x < 430
		&& playerr.player.getPosition().y> 477 && playerr.player.getPosition().y < 595)
	{
		playerr.player.setPosition(recblockbottom2.getPosition().x - 20, playerr.player.getPosition().y);

	}
	//top1 top
	if (playerr.player.getGlobalBounds().intersects(recblocktop1.getGlobalBounds()) &&
		playerr.player.getPosition().x > 150 && playerr.player.getPosition().x < 328
		&& playerr.player.getPosition().y> 100 && playerr.player.getPosition().y < 125)
	{
		playerr.player.setPosition(playerr.player.getPosition().x, recblocktop1.getPosition().y - 25);


	}

	//top1 bottom
	if (playerr.player.getGlobalBounds().intersects(recblocktop1.getGlobalBounds()) &&
		playerr.player.getPosition().x > 150 && playerr.player.getPosition().x < 328
		&& playerr.player.getPosition().y> 200 && playerr.player.getPosition().y < 220)
	{
		playerr.player.setPosition(playerr.player.getPosition().x, recblocktop1.getPosition().y + 95);


	}

	//top1 right 
	if (playerr.player.getGlobalBounds().intersects(recblocktop1.getGlobalBounds()) &&
		playerr.player.getPosition().x > 320 && playerr.player.getPosition().x < 340
		&& playerr.player.getPosition().y> 105 && playerr.player.getPosition().y < 220)
	{
		playerr.player.setPosition(recblocktop1.getPosition().x + 180, playerr.player.getPosition().y);

	}

	//top2 top
	if (playerr.player.getGlobalBounds().intersects(recblocktop2.getGlobalBounds()) &&
		playerr.player.getPosition().x > 405 && playerr.player.getPosition().x < 615
		&& playerr.player.getPosition().y> 100 && playerr.player.getPosition().y < 125)
	{
		playerr.player.setPosition(playerr.player.getPosition().x, recblocktop2.getPosition().y - 25);


	}

	//top2 bottom
	if (playerr.player.getGlobalBounds().intersects(recblocktop2.getGlobalBounds()) &&
		playerr.player.getPosition().x > 405 && playerr.player.getPosition().x < 615
		&& playerr.player.getPosition().y> 200 && playerr.player.getPosition().y < 220)
	{
		playerr.player.setPosition(playerr.player.getPosition().x, recblocktop2.getPosition().y + 95);


	}

	//top2 left 
	if (playerr.player.getGlobalBounds().intersects(recblocktop2.getGlobalBounds()) &&
		playerr.player.getPosition().x > 405 && playerr.player.getPosition().x < 430
		&& playerr.player.getPosition().y> 105 && playerr.player.getPosition().y < 210)
	{
		playerr.player.setPosition(recblocktop2.getPosition().x - 20, playerr.player.getPosition().y);

	}

}

void chooseflav_one(RenderWindow& window) {
	////////////////////choose flavour  menu for oneplayer///////////////////////////
	RectangleShape onepflav(Vector2f(520, 520));
	Texture txonepflav;
	onepflav.setPosition(100, 80);
	txonepflav.loadFromFile("onep.png");
	onepflav.setTexture(&txonepflav);
	Vector2i mousepos = Mouse::getPosition(window);
	window.draw(onepflav);


	if (Mouse::isButtonPressed(Mouse::Left))

	{
		if (mousepos.x > 300 && mousepos.x < 410 && mousepos.y>500 && mousepos.y < 550)
		{
			cnt = 2;
		}

		if (mousepos.x > 250 && mousepos.x < 330 && mousepos.y>200 && mousepos.y < 260)
		{
			oneflav = "brown";
		}
		else if (mousepos.x > 340 && mousepos.x < 370 && mousepos.y>200 && mousepos.y < 260)
		{
			oneflav = "white";
		}

		else if (mousepos.x > 380 && mousepos.x < 420 && mousepos.y>200 && mousepos.y < 260)
		{
			oneflav = "pink";
		}
	}
}
void chooseflav_two(RenderWindow& window) {
	////////////////////choose flavour  menu for two players///////////////////////////
	RectangleShape twopflav(Vector2f(520, 520));
	Texture txtwopflav;
	twopflav.setPosition(100, 80);
	txtwopflav.loadFromFile("towp.png");
	twopflav.setTexture(&txtwopflav);
	Vector2i mousepos = Mouse::getPosition(window);
	window.draw(twopflav);


	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (mousepos.x > 294 && mousepos.x < 420 && mousepos.y>539 && mousepos.y < 598)
		{
			cnt = 2;
		}

		if (mousepos.x > 120 && mousepos.x < 200 && mousepos.y>190 && mousepos.y < 250)

		{
			twoflav[0] = "brown";
			cout << "mm";
		}
		if (mousepos.x > 205 && mousepos.x < 260 && mousepos.y>150 && mousepos.y < 280)

		{
			twoflav[0] = "white";
			cout << "mm";
		}
		if (mousepos.x > 280 && mousepos.x < 330 && mousepos.y>150 && mousepos.y < 280)

		{
			twoflav[0] = "pink";
			cout << "mm";
		}

		if (mousepos.x > 400 && mousepos.x < 440 && mousepos.y>200 && mousepos.y < 260) {
			twoflav[1] = "chocolate";
			cout << "kk";
		}
		if (mousepos.x > 445 && mousepos.x < 500 && mousepos.y>200 && mousepos.y < 260)

		{
			twoflav[1] = "vanilla";
			cout << "kk";
		}

		if (mousepos.x > 530 && mousepos.x < 575 && mousepos.y>200 && mousepos.y < 260)

		{
			twoflav[1] = "rose";
			cout << "kk";
		}

	}
}
void chooseoneflav() {
	if (oneflav == "brown" && win) {
		player1.txplayer.loadFromFile("playersprite2.png");
	}
	else if (oneflav == "pink" && win) {
		player1.txplayer.loadFromFile("playersprite3.png");
	}
	else if (oneflav == "white" && win) {
		player1.txplayer.loadFromFile("playersprite.png");

	}
}
void choosetwoflav() {
	if (twoflav[0] == "brown") {
		player1.txplayer.loadFromFile("playersprite2.png");
	}
	else if (twoflav[0] == "pink") {
		player1.txplayer.loadFromFile("playersprite3.png");
	}
	else if (twoflav[0] == "white") {
		player1.txplayer.loadFromFile("playersprite.png");

	}
	if (twoflav[1] == "chocolate") {
		player2.txplayer.loadFromFile("playersprite2.png");
	}
	else if (twoflav[1] == "rose") {
		player2.txplayer.loadFromFile("playersprite3.png");
	}
	else if (twoflav[1] == "vanilla") {
		player2.txplayer.loadFromFile("playersprite.png");

	}
}
void enemycolision(RenderWindow& window, player& playerr, enemies enemy) {
	if (playerr.player.getGlobalBounds().intersects(enemy.enemy.getGlobalBounds())) {
		win = false;
		playerr.touch++;
		gameover.sound.play();// the play part in the while loop
		//player1.txplayer.loadFromFile("meltdown.jpeg");
		playerr.player.setScale(0, 0);
		winner_tx.loadFromFile("LOSEP1.png");
		winnermenu.setTexture(winner_tx);
		winnermenu.setPosition(150, 280);


	}
}
void middelblockcolision(player& playeer) {

	txmiddleBlock.loadFromFile("middleBlock.png");
	middleBlock.setTexture(txmiddleBlock);
	middleBlock.setPosition(170, 170);
	middleBlock.setScale(4, 4);
	//middleBlock collision 

// left
	if (playeer.player.getGlobalBounds().intersects(middleBlock.getGlobalBounds()) &&
		playeer.player.getPosition().x > 300 && playeer.player.getPosition().x < 315 &&
		playeer.player.getPosition().y>340 && playeer.player.getPosition().y < 420)
	{
		playeer.player.setPosition(middleBlock.getPosition().x + 130, playeer.player.getPosition().y);
	}

	// right
	if (playeer.player.getGlobalBounds().intersects(middleBlock.getGlobalBounds()) &&
		playeer.player.getPosition().x > 420 && playeer.player.getPosition().x < 435 &&
		playeer.player.getPosition().y>340 && playeer.player.getPosition().y < 420)
	{
		playeer.player.setPosition(middleBlock.getPosition().x + 260, playeer.player.getPosition().y);
	}

	// top
	if (playeer.player.getGlobalBounds().intersects(middleBlock.getGlobalBounds()) &&
		playeer.player.getPosition().x > 310 && playeer.player.getPosition().x < 430 &&
		playeer.player.getPosition().y>330 && playeer.player.getPosition().y < 345)
	{
		playeer.player.setPosition(playeer.player.getPosition().x, middleBlock.getPosition().y + 155);

	}

	// bottom
	if (playeer.player.getGlobalBounds().intersects(middleBlock.getGlobalBounds()) &&
		playeer.player.getPosition().x > 310 && playeer.player.getPosition().x < 430 &&
		playeer.player.getPosition().y>415 && playeer.player.getPosition().y < 435)
	{
		playeer.player.setPosition(playeer.player.getPosition().x, middleBlock.getPosition().y + 260);

	}

}
void level1(RenderWindow& window) {

	window.clear();
	enemyanimation(greenenemy);

	window.draw(mainbackground2);
	for (int print = 0; print < 7 * 2 + 3 * 2 + 2 * 2; print++) {
		window.draw(blockface1[print]);
	}
	window.draw(icecastle);
	drawboarder(3, 750, window);
	if (poslevel1) {
		draw_fruits(watermelon1, 617, 563, 495, 452, 87, 1);//right
		draw_fruits(watermelon2, 123, 179, 233, 294, 87, 1);//left
		player1.text.setPosition(10, 10);
		player2.text.setPosition(500, 10);
		greenenemy.enemy.setPosition(64, 150);
		player1.player.setPosition(80, 80);
		player1.player.setScale(0.75, 0.75);
		player1.score = 0;
		player1.text.setString("Score  :  " + to_string(player1.score));

		player1.player.setOrigin(player1.player.getTextureRect().width / 2, player1.player.getTextureRect().height / 2);
		player1.player.setTextureRect(IntRect(0, 0, 51, 79));
		///////player2///////////////
		player2.player.setPosition(500, 650);
		player2.player.setScale(0.75, 0.75);
		player2.score = 0;
		player2.text.setString("Score  :  " + to_string(player1.score));
		player2.player.setOrigin(player1.player.getTextureRect().width / 2, player1.player.getTextureRect().height / 2);
		player2.player.setTextureRect(IntRect(0, 0, 51, 79));
	}
	poslevel1 = false;
	if (cnt == 4) {

		if (player1.score == 0) {

			draw_fruits(watermelon1, 617, 563, 495, 452, 87, 1);//right
			draw_fruits(watermelon2, 123, 179, 233, 294, 87, 1);//left
			innerblock(3);

		}
		if (player1.score == 20) {

			draw_fruits(grape1, 617, 563, 495, 452, 87, 1.5);//right
			draw_fruits(grape2, 123, 179, 233, 294, 87, 1.5);//left

		}

		chooseoneflav();
		playermove1(player1.player, window, 0.75, 670, 80, 80, 670);
		fruitcolision(watermelon1, player1, 10);
		fruitcolision(watermelon2, player1, 10);
		fruitcolision(grape1, player1, 10);
		fruitcolision(grape2, player1, 10);
		icetowercolision(player1);
		blockcoliision(player1);
		player1.player.move(player1.velocity);
		window.draw(player1.player);
		window.draw(player1.text);
		winmenue(window, 40,pass_level1);
		enemycolision(window, player1, greenenemy);

	}
	else {

		if (player1.score == 0 && player2.score == 0) {
			draw_fruits(watermelon1, 617, 563, 495, 452, 87, 1);//right
			draw_fruits(watermelon2, 123, 179, 233, 294, 87, 1);//left

			innerblock(3);
		}
		if ((player1.score + player2.score) == 20) {

			draw_fruits(grape1, 617, 563, 495, 452, 87, 1.5);//right
			draw_fruits(grape2, 123, 179, 233, 294, 87, 1.5);//left

		}

		choosetwoflav();
		playermove1(player1.player, window, 0.75, 670, 80, 80, 670);
		fruitcolision(watermelon1, player1, 10);
		fruitcolision(watermelon2, player1, 10);
		fruitcolision(grape1, player1, 10);
		fruitcolision(grape2, player1, 10);
		icetowercolision(player1);
		blockcoliision(player1);
		player1.player.move(player1.velocity);
		window.draw(player1.player);
		window.draw(player1.text);
		playermove2(player2.player, window, 0.75, 670, 80, 80, 670);
		fruitcolision(watermelon1, player2, 10);
		fruitcolision(watermelon2, player2, 10);
		fruitcolision(grape1, player2, 10);
		fruitcolision(grape2, player2, 10);
		icetowercolision(player2);
		blockcoliision(player2);
		player2.player.move(player2.velocity);
		window.draw(player2.player);
		window.draw(player2.text);
		enemycolision(window, player1, greenenemy);
		enemycolision(window, player2, greenenemy);
		winmenue(window, 40, pass_level1);
	}

	if (player1.score >= 20 || (player1.score + player2.score) >= 20) {

		fruit1.loadFromFile("fruit2.png");
		for (int i = 0; i < 10; i++)
		{
			grape1[i].fruit.setTexture(fruit1);
			grape2[i].fruit.setTexture(fruit1);
		}
		for (int i = 0; i < 10; i++)
		{
			window.draw(grape1[i].fruit);
			window.draw(grape2[i].fruit);
		}
	}
	fruit1.loadFromFile("fruit1.png");
	for (int i = 0; i < 10; i++)
	{
		watermelon1[i].fruit.setTexture(fruit1);
		watermelon2[i].fruit.setTexture(fruit1);
	}
	for (int i = 0; i < 10; i++)
	{
		window.draw(watermelon1[i].fruit);
		window.draw(watermelon2[i].fruit);
	}


	window.draw(greenenemy.enemy);
	if (!win && player1.touch > 0 && cnt == 4) {
		window.draw(winnermenu);
	
	}
	if (!win && player1.touch > 0 && player2.touch > 0) {
		window.draw(winnermenu);
		
	}

}
void level2(RenderWindow& window) {

	window.clear();
	window.draw(mainbackground2);
	drawboarder2(3, 750, window);
	drawinnerboarder(3, 750, window);
	innerblocks2(2, window);
	//icecastle.setPosition(250, 250);
	//window.draw(icecastle);

	enemyanimationlevel2(cowenemy1);
	enemyanimationlevel2(cowenemy2);
	if (poslevel2) {
		draw_fruits(scale1_fruit, banana1, scale2_fruit, y, xx);
		draw_fruits(scale1_fruit, banana2, scale2_fruit, y, 220);
		cowenemy1.enemy.setPosition(110, 110);
		cowenemy2.enemy.setPosition(601, 585);
		player1.player.setPosition(230, 230);
		player1.player.setScale(0.75, 0.75);
		player1.score = 0;
		player1.text.setString("Score  :  " + to_string(player1.score));
		player1.player.setOrigin(player1.player.getTextureRect().width / 2, player1.player.getTextureRect().height / 2);
		player1.player.setTextureRect(IntRect(0, 0, 51, 79));
		///////player2///////////////
		player2.player.setPosition(450, 450);
		player2.player.setScale(0.75, 0.75);
		player2.score = 0;
		player2.text.setString("Score  :  " + to_string(player1.score));
		player2.player.setOrigin(player1.player.getTextureRect().width / 2, player1.player.getTextureRect().height / 2);
		player2.player.setTextureRect(IntRect(0, 0, 51, 79));

	}
	poslevel2 = false;
	if (cnt == 4) {
		if (player1.score == 0) {
			draw_fruits(scale1_fruit, banana1, scale2_fruit, y, xx);
			draw_fruits(scale1_fruit, banana2, scale2_fruit, y, 220);
		}
		chooseoneflav();
		playermove1(player1.player, window, 0.75, 630, 120, 120, 620);
		player1.player.move(player1.velocity);
		window.draw(player1.player);
		window.draw(player1.text);
		winmenue(window, 30, pass_level2);
		innerblockcolision(player1);
		middelblockcolision(player1);
		fruitcolision(banana1, player1, 15);
		fruitcolision(banana2, player1, 15);
		//icetowercolision(player1);
		enemycolision(window, player1, cowenemy1);
		enemycolision(window, player1, cowenemy2);

	}
	else {
		if (player1.score == 0 && player2.score == 0) {
			draw_fruits(scale1_fruit, banana1, scale2_fruit, y, xx);
			draw_fruits(scale1_fruit, banana2, scale2_fruit, y, 220);
		}
		choosetwoflav();
		playermove1(player1.player, window, 0.75, 630, 120, 120, 620);
		//icetowercolision(player1);
		//icetowercolision(player2);
		player1.player.move(player1.velocity);
		window.draw(player1.player);
		window.draw(player1.text);
		playermove2(player2.player, window, 0.75, 630, 120, 120, 620);

		player2.player.move(player2.velocity);
		window.draw(player2.player);
		window.draw(player2.text);
		winmenue(window, 30,pass_level2);
		innerblockcolision(player1);
		fruitcolision(banana1, player1, 15);
		fruitcolision(banana2, player1, 15);
		innerblockcolision(player2);
		middelblockcolision(player1);
		middelblockcolision(player2);
		fruitcolision(banana1, player2, 15);
		fruitcolision(banana2, player2, 15);
		enemycolision(window, player1, cowenemy1);
		enemycolision(window, player1, cowenemy2);
		enemycolision(window, player2, cowenemy1);
		enemycolision(window, player2, cowenemy2);
	}
	fruit1.loadFromFile("banana.png");
	for (int i = 0; i < 15; i++)
	{
		banana1[i].fruit.setTexture(fruit1);
		banana2[i].fruit.setTexture(fruit1);
	}
	for (int i = 0; i < 15; i++)
	{
		window.draw(banana1[i].fruit);
		window.draw(banana2[i].fruit);
	}
	window.draw(middleBlock);
	if (!win && player1.touch > 0 && cnt == 4) {

		window.draw(winnermenu);
	}
	if (!win && player1.touch > 0 && player2.touch > 0) {

		window.draw(winnermenu);
	}

	window.draw(cowenemy1.enemy);
	window.draw(cowenemy2.enemy);


}


void dansetthing(Sprite& s, Texture& tx, int posx, int posy, int i) {

	s.setTexture(tx);
	s.setPosition(Vector2f(i * posx, posy));

}
void dantext(Text& te, Font& font, int charn, int posx, int posy) {
	te.setFont(font);
	te.setFillColor(Color{ 95, 99, 104 });
	te.setPosition(posx, posy);
	te.setCharacterSize(charn);
}
void danusorgame(RenderWindow& window) {

	window.setFramerateLimit(60);
	Texture Dino;
	Sprite dino;
	Dino.loadFromFile("dinoo.png");
	dino.setTexture(Dino);
	dino.setTextureRect(IntRect(0, 0, 100, 106));
	dino.setScale(0.7, 0.7);
	Texture groundtexture;
	Sprite ground[2];
	groundtexture.loadFromFile("GroundImage.png");
	dansetthing(ground[0], groundtexture, 750, 500, 0);
	dansetthing(ground[1], groundtexture, 750, 500, 1);
	//cactus
	Texture Cactus;
	Sprite cactus[2];
	int randomNumber = (rand() % 3) + 1;
	switch (randomNumber)
	{
		/*case 1:
			Cactus.loadFromFile("Cactus1.png");
			break;*/
	case 2:
		Cactus.loadFromFile("Cactus2.png");
		break;
	case 3:
		Cactus.loadFromFile("Cactus3.png");
		break;

	}


	dansetthing(cactus[0], Cactus, 400, 455, 0);
	dansetthing(cactus[1], Cactus, 400, 455, 1);
	//clouds
	Texture Cloud;
	Cloud.loadFromFile("Clouds.png");
	Sprite clouds[3];
	dansetthing(clouds[0], Cloud, 400, 100, 0);
	dansetthing(clouds[1], Cloud, 400, 90, 1);
	dansetthing(clouds[3], Cloud, 400, 80, 2);
	//create sounds

	if (!jumpSound.soundbuffer.loadFromFile("jump.wav"))
	{
		cout << " nn" << endl;
		//return EXIT_FAILURE;
	}
	if (!dieSound.soundbuffer.loadFromFile("die.wav"))
	{
		cout << " nn" << endl;
		//return EXIT_FAILURE;
	}
	if (!pointSound.soundbuffer.loadFromFile("point.wav"))
	{
		cout << " nn" << endl;
		//return EXIT_FAILURE;
	}
	jumpSound.sound.setBuffer(jumpSound.soundbuffer);
	dieSound.sound.setBuffer(dieSound.soundbuffer);
	pointSound.sound.setBuffer(pointSound.soundbuffer);


	//dino animation
	Clock anim;
	anim.restart();
	int animcnt = 0;
	//score
	Clock score_time;
	int score = 0;
	Font font;
	font.loadFromFile("ARCADECLASSIC.otf");
	Text scoretxt;
	dantext(scoretxt, font, 18, 600, 10);
	//error message
	Text err_mes;
	err_mes.setString("The  feature  you  are  trying  to  reach\n  now  is  unavailable \n Please  try  again  later");
	dantext(err_mes, font, 32, 140, 150);

	bool draw = true;

	//game over
	Text gameover_txt;
	gameover_txt.setString("GAMEOVER");
	dantext(gameover_txt, font, 82, 200, 200);
	bool isGameover = false;


	bool start = false;
	//for dino pos 
	static const int DINO_Bottom = 560 - Dino.getSize().y;
	pos dinoPos;
	dinoPos.x = 50;
	dinoPos.y = DINO_Bottom;
	dino.setPosition(dinoPos.x, dinoPos.y - 20);

	int timer = 0, delay = 1, deltatime = 0;


	//for jump

	const int dinoheght = 150;
	int currentheght = 0, frame = 0, speedgame = 10, cloudspeed = -2;
	bool jump = false;
	bool isBottom = true;
	bool game = false;

	bool d = false;


	//for birds
	struct Enemy {
		Sprite shape;
		int speed;
		float animation = 0;
		bool moving = true;
	};

	Texture enemyphoto;
	enemyphoto.loadFromFile("BirdSpriteSheet.png");
	Enemy enemy[4];
	for (int i = 0; i < 2; i++) {      //0,1,2,3 right
		enemy[i].shape.setTexture(enemyphoto);
		enemy[i].speed = rand() % (8 - 4 + 1) + 4;     //15 to 8
		enemy[i].shape.setScale(-0.7, 0.7);
		int y = rand() % (250 - 200 + 1) + 300;   //200 to 100
		if (i < 4) {

			enemy[i].shape.setPosition(10, y);


			enemy[i].shape.setTextureRect(IntRect(90, 0, -90, 80));
		}

	}

	while (window.isOpen())
	{

		Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == Event::Closed)
				window.close();

			if (evnt.type == Event::KeyPressed)
			{
				jumpSound.sound.play();
				if (evnt.key.code == Keyboard::Space) {
					if (!start) {
						draw = false; //remove greeting words
						start = true;
					}
					if (!game)
					{
						game = true;
						isGameover = false;


						/*if (score > 0) {
							dino.setPosition(dinoPos.x + 60, dinoPos.y - 20);
						}
						else {
							dino.setPosition(dinoPos.x, dinoPos.y - 20);
						}*/

						score = 0;

						for (int i = 0; i < 2; i++)
						{
							cactus[i].setScale(0.5, 0.5);
							cactus[i].move(Vector2f(-speedgame * .5, 0));
							enemy[i].moving = true;

						}
						for (int i = 0; i < 3; i++)
						{
							clouds[i].move((Vector2f(-2, 0)));
						}
						dino.setTextureRect(IntRect(0, 0, 100, 106));
						currentheght = 0;
						speedgame = 10;
						jump = false;
						isBottom = true;

						for (int i = 0; i < 2; i++)
						{
							ground[i].move(Vector2f(-5, 0));
						}


					}
					else if (isBottom) {
						jump = true;
						isBottom = false;
						currentheght = 0;
						dino.setTextureRect(IntRect(0, 0, 100, 106));
						randomNumber = (rand() % 3) + 1;
						switch (randomNumber)
						{
						case 1:
							Cactus.loadFromFile("Cactus2.png");
							break;
						case 2:
							Cactus.loadFromFile("Cactus3.png");
							break;
						}
					}

				}
				int x = 7;
				if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
					dino.setTextureRect(IntRect(x * 118, 0, 118, 106));
					x++;
					x = x % 7;
				}
			}


		}


		//jump logic
		if (game) {
			if (!isGameover) {
				if (jump)//jumping
				{
					if (dinoheght > currentheght)
					{
						dino.move(0, (-dinoheght / float(25)));
						currentheght += dinoheght / float(25);
					}
					else
					{
						jump = false;
						currentheght = 0;
					}
				}
				else if (!isBottom)//coming down from jump
				{
					if (dinoheght > currentheght)
					{
						dino.move(0, (dinoheght / float(25)));
						currentheght += dinoheght / float(25);
					}
					else
					{
						isBottom = true;
						//dino_animation = true;
					}
				}
				else //if (dino_animation)//animation otherwise 
				{
					if (anim.getElapsedTime().asSeconds() >= 0.1f) {
						animcnt++;
						anim.restart();
					}
					if (animcnt > 4) {
						animcnt = 0;
					}
					dino.setTextureRect(IntRect(animcnt * 96, 0, 100, 106));
				}
			}
			if ((int)score_time.getElapsedTime().asMilliseconds() >= 100 && start) {
				score++;
				String scorestr = to_string(score);
				scoretxt.setString("Score    " + scorestr);
				score_time.restart();
			}


			//cactus logic

			for (int i = 0; i < 2; i++)
			{
				cactus[i].setScale(0.5, 0.5);
				cactus[i].move(Vector2f(-speedgame * .5, 0));
			}

			if (cactus[0].getPosition().x <= -300)
			{
				cactus[0].setPosition(Vector2f(750, 455));
			}

			else if (cactus[1].getPosition().x <= -300)
			{
				cactus[1].setPosition(Vector2f(750, 455));
			}


			//cloud logic
			for (int i = 0; i < 3; i++)
			{

				clouds[i].move((Vector2f(cloudspeed, 0)));
			}
			if (clouds[0].getPosition().x <= -300)
			{
				clouds[0].setPosition(Vector2f(750, 90));
			}

			else if (clouds[1].getPosition().x <= -300)
			{
				clouds[1].setPosition(Vector2f(750, 70));
			}
			else if (clouds[2].getPosition().x <= -300)
			{
				clouds[2].setPosition(Vector2f(750, 50));
			}




			for (int i = 0; i < 2; i++)
			{
				ground[i].move(Vector2f(-speedgame, 0));
			}
			if (ground[0].getPosition().x <= -750)
			{
				ground[0].setPosition(Vector2f(750, 500));
			}

			else if (ground[1].getPosition().x <= -750)
			{
				ground[1].setPosition(Vector2f(750, 500));
			}


			for (int i = 0; i < 1; i++) {
				if (enemy[i].moving) {
					if (i < 1) {
						enemy[i].shape.move(-enemy[i].speed, 0);
						if (enemy[i].shape.getPosition().x < 0) {
							int y = rand() % (250 - 200 + 1) + 270;
							enemy[i].shape.setPosition(730, y);
							enemy[i].speed = rand() % (15 - 8 + 1) + 8;
						}

					}
				}
			}
		}


		for (int i = 0; i < 2; i++) {
			Clock sound_clk;
			if ((dino.getGlobalBounds().intersects(cactus[i].getGlobalBounds()) || (dino.getGlobalBounds().intersects(enemy[i].shape.getGlobalBounds())) && d) && !isGameover && game) {
				isGameover = true;
				dieSound.sound.play();
				start = false;
				game = false;

				enemy[i].moving = false;
				cloudspeed = 0;
				speedgame = 0;
				dino.setTextureRect(IntRect(580, 0, 100, 106));
				if (timer < 0) {
					danusorgame(window);

					timer = delay;

				}
				else {
					timer -= deltatime;
				}


			}

		}



		window.clear(Color::White);




		if (!isGameover) {
			for (int i = 0; i < 3; i++)
				window.draw(clouds[i]);

			for (int i = 1; i <= 9; i++)
			{
				if (score == 100 * i)
				{
					pointSound.sound.play();
				}
			}

		}

		if (!draw) {
			window.draw(scoretxt);
			if (score >= 50) {
				d = true;
				for (int i = 0; i < 1; i++) {
					//enemy[i].speed = rand() % (8 - 4 + 1) + 4;
					window.draw(enemy[i].shape);
				}
			}
			for (int i = 0; i < 2; i++) {
				cactus[i].setTexture(Cactus);
				window.draw(cactus[i]);
				window.draw(ground[i]);
			}

		}
		else if (draw) {

			window.draw(err_mes);
		}
		if (isGameover)
		{
			window.draw(gameover_txt);
		}


		window.draw(dino);

		for (int i = 0; i < 2; i++) {
			window.draw(ground[i]);
		}

		window.display();
		deltatime = gameclock.getElapsedTime().asSeconds();
	}
}
int llmenu(RenderWindow& window)
{

	int selectedi = 0;
	int selectedj = 0;


	const int spacei = 4;
	const int spacej = 5;

	Font font;
	font.loadFromFile("ARCADECLASSIC.otf");
	Text levelnames[spacei][spacej];
	for (int i = 0; i < spacei; i++)
	{
		for (int j = 0; j < spacej; j++)
		{
			int lvl = (i * 5) + j + 1;
			string lvl_string = to_string(lvl);
			levelnames[i][j].setString(lvl_string);
			levelnames[i][j].setFont(font);

			if (lvl == 1) {
				levelnames[i][j].setPosition(Vector2f(163 + (j * 100), 180 + (i * 75)));
				levelnames[i][j].setFillColor(Color{ 250, 186, 48, 255 });
			}
			else if (lvl > 10)
			{
				levelnames[i][j].setPosition(Vector2f(150 + (j * 100), 170 + (i * 75)));
				levelnames[i][j].setFillColor(Color{ 208,149,22,255 });
			}
			else
			{
				levelnames[i][j].setPosition(Vector2f(163 + (j * 100), 180 + (i * 75)));
				levelnames[i][j].setFillColor(Color{ 208,149,22,255 });
			}
			levelnames[i][j].setCharacterSize(40);

		}
		cout << endl;

	}

	Texture lvl1bg;
	lvl1bg.loadFromFile("background.png");
	lvl1bg.setRepeated(true);
	Sprite lvlmenubg;
	lvlmenubg.setTexture(lvl1bg);
	lvlmenubg.setScale(Vector2f(0.5, 0.5));
	lvlmenubg.setTextureRect(IntRect(0, 0, 1500, 1500));

	Texture yellowbg;
	yellowbg.loadFromFile("menu.png");
	Sprite yellbg_sprite;
	yellbg_sprite.setTexture(yellowbg);
	yellbg_sprite.setScale(Vector2f(1.3, 1.3));
	yellbg_sprite.setPosition(Vector2f(85, 150));

	Texture back_texture;
	back_texture.loadFromFile("backbutton.png");
	Sprite backbtn;
	backbtn.setTexture(back_texture);
	backbtn.setPosition(Vector2f(300, 550));
	backbtn.setScale(Vector2f(1.5, 1.5));

	Texture locked;
	locked.loadFromFile("locked.png");

	Texture unlocked;
	unlocked.loadFromFile("unlocked.png");

	Sprite level[spacei][spacej];
	for (int i = 0; i < spacei; i++) {
		for (int j = 0; j < spacej; j++) {
			if (i == 0 && j == 0) {
				level[i][j].setTexture(unlocked);
				level[i][j].setPosition(Vector2f(126 + (j * 100), 180 + (i * 67)));
				level[i][j].setScale(0.75, 0.7);
			}
			else {
				level[i][j].setTexture(locked);
				level[i][j].setPosition(Vector2f(126 + (j * 100), 180 + (i * 67)));
				level[i][j].setScale(0.75, 0.7);
			}

		}
		cout << endl;
	}


	if (pass_level1) {
		level[0][0].setTexture(unlocked);
		levelnames[0][0].setFillColor(Color{ 147, 213, 239, 255 });
		selectedj++;
		level[0][selectedj].setTexture(unlocked);


	}

	if (pass_level2) {
		level[0][1].setTexture(unlocked);
		levelnames[0][1].setFillColor(Color{ 147, 213, 239, 255 });
		selectedj++;
		level[0][selectedj].setTexture(unlocked);

	}

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
				break;
			}

			Vector2i mousepos = Mouse::getPosition(window);

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (mousepos.x > 300 && mousepos.x < 407 && mousepos.y>550 && mousepos.y < 600)
				{
					cnt = 1;
					return  -1;
				}

			}

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Return && cnt == 2)
				{
					if (selectedi == 0 && selectedj == 0) {
						return 11;
					}

					else if (selectedi == 0 && selectedj == 1) {
						return 22;
					}

					else if (selectedi > 0 || selectedj > 1) {
						RenderWindow window(VideoMode(750, 550), "Dino Game");
						danusorgame(window);
					}
				}




				if (event.key.code == Keyboard::Right && cnt == 2)
				{
					if (selectedi * selectedj > 12)
					{
						selectedi = spacei - 1;
						selectedj = spacej - 1;
					}

					else if (selectedj + 1 < spacej)
					{

						selectedj++;
						level[selectedi][selectedj].setTexture(unlocked);
						/*levelnames[selectedi][selectedj].setFillColor(Color{ 250, 186, 48, 255 });

						levelnames[selectedi][selectedj-1].setFillColor(Color{ 208,149,22,255 });*/



					}
					else if (selectedj + 1 == spacej) {
						selectedj = 0;
						if (selectedi + 1 == spacei) {
							selectedj = spacej - 1;
							level[selectedi][selectedj].setTexture(unlocked);
							//levelnames[selectedi][selectedj].setFillColor(Color{ 250, 186, 48, 255 });


							//levelnames[selectedi][selectedj - 1].setFillColor(Color{ 208,149,22,255 });
						}
						else {
							selectedi++;
							level[selectedi][selectedj].setTexture(unlocked);
							//levelnames[selectedi][selectedj].setFillColor(Color{ 250, 186, 48, 255 });							
							//levelnames[selectedi-1][spacej-1].setFillColor(Color{ 208,149,22,255 });
						}

					}
				}

				cout << selectedi << " " << selectedj << endl;
				if (event.key.code == Keyboard::Left && cnt == 2)
				{
					if (selectedi + selectedj == 0)
					{
						selectedi = 0;
						selectedj = 0;
					}
					else if (selectedj - 1 >= 0)
					{
						level[selectedi][selectedj].setTexture(locked);
						//levelnames[selectedi][selectedj].setFillColor(Color{ 208,149,22,255 });
						selectedj--;
						//levelnames[selectedi][selectedj].setFillColor(Color{ 250, 186, 48, 255 });
					}
					else if (selectedj == 0) {
						//levelnames[selectedi][selectedj].setFillColor(Color{ 208,149,22,255 });

						level[selectedi][selectedj].setTexture(locked);
						selectedj = spacej - 1;

						if (selectedi == 0) {
							selectedj = 0;
							/*levelnames[selectedi][selectedj].setFillColor(Color{ 208,149,22,255 });

							levelnames[selectedi][selectedj].setFillColor(Color{ 250, 186, 48, 255 });*/

						}
						else {
							selectedi--;
							//levelnames[selectedi][selectedj ].setFillColor(Color{ 250, 186, 48, 255 });
						}
					}


				}


			}

		}
		window.clear();
		window.draw(lvlmenubg);
		window.draw(yellbg_sprite);
		window.draw(backbtn);
		for (int i = 0; i < spacei; i++) {
			for (int j = 0; j < spacej; j++) {
				window.draw(level[i][j]);
				if (level[i][j].getTexture() == &unlocked) {
					window.draw(levelnames[i][j]);
				}
			}
			cout << endl;
		}




		window.display();

	}
}



int main()
{

	RenderWindow window(VideoMode(750, 750), "BAD ICE CREAM");
	Play play(450, 253);
	Texture txmenu;
	Sprite menu2;
	txmenu.loadFromFile("menu.png");
	setthings(menu2, txmenu, 150, 280);
	// main background
	Texture mainbackground_tx;
	Sprite mainbackground;
	mainbackground_tx.loadFromFile("main background.jpg");
	setthings(mainbackground, mainbackground_tx, 0, 0);
	//menu2
	Texture menu11;
	Sprite Men1;
	menu11.loadFromFile("menu1.jpeg");
	setthings(Men1, menu11, 0, 75);
	// owners menue
	Texture ownmenue_tx;
	Sprite ownermenue;
	ownmenue_tx.loadFromFile("owners.png");
	setthings(ownermenue, ownmenue_tx, 150, 30);
	////////setinnngs//////
	Texture btn1;
	Sprite setbtn;
	btn1.loadFromFile("btn.png");
	setthings(setbtn, btn1, 680, 0);
	setbtn.setScale(0.5, 0.5);
	// level 1 
	mainbackground_txx.loadFromFile("main background1.jpg");
	mainbackground2.setTexture(mainbackground_txx);
	////the help menu
	Texture helpmenu_tx;
	Sprite helpmenue;
	helpmenu_tx.loadFromFile("help-menu.png");
	setthings(helpmenue, helpmenu_tx, 150, 100);
	///////////////players///////////////////////////
	setplayer(player1);
	setplayer(player2);
	////////////////////ice tower//////////////////////////
	txicecastle.loadFromFile("icecastle.png");
	setthings(icecastle, txicecastle, 250, 200);
	icecastle.setScale(2, 2);
	/////////////////enemies////////////////
	greenenemy.txenemy.loadFromFile("enemy.png");
	setenemy(greenenemy, 2.5, greenenemy.txenemy, 64, 150, 0, 78, 24, 26);
	cowenemy2.txenemy.loadFromFile("enemylevel2.png");
	setenemy(cowenemy2, 1.5, cowenemy2.txenemy, 601, 585, 0, 71, 18, 35);
	cowenemy1.txenemy.loadFromFile("enemylevel2.png");
	setenemy(cowenemy1, 1.5, cowenemy1.txenemy, 110, 110, 0, 71, 18, 35);
	//fruit sound
	fruit.soundbuffer.loadFromFile("fruit.mp3");
	fruit.sound.setBuffer(fruit.soundbuffer);
	//gameover sound
	gameover.soundbuffer.loadFromFile("game over.mp3");
	gameover.sound.setBuffer(gameover.soundbuffer);

	if (!music.openFromFile("music.mpeg")) {

		//return EXIT_FAILURE;
		RenderWindow window(VideoMode(750, 550), "Dino Game");
		danusorgame(window);

	}
	

	while (window.isOpen())
	{


		gameclock.restart();
		speed = 100.0f;
		player1.velocity.x = 0;
		player1.velocity.y = 0;
		player2.velocity.x = 0;
		player2.velocity.y = 0;

		Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
			{
				window.close();
			}
			if (evnt.type == Event::KeyPressed) {
				if (evnt.key.code == Keyboard::Up && cnt == 1) {
					play.MoveUp();
				}
				if (evnt.key.code == Keyboard::Down && cnt == 1) {
					play.MoveDown();
				}
				if (evnt.key.code == Keyboard::Return && cnt == 1) {
					if (play.pressed() == 0) {
						pagenum = 1;
					}
					if (play.pressed() == 1) {
						pagenum = 2;
					}
					if (play.pressed() == 2) {
						pagenum = 3;
					}
					if (play.pressed() == 3) {
						pagenum = -1;
					}
				}
			}


			Vector2i mosPos = Mouse::getPosition(window);
			if (Mouse::isButtonPressed(Mouse::Left)) {


				if (cnt == 0 && mosPos.x > 260 && mosPos.x < 500 && mosPos.y>550 && mosPos.y < 650) {

					cnt = 1;

				}
				if (mosPos.x > 60 && mosPos.x < 80 && mosPos.y > 90 && mosPos.y < 120) {
					music.play();
					music.setLoop(true);
				}

				if (mosPos.x > 20 && mosPos.x < 40 && mosPos.y > 90 && mosPos.y < 120) {
					music.stop();
					music.setLoop(false);
				}
				if (pagenum == 2 && mosPos.x > 150 && mosPos.x < 270 && mosPos.y>620 &&
					mosPos.y < 670) {
					cnt = 1;
					pagenum = 100;
				}

				//for twoplayer
				if (cnt == 3 && mosPos.x > 450 && mosPos.x < 500 && mosPos.y>200 && mosPos.y < 450)
				{
					cnt = 5;

				}
				//for one player
				else if (cnt == 3 && mosPos.x > 200 && mosPos.x < 300 && mosPos.y>200 && mosPos.y < 450)
				{
					cnt = 4;


				}

				//back in help menue
				if (pagenum == 3 && mosPos.x > 330 && mosPos.x < 430 && mosPos.y>450 && mosPos.y < 500) {
					cnt = 1;
					pagenum = 100;
				}
				// choose players
				if (cnt == 3 && mosPos.x > 300 && mosPos.x < 430 && mosPos.y>500 && mosPos.y < 550)
				{
					cnt = 2;
				}
				//goodluck menu
				if (!win && mosPos.x > 330 && mosPos.x < 400 && mosPos.y>380 && mosPos.y < 420) {
					win = true;
					cnt = 1;
					poslevel1 = true;
					poslevel2 = true;

				}
				if (mosPos.x > 680 && mosPos.x < 750 && mosPos.y < 55) {
					cnt = 1;
					poslevel1 = true;
					poslevel2 = true;


				}


			}



		}

		window.clear();
		if (cnt == 0) {

			window.draw(mainbackground);
			window.draw(Men1);

		}
		if (cnt == 1) {
			window.draw(mainbackground);
			window.draw(menu2);
			play.draw(window);
		}

		if (pagenum == 1) {
			cnt = 2;
			pagenum = 100;


		}
		if (pagenum == 2) {
			window.clear();
			window.draw(mainbackground);
			window.draw(ownermenue);

		}
		if (pagenum == 3) {
			window.clear();
			window.draw(mainbackground);
			window.draw(helpmenue);
		}
		if (pagenum == -1) {
			window.close();
		}

		if (cnt == 2) {
			window.draw(setbtn);
			level = llmenu(window);
			if (level != -1)
				cnt = 3;

		}

		else if (cnt == 3) {
			window.draw(mainbackground);

			/////////////choose  menu for two players or one player///////////////////////////
			RectangleShape chplayer(Vector2f(520, 520));
			Texture txchplayer;
			chplayer.setPosition(100, 80);
			txchplayer.loadFromFile("first.png");
			chplayer.setTexture(&txchplayer);

			window.draw(chplayer);

		}
		else if (cnt == 4) {
			window.draw(mainbackground);
			chooseflav_one(window);




		}
		if (cnt == 5) {
			window.draw(mainbackground);
			chooseflav_two(window);
		}
		if (cnt == 4 && oneflav != "null")
		{
			if (level == 11) {
				level1(window);
			}
			else {
				level2(window);
			}

		}
		else if (cnt == 5 && twoflav[0] != "null" && twoflav[1] != "null") {
			if (level == 11) {
				level1(window);
			}
			else {
				level2(window);
			}


		}

		window.draw(setbtn);
		window.display();

		deltatime = gameclock.getElapsedTime().asSeconds();






	}
}









