//figures.h- ��������� ������ ����������� �����
#ifndef figures_h
#define figures_h
//������� ����� ������
class TFigure
{
protected:
	int theCenterX, theCenterY;//����� ������        

public:
	TFigure(int tCenterX, int tCenterY);
	virtual void Show() = 0;//����������
};
#endif
