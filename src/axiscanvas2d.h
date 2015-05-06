#ifndef AXISCANVAS2D_H
#define AXISCANVAS2D_H

#include <QQuickPaintedItem>
#include <QStaticText>

#include "axis2dbase.h"

class AxisCanvas2D : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(Axis2DBase* axis READ axis WRITE setAxis NOTIFY axisChanged)
//    Q_PROPERTY(QRectF plotRect READ plotRect NOTIFY plotRectChanged)
    Q_PROPERTY(qreal scaling READ scaling WRITE setScaling NOTIFY scalingChanged)

    Q_PROPERTY(qreal titleMargin READ titleMargin WRITE setTitleMargin NOTIFY titleMarginChanged)
    Q_PROPERTY(qreal xLabelMargin READ xLabelMargin WRITE setXLabelMargin NOTIFY xLabelMarginChanged)
    Q_PROPERTY(qreal yLabelMargin READ yLabelMargin WRITE setYLabelMargin NOTIFY yLabelMarginChanged)
    Q_PROPERTY(qreal xTicksMargin READ xTicksMargin WRITE setXTicksMargin NOTIFY xTicksMarginChanged)
    Q_PROPERTY(qreal yTicksMargin READ yTicksMargin WRITE setYTicksMargin NOTIFY yTicksMarginChanged)

public:
    explicit AxisCanvas2D(QQuickItem *parent = 0);

    void paint(QPainter *painter);

    Axis2DBase* axis() const;
    void setAxis(Axis2DBase* arg);

    qreal scaling() const;
    void setScaling(qreal arg);

    qreal titleMargin() const;
    void setTitleMargin(qreal arg);

    qreal xLabelMargin() const;
    void setXLabelMargin(qreal arg);

    qreal yLabelMargin() const;
    void setYLabelMargin(qreal arg);

    qreal xTicksMargin() const;
    void setXTicksMargin(qreal arg);

    qreal yTicksMargin() const;
    void setYTicksMargin(qreal arg);

signals:
    void axisChanged(Axis2DBase* arg);
//    void plotRectChanged(QRectF arg);
    void scalingChanged(qreal arg);

    void titleMarginChanged(qreal arg);
    void xLabelMarginChanged(qreal arg);
    void yLabelMarginChanged(qreal arg);
    void xTicksMarginChanged(qreal arg);
    void yTicksMarginChanged(qreal arg);

public slots:
    void triggerUpdate();
    void updatePlotRect();

private:
//    void setPlotRect(QRectF arg);
    QList<qreal> plot2canvasX(QList<qreal> x);
    QList<qreal> plot2canvasY(QList<qreal> y);
    void drawXTicks(QList<qreal> major, QPainter *painter);
    void drawYTicks(QList<qreal> major, QPainter *painter);
    void drawGrid(QList<qreal> xMajor, QList<qreal> yMajor, QPainter *painter);

    void prepareTexts();
    qreal prepareScale(AxisSpec *spec, qreal range, QStaticText *st);
    QSizeF prepareTickLabels(AxisSpec *spec, QHash<QString, QStaticText *> &labelTexts,
                            QList<QString> &tickStrings, qreal scale);
    void drawTitle(QPainter *painter);
    void drawXLabel(QPainter *painter);
    void drawYLabel(QPainter *painter);
    QStaticText *getStaticText(const QString &text);
    void drawXTickLabels(QList<qreal> xFrames, QPainter *painter);
    void drawYTickLabels(QList<qreal> yFrames, QPainter *painter);

    Axis2DBase* m_axis;

    qreal m_scaling;
    qreal m_titleMargin;
    qreal m_xLabelMargin;
    qreal m_yLabelMargin;
    qreal m_xTicksMargin;
    qreal m_yTicksMargin;

//    qreal m_titleHeight;
//    qreal m_xLabelHeight;
//    qreal m_yLabelWidth;
    qreal m_xTicksHeight;
    qreal m_yTicksWidth;

    QHash<QString, QStaticText*> m_xTickText;
    QHash<QString, QStaticText*> m_yTickText;
    QList<QStaticText*> m_tickTextPool; // Holds unused QStaticText objects for later
    QStaticText m_title;
    QStaticText m_xLabel, m_yLabel;
    QStaticText m_xScale, m_yScale;
    QStaticText m_xOffset, m_yOffset;

    QList<QString> m_xTicks;
    QList<QString> m_yTicks;

};

#endif // AXISCANVAS2D_H
