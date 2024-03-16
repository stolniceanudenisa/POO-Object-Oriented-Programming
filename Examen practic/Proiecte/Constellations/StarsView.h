#pragma once

#include <QWidget>
#include "ui_StarsView.h"

#include "Domain.h"

class StarsView : public QWidget
{
	Q_OBJECT

public:
	StarsView(Star s, std::vector<Star> stars, QWidget *parent = Q_NULLPTR);
	~StarsView();

private:
	Ui::StarsView ui;
	std::vector<Star> stars;
	Star clickedStar;

	void populate();
};
