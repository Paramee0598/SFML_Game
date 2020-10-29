#ifndef GAME_H
#define GAME_H


#include"state.h"

class Game
{
private:
	
	// ตัวแปร sf
	sf::RenderWindow  *window; //พ้อยเตอร์
	sf::Event SFevent;

	sf::Clock dtClock; //ค่าเวลา
	float dt; //ค่าเวลาแบบ ทศนิยม

	// ฟังก์ชั่น || ตัวแปรเริ่มต้น
	void inItWindow();



public:

	// funcation เฉพาะ
	Game();
	virtual ~Game();


	//funcation
	void updateDt(); 
	void updateSFMLEvent();
	void update();
	void render();
	void run();



};

#endif
