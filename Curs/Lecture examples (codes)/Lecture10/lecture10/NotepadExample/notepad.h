#ifndef LECTURE10_DEMO_NOTEPAD_H
#define LECTURE10_DEMO_NOTEPAD_H

#include <QtWidgets/QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QTextEdit>

class Notepad : public QMainWindow
{
	Q_OBJECT
public:
	Notepad(QWidget *parent = 0);
	~Notepad();

	void buildWindow();

private:

    QMenu* m_fileMenu;
    QAction *m_openAction;
    QAction *m_saveAction;
    QAction *m_exitAction;
    QTextEdit* m_textEdit;

    std::string m_filename;

	void connectSignalsAndSlots();

public slots:
	void open();
	void save();
};

#endif // LECTURE10_DEMO_NOTEPAD_H
