#include "notepad.h"
#include <QFileDialog>
#include <fstream>
#include <QMessageBox>
#include <sstream>
#include <QToolBar>
#include <QApplication>
#include <QStatusBar>

Notepad::Notepad(QWidget *parent)
	: QMainWindow(parent)
{

	this->buildWindow();
	this->connectSignalsAndSlots();
}

Notepad::~Notepad()
{}

void Notepad::buildWindow()
{
	// add the menu "File" to the menu bar
    this->m_fileMenu = this->menuBar()->addMenu("&File");

	// create open, save and exit actions
    this->m_openAction = new QAction("&Open", this);
    this->m_saveAction = new QAction("&Save", this);
    this->m_exitAction = new QAction("&Exit", this);

	// add the actions to the menu "File"
    this->m_fileMenu->addAction(this->m_openAction);
    this->m_fileMenu->addAction(this->m_saveAction);
    this->m_fileMenu->addSeparator();
    this->m_fileMenu->addAction(this->m_exitAction);

	// central widget
    this->m_textEdit = new QTextEdit{};
	QFont f{ "Verdana", 15 };
    this->m_textEdit->setFont(f);
    this->setCentralWidget(this->m_textEdit);

	// we can also create a file tool bar
	QToolBar* fileToolBar = addToolBar("&File");
    fileToolBar->addAction(m_openAction);
    fileToolBar->addAction(m_saveAction);

	statusBar()->showMessage("Status Message");
}

void Notepad::connectSignalsAndSlots()
{
    QObject::connect(m_openAction, &QAction::triggered, this, &Notepad::open);
    QObject::connect(m_saveAction, &QAction::triggered, this, &Notepad::save);
    QObject::connect(m_exitAction, &QAction::triggered, QApplication::instance(), &QApplication::quit);
}

void Notepad::open()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;C++ Files (*.cpp *.h)");
	if (fileName != "") 
	{
        this->m_filename = fileName.toStdString();

        std::ifstream f{ this->m_filename };
		if (!f.is_open())
		{
			QMessageBox::critical(0, "Error", "File could not be opened!");
			return;
		}

		std::stringstream s;
		s << f.rdbuf();
        this->m_textEdit->setText(QString::fromStdString(s.str()));
		f.close();
	}
}

void Notepad::save()
{
    std::ofstream f{ this->m_filename };
	if (!f.is_open())
	{
		QMessageBox::critical(0, "Error", "File could not be opened!");
		return;
	}

    f << this->m_textEdit->toPlainText().toStdString();
	f.close();
}
