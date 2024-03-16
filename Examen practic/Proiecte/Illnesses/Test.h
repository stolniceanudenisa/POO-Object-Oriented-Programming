#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test.h"
#include "Service.h"

class Test : public QMainWindow
{
    Q_OBJECT

public:
    Test(Service& service, QWidget *parent = Q_NULLPTR);

private:
    Ui::TestClass ui;
    Service& service;

    void populate_list();
    void connections();

    int get_selected_index();
    void show_symptoms();
    void filter();


    void buildWindow();
    QMenu* menu;
    QAction* action;
};
