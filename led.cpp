#include "led.h"

led::led(QObject *parent) : QObject(parent), initialState_(true),
    state_(true), blinkingRate_(100), blinking_(false)
{
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(toggleState()));
}

led::~led()
{

}

void led::setLabel(QLabel* LED)
{
    this->LED = LED;
}
//------------------------------------
bool led::state()
{
    return state_;
}

bool led::isBlinking()
{
    return blinking_;
}

int led::blinkingRate()
{
    return blinkingRate_;
}
// Slots ------------------------------------


void led::setOn()
{
    setState(true);
}

void led::setOff()
{
    setState(false);
}

void led::toggleState()
{
    state_ = !state_;
    stateUpdate();
}

void led::startBlinking()
{
    timer_->start(blinkingRate_);
    setBlinking(true);   
}

void led::stopBlinking()
{
    timer_->stop();
    setBlinking(false);
    setState(false);
}

void led::setBlinkingRate(int rate)
{
    blinkingRate_ = rate;
}

void led::changeColor()
{
    setColor(rand() % 3);
}

//------------------------------------
void led::setBlinking(bool blinking)
{
    blinking_ = blinking;
}

void led::setState(bool state)
{
    state_ = state;
    stateUpdate();
}

void led::setColor(int color)
{
    switch(color){
    case LED::GREEN :
        OnStyle = "image: url(:/ICONS/LED_GREEN_FRAME_ON.png)";
        OffStyle = "image: url(:/ICONS/LED_GREEN_FRAME_OFF.png)";
        stateUpdate();
        break;
    case LED::RED :
        OnStyle = "image: url(:/ICONS/LED_RED_FRAME_ON.png)";
        OffStyle = "image: url(:/ICONS/LED_RED_FRAME_OFF.png)";
        stateUpdate();
        break;
    case LED::ORANGE :
        OnStyle = "image: url(:/ICONS/LED_ORANGE_FRAME_ON.png)";
        OffStyle = "image: url(:/ICONS/LED_ORANGE_FRAME_OFF.png)";
        stateUpdate();
        break;
    case LED::BLUE :
        OnStyle = "image: url(:/ICONS/LED_BLUE_FRAME_ON.png)";
        OffStyle = "image: url(:/ICONS/LED_BLUE_FRAME_OFF.png)";
        stateUpdate();
        break;
    defaut :
        qDebug() << "Color code not valid, please choose 0:GREEN, 1:RED, 2:ORANGE, 3:BLUE";
        break;
    }
}

void led::stateUpdate()
{
    if(state_)
        LED->setStyleSheet(OnStyle);
    else
        LED->setStyleSheet(OffStyle);
}

