#include "Play.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
Play::Play(float width, float height) {
	font.loadFromFile("ARCADECLASSIC.otf");
	playmenu[0].setFont(font);
	playmenu[0].setFillColor(Color{ 0, 0, 0 });
	playmenu[0].setString("Play");
	playmenu[0].setCharacterSize(50);
	playmenu[0].setPosition(Vector2f(320, 310));

	//second word
	playmenu[1].setFont(font);
	playmenu[1].setFillColor(Color{ 255, 204, 0 });
	playmenu[1].setString("owners");
	playmenu[1].setCharacterSize(50);
	playmenu[1].setPosition(Vector2f(300, 350));


	// third word
	playmenu[2].setFont(font);
	playmenu[2].setFillColor(Color{ 255, 204, 0 });
	playmenu[2].setString("help");
	playmenu[2].setCharacterSize(50);
	playmenu[2].setPosition(Vector2f(325, 400));

	// fourth word
	playmenu[3].setFont(font);
	playmenu[3].setFillColor(Color{ 255, 204, 0 });
	playmenu[3].setString("Exit");
	playmenu[3].setCharacterSize(50);
	playmenu[3].setPosition(Vector2f(325, 450));


	selected1 = 0;




}
Play::~Play() {}

void  Play::selectd(int num) {
	selected1 = num;
}
// drawing menue
void Play::draw(RenderWindow& window) {

	for (int i = 0; i < 4; i++) {
		window.draw(playmenu[i]);
	}
}
// movements
void Play::MoveDown() {
	if (selected1 + 1 <= 4) {
		playmenu[selected1].setFillColor(Color{ 255, 204, 0 });
		selected1++;
		if (selected1 == 4) {
			selected1 = 0;
		}
		playmenu[selected1].setFillColor(Color{ 0, 0, 0 });
	}
}
void Play::MoveUp() {
	if (selected1 - 1 >= -1) {
		playmenu[selected1].setFillColor(Color{ 255, 204, 0 });
		selected1--;
		if (selected1 == -1) {
			selected1 = 3;
		}
		playmenu[selected1].setFillColor(Color{ 0, 0, 0 });
	}
}



