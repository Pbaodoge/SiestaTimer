//Backend code
#ifndef TIMER_HPP
#define TIMER_HPP
#include <ctime>
#include <QObject>
#include <QQmlContext>
     class MAINDATA : public QObject {
         Q_OBJECT
           private:
              QString timerqml, date, greetstr;
              time_t now;
              tm *timer;
           public:
              explicit MAINDATA (QObject* parent = nullptr) : QObject(parent) {
                   Q_UNUSED(parent);
                   timerqml = "";
                   date = "";
                   greetstr = "";
             }
              Q_INVOKABLE QString datetimer(){
                    now = time(NULL);
                    timer = localtime(&now);
                    date = ""; //delete the last updated string
                    date = QString::number(timer->tm_mday) + "/" + QString::number(1+timer->tm_mon) + "/" + QString::number(1900+timer->tm_year);
                  return date;
                }

              Q_INVOKABLE QString realtimer(){
                    now = time(NULL);
                    timer = localtime(&now);
                    timerqml = ""; //delete the last updated string
                    timerqml += "\nTime: " + QString::number(timer->tm_hour) + ":" + QString::number(timer->tm_min) + ":" + QString::number(timer->tm_sec);

                  return timerqml;
                }

              Q_INVOKABLE QString greet(){
                  greetstr = ""; //delete the last updated string

                  if(timer->tm_hour >= 5 && timer->tm_hour < 12) {
                      greetstr += "Good Morning!";
                  }
                  else if(timer->tm_hour >= 12 && timer->tm_hour < 18){
                      greetstr += "Good Afternoon!";
                  }
                  else {
                      greetstr += "Good Evening!";
                  }
                   return greetstr;
              }
            };

#endif // TIMER_HPP
