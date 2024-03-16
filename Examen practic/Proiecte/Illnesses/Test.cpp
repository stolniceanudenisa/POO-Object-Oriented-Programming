#include "Test.h"

using namespace std;

Test::Test(Service& service, QWidget *parent)
    : service(service), QMainWindow(parent)
{
    ui.setupUi(this);
    buildWindow();

    populate_list();
    connections();
    this->setWindowTitle("Illnesses");
}

void Test::populate_list()
{
    this->ui.items_listW->clear();
    vector<Item> items = this->service.get_all();

    for (auto i : items)
    {
        this->ui.items_listW->addItem(QString::fromStdString(i.getCategory()+" | "+i.getName()));
    }
}

void Test::connections()
{
      QObject::connect(this->ui.show_pushButton, &QPushButton::clicked, this, &Test::show_symptoms);
      QObject::connect(this->ui.search_lineEdit, &QLineEdit::textChanged, this, &Test::filter);
//      QObject::connect(this->ui.search_pushButton, &QPushButton::clicked, this, &Test::filter);

      QObject::connect(this->action, &QAction::triggered, QApplication::instance(), &QApplication::quit);
}

int Test::get_selected_index()
{
	QModelIndexList selected_indexes = this->ui.items_listW->selectionModel()->selectedIndexes();
	if (selected_indexes.size() == 0)
	{
//		this->location_lineEdit->clear();
//		this->size_lineEdit->clear();
//		this->auraLevel_lineEdit->clear();
//		this->separateParts_lineEdit->clear();
//		this->vision_lineEdit->clear();
		return -1;
	}
	int selected_index = selected_indexes.at(0).row();
	return selected_index;
}

void Test::show_symptoms()
{
    string name = this->ui.illness_lineEdit->text().toStdString();
    Item ill;
    
    vector<Item> v = this->service.get_all();
    for (auto illness : v)
    {
        if (illness.getName() == name)
            ill = illness;
    }
    std::string symptoms = ill.getSymptoms();
    std::vector<std::string> symp = ill.tokenize(symptoms, ',');

    this->ui.listWidget->clear();
    for (auto symptom : symp)
    {
        this->ui.listWidget->addItem(QString::fromStdString(symptom));
    }

}

void Test::filter()
{
    this->ui.items_listW->clear();

    if (this->ui.search_lineEdit->text().toStdString().size() == 0)
    {this->populate_list(); return;}

    string str = this->ui.search_lineEdit->text().toStdString();
    vector<Item> items= this->service.search(str);

    this->ui.items_listW->clear();
    for (auto it : items)
    {
        this->ui.items_listW->addItem(QString::fromStdString(it.getCategory() + " | " + it.getName()));
    }
}

void Test::buildWindow()
{
    this->menu = this->menuBar()->addMenu("Menu");
    this->action = new QAction{ "Exit" };
    this->menu->addAction(this->action);

    QToolBar* tool = addToolBar("Exit");
    tool->addAction(this->action);
}
