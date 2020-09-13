#include<bangtal.h>
using namespace bangtal;

int main() {
	auto room1 = Scene::create("방1", "images/배경-2.png");

	auto room1_door1_opened = false; auto room1_door1_locked = true;
	auto room1_door1 = Object::create("images/문-왼쪽-닫힘.png", room1, 320, 270);
	auto room1_door2_opened = false; auto room1_door2_locked = true;
	auto room1_door2 = Object::create("images/문-오른쪽-닫힘.png", room1, 900, 270);
	auto room1_key1 = Object::create("images/열쇠2.png", room1, 200, 150);
	room1_key1->setScale(0.03f);

	auto cloverkey = Object::create("images/클로버키.png", room1, 590, 210);
	cloverkey->setScale(0.2f);
	auto room1_plant1 = Object::create("images/화분.png", room1, 500, 200);
	room1_plant1->setScale(1.7f);
	auto room1_plant1_moved = false;

	auto room1_keypad1 = Object::create("images/키패드.png", room1, 850, 400);
	room1_keypad1->setScale(4.0f);
	

	//방1 생성

	auto room2 = Scene::create("방2", "images/배경-1.png");
	auto Rat_Catch = Scene::create("쥐를 잡자!", "images/통로_.png");

	auto room2_door1 = Object::create("images/문-왼쪽-열림.png", room2, 320, 300);
	auto room2_door2_opened = false; auto room2_door2_locked = true;
	auto room2_door2 = Object::create("images/문-오른쪽-닫힘.png", room2, 900, 250);
	auto room2_door3_opened = false; auto room2_door3_locked = true;
	auto room2_door3 = Object::create("images/문-오른쪽-닫힘.png", room2, 1100, 220,false);//최종 나가는 문
	auto room2_keypad1 = Object::create("images/키패드.png", room2, 850, 400);
	room2_keypad1->setScale(4.0f);
	auto room2_button = Object::create("images/스위치.png", room2, 450, 600);
	room2_button->setScale(3.0f);
	auto room2_light = true;
	auto room2_note = Object::create("images/note.png", room2, 170, 400);
	room2_note->setScale(0.1f);
	auto room2_hole = Object::create("images/통로.png", room2, 550, 500);
	
	auto room2_finalkeypad = Object::create("images/열쇠판_.png", room2, 200, 100);
	//방2 생성

	auto Keyboard = Scene::create("키패드", "images/열쇠판.png");
	auto Heart = Object::create("images/하트_구멍.png", Keyboard, 250, 370);
	auto Spade = Object::create("images/스페이드_구멍.png", Keyboard,250,120 );
	auto Clover = Object::create("images/클로버_구멍.png", Keyboard,780,120 );
	auto Dia = Object::create("images/다이아_구멍.png", Keyboard, 780, 370);
	auto Key_hole = Object::create("images/열쇠위치.png", Keyboard, 570, 170);
	auto Finalkey = Object::create("images/열쇠_.png", Keyboard, 560, 220,false);
	auto Keyboard_arrow = Object::create("images/화살표_아래.png", Keyboard, 600, 10);
	Keyboard_arrow->setScale(0.2f);
	Finalkey->setScale(2.0f);
		Heart->setScale(0.8f);
		Spade->setScale(0.8f);
		Clover->setScale(0.8f);
		Dia->setScale(0.8f);
		auto Heart_locked = true;
		auto Spade_locked = true;
		auto Clover_locked = true;
		auto Dia_locked = true;

	
	//열쇠판 생성

	auto room3 = Scene::create("방3", "images/배경-1.png");
	auto room3_window = Object::create("images/창문_닫힘.png", room3, 700, 300);
	auto room3_window_closed = true;
	auto room3_door1 = Object::create("images/문-왼쪽-열림.png", room3, 50, 255);
	auto room3_table = Object::create("images/테이블.png", room3, 320, 100);
	room3_table->setScale(0.8f);
	auto room3_fish = Object::create("images/fish.png", room3, 550, 300);
	room3_fish->setScale(0.07f);
	auto room3_knife = Object::create("images/knife.png", room3, 420, 310);
	room3_knife->setScale(0.05f);

	
	//방3 생성

	auto Sea = Scene::create("창문 밖", "images/배경_부둣가.png");
	auto cat = Object::create("images/cat_key.png", Sea, 760, 200);
	cat->setScale(0.3f);
	auto heartkey = Object::create("images/하트키.png", Sea, 750, 100, false);
	heartkey->setScale(0.2f);
	auto Sea_arrow = Object::create("images/화살표_아래.png", Sea,640, 50);
	Sea_arrow->setScale(0.2f);
	//부둣가 생성


	auto room4 = Scene::create("방4", "images/배경-3.png");
	auto room4_door1 = Object::create("images/문-오른쪽-열림.png", room4, 900, 270);
	auto room4_teddy = Object::create("images/teddy_bear.png", room4, 300, 200);
	room4_teddy->setScale(0.4f);
	auto diakey = Object::create("images/다이아키.png", room4, 380, 270,false);
	diakey->setScale(0.2f);
	//방4 생성

	room1_key1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		room1_key1->pick();
		showMessage("열쇠를 주웠다.");

		return true;

	});

	cloverkey->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		cloverkey->pick();
		showMessage("클로버 모양의 무언가를 주웠다. 어디에 쓰는 물건일까?");
		return true;

	});

	room1_door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (room1_door1_opened == true) {
			room4->enter();
		}
		else if (room1_key1->isHanded()) {
			room1_door1->setImage("images/문-왼쪽-열림.png");
			room1_door1_opened = true;
		}


		else { showMessage("열쇠가 필요하다."); }


		return true;
	});

	room1_door2->setOnKeypadCallback([&](ObjectPtr object)->bool {
		room1_door2_locked = false;
		showMessage("철컥- 문이 열리는 소리가 들렸다");

		return true;
	});

	room1_keypad1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showKeypad("SECRET", room1_door2);

		return true;
	});

	room1_door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (room1_door2_locked) {
			showMessage("문이 잠겨있다. 비밀번호를 찾아야 할 것 같다.");

		}

		else if (room1_door2_opened == true) {
			room2->enter();
		}
		else {
			room1_door2->setImage("images/문-오른쪽-열림.png");
			room1_door2_opened = true;

		}


		return true;

	});

	room1_plant1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (room1_plant1_moved == false)
		{
			if (action == MouseAction::MOUSE_DRAG_LEFT) {
				room1_plant1->locate(room1, 400, 200);
				showMessage("화분 뒤에 뭔가가 있다!");
				room1_plant1_moved = true;
			}
			else if (action == MouseAction::MOUSE_DRAG_UP) {
				room1_plant1->locate(room1, 500, 300);
				showMessage("화분 뒤에 뭔가가 있다!");
				room1_plant1_moved = true;

			}
			else if (action == MouseAction::MOUSE_DRAG_RIGHT) {
				room1_plant1->locate(room1, 650, 200);
				showMessage("화분 뒤에 뭔가가 있다!");
				room1_plant1_moved = true;
			}

		}

		return true;
	});

	//방1 동작

	room2_door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		room1->enter();
		return true;
	});

	room2_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (room2_light == true) {
			room2->setLight(0.3f);
			room2_light = false;
			showMessage("숨겨진 문이 나타났다!!");
			room2_door3->show();
		}
		else
		{
			room2->setLight(1);
			room2_light = true;
			
			room2_door3->hide();
		}

		return true;
	});

	room2_door2->setOnKeypadCallback([&](ObjectPtr object)->bool {
		room2_door2_locked = false;
		showMessage("철컥- 문이 열리는 소리가 들렸다");

		return true;
	});

	room2_keypad1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showKeypad("BANGTAL", room2_door2);

		return true;
	});

	room2_door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (room2_door2_locked) {
			showMessage("문이 잠겨있다. 비밀번호를 찾아야 할 것 같다.");

		}

		else if (room2_door2_opened == true) {
			room3->enter();
		}
		else {
			room2_door2->setImage("images/문-오른쪽-열림.png");
			room2_door2_opened = true;

		}


		return true;

	});

	room2_note->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showImageViewer("images/note_.png");
		return true;

	});

	room2_hole->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		Rat_Catch->enter();
		return true;

	});

	//쥐잡기 미니게임
	

	auto spadekey = Object::create("images/스페이드키.png", Rat_Catch, 500, 100, false);


	auto rat1 = Object::create("images/mouse.png", Rat_Catch, 100, 100, false);
	auto rat2 = Object::create("images/mouse.png", Rat_Catch, 800, 300, false);
	auto rat3 = Object::create("images/mouse.png", Rat_Catch, 900, 20, false);
	auto rat4 = Object::create("images/mouse.png", Rat_Catch, 400, 50, false);
	auto rat5 = Object::create("images/mouse.png", Rat_Catch, 600, 100, false);
	auto rat6 = Object::create("images/mouse.png", Rat_Catch, 700, 300, false);
	auto rat7 = Object::create("images/mouse.png", Rat_Catch, 500, 200, false);
	rat1->setScale(0.4f);
	rat2->setScale(0.4f);
	rat3->setScale(0.4f);
	rat4->setScale(0.4f);
	rat5->setScale(0.4f);
	rat6->setScale(0.4f);
	rat7->setScale(0.4f);
	rat1->setScale(0.4f);


	auto startB = Object::create("images/start.png", Rat_Catch, 590, 70);

	auto endB = Object::create("images/end.png", Rat_Catch, 590, 20);


	auto timer = Timer::create(10.f);
	


	startB->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		startB->hide();
		endB->hide();
		timer->set(10.f);

		rat1->show();

		timer->start();

		return 0;
	});

	endB->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		room2->enter();
		return true;

	});

	rat1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		rat1->hide();
		rat2->show();
		return true;

	});

	rat2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		rat2->hide();
		rat3->show();
		return true;

	});

	rat3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		rat3->hide();
		rat4->show();
		return true;

	});

	rat4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		rat4->hide();
		rat5->show();
		return true;

	});

	rat5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		rat5->hide();
		rat6->show();
		return true;

	});

	rat6->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		rat6->hide();
		rat7->show();
		return true;

	});

	rat7->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		rat7->hide();
		timer->stop();
		
		spadekey->show();
		showMessage("뭔가가 나타났다!");
		return true;

	});

	spadekey->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		spadekey->pick();
		showMessage("스페이드 모양의 무언가를 주웠다. 어디에 쓰는 물건일까?");
		endB->show();
		return true;

	});


	showTimer(timer);

	timer->setOnTimerCallback([&](TimerPtr)->bool {
		showMessage("실패...!! 다시 한번 도전해 보자.");
		rat1->hide();
		rat2->hide();
		rat3->hide();
		rat4->hide();
		rat5->hide();
		rat6->hide();
		rat7->hide();
		startB->setImage("images/restart.png");
		startB->show();
		endB->show();
		return true;
	});

	//쥐잡기 미니게임


	room2_finalkeypad->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		Keyboard->enter();
		return true;

	});

	//열쇠판 작동
	Heart->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (heartkey->isHanded()) {
			Heart_locked = false;
			Heart->setImage("images/하트키.png");
			showMessage("하트모양을 끼웠다.");
		}
		else {
			showMessage("뭔가를 끼워야 할 것 같이 생겼다.");
		}
		return true;
	});

	Spade->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (spadekey->isHanded()) {
			Spade_locked = false;
			Spade->setImage("images/스페이드키.png");
			showMessage("스페이드모양을 끼웠다.");
		}
		else {
			showMessage("뭔가를 끼워야 할 것 같이 생겼다.");
		}
		return true;
	});

	Clover->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (cloverkey->isHanded()) {
			Clover_locked = false;
			Clover->setImage("images/클로버키.png");
			showMessage("클로버모양을 끼웠다.");
		}
		else {
			showMessage("뭔가를 끼워야 할 것 같이 생겼다.");
		}
		return true;
	});
	Dia->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (diakey->isHanded()) {
			Dia_locked = false;
			Dia->setImage("images/다이아키.png");
			showMessage("다이아모양을 끼웠다.");
		}
		else {
			showMessage("뭔가를 끼워야 할 것 같이 생겼다.");
		}
		return true;
	});



	Key_hole->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if ((Heart_locked == false) && (Spade_locked == false) && (Clover_locked == false) && (Dia_locked == false)) {
			showMessage("열쇠가 나타났다!");
			Finalkey->show();
		}

		else {
			showMessage("이 곳을 열어야 할 것 같다.");
		}
		return true;
	});

	Finalkey->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		Finalkey->pick();
		return true;
	});
	
	Keyboard_arrow->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		room2->enter();
		return true;
	});
	//열쇠판 작동
	room2_door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (room2_door3_opened == true) {
			endGame();
		}
		else if (Finalkey->isHanded()) {
			room2_door3->setImage("images/문-오른쪽-열림.png");
			room2_door3_opened = true;
		}


		else { showMessage("열쇠가 필요하다."); }


		return true;
	});

	//방2 동작
	room3_door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		room2->enter();
		return true;
	});

	room3_window->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (room3_window_closed == false) {
			Sea->enter();
		}
		else if (room3_window_closed==true) {
			room3_window->setImage("images/창문_열림.png");
			showMessage("창문 밖으로 나갈 수 있을 것 같다.");
			room3_window_closed = false;
		}


		return true;
	});

	room3_fish->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		room3_fish->pick();
		showMessage("생선을 주웠다.");
		return true;

	});

	room3_knife->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		room3_knife->pick();
		showMessage("칼을 주웠다");

		return true;

	});
	//방3 동작

	Sea_arrow->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		room3->enter();
		return true;

	});

	heartkey->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		heartkey->pick();
		showMessage("하트 모양의 무언가를 주웠다. 어디에 쓰는 물건일까?");
		return true;

	});
	cat->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (room3_fish->isHanded()) {
			cat->setImage("images/cat.png");
			heartkey->show();
			showMessage("생선을 주니 고양이가 뭔가를 떨어뜨렸다!");
		}

		else {
			showMessage("고양이가 굉장히 화가 난 듯 하다. 어떻게 하면 다가갈 수 있을까?");
		}

		return true;
	});

	//부두 동작

	room4_door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		room1->enter();
		return true;
	});

	diakey->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		diakey->pick();
		showMessage("다이아몬드 모양의 무언가를 주웠다. 어디에 쓰는 물건일까?");

		return true;

	});

	room4_teddy->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (room3_knife->isHanded()) {
			room4_teddy->setImage("images/teddy_bear_teared.png");
			diakey->show();
			showMessage("곰인형을 찢었더니 무언가 나왔다!");
		}

		else {
			showMessage("곰인형 안에 무언가 들어 있는 것 같다.");
		}

		return true;
	});
	//방4 동작




	startGame(room1);
}