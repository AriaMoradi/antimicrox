#ifndef JOYDPAD_H
#define JOYDPAD_H

#include <QObject>
#include <QHash>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "joydpadbutton.h"

class JoyDPad : public QObject
{
    Q_OBJECT
public:
    explicit JoyDPad(QObject *parent = 0);
    explicit JoyDPad(int index, int originset, QObject *parent=0);
    ~JoyDPad();

    JoyDPadButton* getJoyButton(int index);
    QHash<int, JoyDPadButton*>* getJoyButtons();

    int getCurrentDirection();
    int getJoyNumber();
    int getIndex();
    int getRealJoyNumber();
    QString getName();
    void joyEvent(int value, bool ignoresets=false);
    void readConfig(QXmlStreamReader *xml);
    void writeConfig(QXmlStreamWriter *xml);

protected:
    void populateButtons();

    QHash<int, JoyDPadButton*> buttons;
    int index;
    int prevDirection;
    int originset;

signals:
    
public slots:
    
};

#endif // JOYDPAD_H
