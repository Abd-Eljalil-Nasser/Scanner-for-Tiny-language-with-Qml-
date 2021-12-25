#ifndef CORE_H
#define CORE_H
#include<QObject>
#include<string>
#include<QString>
#include<iostream>
#include <QStack>


class core : public QObject
{
    Q_OBJECT
public:
    explicit core(QObject *parent = nullptr);
    Q_INVOKABLE QString core_work(QString input);


signals:

public slots:

};

#endif // CORE_H
