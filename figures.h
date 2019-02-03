//figures.h- Интерфейс модуля графических фигур
#ifndef figures_h
#define figures_h
//Базовый класс фигура
class TFigure
{
protected:
	int theCenterX, theCenterY;//центр фигуры        

public:
	TFigure(int tCenterX, int tCenterY);
	virtual void Show() = 0;//отобразить
};
#endif
