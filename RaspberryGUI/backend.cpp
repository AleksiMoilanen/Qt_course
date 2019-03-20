#include "backend.h"

BackEnd::BackEnd(QObject *parent) : QObject(parent)
{
    qDebug() << "BackEnd init";

    Sensor* sensor1 = new Sensor();
    sensor1->sensorName = "Lämpötila - Toimisto";
    sensor1->measurementType = Temperature;
    sensor1->interval = 1000;

    Sensor* sensor2 = new Sensor();
    sensor2->sensorName = "Ilmankosteus - Toimisto";
    sensor2->measurementType = Humidity;
    sensor2->interval = 5000;

    Sensor* sensor3 = new Sensor();
    sensor3->sensorName = "Lämpötila - Ulkoilma";
    sensor3->measurementType = Temperature;
    sensor3->interval = 1000;

    sensorList.append(sensor1);
    sensorList.append(sensor2);
    sensorList.append(sensor3);

    qDebug() << "SensorList greated succesfully" << sensorList;
}

void BackEnd::getObjects(QObject *object, QQmlContext *context)
{
    qDebug() << "QObject:" << object << "QQmlContext" << context;

    _object = object;
    _context = context;
}

QString BackEnd::getSensorName(int id)
{
    return sensorList.at(id)->sensorName;
}

QVariant BackEnd::getSensorReadInterval(int id)
{
    return QVariant(sensorList.at(id)->interval);
}

void BackEnd::getSensorValue(QObject* object, int id)
{
    float val = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    //char* value = val + sensorList.at(id)->measurementType
    float nearest = roundf(val * 100) / 100;
    QString value;

    qDebug() << object << id << val;

    switch (sensorList.at(id)->measurementType) {
        case Temperature:
            value = QString::number(nearest) + " °C";
            qDebug() << "TEMPERATURE";
            break;
        case Humidity:
            value = QString::number(nearest) + ' %';
            qDebug() << "HUMIDITY";
        default:
            value = QString::number(nearest);
            break;
    }

    qDebug() << value;

    QMetaObject::invokeMethod(object, "updateSensorValue", Q_ARG(QVariant, QVariant(value)));
}
