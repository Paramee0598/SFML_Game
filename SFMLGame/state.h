#ifndef STATE_H
#define STATE_H

#include<vector>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>

#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>


class state
{
private:

	// ตัวแปร sf
	std::vector<sf::Texture>textures;



	// ฟังก์ชั่น || ตัวแปรเริ่มต้น
	



public:

	
	state();
	virtual ~state();


	//funcation
	virtual void update() = 0;
	virtual void render() = 0;



};

#endif