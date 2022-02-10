#ifndef LED_H
#define LED_H

#include <QWidget>
#include <QTimer>
#include <QLabel>

namespace LED{
    const quint8 GREEN  = 0;
    const quint8 RED    = 1;
    const quint8 ORANGE = 2;
    const quint8 BLUE   = 3;
}

class led : public QObject
{
    Q_OBJECT

public:
    explicit led(QObject *parent = nullptr);
    ~led();

    bool state();
    bool isBlinking();
    int blinkingRate();
    void setLabel(QLabel* LED);

public slots:
    void setOn();
    void setOff();
    void toggleState();
    void setBlinkingRate(int rate);
    void startBlinking();
    void stopBlinking();
    void changeColor();

private:
    void setState(bool state);
    void setBlinking(bool blinking);
    void stateUpdate();
    void setColor(int color);

signals:

private:
    bool initialState_;
    bool state_;
    int blinkingRate_;
    bool blinking_;
    QString OnStyle = "image: url(:/ICONS/LED_GREEN_FRAME_ON.png)";
    QString OffStyle = "image: url(:/ICONS/LED_GREEN_FRAME_OFF.png)";
    QTimer* timer_;
    QLabel* LED;

};

#endif // LED_H
