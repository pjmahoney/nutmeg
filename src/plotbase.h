#ifndef PLOTBASE_H
#define PLOTBASE_H

#include <QQuickItem>
#include "nutmegobject.h"
#include "axisbase.h"

class AxisBase;
class PlotBase : public QQuickItem, public NutmegObject
{
    Q_OBJECT
    Q_PROPERTY(QString handle READ handle WRITE setHandle NOTIFY handleChanged)
    Q_PROPERTY(AxisBase* axis READ axis NOTIFY axisChanged)

public:
    explicit PlotBase(QQuickItem *parent = 0);

    QString handle() const;
    void setHandle(QString arg);

    AxisBase *axis() const;

signals:
    void handleChanged(QString arg);
    void axisChanged(AxisBase* arg);

public slots:
    void findAxis();
    virtual void print(QPainter *painter) { Q_UNUSED(painter); }

    // Nutmeg object. TODO: Remove once Q_GADGET working properly...
    virtual void registerProperties(QMap<QString, QString> mapping) {
        NutmegObject::registerProperties(mapping);
    }
    virtual void registerProperties(QVariantMap mapping) {
        NutmegObject::registerProperties(mapping);
    }
    virtual QString mapProperty(const QString &prop) {
        return NutmegObject::mapProperty(prop);
    }

    virtual void registerMethods(QMap<QString, QString> mapping) {
        NutmegObject::registerMethods(mapping);
    }
    virtual QString mapMethod(const QString &method) {
        return NutmegObject::mapMethod(method);
    }

protected slots:
    virtual void updateAxis(AxisBase* oldAxis, AxisBase* newAxis) { Q_UNUSED(oldAxis); Q_UNUSED(newAxis); }

private:
    void setAxis(AxisBase *arg);
    QString m_handle;
    AxisBase* m_axis;
};

#endif // PLOTBASE_H
