#ifndef PLACESJSMANAGER_H
#define PLACESJSMANAGER_H

#include <QObject>
#include <QVariantList>

class QWebFrame;

class PlacesJsManager : public QObject
{
    Q_OBJECT
public:
    explicit PlacesJsManager(QObject *parent = 0);
    
    void setFrame(QWebFrame * frame) { m_pFrame = frame; }
    QString getCurrentPointOfView() const;
    
    void removeMarkers();
    void createMarkers(const QVariantList & list);
    void recreateSearchCircle(const QString & location, const QString & radius);

private:
    QVariant eval(const QString & script) const;

private:
    QWebFrame * m_pFrame;
};

#endif // PLACESJSMANAGER_H
