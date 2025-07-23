#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <optional>
using namespace sf;

class Player
{
private:

	std::unique_ptr<Sprite> sprite;
	std::unique_ptr<Texture> texture;

public:

	Player();
	~Player();

	void Init_();

	void Update_Player();
	void Render_Player(RenderWindow *window);
};
