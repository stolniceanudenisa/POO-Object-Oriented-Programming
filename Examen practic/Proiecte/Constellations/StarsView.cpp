#include "StarsView.h"

StarsView::StarsView(Star s, std::vector<Star> stars, QWidget *parent)
	: QWidget(parent), stars(stars), clickedStar(s)
{
	ui.setupUi(this);
	populate();
}


StarsView::~StarsView()
{
}

void StarsView::populate()
{
	this->ui.listWidget->clear();
	for (int i=0;i<stars.size();i++)
	{
		this->ui.listWidget->addItem(QString::fromStdString(stars[i].toString()));
    }

}
