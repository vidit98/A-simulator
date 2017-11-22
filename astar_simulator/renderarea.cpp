#include "renderarea.h"
#include <queue>
#include <QTimer>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    scribbling = false;
    astar = new ASTAR;
}

/**
 * @brief Draw the world.
 * @param painter
 */
void RenderArea::drawField(QPainter &painter)
{
    painter.save();
    painter.setRenderHint(QPainter::Antialiasing);
    QRect field;
    field.setTopLeft(QPoint(this->x(), this->y()));
    field.setBottomRight(QPoint(this->width()-1, this->height()-1));
    painter.setPen(Qt::black);
    painter.setBrush(QBrush(Qt::green));
    painter.drawRect(field);
    painter.restore();
}

/**
 * @brief Draw the start position of the bot.
 * @param painter
 */
void RenderArea::drawCurrentPos(QPainter &painter)
{
    painter.save();
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::black);
    painter.setBrush(QBrush(Qt::red));
    painter.drawEllipse(this->x() + astar->currentPos.x() - BOT_RADIUS, this->y() + astar->currentPos.y() - BOT_RADIUS, 2 * BOT_RADIUS, 2 * BOT_RADIUS);
    painter.restore();
}

/**
 * @brief Draw the end point.
 * @param painter
 */
void RenderArea::drawEndPos(QPainter &painter)
{
    painter.save();
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::black);
    painter.setBrush(QBrush(Qt::blue));
    painter.drawEllipse(END_POS_X - BOT_RADIUS, END_POS_Y - BOT_RADIUS, 2 * BOT_RADIUS, 2 * BOT_RADIUS);
    painter.restore();
}

/**
 * @brief Draw all the rectangular obstacles.
 * @param painter
 */
void RenderArea::drawObstacles(QPainter &painter)
{
    painter.save();
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::black);
    painter.setBrush(QBrush(Qt::black));
    pair<Vector2f, Vector2f> obstacle;
    for(int i = 0; i < (int)astar->obstacles->obstacles.size(); i++) {
        obstacle = astar->obstacles->obstacles[i];
        QPoint topLeft(obstacle.first.x(), obstacle.first.y());
        QPoint bottomRight(obstacle.second.x(), obstacle.second.y());
        QRect rect(topLeft, bottomRight);
        painter.drawRect(rect);
    }
    painter.restore();
}

/**
 * @brief Draw all the nodes generated in the astar algorithm.
 * @param painter
 */
void RenderArea::drawNodes(QPainter &painter)
{
    painter.save();
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::black);
    painter.setBrush(QBrush(Qt::black));
    Vector2f pos;
    

    /*
    for(int i = 0; i < (int)astar->open.size() - 1; i++) {
        
        QPointF p1(astar->open[i]->position.x(), astar->open[i]->position.y());
        QPointF p2(astar->open[i+1]->position.x(), astar->open[i+1]->position.y());
        painter.drawLine(p1, p2);
    }
    painter.setPen(Qt::red);
    painter.setBrush(QBrush(Qt::red));
    
    // if a path exists, draw it.*/
    printf("%s\n","LOOOOP" );
    
           
    

    
    for(int i = 0; i < (int)astar->path.size() - 1; i++) {
        QPointF p1(astar->path[i]->position.x(), astar->path[i]->position.y());
        QPointF p2(astar->path[i+1]->position.x(), astar->path[i+1]->position.y());
        painter.drawLine(p1, p2);
    }
    painter.setPen(Qt::red);
   
    painter.setBrush(QBrush(Qt::red));
    for(int i = 0; i < (int)astar->old_path.size() - 1; i++) {
        QPointF p1(astar->old_path[i]->position.x(), astar->old_path[i]->position.y());
        QPointF p2(astar->old_path[i+1]->position.x(), astar->old_path[i+1]->position.y());
        painter.drawLine(p1, p2);
    }
    
    painter.restore();
}

void RenderArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    drawField(painter);
    drawCurrentPos(painter);
    drawEndPos(painter);
    drawObstacles(painter);
    drawNodes(painter);
    emit painting();
}

void RenderArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastMouseClickedPoint = event->pos();
        scribbling = true;
    }
}

void RenderArea::mouseMoveEvent(QMouseEvent *event)
{

}

void RenderArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && scribbling) {
        QPoint curPoint = event->pos();
        astar->obstacles->addObstacle(Vector2f(lastMouseClickedPoint.x(), lastMouseClickedPoint.y()), Vector2f(curPoint.x(), curPoint.y()));
        update();
        scribbling = false;
    }
}
