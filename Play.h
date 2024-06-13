#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class Play
{
public:
	Text playmenu[4];
	Play(float width, float height);
	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void selectd(int n);
	int pressed() {
		return selected1;
	}
	~Play();

private:
	int selected1;
	Font font;

};

