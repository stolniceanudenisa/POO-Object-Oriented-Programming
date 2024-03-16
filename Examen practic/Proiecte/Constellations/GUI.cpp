#include "GUI.h"
#include <QSortFilterProxyModel>
#include "StarsView.h"

using namespace std;

GUI::GUI(Astronomer astronomer, Service& s, Model* m, QWidget *parent)
    : QMainWindow(parent), service(s), model(m), astronomer(astronomer)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromStdString(astronomer.getName()));
    this->ui.tableView->setModel(model);
    this->connections();
}


void GUI::listItemClicked()
{
    QMessageBox::critical(this, "Error", "Please provide all attributes for a turret");
}

int GUI::getSelectedIndex()
{
    QModelIndexList selected_indexes = this->ui.tableView->selectionModel()->selectedIndexes();
    if (selected_indexes.size() == 0)
    {
        return -1;
    }
    int selected_index = selected_indexes.at(0).row();
    return selected_index;
}


void GUI::connections()
{
//    QObject::connect(this->ui.tableView, &QTableView::clicked, this, &GUI::listItemClicked);
    QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &GUI::addStar);
    QObject::connect(this->ui.search_lineEdit, &QLineEdit::textChanged, this, &GUI::filter);
    QObject::connect(this->ui.checkBox, &QCheckBox::stateChanged, this, &GUI::filterCheckBox);
    QObject::connect(this->ui.viewButton, &QPushButton::clicked, this, &GUI::view);
}

void GUI::update()
{
    this->model->update();
}

void GUI::addStar()
{
    if (this->ui.name_lineEdit->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "Please provide name");
        return;
    }
    if (this->ui.diameter_lineEdit->text().toInt() <= 0)
    {
        QMessageBox::critical(this, "Error", "Diameter must be positive");
        return;
    }

    string name = this->ui.name_lineEdit->text().toStdString();
    string constellation = this->astronomer.getConstellation();
    int diameter = this->ui.diameter_lineEdit->text().toInt();
    int RA = this->ui.RA_lineEdit->text().toInt();
    int Dec = this->ui.Dec_lineEdit->text().toInt();

    try
    {
        this->service.addStar(name, constellation, RA, Dec, diameter);
    }
    catch (exception& ex)
    {
        QMessageBox::critical(this, "Error", QString::fromStdString(ex.what()));
        return;
    }

    update();
}

void GUI::filter()
{
    this->ui.search_listWidget->clear();

    string str = this->ui.search_lineEdit->text().toStdString();
    if (str.size() == 0)
    {
        this->ui.search_listWidget->clear();
        return;
    }
    
    vector<Star> items = this->service.searchStar(str);

    for (auto it : items)
    {
        this->ui.search_listWidget->addItem(QString::fromStdString(it.toString()));
    }
}

void GUI::filterCheckBox()
{
    if (this->ui.checkBox->isChecked())
    {
        QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel{};
        proxyModel->setSourceModel(this->model);
        
        // filtering
        proxyModel->setFilterRegExp(QRegExp(QString::fromStdString(this->astronomer.getConstellation()), Qt::CaseSensitive, QRegExp::FixedString));
        proxyModel->setFilterKeyColumn(1);

        this->ui.tableView->setModel(proxyModel);

    }
    else
    {
        this->ui.tableView->setModel(model);
    }

}

void GUI::view()
{
    if (getSelectedIndex() == -1)
        return;
    Star selectedStar = this->service.getStars()[getSelectedIndex()];
    std::string constellation = selectedStar.getConstellation();

    std::vector<Star> starsInConstellation = this->service.getStarsByConstellation(constellation);
    
    StarsView* starview = new StarsView{ selectedStar, starsInConstellation };
    starview->show();
}

