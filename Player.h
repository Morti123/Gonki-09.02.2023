#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"

struct Player {
	sf::Texture texture;
	sf::Sprite sprite;
};
void playerInit(Player& obj, sf::Vector2f pos, std::string fileName) {
	obj.texture.loadFromFile(fileName);
	obj.sprite.setTexture(obj.texture);
	obj.sprite.setPosition(pos);
}
void playerUpdate(Player& obj) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { obj.sprite.move(-5, 0); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { obj.sprite.move(5, 0); }
	if (obj.sprite.getPosition().x <= 150.f) {
		obj.sprite.setPosition(150.f, obj.sprite.getPosition().y);
	}
	if (obj.sprite.getPosition().x >= 350.f) {
		obj.sprite.setPosition(450-100, obj.sprite.getPosition().y);
	}
}

void playerDraw(sf::RenderWindow& window, Player& obj) {
	window.draw(obj.sprite);
}