#ifndef TIMER_HPP
#define TIMER_HPP
#include <ctime>
#include <QObject>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
     class MAINDATA : public QObject {
         Q_OBJECT
           public:
              explicit MAINDATA (QObject* parent = nullptr) : QObject(parent) {
                   Q_UNUSED(parent);
             }
              Q_INVOKABLE QString datetimer(){
                    QQmlApplicationEngine engine;
                    time_t now = time(NULL);
                    tm *timer = localtime(&now);
                    QString date = QString::number(timer->tm_mday) + "/" + QString::number(1+timer->tm_mon) + "/" + QString::number(1900+timer->tm_year);
                  return date;
                }

              Q_INVOKABLE QString realtimer(){
                    QQmlApplicationEngine engine;
                    time_t now = time(NULL);
                    tm *timer = localtime(&now);
                    QString timerqml = QString::number(timer->tm_hour) + ":" + QString::number(timer->tm_min) + ":" + QString::number(timer->tm_sec);

                  return timerqml;
                }
            };

#endif // TIMER_HPP
