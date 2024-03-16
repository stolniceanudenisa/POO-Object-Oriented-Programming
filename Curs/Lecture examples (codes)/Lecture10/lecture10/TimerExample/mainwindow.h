#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QSound>
#include <QTimer>
class AlarmWidget : public QWidget
{
    Q_OBJECT
public:
    AlarmWidget(QObject *parent = nullptr);
    ~AlarmWidget();

public slots:
    void onTimeExpired();

private:
    QTimer  m_timer;
    QSound  m_soundPlayer;
    int     m_intervalMillis;
};
#endif // MAINWINDOW_H
