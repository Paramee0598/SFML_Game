#include "Game.h"


//****************การทำงาน


// funcation คงที่


// funcation เฉพาะ



// funcation เริ่มต้น
void Game::inItWindow() //แสดงหน้า window
{
	std::ifstream ifs("Config/window.ini"); // เซ็ทแล้วให้อ่านค่าตัวอักษรจากไฟล์ภายนอก เพื่อมายัดใส่ใน โปรแกรม

	std::string title = "None"; // เซ็ทสตริงเป็น ว่าง
	sf::VideoMode window_bounds(600,600);
	unsigned frameratr_limt = 120; //สร้างตัวแปร เฟรมเรท
	bool vertical_sync_enabled = false; //สร้างตัวแปร VerticalSyncEnabled เป้น ผิด (0)


	if (ifs.is_open()) //เปิดมา
	{
		std::getline(ifs, title); // อ่านค่าต่อจากไตเติ้ล(น่าจะบรรทัดต่อมานะ)
		ifs >> window_bounds.width >> window_bounds.height; // อ่าน ความกว้าง-ยาว window
		ifs >> frameratr_limt; // อ่าน เฟรมลิมิต
		ifs >> vertical_sync_enabled; //อ่าน ค่า 1 , 0   **ทั้งหมดนี้อ่านจาก note pad** 
	}

	
	this-> window = new sf::RenderWindow (window_bounds, title); //เอามาจากตัวแปรด้านบน
	//       ^--------ตัวแปรชิดเอาพ้อยเตอร์---^
	//  แบบเก่าแบบนี้      sf::RenderWindow window(sf::VideoMode(600, 600), "GAME");
	this->window->setFramerateLimit(frameratr_limt); //เอามาจากตัวแปรด้านบน
	this->window->setVerticalSyncEnabled(vertical_sync_enabled); //เอามาจากตัวแปรด้านบน

}

Game::Game() //จะทำงานเลย เมื่อมีการให้ยืมคลาสใช้ เพราะมันคือส่วนของคลาสหลัก โดยไม่ต้องมาเรียกฟังก์ชั่นย่อยเพื่อเรียกใช้งาน ในส่วนของคลาสหลัก
{
	this->inItWindow(); //แสดงหน้า window
}


Game::~Game()
{
	delete this->window; ///ปิด wwindow
}

//funcation

void Game::updateDt()
{
	/*ยัดเวลาที่สร้างมาใส่ตัวแปร dtClock เพื่อใช้ แรนเดอร์*/

	this-> dt = this->dtClock.restart().asSeconds(); //หน่วงเวลาโดยใช้ ตัวแปร dtClock

	//system("cls"); //ลบแล้วอยู่ที่เดิม ไม่ต้องขึ้นบรรทัดใหม่
	


}

void Game::updateSFMLEvent() // sfml หลักที่ใช้แสดง window
{
	

	while (this->window->pollEvent(this->SFevent)) 
	{
		switch (this->SFevent.type) //แถบ window
		{
		case sf::Event::Closed:
			this->window->close();  // ปิด window ถ้ามีการสั่งปิด

			break;

		//case sf::Event::KeyPressed:
						//std::cout << "Key has been press" << std::endl;

						//switch (event.key.code)
						//{
						//case sf::Keyboard::A:
						//	std::cout << "A" << std::endl;


						//	break;
						//}

						//	break;

		}
	}

}

void Game::update() // จัดอยู่ในการ อัพเดท
{
	this->updateSFMLEvent(); //สั่งเปิด window
}

void Game::render()  
{

	this->window->clear(); // ล้าง

	// กระพริบเพื่อเปลี่ยนแปลง (แรนเดอร์)

	this->window->display(); //แสดง จอดำ //ที่ยังไม่ใส่อะไร

}

void Game::run()
{
	while (this->window->isOpen())  //วนไป
	{

		this->updateDt(); //ใช้งานหน่วงเวลา
		this->update();  //สั่งเปิด window
		this->render();   // สั่งล้าง เพื่อแรนเดอร์ใหม่ 

	}
}


