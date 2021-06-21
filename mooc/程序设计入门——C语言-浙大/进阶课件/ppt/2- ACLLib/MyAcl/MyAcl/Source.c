#include "acllib.h"

void Paint1();
void Paint2();
void Paint3();

void ImageTest();
int Setup()
{
	//Paint1();
	// Paint2();
	  //Paint3();
	
	ImageTest();
	return 0;
}


void ImageTest(){
	initWindow("Image", DEFAULT, DEFAULT, 500, 500);
	beginPaint();
	//void ellipse(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect);
	for (int i = 0; i < 6; i++)
	{
		i++;
	}
	ellipse(0, 0, 50, 50);
	rectangle(60, 60, 80, 80);

	/*int point[5][2] = { { 80, 80 }, { 80, 200 }, { 200, 44 }, { 300, 66 }, { 420, 400 } };
	polygon(point, 5);*/


	/*void arc(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, \
		int nXStartArc, int nYStartArc, int nXEndArc, int nYEndArc);
		说明：
		绘制一段圆（椭圆）弧。
		前 4 个参数给出一个矩形的左上角、 右下角定点。 绘制的弧线内切该矩形。 后两个参数
		指定两个点，这两个点到矩形中心的连线作为圆弧起始、终止位置的线。
		该函数的参数与 chrod、 pie 相同，建议实际测试了解其使用方法*/
	/*void pie(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, \
int nXRadial1, int nYRadial1, int nXRadial2, int nYRadial2);*/
	arc(40, 40, 300, 300, 140, 140, 220, 220);
	//pie(80, 100, 100, 200, 12, 12, 44, 44);
	endPaint();

}

void Paint1(){
	initWindow("Paint1", DEFAULT, DEFAULT, 350, 350);
	beginPaint();

	setBrushColor(RGB(210, 229, 163));//1
	rectangle(50, 0, 350, 50);

	setBrushColor(RGB(223, 88, 84));//2
	rectangle(0, 0, 50, 300);

	setBrushColor(RGB(255, 89, 175));//3
	rectangle(0, 300, 300, 350);

	setBrushColor(RGB(209, 0, 2));//4
	rectangle(300, 100, 350, 350);

	setBrushColor(RGB(190, 143, 245));//5
	rectangle(100, 50, 350, 100);

	setBrushColor(RGB(0, 208, 0));//6
	rectangle(50, 50, 100, 250);

	setBrushColor(RGB(213, 247, 248));//7
	rectangle(50, 250, 250, 300);

	setBrushColor(RGB(255, 207, 1));//8
	rectangle(250, 150, 300, 300);

	setBrushColor(RGB(255, 220, 901));//9
	rectangle(150, 100, 300, 150);

	setBrushColor(RGB(0, 154, 206));//10
	rectangle(100, 100, 150, 200);

	setBrushColor(RGB(96, 219, 94));//11
	rectangle(100, 200, 200, 250);

	setBrushColor(RGB(255, 105, 0));//12
	rectangle(200, 150, 250, 250);

	setBrushColor(RGB(133, 120, 158));//13
	rectangle(150, 150, 200, 200);

	endPaint();
}

void Paint2(){
	initWindow("Paint2", DEFAULT, DEFAULT, 300, 300);
	int color = 0, row = 0, col = 0;
	beginPaint();

	for (row = 0; row<3; row++){
		for (col = 0; col<3; col++){
			if (color == 0){
				setBrushColor(WHITE);
				color = 1;
			}
			else{
				setBrushColor(BLACK);
				color = 0;
			}
			rectangle(100 * col, 100 * row, 100 + 100 * col, 100 + 100 * row);

			if (color == 0){
				setBrushColor(WHITE);
			}
			else{
				setBrushColor(BLACK);
			}
			pie(100 * col - 50, 100 * row - 50, 100 * col + 50, 100 * row + 50, 100 * col, 100 * row + 50, 100 * col + 50, 100 * row);
			pie(100 * col + 50, 100 * row - 50, 100 * col + 150, 100 * row + 50, 100 * col + 50, 100 * row, 100 * col + 100, 100 * row + 50);
			pie(100 * col - 50, 100 * row + 50, 100 * col + 50, 100 * row + 150, 100 * col + 50, 100 * row + 100, 100 * col, 100 * row + 50);
			pie(100 * col + 50, 100 * row + 50, 100 * col + 150, 100 * row + 150, 100 * col + 100, 100 * row + 50, 100 * col + 50, 100 * row + 100);
		}
	}

	endPaint();
}

void Paint3(){
	initWindow("Paint3", DEFAULT, DEFAULT, 476, 558);
	beginPaint();
	POINT point[4];

	setBrushColor(WHITE);
	point[0].x = 122;
	point[0].y = 74;
	point[1].x = 238;
	point[1].y = 12;
	point[2].x = 355;
	point[2].y = 74;
	point[3].x = 238;
	point[3].y = 137;
	polygon(point, 4);

	setBrushColor(BLACK);
	point[0].x = 0;
	point[0].y = 144;
	point[1].x = 122;
	point[1].y = 74;
	point[2].x = 122;
	point[2].y = 215;
	point[3].x = 0;
	point[3].y = 277;
	polygon(point, 4);
	point[0].x = 238;
	point[0].y = 137;
	point[1].x = 355;
	point[1].y = 74;
	point[2].x = 355;
	point[2].y = 212;
	point[3].x = 238;
	point[3].y = 277;
	polygon(point, 4);
	point[0].x = 122;
	point[0].y = 344;
	point[1].x = 238;
	point[1].y = 277;
	point[2].x = 238;
	point[2].y = 416;
	point[3].x = 122;
	point[3].y = 484;
	polygon(point, 4);
	point[0].x = 355;
	point[0].y = 351;
	point[1].x = 476;
	point[1].y = 277;
	point[2].x = 476;
	point[2].y = 419;
	point[3].x = 355;
	point[3].y = 489;
	polygon(point, 4);

	setBrushColor(RGB(178, 178, 178));
	point[0].x = 122;
	point[0].y = 74;
	point[1].x = 238;
	point[1].y = 137;
	point[2].x = 238;
	point[2].y = 277;
	point[3].x = 122;
	point[3].y = 215;
	polygon(point, 4);
	point[0].x = 355;
	point[0].y = 74;
	point[1].x = 476;
	point[1].y = 141;
	point[2].x = 476;
	point[2].y = 277;
	point[3].x = 355;
	point[3].y = 212;
	polygon(point, 4);
	point[0].x = 355;
	point[0].y = 212;
	point[1].x = 476;
	point[1].y = 277;
	point[2].x = 355;
	point[2].y = 351;
	point[3].x = 238;
	point[3].y = 277;
	polygon(point, 4);
	point[0].x = 122;
	point[0].y = 215;
	point[1].x = 238;
	point[1].y = 277;
	point[2].x = 122;
	point[2].y = 344;
	point[3].x = 0;
	point[3].y = 277;
	polygon(point, 4);
	point[0].x = 0;
	point[0].y = 277;
	point[1].x = 122;
	point[1].y = 344;
	point[2].x = 122;
	point[2].y = 484;
	point[3].x = 0;
	point[3].y = 419;
	polygon(point, 4);
	point[0].x = 238;
	point[0].y = 277;
	point[1].x = 355;
	point[1].y = 351;
	point[2].x = 355;
	point[2].y = 489;
	point[3].x = 238;
	point[3].y = 416;
	polygon(point, 4);
	point[0].x = 238;
	point[0].y = 416;
	point[1].x = 355;
	point[1].y = 489;
	point[2].x = 240;
	point[2].y = 550;
	point[3].x = 122;
	point[3].y = 484;
	polygon(point, 4);

	endPaint();
}