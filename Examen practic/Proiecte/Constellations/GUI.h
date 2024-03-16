#pragma once

#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qgridlayout.h>
#include <qformlayout.h>
#include <qlayout.h>
#include <qboxlayout.h>
#include <qlineedit.h>
#include <qlabel.h>



#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"

#include "Model.h"
#include "Service.h"

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    GUI(Astronomer astronomer, Service& s, Model* m, QWidget *parent = Q_NULLPTR);

private:
    Ui::GUIClass ui;
    Service& service;
    Model* model;
    Astronomer astronomer;

    void listItemClicked();

    int getSelectedIndex();
    void connections();

    void update();


    void addStar();
    void filter();
    void filterCheckBox();
    void view();
};
