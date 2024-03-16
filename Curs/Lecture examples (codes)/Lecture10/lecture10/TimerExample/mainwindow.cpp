#include "mainwindow.h"

#include <QDebug>
#include <QSound>
#include <QMessageBox>
#include <QApplication>

AlarmWidget::AlarmWidget(QObject *parent):m_soundPlayer{"://alarm_sound.wav"}
{
    m_intervalMillis = 5000;
    m_timer.setInterval(m_intervalMillis);
    m_timer.setSingleShot(false);
    m_timer.start();

    auto connected = connect(&m_timer, &QTimer::timeout, this, &AlarmWidget::onTimeExpired);
    Q_ASSERT(connected);
    Q_UNUSED(connected)
}

AlarmWidget::~AlarmWidget()
{
}

void AlarmWidget::onTimeExpired()
{
    m_soundPlayer.play();

    QMessageBox msgBox;
    msgBox.setText("You need a break :) ");
    msgBox.setStandardButtons(QMessageBox::Close | QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Ok:
        qDebug()<<"Ok pressed";
        m_soundPlayer.stop();
        break;
    case QMessageBox::Close:
        qDebug()<<"Close pressed ";
        QApplication::instance()->quit();
        break;
    }
}

