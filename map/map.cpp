#include "map.h"

std::string map::startingPoint;
std::vector<map*> euromap;

map::map(const std::string& name, int x, int y) {
    location = name;
    isSelected = false;
    isAvailable = true;
    pressed = false;
    this->x = x;
    this->y = y;
    brush = (Qt::blue);
}

std::string map::GetLocation() const { return location; };

QRectF map::boundingRect() const { return QRectF(x, y, 10, 10); }

void map::setPressed(bool isPressed) {
    pressed = isPressed;
    isSelected = true;
    QGraphicsItem::update();
}

void map::setIsSelected(bool isDotSelected) {
    isSelected = isDotSelected;
    pressed = false;
    QGraphicsItem::update();
}

void map::setAvailability(bool available) {
    isAvailable = available;
    QGraphicsItem::update();
}

void map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget) {
    rec = boundingRect();

    if (isAvailable) {
        painter->setPen(Qt::black);
        brush.setColor(Qt::green);
        if (isSelected) {
            brush.setColor(Qt::blue);
            if (pressed) {
                startingPoint = location;
                brush.setColor(Qt::red);
            }
        }
    }
    else {
        painter->setPen(Qt::transparent);
        brush.setColor(Qt::transparent);
    }
    painter->fillRect(rec, brush);
    painter->drawRect(rec);
}

void map::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    pressed = !pressed;
    for (auto & dot: euromap) {
        if (dot->pressed && dot->location == startingPoint) {
            dot->setPressed(false);
        }
    }
    QGraphicsItem::mousePressEvent(event);
    QGraphicsItem::update();
}

std::string map::getStartingCity() {
    return startingPoint;
}