#ifndef BACKEND_H
#define BACKEND_H

#include <QDebug>
#include <QObject>
#include <QQmlContext>

struct Sensor{
    QString sensorName;
    int measurementType;
    int interval;
};

enum MeasurementType{
    Temperature = 0,
    Humidity = 1
};

class BackEnd : public QObject
{
    Q_OBJECT

    public:
        BackEnd(QObject* parent = nullptr);

        void getObjects(QObject* object, QQmlContext* context);

        Q_INVOKABLE QString getSensorName(int id);
        Q_INVOKABLE QVariant getSensorReadInterval(int id);

        Q_INVOKABLE void getSensorValue(QObject* object, int id);

    private:

        QObject* _object;
        QQmlContext* _context;

        QList<Sensor*> sensorList;
};

#endif // BACKEND_H
